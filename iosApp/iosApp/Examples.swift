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

let movieEffect = Effect<MovieActions.AddMovie, MovieActions.AddMovie>(ofType: MovieActions.AddMovie.self) { action in action }

let movieReducer = AnyReducer<MoviesState>(ofType: MoviesState.self) { state, action in
    switch action {
    case _ as CoolAction:
        return state.doCopy(movies: state.movies, isMovieAdded: state.isMovieAdded, iosCoolAction:  true)
    case let a as MovieActions.AddMovie:
        var movies = state.movies
        movies.append(a.movie)
        return state.doCopy(movies: movies, isMovieAdded: state.isMovieAdded, iosCoolAction: state.iosCoolAction)
    case let a as MovieActions.RemoveMovie:
        var movies = state.movies
        movies.removeAll {  $0.isEqual(a.movie) }
        return state.doCopy(movies: movies, isMovieAdded: state.isMovieAdded, iosCoolAction: state.iosCoolAction)
    default:
        return state
    }
}

let movieTypedReducer = TypedReducer<MoviesState, MovieActions>(ofType: MoviesState.self, onAction: MovieActions.self) { state, action in
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

let action = TypedActionCreator(ofType: ExampleType.SimpleType) { (args: SimpleArgs?) in args }

let singleAction = SingleAction(type: ExampleType.SimpleType)

let newStore: Store<MoviesState> = Store(reducer: movieReducer, initialState: MoviesState(movies: [], isMovieAdded: false, iosCoolAction: false))

// sample fractured store
let fracturedStore: Store<FracturedState> = FracturedStore(map: [movieReducer as! Reducer<AnyObject> : MoviesState(movies: [], isMovieAdded: false, iosCoolAction: false)])

let moviesSelector = SelectorCreator<MoviesState, NSArray> { state in state.movies as NSArray }
