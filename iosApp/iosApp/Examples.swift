//
//  Examples.swift
//  iosApp
//
//  Created by Andrew Grosner on 3/31/20.
//

import Foundation
import app

let movieEffect = EffectCreator(ofType: Movie.self).createEffect { (action: ObservableWrapper<MovieActions.AddMovie>) in action }

let movieReducer = ReducerCreator<MoviesState>(ofType: MoviesState.self).anyReducer { state, action in
    switch action.self {
    case _ as MovieActions.AddMovie:
        return state
    default:
        return state
    }
}

let movieTypedReducer = TypedReducerCreator<MoviesState, MovieActions>(ofType: MoviesState.self, onAction: MovieActions.self).typedReducer { state, action in
    switch action.self {
    case _ as MovieActions.AddMovie:
        return state
    default:
        return state
    }
}

class ExampleType {
    let name: String
    
    init(name: String) {
        self.name = name
    }
    
    static var SimpleType = ExampleType(name: "Simple Type")
}

class SimpleArgs {
    let data: String
    
    init(data: String) {
        self.data = data
    }
}

let action = ActionCreate(ofType: ExampleType.SimpleType) { (args: SimpleArgs) in args }

let noMapper = ActionCreateNoArgument(ofType: ExampleType.SimpleType) { SimpleArgs(data: "Data") }

let singleAction = SingleAction(type: ExampleType.SimpleType)
