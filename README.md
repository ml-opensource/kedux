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

## Reducers

There are two main kinds of reducers.

`anyReducer`: constructs a reducer on the whole global store, without specifying action type. This is useful when your reducer 
consumes multiple action classes. You will need to handle default case in this instance.

`typedReducer` (preferred): constructs a reducer that will only run when the `Action` class type is of the type specified. So 
that a safer consumption occurs. I.e. the reducer only executes when the action type is a subtype of the expected action type.

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
val productSelector = locationSelector.compose { state -> state.product}
val productNameSelector = productSelector.compose { state -> state.name }
```

By composing selectors in separate fields, they become more reusable.

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

[badge-android]: http://img.shields.io/badge/platform-android-brightgreen.svg?style=flat
[badge-ios]: http://img.shields.io/badge/platform-ios-lightgrey.svg?style=flat
[badge-js]: http://img.shields.io/badge/platform-js-yellow.svg?style=flat
[badge-jvm]: http://img.shields.io/badge/platform-jvm-orange.svg?style=flat
[badge-linux]: http://img.shields.io/badge/platform-linux-important.svg?style=flat 
[badge-windows]: http://img.shields.io/badge/platform-windows-informational.svg?style=flat
[badge-mac]: http://img.shields.io/badge/platform-macos-lightgrey.svg?style=flat
[badge-wasm]: https://img.shields.io/badge/platform-wasm-darkblue.svg?style=flat
