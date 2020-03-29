# Kedux

![badge][badge-android]
![badge][badge-ios]
![badge][badge-js]
![badge][badge-jvm]
![badge][badge-mac]

Kedux is a Kotlin-multiplatform implementation of [redux](redux.js.org) that works 
on Android, iOS, MacOS, and JS utilizing [Reaktive](https://github.com/badoo/Reaktive)
 to provide the RX plumbing on all platforms.
 
 __NOTE: This library is currently in development preview. Please check back later when it's ready for release.__

## Getting Started

### State

State in Kedux should be immutable. This means utilizing `data class`, `List`, `Map`, and 
all immutable constructs Kotlin provides.

The `State` object should represent your application's state. *Note*: Kedux supports `FracturedState` for apps that want to split up 
state into multiple modules.

Say we have a simple state as:

```kotlin
data class Product(val id: Int, val name: String)
data class Location(val id: Int, val other: String, val product: Product? = null)
data class GlobalState(val name: String, val location: Location? = null)

// define an initial state (required)
// gets emitted on first selector subscription.
val initialState = GlobalState(name = "", location = null)
``` 

### Reducer

Next define a set of actions. These actions should be `sealed class` type so we can do some magic.

```kotlin
sealed class StoreTestAction {

    data class NameChange(val name: String) :
        StoreTestAction()

    data class LocationChange(val location: Location) :
        StoreTestAction()

    // objects are nice
    object Reset : StoreTestAction()
}
``` 

Next, we define our global reducer for our state. Kedux supports reducers from global state, fractured state, 
and on specific action types automatically.

```kotlin
val sampleReducer = typedReducer<GlobalState, StoreTestAction> { state, action ->
    // due to action sealed class, compiler can verify all action type args!
    // under the hood, this inline function typedReducer verifies the action is the proper type 
    // before arriving here.
    when (action) {
        is StoreTestAction.NameChange -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
        is StoreTestAction.LocationChange -> state.copy(location = action.location)
    }
}
```

As you would for Redux, construct your store somewhere accessible.

We recommend using dependency injection to provide your store in your app so it's easier to test.

```kotlin

val store =  createStore(sampleReducer, initialState)

```

#### Logging

`Store.loggingEnabled`: set this to log events to the native console as they come in. Preferrably this is set only on development 
builds.

### Selectors

Selectors are pure `Observable` functions that accept state and emit changes to the state.

Selectors _only_ emit when their output is distinct. 

Selectors _only_ recompute when their upstream state is distinct.

Selectors emit on subscription. So dowstream observers will receive the latest state.

Selectors can be combined.

To observe changes on the store, subscribe to its state:

```kotlin
val nameSelector = createSelector<GlobalState, String> { state -> state.name }

// subscribe to store updates
store.select(nameSelector).subscribe { name ->
  // do something with name
}.addTo(compositeDisposable) 
```

It's important to ensure you add the store subscription to `compositeDisposable` in scope, 
so that you do not introduce memory leaks.

## Features

This library has a few features. TBD on full descriptions.

## Store

`Store` is an object that exposes an `Observable<State>` in which subscribers can listen to state changes. 

`createStore`: creates the store with a global `reducer`, initialState (required), `enhancer` (more on these later), 
and `loggingEnabled`.

`Store.dispatch`: **asynchronously** dispatches actions to the `state`. Selection happens on the `computationScheduler`, 
and then returns the result object on the `mainScheduler` thread of the platform.

__Note__: Kotlin Native targets should be wary of frozen objects. Using Reaktive's `threadLocal` method, we can mostly 
get around this, but its not perfect and please be forewarned. `State` in any sense should be immutable, so in theory this 
will not be much of an issue. 

### Supported Action Types

You can `dispatch` special objects on the `Store` if you wish.

Supported types:

`1`. `Pair` - dispatches both actions on the store in order.
```kotlin
store.dispatch(MyAction() to MyAction2())
```  

`2`. `Triple` - dispatches all three actions on the store in order.
```kotlin
store.dispatch(Triple(MyAction(), MyAction2(), MyAction3()))
```

`3`. `MultiAction` - dispatches 0 to N actions on the store in order.

```kotlin
store.dispatch(multipleActionOf(MyAction(), MyAction2(), MyAction3(), MyActionN()))
```

`4`. `NoAction` - store will not dispatch the action. Useful for `Effects` that are silent, or within a `when` returns that 
return an Action type based on conditions and you want to ignore the action:

```kotlin
store.dispatch(when(name) {
    "first" -> FirstNameChanged(name) 
    "middle" -> MiddleNameChanged(name)
    "last" -> LastNameChanged(name)
    else -> NoAction
})
```

`5`. `Action<T>` - actions based on a type argument to distinguish them. Rather instead of using Action `data class`, 
you can create actions as functions:

```kotlin

// no arguments or payload immediately create action (to get around passing `Unit` to `ActionCreator`)
val loadUsersAction = createAction("[Users] Load Users")

// use on store
store.dispatch(loadUsersAction)

// ActionCreator with `Int` argument, that returns an action with `Int` payload incremented by 1.
val loadUserAction = createAction("[Users] Load User by Id") { argument: Int -> argument + 1 }

// use on store
store.dispatch(loadUserAction(5))

// ActionCreator that accepts no arguments but allows payload return:
val loadUserActionDefault = createAction("[Users] Load User by Id Default") { 1 }

// use on Store
store.dispatch(loadUserActionDefault())

```

## Reducers

There are three main kinds of reducers.

`anyReducer`: constructs a reducer on the whole global store, without specifying action type. This is useful when your reducer 
consumes multiple action classes. You will need to handle default case in this instance.

`typedReducer` (preferred): constructs a reducer that will only run when the `Action` class type is of the type specified. So 
that a safer consumption occurs. I.e. the reducer only executes when the action type is a subtype of the expected action type.

```kotlin
val sampleReducer = typedReducer<GlobalState, StoreTestAction> { state, action ->
    when (action) {
        is StoreTestAction.NameChange   -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
        is StoreTestAction.LocationChange -> state.copy(location = action.location)
        is StoreTestAction.NamedChanged -> state.copy(nameChanged = true)
        is StoreTestAction.LocationChanged -> state
        // using data classes, compiler doesn't need an `else` branch.
    }
}
```

`actionTypeReducer`: constructs a reducer that will only run when the `Action.type` matches the type specified in the reducer. 
This is useful for `createAction` results by function and switching on the type you want to consume.

```kotlin
val sampleTypedReducer = actionTypeReducer { state: GlobalState, action: Action<SampleEnumType, out Any> ->
    when (action.type) {
        SampleEnumType.LocationChange -> state.copy(location = action.payload as Location?)
        SampleEnumType.NameChange -> state.copy(name = action.payload as String)
        SampleEnumType.Reset -> initialState
        // use enum for action type tokens ensures compiler doesnt need an `else` branch.
    }
}
```

`combineReducers`: Combines multiple reducers to listen on the same state object. 

## Selectors

Selectors are functions that are memoized with their input data and only recompute when the state changes. 
They are useful for heavy calculations such as retrieving an object out of a list by id, for example.

Creating a selector is easy:
```kotlin
val fieldSelector = createSelector<GlobalState, Field> { state -> state.field }
store.select(fieldSelector).subscribe { value  ->
  // do something
}
.addTo(compositeDisposable)
```

Selectors can be composed. Each nested level only recomputes when its outer state changes. It's best practice 
to break up the composition into smaller pieces.

```kotlin
// avoid
val nameSelector = createSelector<GlobalState, Location?> { state -> state.location }
    .compose { state -> state.product}
    .compose { state -> state.name }

// preferred
val locationSelector = createSelector<GlobalState, Location?>  { state -> state.location }
val productSelector = locationSelector.compose { state -> state.product }
val productNameSelector = productSelector.compose { state -> state.name }
```

By composing selectors in separate fields, they become more reusable.

## Effects / Sagas

Effects are `Observable` chains that respond to a particular action, or set of actions and return with 
another action, set of actions (`MultiAction`), or `NoAction`.

To define an `Effect`:

```kotlin
val getUsersEffect = createEffect<LoadUsers, UsersReceived> { actionObservable ->
    actionObservable.flatMap { (userId) -> userService.getUsers(userId) }
        .map { users -> UsersReceived(users) }
}
```

In this example, the `Effect` responds to a `LoadUsers` action, calls out to `UserService`, and returns a `UsersReceived` 
action, which the store dispatches out to a `Reducer` to handle. 

__Pro Tip__: Be careful of cyclical `Effect`. If you have two separate effects consume and dispatch each other's effects, 
you could run into a cycle that consumes your application and might cause it to freeze.

Now group the `Effect` into an `Effects` object:

```kotlin
val usersEffects = Effects(getUsersEffect)
```

An `Effects` object manage the scoped lifecycle and binding to the `Store` actions. They efficiently 
group the bindings together into logical components.

`Effects` are bound to the `Store` in a couple of ways: globally and scoped.

Globally - bind to the `Store` in global scope when the `Store` is created:

```kotlin
store = createStore(...)
    .also { usersEffects.bindTo(it) }
 ```

Or Scope Effect groupings at a smaller level, such as within a particular flow in your application:
```kotlin

val usersEffects = Effects(getUsersEffect, effect2, effectN)

// bind to store when object in scope
userEffect.bindTo(store)

// remove subscriptions to Store when out of scope.
userEffect.clearBindings()

```

### Multiple Actions

`Effects` can return multiple effects at a time in a fan-out fashion. This is very useful 
when you want keep your actions pure, such as notifying a `Reducer` of a loading state change, while another `Reducer`  
receives the actual data.

```kotlin
val multipleDispatchEffect = createEffect<LocationChange, MultiAction> { change ->
    change.map { (location) -> multipleActionOf(LocationChanged(location.other), LoadStatus.Done) }
}
```

All types specified in `Store` are supported as return types in `Effects`.

## Advanced Features

## Enhancers

Enhancers enable you to transform an action as they come in and go to `dispatch`. They enable 
you to dispatch multiple actions outside the normal single-dispatch action. 

```kotlin
createStore(reducer, initialState, enhancer = DevToolsEnhancer()) // just an example
```

__combining enhancers__: coming soon.

### Fractured States

Fractured state is when we want to have our reducers only respond to state changes on a single field from the `GlobalState` 
variable. This is accomplished using the `FracturedState` object and special creation of our store:
```kotlin
 store = createFracturedStore(
            productReducer reduce Product(0, ""),
            locationReducer reduce Location(0, "")
        )
```
This method returns a `Store<FracturedState>` with a few helper extensions to make usage cleaner.
`FracturedState` is essentially a reducer-class to object map. 

`reduce` is an `infix` convenience to enforce unified object type between our reducer and default state of its fractured state. This 
is impossible to enforce using the `Pair` class directly, so use `reduce` instead of `to`.

`productReducer` looks like:
```kotlin
// has a different set of actions, and use top-level object we want to grab
val productReducer = typedReducer<Product, ProductActions> { state, action ->
    when (action) {
        is ProductActions.NameChange -> state.copy(name = action.name)
    }
}
```

Now we can subscribe to the changes via:
```kotlin
 store.select(fracturedSelector(productReducer))
  .subscribe { value ->
   // do something with Product                 
 }.addTo(compositeDisposable)
```

The `fracturedReducer` will loop through each reducer to determine any state changes and update subscribers across the fractured state map. 

Nesting `fracturedReducer` is not supported, though `compose`-ing is supported.

### Loading States

Typically to represent loading state you might create an object to represent success, error, loading, and result.

Kedux provides a convenience object `KeduxLoader` to represent all actions, a reducer to handle state changes, and an effect to coordinate 
the loading, success, and error states.

Also, `KeduxLoader` supports clearing state via `loader.clear` action type.

```kotlin
val userLoadingState = KeduxLoader<Int, User>("user") { id -> userService.getUser(id) }

// request action
store.dispatch(userLoadingState.request(5))

// resets state back to LoadingModel.empty()
store.dispatch(userLoadingState.clear)

// can manually call if you dont want the default effect
store.dispatch(userLoadingState.success(user))
store.dispatch(userLoadingState.error(error))

// you must use the LoadingModel object to represent it's state.
data class State(val user: LoadingModel<User> = LoadingModel.empty())

// define selectod
val userLoadingStateSelector = createSelector { state: State -> state.user }
// only emits if success is not null
val userSuccess = userLoadingStateSelector.success()
val userOptionalSuccess = userLoadingStateSelector.optionalSucces()
// only emits if error is not null
val userError = userLoadingStateSelector.error()
val userOptionalError = userLoadingStateSelector.optionalError()

// convenience extensions on selectors
store.select(userSuccess)
 .subscribe { success ->
  // only returns if there's a success value
 }
 .addTo(disposable)
```

Since we want to avoid reflection, using the `KeduxLoader` reducer requires a little more magic:
```kotlin
val reducer = typedReducer { state: State, action: LoadingAction<*, *> ->
    state.copy(product = loadingProduct.reducer.reduce(state.product, action))
}
```

We need to call the reducer manually in this case.

[badge-android]: http://img.shields.io/badge/platform-android-brightgreen.svg?style=flat
[badge-ios]: http://img.shields.io/badge/platform-ios-lightgrey.svg?style=flat
[badge-js]: http://img.shields.io/badge/platform-js-yellow.svg?style=flat
[badge-jvm]: http://img.shields.io/badge/platform-jvm-orange.svg?style=flat
[badge-linux]: http://img.shields.io/badge/platform-linux-important.svg?style=flat 
[badge-windows]: http://img.shields.io/badge/platform-windows-informational.svg?style=flat
[badge-mac]: http://img.shields.io/badge/platform-macos-lightgrey.svg?style=flat
[badge-wasm]: https://img.shields.io/badge/platform-wasm-darkblue.svg?style=flat
