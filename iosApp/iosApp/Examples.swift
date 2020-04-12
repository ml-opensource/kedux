//
//  Examples.swift
//  iosApp
//
//  Created by Andrew Grosner on 3/31/20.
//

import Foundation
import app

struct CoolAction {
    let name: String
}

let movieEffect = EffectCreator(ofType: Movie.self).createEffect { (action: ObservableWrapper<MovieActions.AddMovie>) in action }

let movieReducer = KonanReducer<MoviesState>(ofType: MoviesState.self) { state, action in
    switch action.self {
    case _ as CoolAction:
        return state.doCopy(movies: state.movies, isMovieAdded: state.isMovieAdded, iosCoolAction:  true)
    default:
        return state
    }
}

let movieTypedReducer = TypedKonanReducer<MoviesState, MovieActions>(ofType: MoviesState.self, onAction: MovieActions.self) { state, action in
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

let singleAction = SingleAction(type: ExampleType.SimpleType)

let newStore: Store<MoviesState> = Store(reducer: movieReducer, initialState: MoviesState(movies: [], isMovieAdded: false, iosCoolAction: false))

let fracturedStore: Store<FracturedState> = FracturedStore(map: [movieReducer as! Reducer<AnyObject> : MoviesState(movies: [], isMovieAdded: false, iosCoolAction: false)])
