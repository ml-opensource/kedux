//
//  PropertyWrappers.swift
//  iosApp
//
//  Created by Andrew Grosner on 3/23/20.
//

import Foundation
import SwiftUI
import app

class SelectedState<S: AnyObject>: ObservableObject {

    private let disposeBag = CompositeDisposable()

    @Published
    var value: S

    init(with initialValue: S, selector: app.ObservableWrapper<S>){
        self.value = initialValue
        selector.subscribe(isThreadLocal: false, onSubscribe: nil, onError: nil, onComplete: nil) { next in
            if let next = next {
                self.value = next
            }
        }
    }

    var wrappedValue: S {
        get {
            return value
        }
    }
}
