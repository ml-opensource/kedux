//
//  PropertyWrappers.swift
//  iosApp
//
//  Created by Andrew Grosner on 3/23/20.
//

import Foundation
import SwiftUI
import app
import Combine

class SelectedState<S: AnyObject>: ObservableObject {

    private let disposeBag = Set<AnyCancellable>()

    @Published
    var value: S

    init(with initialValue: S, selector: CFlow<S>){
        self.value = initialValue
        createPublisher(flow: selector)
            .sink(receiveCompletion: { _ in }) { value in
                self.value = value
        }
    }

    var wrappedValue: S {
        get {
            return value
        }
    }
}
