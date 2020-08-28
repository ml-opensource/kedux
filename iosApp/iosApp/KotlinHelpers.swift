//
//  KotlinHelpers.swift
//  iosApp
//
//  Created by Andrew Grosner on 8/27/20.
//

import Foundation
import app
import Combine


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
