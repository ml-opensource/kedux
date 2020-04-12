//
//  SceneDelegate.swift
//  iosApp
//
//  Created by Andrew Grosner on 3/21/20.
//

import Foundation
import UIKit
import SwiftUI
import app

class BindableStore: ObservableObject {
    @Published var store = StoreKt_.appGlobalStore()
}

class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?


    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        if let windowScene = scene as? UIWindowScene {
            let window = UIWindow(windowScene: windowScene)
            #if targetEnvironment(macCatalyst)
            windowScene.titlebar?.titleVisibility = .hidden
            #endif

            let store = StoreKt_.appGlobalStore()
            let controller = UIHostingController(rootView: HomeView(store: store))

            window.rootViewController = controller
            self.window = window
            window.makeKeyAndVisible()
        }
    }

    func sceneDidEnterBackground(_ scene: UIScene) {
    }
}
