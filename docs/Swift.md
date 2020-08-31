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
let sampleReducer = TypedReducer<GlobalState, StoreTestAction> { state, action in 
    switch action {
        case let a as StoreTestAction.NameChange:
            var mutState = state
            mutState.name = a.name
            return mutState
        case let a as StoreTestAction.Reset:
            var mutState = state
            return mutState
        case let a as StoreTestAction.LocationChange:
            var mutState = state
            mutState.location = a.location
            return mutState
    }
}
```

As you would for Redux, construct your store somewhere accessible.

We recommend using dependency injection to provide your store in your app so it's easier to test.

```swift 

let store = Store(reducer: sampleReducer, initialState: initialState)

```

#### Logging

`Store.companion.loggingEnabled`: set this to log events to the native console as they come in. 
Preferrably this is set only on development builds.

### Selectors

Selectors are pure `CFlow` functions that accept state and emit changes to the state.

Selectors _only_ emit when their output is distinct. 

Selectors _only_ recompute when their upstream state is distinct.

Selectors emit on subscription. So dowstream observers will receive the latest state.

Selectors can be combined.

To observe changes on the store, subscribe to its state:

```swift 
let nameSelector = SelectorCreator<GlobalState, String>  { state in state.name }

// subscribe to store updates
let subscription = store.select(selector: nameSelector)
    .watch { movies in
          // do something with name
    }

// invoke subscription to cancel
subscription()
```

`watch` is a convenience method for Swift callers to provide a friendly interface for watching changes. It runs on the 
`DispatchQueue.main` thread.

Please **Note**: Flow does not play nicely with Swift as much as this library can. 

For use with Combine, you should wrap the returned `Flow` object into a construct like:
```
func createPublisher<T : AnyObject>(flow: CFlow<T>) -> FlowPublisher<T, Swift.Error> {
   return FlowPublisher(flow: flow)
}


class FlowPublisher<Output : AnyObject, Failure: Swift.Error> : Publisher, Cancellable {
    
    let flow: CFlow<Output>
    private var watchBlock: (() -> Void)?
    
    init(flow: CFlow<Output>) {
        self.flow = flow;
    }
    
    func receive<S>(subscriber: S) where S : Subscriber, Failure == S.Failure, Output == S.Input {
        self.watchBlock = flow.watch { value in
            if let value = value {
                subscriber.receive(value)
            }
        }
    }
    
    func cancel() {
        if let watchBlock = self.watchBlock {
            watchBlock()
        }
    }
    
}
```
