import UIKit
import app
import SwiftUI

class MoviesModel {
    let disposable = CompositeDisposable()
    let store = StoreKt_.appGlobalStore()
    public var movies: [Movie] = []

    init() {
        SelectorsKt.moviesSelector(store: store)
            .subscribe(isThreadLocal: false, onSubscribe: nil, onError: nil, onComplete: nil) { movies in
            self.movies = movies as! [Movie]
        }
    }
}

struct HomeView: View {
    
    @State var moviesModel = MoviesModel()
    
    init() {
        
    }

    var body: some View {
       VStack {
        Text("Name")
        ForEach(moviesModel.movies, id: \.self) {
                    Text($0.name)
                }
        }
    }
}
