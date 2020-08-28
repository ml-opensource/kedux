import UIKit
import app
import SwiftUI
import Combine

class MoviesModel: ObservableObject {
    var disposable = Set<AnyCancellable>()
    
    @Published
    var movies: [Movie] = []

    init(store: Store<FracturedState>) {
        disposable.insert(createPublisher(flow: store.select(listSelector: SelectorsKt_.moviesSelector))
            .sink(receiveCompletion: {_ in }) { movies in
                self.movies = movies as! [Movie]
        })
    }
}

struct HomeView: View {

    @ObservedObject
    var moviesModel: MoviesModel

    private let store: Store<FracturedState>

    init(store: Store<FracturedState>) {
        self.store = store
        self.moviesModel  = MoviesModel(store: store)
    }

    var body: some View {
        VStack {
            Text("Name")
            ForEach(moviesModel.movies, id: \.self) {
                Text($0.name)
            }
            Spacer(minLength: 10)
            NavigationView {
                NavigationLink(destination: HomeView2(store: newStore)) {
                    Text("Launch Swift Only Store")
                    .padding()
                    .accentColor(Color.green)
                    .border(Color.green, width: 1)
                }
            }
            HStack {
                Button(action: {
                    self.store.dispatch(action: MovieActions.AddMovie(movie: Movie(id: 0, name: "Random Movie \(self.moviesModel.movies.count + 1)", description: "I am a movie")))
                }) {
                    Text("Add Movie")
                            .padding()
                            .accentColor(Color.blue)
                            .border(Color.blue, width: 1)
                }
                Spacer().frame(width: 10)
                Button(action: {
                    if let last = self.moviesModel.movies.last {
                        self.store.dispatch(action: MovieActions.RemoveMovie(movie: last))
                    }
                }) {
                    Text("Remove Movie")
                            .accentColor(Color.red)
                            .padding()
                            .border(Color.red, width: 1)
                }
            }
        }
    }
}

class MoviesModel2: ObservableObject {
    var disposable = Set<AnyCancellable>()

    @Published
    var movies: [Movie] = []

    init(store: Store<MoviesState>) {
        disposable.insert(createPublisher(flow: store.select(listSelector: moviesSelector)).sink(receiveCompletion: { _ in }) { movies in
            self.movies = movies as! [Movie]
        })
    }
}

struct HomeView2: View {

    @ObservedObject
    var moviesModel: MoviesModel2

    private let store: Store<MoviesState>

    init(store: Store<MoviesState>) {
        self.store = store
        self.moviesModel  = MoviesModel2(store: store)
    }

    var body: some View {
        VStack {
            Text("Name")
            ForEach(moviesModel.movies, id: \.self) {
                Text($0.name)
            }
            Spacer(minLength: 10)
            HStack {
                Button(action: {
                    self.store.dispatch(action: MovieActions.AddMovie(movie: Movie(id: 0, name: "Random Movie \(self.moviesModel.movies.count + 1)", description: "I am a movie")))
                }) {
                    Text("Add Movie")
                            .padding()
                            .accentColor(Color.blue)
                            .border(Color.blue, width: 1)
                }
                Spacer().frame(width: 10)
                Button(action: {
                    if let last = self.moviesModel.movies.last {
                        self.store.dispatch(action: MovieActions.RemoveMovie(movie: last))
                    }
                }) {
                    Text("Remove Movie")
                            .accentColor(Color.red)
                            .padding()
                            .border(Color.red, width: 1)
                }
            }
        }
    }
}
