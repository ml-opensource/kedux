import UIKit
import app
import SwiftUI

class MoviesModel: ObservableObject {
    let disposable = CompositeDisposable()

    @Published
    var movies: [Movie] = []

    init(store: Store<FracturedState>) {
        disposable.add(disposable: SelectorsKt.moviesSelector(store: store)
                .subscribe(isThreadLocal: false, onSubscribe: nil, onError: nil, onComplete: nil) { movies in
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
            Button(action: {
                self.store.dispatch(action: MovieActions.AddMovie(movie: Movie(id: 0, name: "Random Movie \(self.moviesModel.movies.count + 1)", description: "I am a movie")))
            }) {
                Text("Add Movie")
                        .padding()
                        .accentColor(Color.blue)
                        .border(Color.blue, width: 1)
            }
            Spacer().frame(height: 10)
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
