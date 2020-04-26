# Swift Guide

This document outlines Swift APIs and support for getting started with Kedux.
Kedux fully supports Swift APIs and provides a nice Swift API.

## Installing

Using Cocoapods, add the Pod to your Podfile:

```ruby
  pod Kedux
```

## Getting Started

### State

State in Kedux should be immutable. Utilize structs to provide best immutability support.

The `State` object represents your application's global state. Each slice of state might represent separate pieces of your 
application. 

Say we have a simple state as:

```swift 
struct Product {
  let id: Int
  let name: String
}

struct Location {
  let id: Int
  let other: String
  let product: Product?
}

struct GlobalState {
  let name: String
  let location: Location?
}

// define any initial state (required)
// gets emitted on first selector subscription.
let initialState = GlobalState(name: "", location = nil)
```

### Reducer

Next define a set of actions. These actions should be `enum` so the compiler can verify 
the types.

```swift 
enum StoreTestAction {
  case nameChange(let name: String)
  case locationChange(let location: Location)
  case reset
}
```

Next, we define our global reducer for our state. Kedux supports reducers from global state, fractured state, 
and on specific action types automatically.

```swift 
let sampleReducer = 
```
