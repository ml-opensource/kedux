# Kedux

![badge][badge-android]
![badge][badge-ios]
![badge][badge-js]
![badge][badge-jvm]
![badge][badge-mac]

Kedux is a Kotlin-multiplatform implementation of [redux](redux.js.org) that works 
on Android, iOS, MacOS, and JS utilizing [Reaktive](https://github.com/badoo/Reaktive)
 to provide the RX plumbing on all platforms.

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

We recommend using dependency injection to provide your store in your application so it's easier to test.

```kotlin

val store =  createStore(sampleReducer, initialState, loggingEnabled = true)

```

### Selectors

To observe changes on the store, subscribe to its state:

```kotlin
store.createSelector { state -> state.name }
.subscribe { name ->
  // do something with name
}.addTo(compositeDisposable) 
```

It's important to ensure you add the store subscription to `compositeDisposable` in scope, 
so that you do not introduce memory leaks.


## Features

This library has a few features. TBD on full descriptions.

### Fractured State

Fractured state is when we want to have our reducers only respond to state changes on a single field from the `GlobalState` 
variable. This is accomplished using the `FracturedState` object and special creation of our store:
```kotlin
 store = createFracturedStore(
            productReducer reduce Product(0, ""),
            locationReducer reduce Location(0, ""),
            loggingEnabled = true
        )
```
This method returns a `Store<FracturedState>` with a few helper extensions to make usage cleaner.
`FracturedState` is essentially an unsafe reducer-class to object mapper. 

`reduce` is an `infix` convenience to enforce our reducer we specify lines up with the default state of its fractured state.

`productReducer` looks like:
```kotlin
// has a different set of actions, and use top-level object we want to grab
val productReducer = typedReducer<Product, ProductActions> { state, action ->
    when (action) {
        is ProductActions.NameChange -> state.copy(name = action.name)
    }
}
```

`loggingEnabled`: set this to log events to the native console as they come in. Preferrably this is set only on development 
builds.

Now we can subscribe to the changes via:
```kotlin
 store.fracturedSelector(productReducer)
  .subscribe { value ->
   // do something with Product                 
 }.addTo(compositeDisposable)
```

The `fracturedReducer` will loop through each reducer to determine any state changes and update subscribers across the fractured state map. 

[badge-android]: http://img.shields.io/badge/platform-android-brightgreen.svg?style=flat
[badge-ios]: http://img.shields.io/badge/platform-ios-lightgrey.svg?style=flat
[badge-js]: http://img.shields.io/badge/platform-js-yellow.svg?style=flat
[badge-jvm]: http://img.shields.io/badge/platform-jvm-orange.svg?style=flat
[badge-linux]: http://img.shields.io/badge/platform-linux-important.svg?style=flat 
[badge-windows]: http://img.shields.io/badge/platform-windows-informational.svg?style=flat
[badge-mac]: http://img.shields.io/badge/platform-macos-lightgrey.svg?style=flat
[badge-wasm]: https://img.shields.io/badge/platform-wasm-darkblue.svg?style=flat
