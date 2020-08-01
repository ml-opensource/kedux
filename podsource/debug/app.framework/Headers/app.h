#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class AppObservableWrapper<__covariant T>, AppEffectFn<R>, AppReducer<S>, AppKotlinArray<T>, AppComposeSelectorCreator<S, T, R1, R2>, AppSelector<S, R>, AppMultiAction, AppNoAction, AppKotlinPair<__covariant A, __covariant B>, AppKotlinTriple<__covariant A, __covariant B, __covariant C>, AppStore<S>, AppFracturedState, AppLoadingActionTypesClear, AppKotlinUnit, AppLoadingAction<AT, P>, AppLoadingActionTypesError, AppKotlinThrowable, AppActionCreator<T, A, P>, AppLoadingModel<T>, AppLoadingActionTypesRequest, AppLoadingActionTypesSuccess, AppLoadingActionTypes, AppKotlinException, AppKotlinRuntimeException, AppSubjectStatus, AppSubjectStatusError, AppThreadLocalHolder<T>, AppMovie, AppMovieActions, AppMovieActionsAddMovie, AppMovieActionsMovieAdded, AppMovieActionsRemoveMovie, AppMoviesState, AppCompositeDisposable, AppAtomicReference<T>, AppKotlinFreezableAtomicReference<T>, AppLock, AppFracturedStore, AppReducerMap, AppSelectorCreator<S, R>, AppCompletableWrapper, AppMaybeWrapper<__covariant T>, AppSingleWrapper<__covariant T>, AppDisposableWrapper, AppEffects, AppKodein_di_coreKodeinTrigger, AppKodein_di_coreKodeinModule, AppKodein_di_coreKodeinKey<__contravariant C, __contravariant A, __covariant T>, AppKodein_di_coreScopeRegistry, AppKodein_di_coreKodeinDefinition<C, A, T>, AppKodein_di_coreSearchSpecs, AppKodein_di_coreReference<__covariant T>, AppKodein_di_coreKodeinDefining<C, A, T>;

@protocol AppAction, AppObservable, AppKotlinKClass, AppDispatcher, AppObserver, AppSource, AppObservableObserver, AppDisposable, AppCompleteCallback, AppErrorCallback, AppEmitter, AppCompletableCallbacks, AppCompletable, AppCompletableObserver, AppSchedulerExecutor, AppValueCallback, AppRelay, AppObservableCallbacks, AppSubject, AppSuccessCallback, AppMaybeCallbacks, AppMaybe, AppMaybeObserver, AppSingleCallbacks, AppSingle, AppSingleObserver, AppConnectable, AppClock, AppCondition, AppCompletableEmitter, AppBehaviorSubject, AppPublishSubject, AppScheduler, AppUnicastSubject, AppReplaySubject, AppMaybeEmitter, AppSingleEmitter, AppDisposableScope, AppObservableEmitter, AppConnectableObservable, AppKodein_di_coreKodein, AppKodein_di_coreKodeinMainBuilder, AppKotlinKDeclarationContainer, AppKotlinKAnnotatedElement, AppKotlinKClassifier, AppKotlinIterator, AppKodein_di_coreKodeinContainer, AppKodein_di_coreKodeinContext, AppKodein_di_coreKodeinAware, AppKodein_di_coreDKodein, AppKodein_di_coreCopy, AppKodein_di_coreExternalSource, AppKodein_di_coreKodeinBuilderDirectBinder, AppKodein_di_coreKodeinBuilderTypeBinder, AppKodein_di_coreTypeToken, AppKodein_di_coreContextTranslator, AppKodein_di_coreKodeinBuilderConstantBinder, AppKodein_di_coreKodeinContainerBuilder, AppKodein_di_coreKodeinBindBuilder, AppKodein_di_coreKodeinBindBuilderWithContext, AppKodein_di_coreScope, AppKodein_di_coreKodeinBindBuilderWithScope, AppKodein_di_coreKodeinBuilder, AppKodein_di_coreKodeinTree, AppKotlinLazy, AppKodein_di_coreDKodeinAware, AppKodein_di_coreDKodeinBase, AppKodein_di_coreBindingKodein, AppKodein_di_coreKodeinBinding, AppKodein_di_coreWithContext, AppKodein_di_coreSimpleBindingKodein, AppKodein_di_coreKodeinBindingCopier, AppKodein_di_coreBinding, AppKodein_di_coreScopeCloseable;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wnullability"

__attribute__((swift_name("KotlinBase")))
@interface AppBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end;

@interface AppBase (AppBaseCopying) <NSCopying>
@end;

__attribute__((swift_name("KotlinMutableSet")))
@interface AppMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((swift_name("KotlinMutableDictionary")))
@interface AppMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorAppKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

__attribute__((swift_name("KotlinNumber")))
@interface AppNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end;

__attribute__((swift_name("KotlinByte")))
@interface AppByte : AppNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end;

__attribute__((swift_name("KotlinUByte")))
@interface AppUByte : AppNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end;

__attribute__((swift_name("KotlinShort")))
@interface AppShort : AppNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end;

__attribute__((swift_name("KotlinUShort")))
@interface AppUShort : AppNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end;

__attribute__((swift_name("KotlinInt")))
@interface AppInt : AppNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end;

__attribute__((swift_name("KotlinUInt")))
@interface AppUInt : AppNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end;

__attribute__((swift_name("KotlinLong")))
@interface AppLong : AppNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end;

__attribute__((swift_name("KotlinULong")))
@interface AppULong : AppNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end;

__attribute__((swift_name("KotlinFloat")))
@interface AppFloat : AppNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end;

__attribute__((swift_name("KotlinDouble")))
@interface AppDouble : AppNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end;

__attribute__((swift_name("KotlinBoolean")))
@interface AppBoolean : AppNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end;

__attribute__((swift_name("Action")))
@protocol AppAction
@required
@property (readonly) id _Nullable payload __attribute__((swift_name("payload")));
@property (readonly) id type __attribute__((swift_name("type")));
@end;

__attribute__((swift_name("ActionCreator")))
@interface AppActionCreator<T, A, P> : AppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id<AppAction>)createArguments:(A _Nullable)arguments __attribute__((swift_name("create(arguments:)")));
- (id<AppAction>)invokeArguments:(A _Nullable)arguments __attribute__((swift_name("invoke(arguments:)")));
@end;

__attribute__((swift_name("EffectFn")))
@interface AppEffectFn<R> : AppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (AppObservableWrapper<R> *)invokeActions:(AppObservableWrapper<id> *)actions __attribute__((swift_name("invoke(actions:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ActionTypeEffectClass")))
@interface AppActionTypeEffectClass<T, P, R, RP> : AppEffectFn<id<AppAction>>
- (instancetype)initWithMapper:(id<AppObservable> (^)(AppObservableWrapper<id<AppAction>> *))mapper __attribute__((swift_name("init(mapper:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppObservableWrapper<id<AppAction>> *)invokeActions:(AppObservableWrapper<id> *)actions __attribute__((swift_name("invoke(actions:)")));
@end;

__attribute__((swift_name("Reducer")))
@interface AppReducer<S> : AppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ActionTypeReducer")))
@interface AppActionTypeReducer<S, T> : AppReducer<S>
- (instancetype)initWithOfType:(Class)ofType onAction:(Class)onAction fn:(S (^)(S, id<AppAction>))fn __attribute__((swift_name("init(ofType:onAction:fn:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ActionTypeReducerClass")))
@interface AppActionTypeReducerClass<S, T> : AppReducer<S>
- (instancetype)initWithStateClass:(id<AppKotlinKClass>)stateClass typeClass:(id<AppKotlinKClass>)typeClass fn:(S (^)(S, id<AppAction>))fn __attribute__((swift_name("init(stateClass:typeClass:fn:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AnyReducer")))
@interface AppAnyReducer<S> : AppReducer<S>
- (instancetype)initWithOfType:(Class)ofType fn:(S (^)(S, id))fn __attribute__((swift_name("init(ofType:fn:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AnyReducerClass")))
@interface AppAnyReducerClass<S> : AppReducer<S>
- (instancetype)initWithStateClass:(id<AppKotlinKClass>)stateClass fn:(S (^)(S, id))fn __attribute__((swift_name("init(stateClass:fn:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CombineReducers")))
@interface AppCombineReducers<S> : AppReducer<S>
- (instancetype)initWithStateClass:(id<AppKotlinKClass>)stateClass reducers:(AppKotlinArray<AppReducer<S> *> *)reducers __attribute__((swift_name("init(stateClass:reducers:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((swift_name("Selector")))
@interface AppSelector<S, R> : AppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (AppComposeSelectorCreator<S, R, id, id> *)composeSelectorTransform:(id<AppObservable> (^)(AppObservableWrapper<R> *))selectorTransform composeFunction:(id _Nullable (^)(id _Nullable))composeFunction __attribute__((swift_name("compose(selectorTransform:composeFunction:)")));
- (AppComposeSelectorCreator<S, R, R, id> *)composeComposeFunction:(id _Nullable (^)(R _Nullable))composeFunction __attribute__((swift_name("compose(composeFunction:)")));
- (AppObservableWrapper<R> *)invokeState:(AppObservableWrapper<S> *)state __attribute__((swift_name("invoke(state:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ComposeSelectorCreator")))
@interface AppComposeSelectorCreator<S, T, R1, R2> : AppSelector<S, R2>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppComposeSelectorCreator<S, R2, id, id> *)composeSelectorTransform:(id<AppObservable> (^)(AppObservableWrapper<R2> *))selectorTransform composeFunction:(id _Nullable (^)(id _Nullable))composeFunction __attribute__((swift_name("compose(selectorTransform:composeFunction:)")));
- (AppComposeSelectorCreator<S, R2, R2, id> *)composeComposeFunction:(id _Nullable (^)(R2 _Nullable))composeFunction __attribute__((swift_name("compose(composeFunction:)")));
- (AppObservableWrapper<R2> *)invokeState:(AppObservableWrapper<S> *)state __attribute__((swift_name("invoke(state:)")));
@end;

__attribute__((swift_name("Dispatcher")))
@protocol AppDispatcher
@required
- (void)dispatchTypedAction:(id<AppAction>)typedAction __attribute__((swift_name("dispatch(typedAction:)")));
- (void)dispatchMultiAction:(AppMultiAction *)multiAction __attribute__((swift_name("dispatch(multiAction:)")));
- (void)dispatchNoAction:(AppNoAction *)noAction __attribute__((swift_name("dispatch(noAction:)")));
- (void)dispatchAction:(id)action __attribute__((swift_name("dispatch(action:)")));
- (void)dispatchPair:(AppKotlinPair<id, id> *)pair __attribute__((swift_name("dispatch(pair:)")));
- (void)dispatchTriple:(AppKotlinTriple<id, id, id> *)triple __attribute__((swift_name("dispatch(triple:)")));
- (void)dispatchActualAction:(id)action __attribute__((swift_name("dispatchActual(action:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Effect")))
@interface AppEffect<A, R> : AppEffectFn<R>
- (instancetype)initWithOfType:(Class)ofType mapper:(id<AppObservable> (^)(AppObservableWrapper<A> *))mapper __attribute__((swift_name("init(ofType:mapper:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppObservableWrapper<R> *)invokeActions:(AppObservableWrapper<id> *)actions __attribute__((swift_name("invoke(actions:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EffectClass")))
@interface AppEffectClass<A, R> : AppEffectFn<R>
- (instancetype)initWithActionClass:(id<AppKotlinKClass>)actionClass mapper:(id<AppObservable> (^)(AppObservableWrapper<A> *))mapper __attribute__((swift_name("init(actionClass:mapper:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppObservableWrapper<R> *)invokeActions:(AppObservableWrapper<id> *)actions __attribute__((swift_name("invoke(actions:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Effects")))
@interface AppEffects : AppBase
- (instancetype)initWithEffectArgs:(AppKotlinArray<AppEffectFn<id> *> *)effectArgs __attribute__((swift_name("init(effectArgs:)"))) __attribute__((objc_designated_initializer));
- (void)bindToStore:(AppStore<id> *)store __attribute__((swift_name("bindTo(store:)")));
- (void)clearBindings __attribute__((swift_name("clearBindings()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FracturedState")))
@interface AppFracturedState : AppBase
- (instancetype)initWithMap:(NSDictionary<id<AppKotlinKClass>, id> *)map __attribute__((swift_name("init(map:)"))) __attribute__((objc_designated_initializer));
- (AppFracturedState *)doCopyMap:(NSDictionary<id<AppKotlinKClass>, id> *)map __attribute__((swift_name("doCopy(map:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (id)fromReducerReducer:(AppReducer<id> *)reducer __attribute__((swift_name("fromReducer(reducer:)")));
- (id)getStateValueClass:(id<AppKotlinKClass>)valueClass __attribute__((swift_name("getState(valueClass:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end;

__attribute__((swift_name("Store")))
@interface AppStore<S> : AppBase <AppDispatcher>
- (instancetype)initWithReducer:(AppReducer<S> *)reducer initialState:(S)initialState __attribute__((swift_name("init(reducer:initialState:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithReducer:(AppReducer<S> *)reducer initialState:(S)initialState enhancer:(id (^(^(^)(AppStore<S> *))(id (^)(id)))(id))enhancer __attribute__((swift_name("init(reducer:initialState:enhancer:)"))) __attribute__((objc_designated_initializer));
- (void)dispatchActualAction:(id)action __attribute__((swift_name("dispatchActual(action:)")));
- (AppObservableWrapper<id> *)effectEffect:(AppEffectFn<id> *)effect __attribute__((swift_name("effect(effect:)")));
- (void)replaceReducerReducer:(AppReducer<S> *)reducer __attribute__((swift_name("replaceReducer(reducer:)")));
- (AppObservableWrapper<id> *)selectSelector:(AppSelector<S, id> *)selector __attribute__((swift_name("select(selector:)")));
- (AppObservableWrapper<NSArray<id> *> *)selectListSelector:(AppSelector<S, NSArray<id> *> *)listSelector __attribute__((swift_name("select(listSelector:)")));
@property (readonly) AppObservableWrapper<id> *actions __attribute__((swift_name("actions")));
@property (readonly) AppObservableWrapper<S> *state __attribute__((swift_name("state")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FracturedStore")))
@interface AppFracturedStore : AppStore<AppFracturedState *>
- (instancetype)initWithMap:(NSDictionary<AppReducer<id> *, id> *)map __attribute__((swift_name("init(map:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMap:(NSDictionary<AppReducer<id> *, id> *)map enhancer:(id (^(^(^)(AppStore<AppFracturedState *> *))(id (^)(id)))(id))enhancer __attribute__((swift_name("init(map:enhancer:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithReducer:(AppReducer<id> *)reducer initialState:(id)initialState __attribute__((swift_name("init(reducer:initialState:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithReducer:(AppReducer<id> *)reducer initialState:(id)initialState enhancer:(id (^(^(^)(AppStore<id> *))(id (^)(id)))(id))enhancer __attribute__((swift_name("init(reducer:initialState:enhancer:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)replaceReducerReducer:(AppReducer<AppFracturedState *> *)reducer __attribute__((swift_name("replaceReducer(reducer:)")));
- (AppObservableWrapper<id> *)selectSelector:(AppSelector<AppFracturedState *, id> *)selector __attribute__((swift_name("select(selector:)")));
- (AppObservableWrapper<NSArray<id> *> *)selectListSelector:(AppSelector<AppFracturedState *, NSArray<id> *> *)listSelector __attribute__((swift_name("select(listSelector:)")));
@property (readonly) AppObservableWrapper<AppFracturedState *> *state __attribute__((swift_name("state")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeduxLoader")))
@interface AppKeduxLoader<TRequest, TSuccess> : AppBase
- (instancetype)initWithName:(NSString *)name requester:(id<AppObservable> (^)(TRequest))requester __attribute__((swift_name("init(name:requester:)"))) __attribute__((objc_designated_initializer));
@property (readonly) AppLoadingAction<AppLoadingActionTypesClear *, AppKotlinUnit *> *clear __attribute__((swift_name("clear")));
@property (readonly) AppEffectFn<id<AppAction>> *effect __attribute__((swift_name("effect")));
@property (readonly) AppActionCreator<AppLoadingActionTypesError *, AppKotlinThrowable *, AppKotlinThrowable *> *error __attribute__((swift_name("error")));
@property (readonly) AppReducer<AppLoadingModel<TSuccess> *> *reducer __attribute__((swift_name("reducer")));
@property (readonly) AppActionCreator<AppLoadingActionTypesRequest *, TRequest, TRequest> *request __attribute__((swift_name("request")));
@property (readonly) AppActionCreator<AppLoadingActionTypesSuccess *, TSuccess, TSuccess> *success __attribute__((swift_name("success")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingAction")))
@interface AppLoadingAction<AT, P> : AppBase <AppAction>
- (instancetype)initWithType:(AT)type payload:(P _Nullable)payload __attribute__((swift_name("init(type:payload:)"))) __attribute__((objc_designated_initializer));
- (AT)component1 __attribute__((swift_name("component1()")));
- (P _Nullable)component2 __attribute__((swift_name("component2()")));
- (AppLoadingAction<AT, P> *)doCopyType:(AT)type payload:(P _Nullable)payload __attribute__((swift_name("doCopy(type:payload:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) P _Nullable payload __attribute__((swift_name("payload")));
@property (readonly) AT type __attribute__((swift_name("type")));
@end;

__attribute__((swift_name("LoadingActionTypes")))
@interface AppLoadingActionTypes : AppBase
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingActionTypes.Clear")))
@interface AppLoadingActionTypesClear : AppLoadingActionTypes
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (AppLoadingActionTypesClear *)doCopyName:(NSString *)name __attribute__((swift_name("doCopy(name:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingActionTypes.Error")))
@interface AppLoadingActionTypesError : AppLoadingActionTypes
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (AppLoadingActionTypesError *)doCopyName:(NSString *)name __attribute__((swift_name("doCopy(name:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingActionTypes.Request")))
@interface AppLoadingActionTypesRequest : AppLoadingActionTypes
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (AppLoadingActionTypesRequest *)doCopyName:(NSString *)name __attribute__((swift_name("doCopy(name:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingActionTypes.Success")))
@interface AppLoadingActionTypesSuccess : AppLoadingActionTypes
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (AppLoadingActionTypesSuccess *)doCopyName:(NSString *)name __attribute__((swift_name("doCopy(name:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingModel")))
@interface AppLoadingModel<T> : AppBase
- (BOOL)component1 __attribute__((swift_name("component1()")));
- (BOOL)component2 __attribute__((swift_name("component2()")));
- (BOOL)component3 __attribute__((swift_name("component3()")));
- (T _Nullable)component4 __attribute__((swift_name("component4()")));
- (AppKotlinThrowable * _Nullable)component5 __attribute__((swift_name("component5()")));
- (AppLoadingModel<T> *)doCopyIsLoading:(BOOL)isLoading isError:(BOOL)isError isSuccess:(BOOL)isSuccess optionalSuccess:(T _Nullable)optionalSuccess optionalError:(AppKotlinThrowable * _Nullable)optionalError __attribute__((swift_name("doCopy(isLoading:isError:isSuccess:optionalSuccess:optionalError:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (AppLoadingModel<T> *)loadingSuccess:(T _Nullable)success __attribute__((swift_name("loading(success:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) AppKotlinThrowable *error __attribute__((swift_name("error")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) BOOL isError __attribute__((swift_name("isError")));
@property (readonly) BOOL isLoading __attribute__((swift_name("isLoading")));
@property (readonly) BOOL isSuccess __attribute__((swift_name("isSuccess")));
@property (readonly) AppKotlinThrowable * _Nullable optionalError __attribute__((swift_name("optionalError")));
@property (readonly) T _Nullable optionalSuccess __attribute__((swift_name("optionalSuccess")));
@property (readonly) T _Nullable success __attribute__((swift_name("success")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadingModelCompanion")))
@interface AppLoadingModelCompanion : AppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (AppLoadingModel<id> *)empty __attribute__((swift_name("empty()")));
- (AppLoadingModel<id> *)errorError:(AppKotlinThrowable * _Nullable)error optionalSuccess:(id _Nullable)optionalSuccess __attribute__((swift_name("error(error:optionalSuccess:)")));
- (AppLoadingModel<id> *)successSuccess:(id _Nullable)success __attribute__((swift_name("success(success:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MultiAction")))
@interface AppMultiAction : AppBase
- (instancetype)initWithActions:(NSArray<id> *)actions __attribute__((swift_name("init(actions:)"))) __attribute__((objc_designated_initializer));
- (NSArray<id> *)component1 __attribute__((swift_name("component1()")));
- (AppMultiAction *)doCopyActions:(NSArray<id> *)actions __attribute__((swift_name("doCopy(actions:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<id> *actions __attribute__((swift_name("actions")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NoAction")))
@interface AppNoAction : AppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)noAction __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReducerMap")))
@interface AppReducerMap : AppReducer<AppFracturedState *>
- (instancetype)initWithReducers:(NSArray<AppReducer<id> *> *)reducers __attribute__((swift_name("init(reducers:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppFracturedState *)reduceState:(AppFracturedState *)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelectorCreator")))
@interface AppSelectorCreator<S, R> : AppSelector<S, R>
- (instancetype)initWithSelectorFunction:(R _Nullable (^)(S))selectorFunction __attribute__((swift_name("init(selectorFunction:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppObservableWrapper<R> *)invokeState:(AppObservableWrapper<S> *)state __attribute__((swift_name("invoke(state:)")));
@end;

__attribute__((swift_name("Source")))
@protocol AppSource
@required
- (void)subscribeObserver:(id<AppObserver>)observer __attribute__((swift_name("subscribe(observer:)")));
@end;

__attribute__((swift_name("Observable")))
@protocol AppObservable <AppSource>
@required
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelectorSubject")))
@interface AppSelectorSubject<S, R> : AppBase <AppObservable>
- (void)dispose __attribute__((swift_name("dispose()")));
- (void)subscribeObserver:(id<AppObservableObserver>)observer __attribute__((swift_name("subscribe(observer:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SilentEffect")))
@interface AppSilentEffect<A> : AppEffectFn<AppNoAction *>
- (instancetype)initWithOfType:(Class)ofType mapper:(id<AppObservable> (^)(AppObservableWrapper<A> *))mapper __attribute__((swift_name("init(ofType:mapper:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppObservableWrapper<AppNoAction *> *)invokeActions:(AppObservableWrapper<id> *)actions __attribute__((swift_name("invoke(actions:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SilentEffectClass")))
@interface AppSilentEffectClass<A> : AppEffectFn<AppNoAction *>
- (instancetype)initWithActionClass:(id<AppKotlinKClass>)actionClass mapper:(id<AppObservable> (^)(AppObservableWrapper<A> *))mapper __attribute__((swift_name("init(actionClass:mapper:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (AppObservableWrapper<AppNoAction *> *)invokeActions:(AppObservableWrapper<id> *)actions __attribute__((swift_name("invoke(actions:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SingleAction")))
@interface AppSingleAction<T> : AppBase <AppAction>
- (instancetype)initWithType:(T)type __attribute__((swift_name("init(type:)"))) __attribute__((objc_designated_initializer));
@property (readonly) AppKotlinUnit *payload __attribute__((swift_name("payload")));
@property (readonly) T type __attribute__((swift_name("type")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StoreCompanion")))
@interface AppStoreCompanion : AppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (void)logIfEnabledMessageBuilder:(NSString *(^)(void))messageBuilder __attribute__((swift_name("logIfEnabled(messageBuilder:)")));
@property BOOL loggingEnabled __attribute__((swift_name("loggingEnabled")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TypedActionCreator")))
@interface AppTypedActionCreator<T, A, P> : AppActionCreator<T, A, P>
- (instancetype)initWithOfType:(T)ofType payloadCreator:(P _Nullable (^)(A _Nullable))payloadCreator __attribute__((swift_name("init(ofType:payloadCreator:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (id<AppAction>)createArguments:(A _Nullable)arguments __attribute__((swift_name("create(arguments:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TypedReducer")))
@interface AppTypedReducer<S, A> : AppReducer<S>
- (instancetype)initWithOfType:(Class)ofType onAction:(Class)onAction fn:(S (^)(S, A))fn __attribute__((swift_name("init(ofType:onAction:fn:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TypedReducerClass")))
@interface AppTypedReducerClass<S, A> : AppReducer<S>
- (instancetype)initWithStateClass:(id<AppKotlinKClass>)stateClass actionClass:(id<AppKotlinKClass>)actionClass fn:(S (^)(S, A))fn __attribute__((swift_name("init(stateClass:actionClass:fn:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (S)reduceState:(S)state action:(id)action __attribute__((swift_name("reduce(state:action:)")));
@property (readonly) id<AppKotlinKClass> stateClass __attribute__((swift_name("stateClass")));
@end;

__attribute__((swift_name("CompleteCallback")))
@protocol AppCompleteCallback
@required
- (void)onComplete __attribute__((swift_name("onComplete()")));
@end;

__attribute__((swift_name("Connectable")))
@protocol AppConnectable
@required
- (void)connectOnConnect:(void (^ _Nullable)(id<AppDisposable>))onConnect __attribute__((swift_name("connect(onConnect:)")));
@end;

__attribute__((swift_name("Emitter")))
@protocol AppEmitter
@required
- (void)setDisposableDisposable:(id<AppDisposable> _Nullable)disposable __attribute__((swift_name("setDisposable(disposable:)")));
@property (readonly) BOOL isDisposed __attribute__((swift_name("isDisposed")));
@end;

__attribute__((swift_name("ErrorCallback")))
@protocol AppErrorCallback
@required
- (void)onErrorError:(AppKotlinThrowable *)error __attribute__((swift_name("onError(error:)")));
@end;

__attribute__((swift_name("Observer")))
@protocol AppObserver
@required
- (void)onSubscribeDisposable:(id<AppDisposable>)disposable __attribute__((swift_name("onSubscribe(disposable:)")));
@end;

__attribute__((swift_name("SuccessCallback")))
@protocol AppSuccessCallback
@required
- (void)onSuccessValue:(id _Nullable)value __attribute__((swift_name("onSuccess(value:)")));
@end;

__attribute__((swift_name("ValueCallback")))
@protocol AppValueCallback
@required
- (void)onNextValue:(id _Nullable)value __attribute__((swift_name("onNext(value:)")));
@end;

__attribute__((swift_name("KotlinThrowable")))
@interface AppKotlinThrowable : AppBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (AppKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) AppKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
@end;

__attribute__((swift_name("KotlinException")))
@interface AppKotlinException : AppKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end;

__attribute__((swift_name("KotlinRuntimeException")))
@interface AppKotlinRuntimeException : AppKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompositeException")))
@interface AppCompositeException : AppKotlinRuntimeException
- (instancetype)initWithCause1:(AppKotlinThrowable *)cause1 cause2:(AppKotlinThrowable *)cause2 __attribute__((swift_name("init(cause1:cause2:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) AppKotlinThrowable *cause1 __attribute__((swift_name("cause1")));
@property (readonly) AppKotlinThrowable *cause2 __attribute__((swift_name("cause2")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeoutException")))
@interface AppTimeoutException : AppKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

__attribute__((swift_name("Completable")))
@protocol AppCompletable <AppSource>
@required
@end;

__attribute__((swift_name("CompletableCallbacks")))
@protocol AppCompletableCallbacks <AppCompleteCallback, AppErrorCallback>
@required
@end;

__attribute__((swift_name("CompletableEmitter")))
@protocol AppCompletableEmitter <AppEmitter, AppCompletableCallbacks>
@required
@end;

__attribute__((swift_name("CompletableObserver")))
@protocol AppCompletableObserver <AppObserver, AppCompletableCallbacks>
@required
@end;

__attribute__((swift_name("CompletableWrapper")))
@interface AppCompletableWrapper : AppBase <AppCompletable>
- (instancetype)initWithInner:(id<AppCompletable>)inner __attribute__((swift_name("init(inner:)"))) __attribute__((objc_designated_initializer));
- (void)subscribeObserver:(id<AppCompletableObserver>)observer __attribute__((swift_name("subscribe(observer:)")));
- (id<AppDisposable>)subscribeIsThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete __attribute__((swift_name("subscribe(isThreadLocal:onSubscribe:onError:onComplete:)")));
@end;

__attribute__((swift_name("Scheduler")))
@protocol AppScheduler
@required
- (void)destroy __attribute__((swift_name("destroy()")));
- (id<AppSchedulerExecutor>)doNewExecutor __attribute__((swift_name("doNewExecutor()")));
@end;

__attribute__((swift_name("Disposable")))
@protocol AppDisposable
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@property (readonly) BOOL isDisposed __attribute__((swift_name("isDisposed")));
@end;

__attribute__((swift_name("SchedulerExecutor")))
@protocol AppSchedulerExecutor <AppDisposable>
@required
- (void)cancel __attribute__((swift_name("cancel()")));
- (void)submitDelayMillis:(int64_t)delayMillis task:(void (^)(void))task __attribute__((swift_name("submit(delayMillis:task:)")));
- (void)submitRepeatingStartDelayMillis:(int64_t)startDelayMillis periodMillis:(int64_t)periodMillis task:(void (^)(void))task __attribute__((swift_name("submitRepeating(startDelayMillis:periodMillis:task:)")));
@end;

__attribute__((swift_name("Relay")))
@protocol AppRelay <AppObservable, AppValueCallback>
@required
@end;

__attribute__((swift_name("ObservableCallbacks")))
@protocol AppObservableCallbacks <AppValueCallback, AppCompletableCallbacks>
@required
@end;

__attribute__((swift_name("Subject")))
@protocol AppSubject <AppRelay, AppObservableCallbacks>
@required
@property (readonly) AppSubjectStatus *status __attribute__((swift_name("status")));
@end;

__attribute__((swift_name("SubjectStatus")))
@interface AppSubjectStatus : AppBase
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubjectStatusActive")))
@interface AppSubjectStatusActive : AppSubjectStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)active __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubjectStatusCompleted")))
@interface AppSubjectStatusCompleted : AppSubjectStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)completed __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubjectStatusError")))
@interface AppSubjectStatusError : AppSubjectStatus
- (instancetype)initWithError:(AppKotlinThrowable *)error __attribute__((swift_name("init(error:)"))) __attribute__((objc_designated_initializer));
- (AppKotlinThrowable *)component1 __attribute__((swift_name("component1()")));
- (AppSubjectStatusError *)doCopyError:(AppKotlinThrowable *)error __attribute__((swift_name("doCopy(error:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) AppKotlinThrowable *error __attribute__((swift_name("error")));
@end;

__attribute__((swift_name("UnicastSubject")))
@protocol AppUnicastSubject <AppSubject>
@required
@end;

__attribute__((swift_name("ReplaySubject")))
@protocol AppReplaySubject <AppSubject>
@required
@end;

__attribute__((swift_name("BehaviorSubject")))
@protocol AppBehaviorSubject <AppSubject>
@required
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end;

__attribute__((swift_name("PublishSubject")))
@protocol AppPublishSubject <AppSubject>
@required
@end;

__attribute__((swift_name("Maybe")))
@protocol AppMaybe <AppSource>
@required
@end;

__attribute__((swift_name("MaybeCallbacks")))
@protocol AppMaybeCallbacks <AppSuccessCallback, AppCompletableCallbacks>
@required
@end;

__attribute__((swift_name("MaybeEmitter")))
@protocol AppMaybeEmitter <AppEmitter, AppMaybeCallbacks>
@required
@end;

__attribute__((swift_name("MaybeObserver")))
@protocol AppMaybeObserver <AppObserver, AppMaybeCallbacks>
@required
@end;

__attribute__((swift_name("MaybeWrapper")))
@interface AppMaybeWrapper<__covariant T> : AppBase <AppMaybe>
- (instancetype)initWithInner:(id<AppMaybe>)inner __attribute__((swift_name("init(inner:)"))) __attribute__((objc_designated_initializer));
- (void)subscribeObserver:(id<AppMaybeObserver>)observer __attribute__((swift_name("subscribe(observer:)")));
- (id<AppDisposable>)subscribeIsThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete onSuccess:(void (^ _Nullable)(T _Nullable))onSuccess __attribute__((swift_name("subscribe(isThreadLocal:onSubscribe:onError:onComplete:onSuccess:)")));
@end;

__attribute__((swift_name("Single")))
@protocol AppSingle <AppSource>
@required
@end;

__attribute__((swift_name("SingleCallbacks")))
@protocol AppSingleCallbacks <AppSuccessCallback, AppErrorCallback>
@required
@end;

__attribute__((swift_name("SingleEmitter")))
@protocol AppSingleEmitter <AppEmitter, AppSingleCallbacks>
@required
@end;

__attribute__((swift_name("SingleObserver")))
@protocol AppSingleObserver <AppObserver, AppSingleCallbacks>
@required
@end;

__attribute__((swift_name("SingleWrapper")))
@interface AppSingleWrapper<__covariant T> : AppBase <AppSingle>
- (instancetype)initWithInner:(id<AppSingle>)inner __attribute__((swift_name("init(inner:)"))) __attribute__((objc_designated_initializer));
- (void)subscribeObserver:(id<AppSingleObserver>)observer __attribute__((swift_name("subscribe(observer:)")));
- (id<AppDisposable>)subscribeIsThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onSuccess:(void (^ _Nullable)(T _Nullable))onSuccess __attribute__((swift_name("subscribe(isThreadLocal:onSubscribe:onError:onSuccess:)")));
@end;

__attribute__((swift_name("CompositeDisposable")))
@interface AppCompositeDisposable : AppBase <AppDisposable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)addDisposable:(id<AppDisposable>)disposable __attribute__((swift_name("add(disposable:)")));
- (void)clearDispose:(BOOL)dispose __attribute__((swift_name("clear(dispose:)")));
- (void)dispose __attribute__((swift_name("dispose()")));
- (void)purge __attribute__((swift_name("purge()")));
- (BOOL)removeDisposable:(id<AppDisposable>)disposable dispose:(BOOL)dispose __attribute__((swift_name("remove(disposable:dispose:)")));
@property (readonly) BOOL isDisposed __attribute__((swift_name("isDisposed")));
@end;

__attribute__((swift_name("DisposableWrapper")))
@interface AppDisposableWrapper : AppBase <AppDisposable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)dispose __attribute__((swift_name("dispose()")));
- (id<AppDisposable> _Nullable)replaceDisposable:(id<AppDisposable> _Nullable)disposable __attribute__((swift_name("replace(disposable:)")));
- (void)setDisposable:(id<AppDisposable> _Nullable)disposable __attribute__((swift_name("set(disposable:)")));
@property (readonly) BOOL isDisposed __attribute__((swift_name("isDisposed")));
@end;

__attribute__((swift_name("DisposableScope")))
@protocol AppDisposableScope <AppDisposable>
@required
- (id<AppCompleteCallback>)scope:(id<AppCompleteCallback>)receiver __attribute__((swift_name("scope(_:)")));
- (id<AppDisposable>)scope_:(id<AppDisposable>)receiver __attribute__((swift_name("scope(__:)")));
- (id<AppDisposable>)subscribeScoped:(id<AppCompletable>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete __attribute__((swift_name("subscribeScoped(_:isThreadLocal:onSubscribe:onError:onComplete:)")));
- (id<AppDisposable>)subscribeScoped:(id<AppMaybe>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete onSuccess:(void (^ _Nullable)(id _Nullable))onSuccess __attribute__((swift_name("subscribeScoped(_:isThreadLocal:onSubscribe:onError:onComplete:onSuccess:)")));
- (id<AppDisposable>)subscribeScoped:(id<AppObservable>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete onNext:(void (^ _Nullable)(id _Nullable))onNext __attribute__((swift_name("subscribeScoped(_:isThreadLocal:onSubscribe:onError:onComplete:onNext:)")));
- (id<AppDisposable>)subscribeScoped:(id<AppSingle>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onSuccess:(void (^ _Nullable)(id _Nullable))onSuccess __attribute__((swift_name("subscribeScoped(_:isThreadLocal:onSubscribe:onError:onSuccess:)")));
@end;

__attribute__((swift_name("ThreadLocalHolder")))
@interface AppThreadLocalHolder<T> : AppBase
- (instancetype)initWithInitialValue:(T _Nullable)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer));
- (void)dispose __attribute__((swift_name("dispose()")));
- (T _Nullable)get __attribute__((swift_name("get()")));
- (void)setValue:(T _Nullable)value __attribute__((swift_name("set(value:)")));
@property (readonly) BOOL isDisposed __attribute__((swift_name("isDisposed")));
@end;

__attribute__((swift_name("ThreadLocalStorage")))
@interface AppThreadLocalStorage<T> : AppThreadLocalHolder<T> <AppDisposable>
- (instancetype)initWithInitialValue:(T _Nullable)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("Use ThreadLocalHolder from 'utils' package. This class will be removed soon.")));
@end;

__attribute__((swift_name("ConnectableObservable")))
@protocol AppConnectableObservable <AppObservable, AppConnectable>
@required
@end;

__attribute__((swift_name("ObservableEmitter")))
@protocol AppObservableEmitter <AppEmitter, AppObservableCallbacks>
@required
@end;

__attribute__((swift_name("ObservableObserver")))
@protocol AppObservableObserver <AppObserver, AppObservableCallbacks>
@required
@end;

__attribute__((swift_name("ObservableWrapper")))
@interface AppObservableWrapper<__covariant T> : AppBase <AppObservable>
- (instancetype)initWithInner:(id<AppObservable>)inner __attribute__((swift_name("init(inner:)"))) __attribute__((objc_designated_initializer));
- (void)subscribeObserver:(id<AppObservableObserver>)observer __attribute__((swift_name("subscribe(observer:)")));
- (id<AppDisposable>)subscribeIsThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete onNext:(void (^ _Nullable)(T _Nullable))onNext __attribute__((swift_name("subscribe(isThreadLocal:onSubscribe:onError:onComplete:onNext:)")));
@end;

__attribute__((swift_name("ObjectReference")))
@interface AppObjectReference<T> : AppBase
- (instancetype)initWithInitialValue:(T _Nullable)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer));
@property T _Nullable value __attribute__((swift_name("value")));
@end;

__attribute__((swift_name("Clock")))
@protocol AppClock
@required
@property (readonly) int64_t uptimeMillis __attribute__((swift_name("uptimeMillis")));
@property (readonly) int64_t uptimeNanos __attribute__((swift_name("uptimeNanos")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultClock")))
@interface AppDefaultClock : AppBase <AppClock>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)defaultClock __attribute__((swift_name("init()")));
@property (readonly) int64_t uptimeMillis __attribute__((swift_name("uptimeMillis")));
@property (readonly) int64_t uptimeNanos __attribute__((swift_name("uptimeNanos")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicBoolean")))
@interface AppAtomicBoolean : AppBase
- (instancetype)initWithInitialValue:(BOOL)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer));
- (BOOL)compareAndSetExpectedValue:(BOOL)expectedValue newValue:(BOOL)newValue __attribute__((swift_name("compareAndSet(expectedValue:newValue:)")));
@property BOOL value __attribute__((swift_name("value")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicInt")))
@interface AppAtomicInt : AppBase
- (instancetype)initWithInitialValue:(int32_t)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer));
- (int32_t)addAndGetDelta:(int32_t)delta __attribute__((swift_name("addAndGet(delta:)")));
- (BOOL)compareAndSetExpectedValue:(int32_t)expectedValue newValue:(int32_t)newValue __attribute__((swift_name("compareAndSet(expectedValue:newValue:)")));
@property int32_t value __attribute__((swift_name("value")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicLong")))
@interface AppAtomicLong : AppBase
- (instancetype)initWithInitialValue:(int64_t)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer));
- (int64_t)addAndGetDelta:(int64_t)delta __attribute__((swift_name("addAndGet(delta:)")));
- (BOOL)compareAndSetExpectedValue:(int64_t)expectedValue newValue:(int64_t)newValue __attribute__((swift_name("compareAndSet(expectedValue:newValue:)")));
@property int64_t value __attribute__((swift_name("value")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicReference")))
@interface AppAtomicReference<T> : AppBase
- (instancetype)initWithInitialValue:(T _Nullable)initialValue __attribute__((swift_name("init(initialValue:)"))) __attribute__((objc_designated_initializer));
- (BOOL)compareAndSetExpectedValue:(T _Nullable)expectedValue newValue:(T _Nullable)newValue __attribute__((swift_name("compareAndSet(expectedValue:newValue:)")));
@property T _Nullable value __attribute__((swift_name("value")));
@end;

__attribute__((swift_name("Condition")))
@protocol AppCondition
@required
- (void)awaitTimeoutNanos:(int64_t)timeoutNanos __attribute__((swift_name("await(timeoutNanos:)")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (void)signal __attribute__((swift_name("signal()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Lock")))
@interface AppLock : AppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)acquire __attribute__((swift_name("acquire()")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (id<AppCondition>)doNewCondition __attribute__((swift_name("doNewCondition()")));
- (void)release_ __attribute__((swift_name("release()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Movie")))
@interface AppMovie : AppBase
- (instancetype)initWithId:(int32_t)id name:(NSString *)name description:(NSString *)description __attribute__((swift_name("init(id:name:description:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (NSString *)component3 __attribute__((swift_name("component3()")));
- (AppMovie *)doCopyId:(int32_t)id name:(NSString *)name description:(NSString *)description __attribute__((swift_name("doCopy(id:name:description:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly, getter=description_) NSString *description __attribute__((swift_name("description")));
@property (readonly) int32_t id __attribute__((swift_name("id")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end;

__attribute__((swift_name("MovieActions")))
@interface AppMovieActions : AppBase
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MovieActions.AddMovie")))
@interface AppMovieActionsAddMovie : AppMovieActions
- (instancetype)initWithMovie:(AppMovie *)movie __attribute__((swift_name("init(movie:)"))) __attribute__((objc_designated_initializer));
- (AppMovie *)component1 __attribute__((swift_name("component1()")));
- (AppMovieActionsAddMovie *)doCopyMovie:(AppMovie *)movie __attribute__((swift_name("doCopy(movie:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) AppMovie *movie __attribute__((swift_name("movie")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MovieActions.ClearMovies")))
@interface AppMovieActionsClearMovies : AppMovieActions
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)clearMovies __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MovieActions.MovieAdded")))
@interface AppMovieActionsMovieAdded : AppMovieActions
- (instancetype)initWithMovie:(AppMovie *)movie __attribute__((swift_name("init(movie:)"))) __attribute__((objc_designated_initializer));
- (AppMovie *)component1 __attribute__((swift_name("component1()")));
- (AppMovieActionsMovieAdded *)doCopyMovie:(AppMovie *)movie __attribute__((swift_name("doCopy(movie:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) AppMovie *movie __attribute__((swift_name("movie")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MovieActions.RemoveMovie")))
@interface AppMovieActionsRemoveMovie : AppMovieActions
- (instancetype)initWithMovie:(AppMovie *)movie __attribute__((swift_name("init(movie:)"))) __attribute__((objc_designated_initializer));
- (AppMovie *)component1 __attribute__((swift_name("component1()")));
- (AppMovieActionsRemoveMovie *)doCopyMovie:(AppMovie *)movie __attribute__((swift_name("doCopy(movie:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) AppMovie *movie __attribute__((swift_name("movie")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MoviesState")))
@interface AppMoviesState : AppBase
- (instancetype)initWithMovies:(NSArray<AppMovie *> *)movies isMovieAdded:(BOOL)isMovieAdded iosCoolAction:(BOOL)iosCoolAction __attribute__((swift_name("init(movies:isMovieAdded:iosCoolAction:)"))) __attribute__((objc_designated_initializer));
- (NSArray<AppMovie *> *)component1 __attribute__((swift_name("component1()")));
- (BOOL)component2 __attribute__((swift_name("component2()")));
- (BOOL)component3 __attribute__((swift_name("component3()")));
- (AppMoviesState *)doCopyMovies:(NSArray<AppMovie *> *)movies isMovieAdded:(BOOL)isMovieAdded iosCoolAction:(BOOL)iosCoolAction __attribute__((swift_name("doCopy(movies:isMovieAdded:iosCoolAction:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL iosCoolAction __attribute__((swift_name("iosCoolAction")));
@property (readonly) BOOL isMovieAdded __attribute__((swift_name("isMovieAdded")));
@property (readonly) NSArray<AppMovie *> *movies __attribute__((swift_name("movies")));
@end;

@interface AppSelector (Extensions)
- (AppComposeSelectorCreator<id, AppLoadingModel<id> *, AppLoadingModel<id> *, AppKotlinThrowable *> *)error __attribute__((swift_name("error()")));
- (AppComposeSelectorCreator<id, AppLoadingModel<id> *, AppLoadingModel<id> *, AppBoolean *> *)loading __attribute__((swift_name("loading()")));
- (AppComposeSelectorCreator<id, AppLoadingModel<id> *, AppLoadingModel<id> *, AppKotlinThrowable *> *)optionalError __attribute__((swift_name("optionalError()")));
- (AppComposeSelectorCreator<id, AppLoadingModel<id> *, AppLoadingModel<id> *, id> *)optionalSuccess __attribute__((swift_name("optionalSuccess()")));
- (AppComposeSelectorCreator<id, AppLoadingModel<id> *, AppLoadingModel<id> *, id> *)success __attribute__((swift_name("success()")));
@end;

@interface AppObservableWrapper (Extensions)
- (id<AppObservable>)filterInstanceKClass:(Class)kClass __attribute__((swift_name("filterInstance(kClass:)")));
@end;

@interface AppReducer (Extensions)
- (AppKotlinPair<AppReducer<id> *, id> *)reduceData:(id)data __attribute__((swift_name("reduce(data:)")));
@end;

@interface AppKotlinThrowable (Extensions)
- (id<AppCompletable>)toCompletableOfError __attribute__((swift_name("toCompletableOfError()")));
- (id<AppMaybe>)toMaybeOfError __attribute__((swift_name("toMaybeOfError()")));
- (id<AppSingle>)toSingleOfError __attribute__((swift_name("toSingleOfError()")));
- (id<AppObservable>)toObservableOfError __attribute__((swift_name("toObservableOfError()")));
- (void)printStack __attribute__((swift_name("printStack()")));
@end;

@interface AppSubjectStatus (Extensions)
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@end;

@interface AppCompositeDisposable (Extensions)
- (void)minusAssignDisposable:(id<AppDisposable>)disposable __attribute__((swift_name("minusAssign(disposable:)")));
- (void)plusAssignDisposable:(id<AppDisposable>)disposable __attribute__((swift_name("plusAssign(disposable:)")));
@end;

@interface AppAtomicReference (Extensions)
- (id _Nullable)getAndSetValue:(id _Nullable)value __attribute__((swift_name("getAndSet(value:)")));
- (id _Nullable)getAndUpdateUpdate:(id _Nullable (^)(id _Nullable))update __attribute__((swift_name("getAndUpdate(update:)")));
- (void)updateUpdate:(id _Nullable (^)(id _Nullable))update __attribute__((swift_name("update(update:)")));
- (id _Nullable)updateAndGetUpdate:(id _Nullable (^)(id _Nullable))update __attribute__((swift_name("updateAndGet(update:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinFreezableAtomicReference")))
@interface AppKotlinFreezableAtomicReference<T> : AppBase
- (instancetype)initWithValue_:(T _Nullable)value_ __attribute__((swift_name("init(value_:)"))) __attribute__((objc_designated_initializer));
- (BOOL)compareAndSetExpected:(T _Nullable)expected new:(T _Nullable)new_ __attribute__((swift_name("compareAndSet(expected:new:)")));
- (T _Nullable)compareAndSwapExpected:(T _Nullable)expected new:(T _Nullable)new_ __attribute__((swift_name("compareAndSwap(expected:new:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property T _Nullable value __attribute__((swift_name("value")));
@end;

@interface AppKotlinFreezableAtomicReference (Extensions)
- (void)setValueValue:(id _Nullable)value __attribute__((swift_name("setValue(value:)")));
@end;

@interface AppLock (Extensions)
- (id _Nullable)synchronizedBlock:(id _Nullable (^)(void))block __attribute__((swift_name("synchronized(block:)")));
- (id _Nullable)useBlock:(id _Nullable (^)(AppLock *))block __attribute__((swift_name("use(block:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReducersKt")))
@interface AppReducersKt : AppBase
+ (AppReducer<id> *)actionTypeReducerFn:(id (^)(id, id<AppAction>))fn __attribute__((swift_name("actionTypeReducer(fn:)")));
+ (AppReducer<id> *)anyReducerFn:(id (^)(id, id))fn __attribute__((swift_name("anyReducer(fn:)")));
+ (AppReducer<id> *)combineReducersReducers:(AppKotlinArray<AppReducer<id> *> *)reducers __attribute__((swift_name("combineReducers(reducers:)")));
+ (AppReducer<id> *)typedReducerFn:(id (^)(id, id))fn __attribute__((swift_name("typedReducer(fn:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ActionsKt")))
@interface AppActionsKt : AppBase
+ (id<AppAction>)createActionType:(id)type __attribute__((swift_name("createAction(type:)")));
+ (AppActionCreator<id, id, id> *)createActionType:(id)type payloadCreator:(id _Nullable (^)(id))payloadCreator __attribute__((swift_name("createAction(type:payloadCreator:)")));
+ (AppMultiAction *)multipleActionOfActions:(AppKotlinArray<id> *)actions __attribute__((swift_name("multipleActionOf(actions:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EffectsKt")))
@interface AppEffectsKt : AppBase
+ (AppEffectFn<id<AppAction>> *)createActionTypeEffectMapper:(id<AppObservable> (^)(AppObservableWrapper<id<AppAction>> *))mapper __attribute__((swift_name("createActionTypeEffect(mapper:)")));
+ (AppEffectFn<id> *)createEffectMapper:(id<AppObservable> (^)(AppObservableWrapper<id> *))mapper __attribute__((swift_name("createEffect(mapper:)")));
+ (AppEffectFn<AppNoAction *> *)createSilentEffectMapper:(id<AppObservable> (^)(AppObservableWrapper<id> *))mapper __attribute__((swift_name("createSilentEffect(mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FracturedKt")))
@interface AppFracturedKt : AppBase
+ (AppFracturedStore *)createFracturedStorePairs:(AppKotlinArray<AppKotlinPair<AppReducer<id> *, id> *> *)pairs enhancer:(id (^(^(^)(AppStore<AppFracturedState *> *))(id (^)(id)))(id))enhancer __attribute__((swift_name("createFracturedStore(pairs:enhancer:)")));
+ (AppReducerMap *)fracturedReducerReducers:(AppKotlinArray<AppReducer<id> *> *)reducers __attribute__((swift_name("fracturedReducer(reducers:)")));
+ (AppSelector<AppFracturedState *, id> *)fracturedSelectorReducer:(AppReducer<id> *)reducer __attribute__((swift_name("fracturedSelector(reducer:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelectorsKt")))
@interface AppSelectorsKt : AppBase
+ (AppSelectorCreator<id, id> *)createSelectorSelectorFunction:(id _Nullable (^)(id))selectorFunction __attribute__((swift_name("createSelector(selectorFunction:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StoreKt")))
@interface AppStoreKt : AppBase
+ (AppStore<id> *)createStoreReducer:(AppReducer<id> *)reducer initialState:(id)initialState enhancer:(id (^(^(^)(AppStore<id> *))(id (^)(id)))(id))enhancer __attribute__((swift_name("createStore(reducer:initialState:enhancer:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EnhancersKt")))
@interface AppEnhancersKt : AppBase
+ (id (^(^(^)(AppStore<id> *))(id (^)(id)))(id))emptyEnhancer __attribute__((swift_name("emptyEnhancer()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorCallbackExtKt")))
@interface AppErrorCallbackExtKt : AppBase
+ (void)tryCatch:(id<AppErrorCallback>)receiver block:(id _Nullable (^)(void))block errorTransformer:(AppKotlinThrowable *(^)(AppKotlinThrowable *))errorTransformer onSuccess:(void (^)(id _Nullable))onSuccess __attribute__((swift_name("tryCatch(_:block:errorTransformer:onSuccess:)")));
+ (void)tryCatch:(id<AppErrorCallback>)receiver errorTransformer:(AppKotlinThrowable *(^)(AppKotlinThrowable *))errorTransformer block:(void (^)(void))block __attribute__((swift_name("tryCatch(_:errorTransformer:block:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompletableByEmitterKt")))
@interface AppCompletableByEmitterKt : AppBase
+ (id<AppCompletable>)completableOnSubscribe:(void (^)(id<AppCompletableEmitter>))onSubscribe __attribute__((swift_name("completable(onSubscribe:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeferKt")))
@interface AppDeferKt : AppBase
+ (id<AppCompletable>)completableDeferSupplier:(id<AppCompletable> (^)(void))supplier __attribute__((swift_name("completableDefer(supplier:)")));
+ (id<AppMaybe>)maybeDeferSupplier:(id<AppMaybe> (^)(void))supplier __attribute__((swift_name("maybeDefer(supplier:)")));
+ (id<AppSingle>)singleDeferSupplier:(id<AppSingle> (^)(void))supplier __attribute__((swift_name("singleDefer(supplier:)")));
+ (id<AppObservable>)observableDeferSupplier:(id<AppObservable> (^)(void))supplier __attribute__((swift_name("observableDefer(supplier:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VariousKt")))
@interface AppVariousKt : AppBase
+ (id<AppCompletable>)completableFromFunctionFunc:(void (^)(void))func __attribute__((swift_name("completableFromFunction(func:)")));
+ (id<AppCompletable>)completableOfEmpty __attribute__((swift_name("completableOfEmpty()")));
+ (id<AppCompletable>)completableOfErrorError:(AppKotlinThrowable *)error __attribute__((swift_name("completableOfError(error:)")));
+ (id<AppCompletable>)completableOfNever __attribute__((swift_name("completableOfNever()")));
+ (id<AppCompletable>)completableUnsafeOnSubscribe:(void (^)(id<AppCompletableObserver>))onSubscribe __attribute__((swift_name("completableUnsafe(onSubscribe:)")));
+ (id<AppBehaviorSubject>)behaviorSubjectInitialValue:(id _Nullable)initialValue __attribute__((swift_name("behaviorSubject(initialValue:)"))) __attribute__((deprecated("Use BehaviorSubject() builder")));
+ (id<AppPublishSubject>)publishSubject __attribute__((swift_name("publishSubject()"))) __attribute__((deprecated("Use PublishSubject() builder")));
+ (id<AppMaybe>)maybeFromFunctionFunc:(id _Nullable (^)(void))func __attribute__((swift_name("maybeFromFunction(func:)")));
+ (id<AppMaybe>)maybeOfValue:(id _Nullable)value __attribute__((swift_name("maybeOf(value:)")));
+ (id<AppMaybe>)maybeOfEmpty __attribute__((swift_name("maybeOfEmpty()")));
+ (id<AppMaybe>)maybeOfErrorError:(AppKotlinThrowable *)error __attribute__((swift_name("maybeOfError(error:)")));
+ (id<AppMaybe>)maybeOfNever __attribute__((swift_name("maybeOfNever()")));
+ (id<AppMaybe>)maybeOfNotNullValue:(id _Nullable)value __attribute__((swift_name("maybeOfNotNull(value:)")));
+ (id<AppMaybe>)maybeUnsafeOnSubscribe:(void (^)(id<AppMaybeObserver>))onSubscribe __attribute__((swift_name("maybeUnsafe(onSubscribe:)")));
+ (id<AppMaybe>)toMaybe:(id _Nullable)receiver __attribute__((swift_name("toMaybe(_:)")));
+ (id<AppMaybe>)toMaybeNotNull:(id _Nullable)receiver __attribute__((swift_name("toMaybeNotNull(_:)")));
+ (id<AppSingle>)singleFromFunctionFunc:(id _Nullable (^)(void))func __attribute__((swift_name("singleFromFunction(func:)")));
+ (id<AppSingle>)singleOfValue:(id _Nullable)value __attribute__((swift_name("singleOf(value:)")));
+ (id<AppSingle>)singleOfErrorError:(AppKotlinThrowable *)error __attribute__((swift_name("singleOfError(error:)")));
+ (id<AppSingle>)singleOfNever __attribute__((swift_name("singleOfNever()")));
+ (id<AppSingle>)singleUnsafeOnSubscribe:(void (^)(id<AppSingleObserver>))onSubscribe __attribute__((swift_name("singleUnsafe(onSubscribe:)")));
+ (id<AppSingle>)asSingle:(id _Nullable (^)(void))receiver __attribute__((swift_name("asSingle(_:)")));
+ (id<AppSingle>)toSingle:(id _Nullable)receiver __attribute__((swift_name("toSingle(_:)")));
+ (id<AppDisposable>)Disposable __attribute__((swift_name("Disposable()")));
+ (id<AppDisposable>)DisposableOnDispose:(void (^)(void))onDispose __attribute__((swift_name("Disposable(onDispose:)")));
+ (id<AppObservable>)observableFromFunctionFunc:(id _Nullable (^)(void))func __attribute__((swift_name("observableFromFunction(func:)")));
+ (id<AppObservable>)observableOfValue:(id _Nullable)value __attribute__((swift_name("observableOf(value:)")));
+ (id<AppObservable>)observableOfValues:(AppKotlinArray<id> *)values __attribute__((swift_name("observableOf(values:)")));
+ (id<AppObservable>)observableOfEmpty __attribute__((swift_name("observableOfEmpty()")));
+ (id<AppObservable>)observableOfErrorError:(AppKotlinThrowable *)error __attribute__((swift_name("observableOfError(error:)")));
+ (id<AppObservable>)observableOfNever __attribute__((swift_name("observableOfNever()")));
+ (id<AppObservable>)observableUnsafeOnSubscribe:(void (^)(id<AppObservableObserver>))onSubscribe __attribute__((swift_name("observableUnsafe(onSubscribe:)")));
+ (id<AppObservable>)asObservable:(id)receiver __attribute__((swift_name("asObservable(_:)")));
+ (id<AppObservable>)toObservable:(id _Nullable)receiver __attribute__((swift_name("toObservable(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimerKt")))
@interface AppTimerKt : AppBase
+ (id<AppCompletable>)completableTimerDelayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("completableTimer(delayMillis:scheduler:)")));
+ (id<AppMaybe>)maybeTimerDelayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("maybeTimer(delayMillis:scheduler:)")));
+ (id<AppSingle>)singleTimerDelayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("singleTimer(delayMillis:scheduler:)")));
+ (id<AppObservable>)observableTimerDelayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("observableTimer(delayMillis:scheduler:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcatKt")))
@interface AppConcatKt : AppBase
+ (id<AppCompletable>)concatSources:(AppKotlinArray<id<AppCompletable>> *)sources __attribute__((swift_name("concat(sources:)")));
+ (id<AppCompletable>)concat:(id)receiver __attribute__((swift_name("concat(_:)")));
+ (id<AppObservable>)concatSources_:(AppKotlinArray<id<AppMaybe>> *)sources __attribute__((swift_name("concat(sources_:)")));
+ (id<AppObservable>)concat_:(id)receiver __attribute__((swift_name("concat(__:)")));
+ (id<AppObservable>)concatSources__:(AppKotlinArray<id<AppSingle>> *)sources __attribute__((swift_name("concat(sources__:)")));
+ (id<AppObservable>)concat__:(id)receiver __attribute__((swift_name("concat(___:)")));
+ (id<AppObservable>)concatSources___:(AppKotlinArray<id<AppObservable>> *)sources __attribute__((swift_name("concat(sources___:)")));
+ (id<AppObservable>)concat___:(id)receiver __attribute__((swift_name("concat(____:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MergeKt")))
@interface AppMergeKt : AppBase
+ (id<AppCompletable>)mergeSources:(AppKotlinArray<id<AppCompletable>> *)sources __attribute__((swift_name("merge(sources:)")));
+ (id<AppCompletable>)merge:(id)receiver __attribute__((swift_name("merge(_:)")));
+ (id<AppObservable>)mergeSources_:(AppKotlinArray<id<AppMaybe>> *)sources __attribute__((swift_name("merge(sources_:)")));
+ (id<AppObservable>)merge_:(id)receiver __attribute__((swift_name("merge(__:)")));
+ (id<AppObservable>)mergeSources__:(AppKotlinArray<id<AppSingle>> *)sources __attribute__((swift_name("merge(sources__:)")));
+ (id<AppObservable>)merge__:(id)receiver __attribute__((swift_name("merge(___:)")));
+ (id<AppObservable>)mergeSources___:(AppKotlinArray<id<AppObservable>> *)sources __attribute__((swift_name("merge(sources___:)")));
+ (id<AppObservable>)merge___:(id)receiver __attribute__((swift_name("merge(____:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AndThenKt")))
@interface AppAndThenKt : AppBase
+ (id<AppCompletable>)andThen:(id<AppCompletable>)receiver completable:(id<AppCompletable>)completable __attribute__((swift_name("andThen(_:completable:)")));
+ (id<AppMaybe>)andThen:(id<AppCompletable>)receiver maybe:(id<AppMaybe>)maybe __attribute__((swift_name("andThen(_:maybe:)")));
+ (id<AppObservable>)andThen:(id<AppCompletable>)receiver observable:(id<AppObservable>)observable __attribute__((swift_name("andThen(_:observable:)")));
+ (id<AppSingle>)andThen:(id<AppCompletable>)receiver single:(id<AppSingle>)single __attribute__((swift_name("andThen(_:single:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AsMaybeKt")))
@interface AppAsMaybeKt : AppBase
+ (id<AppMaybe>)asMaybe:(id<AppCompletable>)receiver __attribute__((swift_name("asMaybe(_:)")));
+ (id<AppMaybe>)asMaybe_:(id<AppSingle>)receiver __attribute__((swift_name("asMaybe(__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AsObservableKt")))
@interface AppAsObservableKt : AppBase
+ (id<AppObservable>)asObservable_:(id<AppCompletable>)receiver __attribute__((swift_name("asObservable(__:)")));
+ (id<AppObservable>)asObservable__:(id<AppMaybe>)receiver __attribute__((swift_name("asObservable(___:)")));
+ (id<AppObservable>)asObservable___:(id<AppSingle>)receiver __attribute__((swift_name("asObservable(____:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AsSingleKt")))
@interface AppAsSingleKt : AppBase
+ (id<AppSingle>)asSingle:(id<AppCompletable>)receiver defaultValueSupplier:(id _Nullable (^)(void))defaultValueSupplier __attribute__((swift_name("asSingle(_:defaultValueSupplier:)")));
+ (id<AppSingle>)asSingle:(id<AppCompletable>)receiver defaultValue:(id _Nullable)defaultValue __attribute__((swift_name("asSingle(_:defaultValue:)")));
+ (id<AppSingle>)asSingle:(id<AppMaybe>)receiver defaultValueSupplier_:(id _Nullable (^)(void))defaultValueSupplier __attribute__((swift_name("asSingle(_:defaultValueSupplier_:)")));
+ (id<AppSingle>)asSingle:(id<AppMaybe>)receiver defaultValue_:(id _Nullable)defaultValue __attribute__((swift_name("asSingle(_:defaultValue_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DelayKt")))
@interface AppDelayKt : AppBase
+ (id<AppCompletable>)delay:(id<AppCompletable>)receiver delayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler delayError:(BOOL)delayError __attribute__((swift_name("delay(_:delayMillis:scheduler:delayError:)")));
+ (id<AppMaybe>)delay:(id<AppMaybe>)receiver delayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler delayError_:(BOOL)delayError __attribute__((swift_name("delay(_:delayMillis:scheduler:delayError_:)")));
+ (id<AppSingle>)delay:(id<AppSingle>)receiver delayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler delayError__:(BOOL)delayError __attribute__((swift_name("delay(_:delayMillis:scheduler:delayError__:)")));
+ (id<AppObservable>)delay:(id<AppObservable>)receiver delayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler delayError___:(BOOL)delayError __attribute__((swift_name("delay(_:delayMillis:scheduler:delayError___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DelaySubscriptionKt")))
@interface AppDelaySubscriptionKt : AppBase
+ (id<AppCompletable>)delaySubscription:(id<AppCompletable>)receiver delayMillis:(int64_t)delayMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("delaySubscription(_:delayMillis:scheduler:)")));
+ (id<AppMaybe>)delaySubscription:(id<AppMaybe>)receiver delayMillis:(int64_t)delayMillis scheduler_:(id<AppScheduler>)scheduler __attribute__((swift_name("delaySubscription(_:delayMillis:scheduler_:)")));
+ (id<AppSingle>)delaySubscription:(id<AppSingle>)receiver delayMillis:(int64_t)delayMillis scheduler__:(id<AppScheduler>)scheduler __attribute__((swift_name("delaySubscription(_:delayMillis:scheduler__:)")));
+ (id<AppObservable>)delaySubscription:(id<AppObservable>)receiver delayMillis:(int64_t)delayMillis scheduler___:(id<AppScheduler>)scheduler __attribute__((swift_name("delaySubscription(_:delayMillis:scheduler___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DoOnAfterKt")))
@interface AppDoOnAfterKt : AppBase
+ (id<AppCompletable>)doOnAfterComplete:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnAfterComplete(_:action:)")));
+ (id<AppCompletable>)doOnAfterDispose:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnAfterDispose(_:action:)")));
+ (id<AppCompletable>)doOnAfterError:(id<AppCompletable>)receiver consumer:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnAfterError(_:consumer:)")));
+ (id<AppCompletable>)doOnAfterFinally:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnAfterFinally(_:action:)")));
+ (id<AppCompletable>)doOnAfterSubscribe:(id<AppCompletable>)receiver action:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnAfterSubscribe(_:action:)")));
+ (id<AppCompletable>)doOnAfterTerminate:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnAfterTerminate(_:action:)")));
+ (id<AppMaybe>)doOnAfterComplete:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnAfterComplete(_:action_:)")));
+ (id<AppMaybe>)doOnAfterDispose:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnAfterDispose(_:action_:)")));
+ (id<AppMaybe>)doOnAfterError:(id<AppMaybe>)receiver consumer_:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnAfterError(_:consumer_:)")));
+ (id<AppMaybe>)doOnAfterFinally:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnAfterFinally(_:action_:)")));
+ (id<AppMaybe>)doOnAfterSubscribe:(id<AppMaybe>)receiver action_:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnAfterSubscribe(_:action_:)")));
+ (id<AppMaybe>)doOnAfterSuccess:(id<AppMaybe>)receiver action:(void (^)(id _Nullable))action __attribute__((swift_name("doOnAfterSuccess(_:action:)")));
+ (id<AppMaybe>)doOnAfterTerminate:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnAfterTerminate(_:action_:)")));
+ (id<AppSingle>)doOnAfterDispose:(id<AppSingle>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnAfterDispose(_:action__:)")));
+ (id<AppSingle>)doOnAfterError:(id<AppSingle>)receiver consumer__:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnAfterError(_:consumer__:)")));
+ (id<AppSingle>)doOnAfterFinally:(id<AppSingle>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnAfterFinally(_:action__:)")));
+ (id<AppSingle>)doOnAfterSubscribe:(id<AppSingle>)receiver action__:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnAfterSubscribe(_:action__:)")));
+ (id<AppSingle>)doOnAfterSuccess:(id<AppSingle>)receiver action_:(void (^)(id _Nullable))action __attribute__((swift_name("doOnAfterSuccess(_:action_:)")));
+ (id<AppSingle>)doOnAfterTerminate:(id<AppSingle>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnAfterTerminate(_:action__:)")));
+ (id<AppObservable>)doOnAfterComplete:(id<AppObservable>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnAfterComplete(_:action__:)")));
+ (id<AppObservable>)doOnAfterDispose:(id<AppObservable>)receiver action___:(void (^)(void))action __attribute__((swift_name("doOnAfterDispose(_:action___:)")));
+ (id<AppObservable>)doOnAfterError:(id<AppObservable>)receiver consumer___:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnAfterError(_:consumer___:)")));
+ (id<AppObservable>)doOnAfterFinally:(id<AppObservable>)receiver action___:(void (^)(void))action __attribute__((swift_name("doOnAfterFinally(_:action___:)")));
+ (id<AppObservable>)doOnAfterNext:(id<AppObservable>)receiver consumer:(void (^)(id _Nullable))consumer __attribute__((swift_name("doOnAfterNext(_:consumer:)")));
+ (id<AppObservable>)doOnAfterSubscribe:(id<AppObservable>)receiver action___:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnAfterSubscribe(_:action___:)")));
+ (id<AppObservable>)doOnAfterTerminate:(id<AppObservable>)receiver action___:(void (^)(void))action __attribute__((swift_name("doOnAfterTerminate(_:action___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DoOnBeforeKt")))
@interface AppDoOnBeforeKt : AppBase
+ (id<AppCompletable>)doOnBeforeComplete:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnBeforeComplete(_:action:)")));
+ (id<AppCompletable>)doOnBeforeDispose:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnBeforeDispose(_:action:)")));
+ (id<AppCompletable>)doOnBeforeError:(id<AppCompletable>)receiver consumer:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnBeforeError(_:consumer:)")));
+ (id<AppCompletable>)doOnBeforeFinally:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnBeforeFinally(_:action:)")));
+ (id<AppCompletable>)doOnBeforeSubscribe:(id<AppCompletable>)receiver action:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnBeforeSubscribe(_:action:)")));
+ (id<AppCompletable>)doOnBeforeTerminate:(id<AppCompletable>)receiver action:(void (^)(void))action __attribute__((swift_name("doOnBeforeTerminate(_:action:)")));
+ (id<AppMaybe>)doOnBeforeComplete:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnBeforeComplete(_:action_:)")));
+ (id<AppMaybe>)doOnBeforeDispose:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnBeforeDispose(_:action_:)")));
+ (id<AppMaybe>)doOnBeforeError:(id<AppMaybe>)receiver consumer_:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnBeforeError(_:consumer_:)")));
+ (id<AppMaybe>)doOnBeforeFinally:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnBeforeFinally(_:action_:)")));
+ (id<AppMaybe>)doOnBeforeSubscribe:(id<AppMaybe>)receiver action_:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnBeforeSubscribe(_:action_:)")));
+ (id<AppMaybe>)doOnBeforeSuccess:(id<AppMaybe>)receiver consumer:(void (^)(id _Nullable))consumer __attribute__((swift_name("doOnBeforeSuccess(_:consumer:)")));
+ (id<AppMaybe>)doOnBeforeTerminate:(id<AppMaybe>)receiver action_:(void (^)(void))action __attribute__((swift_name("doOnBeforeTerminate(_:action_:)")));
+ (id<AppSingle>)doOnBeforeDispose:(id<AppSingle>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnBeforeDispose(_:action__:)")));
+ (id<AppSingle>)doOnBeforeError:(id<AppSingle>)receiver consumer__:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnBeforeError(_:consumer__:)")));
+ (id<AppSingle>)doOnBeforeFinally:(id<AppSingle>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnBeforeFinally(_:action__:)")));
+ (id<AppSingle>)doOnBeforeSubscribe:(id<AppSingle>)receiver action__:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnBeforeSubscribe(_:action__:)")));
+ (id<AppSingle>)doOnBeforeSuccess:(id<AppSingle>)receiver consumer_:(void (^)(id _Nullable))consumer __attribute__((swift_name("doOnBeforeSuccess(_:consumer_:)")));
+ (id<AppSingle>)doOnBeforeTerminate:(id<AppSingle>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnBeforeTerminate(_:action__:)")));
+ (id<AppObservable>)doOnBeforeComplete:(id<AppObservable>)receiver action__:(void (^)(void))action __attribute__((swift_name("doOnBeforeComplete(_:action__:)")));
+ (id<AppObservable>)doOnBeforeDispose:(id<AppObservable>)receiver action___:(void (^)(void))action __attribute__((swift_name("doOnBeforeDispose(_:action___:)")));
+ (id<AppObservable>)doOnBeforeError:(id<AppObservable>)receiver consumer___:(void (^)(AppKotlinThrowable *))consumer __attribute__((swift_name("doOnBeforeError(_:consumer___:)")));
+ (id<AppObservable>)doOnBeforeFinally:(id<AppObservable>)receiver action___:(void (^)(void))action __attribute__((swift_name("doOnBeforeFinally(_:action___:)")));
+ (id<AppObservable>)doOnBeforeNext:(id<AppObservable>)receiver consumer:(void (^)(id _Nullable))consumer __attribute__((swift_name("doOnBeforeNext(_:consumer:)")));
+ (id<AppObservable>)doOnBeforeSubscribe:(id<AppObservable>)receiver action___:(void (^)(id<AppDisposable>))action __attribute__((swift_name("doOnBeforeSubscribe(_:action___:)")));
+ (id<AppObservable>)doOnBeforeTerminate:(id<AppObservable>)receiver action___:(void (^)(void))action __attribute__((swift_name("doOnBeforeTerminate(_:action___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObserveOnKt")))
@interface AppObserveOnKt : AppBase
+ (id<AppCompletable>)observeOn:(id<AppCompletable>)receiver scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("observeOn(_:scheduler:)")));
+ (id<AppMaybe>)observeOn:(id<AppMaybe>)receiver scheduler_:(id<AppScheduler>)scheduler __attribute__((swift_name("observeOn(_:scheduler_:)")));
+ (id<AppSingle>)observeOn:(id<AppSingle>)receiver scheduler__:(id<AppScheduler>)scheduler __attribute__((swift_name("observeOn(_:scheduler__:)")));
+ (id<AppObservable>)observeOn:(id<AppObservable>)receiver scheduler___:(id<AppScheduler>)scheduler __attribute__((swift_name("observeOn(_:scheduler___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OnErrorCompleteKt")))
@interface AppOnErrorCompleteKt : AppBase
+ (id<AppCompletable>)onErrorComplete:(id<AppCompletable>)receiver __attribute__((swift_name("onErrorComplete(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OnErrorResumeNextKt")))
@interface AppOnErrorResumeNextKt : AppBase
+ (id<AppCompletable>)onErrorResumeNext:(id<AppCompletable>)receiver nextSupplier:(id<AppCompletable> (^)(AppKotlinThrowable *))nextSupplier __attribute__((swift_name("onErrorResumeNext(_:nextSupplier:)")));
+ (id<AppCompletable>)onErrorResumeNext:(id<AppCompletable>)receiver next:(id<AppCompletable>)next __attribute__((swift_name("onErrorResumeNext(_:next:)")));
+ (id<AppMaybe>)onErrorResumeNext:(id<AppMaybe>)receiver nextSupplier_:(id<AppMaybe> (^)(AppKotlinThrowable *))nextSupplier __attribute__((swift_name("onErrorResumeNext(_:nextSupplier_:)")));
+ (id<AppMaybe>)onErrorResumeNext:(id<AppMaybe>)receiver next_:(id<AppMaybe>)next __attribute__((swift_name("onErrorResumeNext(_:next_:)")));
+ (id<AppSingle>)onErrorResumeNext:(id<AppSingle>)receiver nextSupplier__:(id<AppSingle> (^)(AppKotlinThrowable *))nextSupplier __attribute__((swift_name("onErrorResumeNext(_:nextSupplier__:)")));
+ (id<AppSingle>)onErrorResumeNext:(id<AppSingle>)receiver next__:(id<AppSingle>)next __attribute__((swift_name("onErrorResumeNext(_:next__:)")));
+ (id<AppObservable>)onErrorResumeNext:(id<AppObservable>)receiver nextSupplier___:(id<AppObservable> (^)(AppKotlinThrowable *))nextSupplier __attribute__((swift_name("onErrorResumeNext(_:nextSupplier___:)")));
+ (id<AppObservable>)onErrorResumeNext:(id<AppObservable>)receiver next___:(id<AppObservable>)next __attribute__((swift_name("onErrorResumeNext(_:next___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RepeatKt")))
@interface AppRepeatKt : AppBase
+ (id<AppCompletable>)repeat:(id<AppCompletable>)receiver count:(int32_t)count __attribute__((swift_name("repeat(_:count:)")));
+ (id<AppObservable>)repeat:(id<AppMaybe>)receiver count_:(int32_t)count __attribute__((swift_name("repeat(_:count_:)")));
+ (id<AppObservable>)repeat:(id<AppSingle>)receiver count__:(int32_t)count __attribute__((swift_name("repeat(_:count__:)")));
+ (id<AppObservable>)repeat:(id<AppObservable>)receiver count___:(int32_t)count __attribute__((swift_name("repeat(_:count___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RepeatUntilKt")))
@interface AppRepeatUntilKt : AppBase
+ (id<AppCompletable>)repeatUntil:(id<AppCompletable>)receiver predicate:(AppBoolean *(^)(void))predicate __attribute__((swift_name("repeatUntil(_:predicate:)")));
+ (id<AppObservable>)repeatUntil:(id<AppMaybe>)receiver predicate_:(AppBoolean *(^)(void))predicate __attribute__((swift_name("repeatUntil(_:predicate_:)")));
+ (id<AppObservable>)repeatUntil:(id<AppSingle>)receiver predicate__:(AppBoolean *(^)(id _Nullable))predicate __attribute__((swift_name("repeatUntil(_:predicate__:)")));
+ (id<AppObservable>)repeatUntil:(id<AppObservable>)receiver predicate___:(AppBoolean *(^)(void))predicate __attribute__((swift_name("repeatUntil(_:predicate___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RetryKt")))
@interface AppRetryKt : AppBase
+ (id<AppCompletable>)retry:(id<AppCompletable>)receiver predicate:(AppBoolean *(^)(AppInt *, AppKotlinThrowable *))predicate __attribute__((swift_name("retry(_:predicate:)")));
+ (id<AppCompletable>)retry:(id<AppCompletable>)receiver times:(int32_t)times __attribute__((swift_name("retry(_:times:)")));
+ (id<AppMaybe>)retry:(id<AppMaybe>)receiver predicate_:(AppBoolean *(^)(AppInt *, AppKotlinThrowable *))predicate __attribute__((swift_name("retry(_:predicate_:)")));
+ (id<AppMaybe>)retry:(id<AppMaybe>)receiver times_:(int32_t)times __attribute__((swift_name("retry(_:times_:)")));
+ (id<AppSingle>)retry:(id<AppSingle>)receiver predicate__:(AppBoolean *(^)(AppInt *, AppKotlinThrowable *))predicate __attribute__((swift_name("retry(_:predicate__:)")));
+ (id<AppSingle>)retry:(id<AppSingle>)receiver times__:(int32_t)times __attribute__((swift_name("retry(_:times__:)")));
+ (id<AppObservable>)retry:(id<AppObservable>)receiver predicate___:(AppBoolean *(^)(AppInt *, AppKotlinThrowable *))predicate __attribute__((swift_name("retry(_:predicate___:)")));
+ (id<AppObservable>)retry:(id<AppObservable>)receiver times___:(int32_t)times __attribute__((swift_name("retry(_:times___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompletableEmitterSerializeKt")))
@interface AppCompletableEmitterSerializeKt : AppBase
+ (id<AppCompletableEmitter>)serialize:(id<AppCompletableEmitter>)receiver __attribute__((swift_name("serialize(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubscribeKt")))
@interface AppSubscribeKt : AppBase
+ (id<AppDisposable>)subscribe:(id<AppCompletable>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete __attribute__((swift_name("subscribe(_:isThreadLocal:onSubscribe:onError:onComplete:)")));
+ (id<AppDisposable>)subscribe:(id<AppMaybe>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete onSuccess:(void (^ _Nullable)(id _Nullable))onSuccess __attribute__((swift_name("subscribe(_:isThreadLocal:onSubscribe:onError:onComplete:onSuccess:)")));
+ (id<AppDisposable>)subscribe:(id<AppSingle>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onSuccess:(void (^ _Nullable)(id _Nullable))onSuccess __attribute__((swift_name("subscribe(_:isThreadLocal:onSubscribe:onError:onSuccess:)")));
+ (id<AppDisposable>)subscribe:(id<AppObservable>)receiver isThreadLocal:(BOOL)isThreadLocal onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe onError:(void (^ _Nullable)(AppKotlinThrowable *))onError onComplete:(void (^ _Nullable)(void))onComplete onNext:(void (^ _Nullable)(id _Nullable))onNext __attribute__((swift_name("subscribe(_:isThreadLocal:onSubscribe:onError:onComplete:onNext:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubscribeOnKt")))
@interface AppSubscribeOnKt : AppBase
+ (id<AppCompletable>)subscribeOn:(id<AppCompletable>)receiver scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("subscribeOn(_:scheduler:)")));
+ (id<AppMaybe>)subscribeOn:(id<AppMaybe>)receiver scheduler_:(id<AppScheduler>)scheduler __attribute__((swift_name("subscribeOn(_:scheduler_:)")));
+ (id<AppSingle>)subscribeOn:(id<AppSingle>)receiver scheduler__:(id<AppScheduler>)scheduler __attribute__((swift_name("subscribeOn(_:scheduler__:)")));
+ (id<AppObservable>)subscribeOn:(id<AppObservable>)receiver scheduler___:(id<AppScheduler>)scheduler __attribute__((swift_name("subscribeOn(_:scheduler___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThreadLocalKt")))
@interface AppThreadLocalKt : AppBase
+ (id<AppCompletable>)threadLocal:(id<AppCompletable>)receiver __attribute__((swift_name("threadLocal(_:)")));
+ (id<AppMaybe>)threadLocal_:(id<AppMaybe>)receiver __attribute__((swift_name("threadLocal(__:)")));
+ (id<AppSingle>)threadLocal__:(id<AppSingle>)receiver __attribute__((swift_name("threadLocal(___:)")));
+ (id<AppObservable>)threadLocal___:(id<AppObservable>)receiver __attribute__((swift_name("threadLocal(____:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeoutKt")))
@interface AppTimeoutKt : AppBase
+ (id<AppCompletable>)timeout:(id<AppCompletable>)receiver timeoutMillis:(int64_t)timeoutMillis scheduler:(id<AppScheduler>)scheduler other:(id<AppCompletable> _Nullable)other __attribute__((swift_name("timeout(_:timeoutMillis:scheduler:other:)")));
+ (id<AppMaybe>)timeout:(id<AppMaybe>)receiver timeoutMillis:(int64_t)timeoutMillis scheduler:(id<AppScheduler>)scheduler other_:(id<AppMaybe> _Nullable)other __attribute__((swift_name("timeout(_:timeoutMillis:scheduler:other_:)")));
+ (id<AppSingle>)timeout:(id<AppSingle>)receiver timeoutMillis:(int64_t)timeoutMillis scheduler:(id<AppScheduler>)scheduler other__:(id<AppSingle> _Nullable)other __attribute__((swift_name("timeout(_:timeoutMillis:scheduler:other__:)")));
+ (id<AppObservable>)timeout:(id<AppObservable>)receiver timeoutMillis:(int64_t)timeoutMillis scheduler:(id<AppScheduler>)scheduler other___:(id<AppObservable> _Nullable)other __attribute__((swift_name("timeout(_:timeoutMillis:scheduler:other___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompletableWrapperKt")))
@interface AppCompletableWrapperKt : AppBase
+ (AppCompletableWrapper *)wrap:(id<AppCompletable>)receiver __attribute__((swift_name("wrap(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SchedulersKt")))
@interface AppSchedulersKt : AppBase
+ (void)overrideSchedulersMain:(id<AppScheduler> (^)(void))main computation:(id<AppScheduler> (^)(void))computation io:(id<AppScheduler> (^)(void))io trampoline:(id<AppScheduler> (^)(void))trampoline single:(id<AppScheduler> (^)(void))single newThread:(id<AppScheduler> (^)(void))newThread __attribute__((swift_name("overrideSchedulers(main:computation:io:trampoline:single:newThread:)")));
@property (class, readonly) id<AppScheduler> computationScheduler __attribute__((swift_name("computationScheduler")));
@property (class, readonly) id<AppScheduler> ioScheduler __attribute__((swift_name("ioScheduler")));
@property (class, readonly) id<AppScheduler> mainScheduler __attribute__((swift_name("mainScheduler")));
@property (class, readonly, getter=doNewThreadScheduler) id<AppScheduler> newThreadScheduler __attribute__((swift_name("newThreadScheduler")));
@property (class, readonly) id<AppScheduler> singleScheduler __attribute__((swift_name("singleScheduler")));
@property (class, readonly) id<AppScheduler> trampolineScheduler __attribute__((swift_name("trampolineScheduler")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreateComputationSchedulerKt")))
@interface AppCreateComputationSchedulerKt : AppBase
+ (id<AppScheduler>)createComputationScheduler __attribute__((swift_name("createComputationScheduler()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreateIoSchedulerKt")))
@interface AppCreateIoSchedulerKt : AppBase
+ (id<AppScheduler>)createIoScheduler __attribute__((swift_name("createIoScheduler()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreateMainSchedulerKt")))
@interface AppCreateMainSchedulerKt : AppBase
+ (id<AppScheduler>)createMainScheduler __attribute__((swift_name("createMainScheduler()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreateNewThreadSchedulerKt")))
@interface AppCreateNewThreadSchedulerKt : AppBase
+ (id<AppScheduler>)createNewThreadScheduler __attribute__((swift_name("createNewThreadScheduler()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreateSingleSchedulerKt")))
@interface AppCreateSingleSchedulerKt : AppBase
+ (id<AppScheduler>)createSingleScheduler __attribute__((swift_name("createSingleScheduler()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreateTrampolineSchedulerKt")))
@interface AppCreateTrampolineSchedulerKt : AppBase
+ (id<AppScheduler>)createTrampolineScheduler __attribute__((swift_name("createTrampolineScheduler()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SchedulerExtKt")))
@interface AppSchedulerExtKt : AppBase
+ (id<AppDisposable>)submit:(id<AppScheduler>)receiver delayMillis:(int64_t)delayMillis task:(void (^)(void))task __attribute__((swift_name("submit(_:delayMillis:task:)")));
+ (id<AppDisposable>)submitRepeating:(id<AppScheduler>)receiver startDelayMillis:(int64_t)startDelayMillis periodMillis:(int64_t)periodMillis task:(void (^)(void))task __attribute__((swift_name("submitRepeating(_:startDelayMillis:periodMillis:task:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SubjectExtKt")))
@interface AppSubjectExtKt : AppBase
+ (BOOL)isActive:(id<AppSubject>)receiver __attribute__((swift_name("isActive(_:)")));
+ (id<AppObservableObserver>)getObserver:(id<AppSubject>)receiver onSubscribe:(void (^ _Nullable)(id<AppDisposable>))onSubscribe __attribute__((swift_name("getObserver(_:onSubscribe:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnicastSubjectBuilderKt")))
@interface AppUnicastSubjectBuilderKt : AppBase
+ (id<AppUnicastSubject>)UnicastSubjectBufferSize:(int32_t)bufferSize onTerminate:(void (^)(void))onTerminate __attribute__((swift_name("UnicastSubject(bufferSize:onTerminate:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReplaySubjectBuilderKt")))
@interface AppReplaySubjectBuilderKt : AppBase
+ (id<AppReplaySubject>)ReplaySubjectBufferSize:(int32_t)bufferSize __attribute__((swift_name("ReplaySubject(bufferSize:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BehaviorSubjectBuilderKt")))
@interface AppBehaviorSubjectBuilderKt : AppBase
+ (id<AppBehaviorSubject>)BehaviorSubjectInitialValue:(id _Nullable)initialValue __attribute__((swift_name("BehaviorSubject(initialValue:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PublishSubjectBuilderKt")))
@interface AppPublishSubjectBuilderKt : AppBase
+ (id<AppPublishSubject>)PublishSubject __attribute__((swift_name("PublishSubject()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MaybeByEmitterKt")))
@interface AppMaybeByEmitterKt : AppBase
+ (id<AppMaybe>)maybeOnSubscribe:(void (^)(id<AppMaybeEmitter>))onSubscribe __attribute__((swift_name("maybe(onSubscribe:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZipKt")))
@interface AppZipKt : AppBase
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 mapper:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 source5:(id<AppMaybe>)source5 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 source5:(id<AppMaybe>)source5 source6:(id<AppMaybe>)source6 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 source5:(id<AppMaybe>)source5 source6:(id<AppMaybe>)source6 source7:(id<AppMaybe>)source7 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 source5:(id<AppMaybe>)source5 source6:(id<AppMaybe>)source6 source7:(id<AppMaybe>)source7 source8:(id<AppMaybe>)source8 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 source5:(id<AppMaybe>)source5 source6:(id<AppMaybe>)source6 source7:(id<AppMaybe>)source7 source8:(id<AppMaybe>)source8 source9:(id<AppMaybe>)source9 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:source9:mapper:)")));
+ (id<AppMaybe>)zipSource1:(id<AppMaybe>)source1 source2:(id<AppMaybe>)source2 source3:(id<AppMaybe>)source3 source4:(id<AppMaybe>)source4 source5:(id<AppMaybe>)source5 source6:(id<AppMaybe>)source6 source7:(id<AppMaybe>)source7 source8:(id<AppMaybe>)source8 source9:(id<AppMaybe>)source9 source10:(id<AppMaybe>)source10 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:source9:source10:mapper:)")));
+ (id<AppMaybe>)zipSources:(AppKotlinArray<id<AppMaybe>> *)sources mapper:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("zip(sources:mapper:)")));
+ (id<AppMaybe>)zip:(id)receiver mapper:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("zip(_:mapper:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 source5:(id<AppSingle>)source5 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 source5:(id<AppSingle>)source5 source6:(id<AppSingle>)source6 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 source5:(id<AppSingle>)source5 source6:(id<AppSingle>)source6 source7:(id<AppSingle>)source7 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 source5:(id<AppSingle>)source5 source6:(id<AppSingle>)source6 source7:(id<AppSingle>)source7 source8:(id<AppSingle>)source8 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 source5:(id<AppSingle>)source5 source6:(id<AppSingle>)source6 source7:(id<AppSingle>)source7 source8:(id<AppSingle>)source8 source9:(id<AppSingle>)source9 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:source9:mapper_:)")));
+ (id<AppSingle>)zipSource1:(id<AppSingle>)source1 source2:(id<AppSingle>)source2 source3:(id<AppSingle>)source3 source4:(id<AppSingle>)source4 source5:(id<AppSingle>)source5 source6:(id<AppSingle>)source6 source7:(id<AppSingle>)source7 source8:(id<AppSingle>)source8 source9:(id<AppSingle>)source9 source10:(id<AppSingle>)source10 mapper_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:source9:source10:mapper_:)")));
+ (id<AppSingle>)zipSources:(AppKotlinArray<id<AppSingle>> *)sources mapper_:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("zip(sources:mapper_:)")));
+ (id<AppSingle>)zip:(id)receiver mapper_:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("zip(_:mapper_:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 source8:(id<AppObservable>)source8 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 source8:(id<AppObservable>)source8 source9:(id<AppObservable>)source9 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:source9:mapper__:)")));
+ (id<AppObservable>)zipSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 source8:(id<AppObservable>)source8 source9:(id<AppObservable>)source9 source10:(id<AppObservable>)source10 mapper__:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("zip(source1:source2:source3:source4:source5:source6:source7:source8:source9:source10:mapper__:)")));
+ (id<AppObservable>)zipSources:(AppKotlinArray<id<AppObservable>> *)sources mapper__:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("zip(sources:mapper__:)")));
+ (id<AppObservable>)zip:(id)receiver mapper__:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("zip(_:mapper__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AsCompletableKt")))
@interface AppAsCompletableKt : AppBase
+ (id<AppCompletable>)asCompletable:(id<AppMaybe>)receiver __attribute__((swift_name("asCompletable(_:)")));
+ (id<AppCompletable>)asCompletable_:(id<AppSingle>)receiver __attribute__((swift_name("asCompletable(__:)")));
+ (id<AppCompletable>)asCompletable__:(id<AppObservable>)receiver __attribute__((swift_name("asCompletable(___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AsSingleOrErrorKt")))
@interface AppAsSingleOrErrorKt : AppBase
+ (id<AppSingle>)asSingleOrError:(id<AppMaybe>)receiver errorSupplier:(AppKotlinThrowable *(^)(void))errorSupplier __attribute__((swift_name("asSingleOrError(_:errorSupplier:)")));
+ (id<AppSingle>)asSingleOrError:(id<AppMaybe>)receiver error:(AppKotlinThrowable *)error __attribute__((swift_name("asSingleOrError(_:error:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlockingGetKt")))
@interface AppBlockingGetKt : AppBase
+ (id _Nullable)blockingGet:(id<AppMaybe>)receiver __attribute__((swift_name("blockingGet(_:)")));
+ (id _Nullable)blockingGet_:(id<AppSingle>)receiver __attribute__((swift_name("blockingGet(__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultIfEmptyKt")))
@interface AppDefaultIfEmptyKt : AppBase
+ (id<AppSingle>)defaultIfEmpty:(id<AppMaybe>)receiver defaultValue:(id _Nullable)defaultValue __attribute__((swift_name("defaultIfEmpty(_:defaultValue:)")));
+ (id<AppObservable>)defaultIfEmpty:(id<AppObservable>)receiver defaultValue_:(id _Nullable)defaultValue __attribute__((swift_name("defaultIfEmpty(_:defaultValue_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FilterKt")))
@interface AppFilterKt : AppBase
+ (id<AppMaybe>)filter:(id<AppMaybe>)receiver predicate:(AppBoolean *(^)(id _Nullable))predicate __attribute__((swift_name("filter(_:predicate:)")));
+ (id<AppMaybe>)filter:(id<AppSingle>)receiver predicate_:(AppBoolean *(^)(id _Nullable))predicate __attribute__((swift_name("filter(_:predicate_:)")));
+ (id<AppObservable>)filter:(id<AppObservable>)receiver predicate__:(AppBoolean *(^)(id _Nullable))predicate __attribute__((swift_name("filter(_:predicate__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlatMapKt")))
@interface AppFlatMapKt : AppBase
+ (id<AppMaybe>)flatMap:(id<AppMaybe>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper __attribute__((swift_name("flatMap(_:mapper:)")));
+ (id<AppMaybe>)flatMap:(id<AppMaybe>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMap(_:mapper:resultSelector:)")));
+ (id<AppSingle>)flatMap:(id<AppSingle>)receiver mapper_:(id<AppSingle> (^)(id _Nullable))mapper __attribute__((swift_name("flatMap(_:mapper_:)")));
+ (id<AppSingle>)flatMap:(id<AppSingle>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper resultSelector_:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMap(_:mapper:resultSelector_:)")));
+ (id<AppObservable>)flatMap:(id<AppObservable>)receiver mapper__:(id<AppObservable> (^)(id _Nullable))mapper __attribute__((swift_name("flatMap(_:mapper__:)")));
+ (id<AppObservable>)flatMap:(id<AppObservable>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper resultSelector__:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMap(_:mapper:resultSelector__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlatMapCompletableKt")))
@interface AppFlatMapCompletableKt : AppBase
+ (id<AppCompletable>)flatMapCompletable:(id<AppMaybe>)receiver mapper:(id<AppCompletable> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapCompletable(_:mapper:)")));
+ (id<AppCompletable>)flatMapCompletable:(id<AppSingle>)receiver mapper_:(id<AppCompletable> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapCompletable(_:mapper_:)")));
+ (id<AppCompletable>)flatMapCompletable:(id<AppObservable>)receiver mapper__:(id<AppCompletable> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapCompletable(_:mapper__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlatMapIterableKt")))
@interface AppFlatMapIterableKt : AppBase
+ (id<AppObservable>)flatMapIterable:(id<AppMaybe>)receiver transformer:(id (^)(id _Nullable))transformer __attribute__((swift_name("flatMapIterable(_:transformer:)")));
+ (id<AppObservable>)flatMapIterable:(id<AppSingle>)receiver transformer_:(id (^)(id _Nullable))transformer __attribute__((swift_name("flatMapIterable(_:transformer_:)")));
+ (id<AppObservable>)flatMapIterable:(id<AppObservable>)receiver transformer__:(id (^)(id _Nullable))transformer __attribute__((swift_name("flatMapIterable(_:transformer__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlatMapObservableKt")))
@interface AppFlatMapObservableKt : AppBase
+ (id<AppObservable>)flatMapObservable:(id<AppMaybe>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapObservable(_:mapper:)")));
+ (id<AppObservable>)flatMapObservable:(id<AppMaybe>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMapObservable(_:mapper:resultSelector:)")));
+ (id<AppObservable>)flatMapObservable:(id<AppSingle>)receiver mapper_:(id<AppObservable> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapObservable(_:mapper_:)")));
+ (id<AppObservable>)flatMapObservable:(id<AppSingle>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper resultSelector_:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMapObservable(_:mapper:resultSelector_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlatMapSingleKt")))
@interface AppFlatMapSingleKt : AppBase
+ (id<AppMaybe>)flatMapSingle:(id<AppMaybe>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapSingle(_:mapper:)")));
+ (id<AppMaybe>)flatMapSingle:(id<AppMaybe>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMapSingle(_:mapper:resultSelector:)")));
+ (id<AppObservable>)flatMapSingle:(id<AppObservable>)receiver mapper_:(id<AppSingle> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapSingle(_:mapper_:)")));
+ (id<AppObservable>)flatMapSingle:(id<AppObservable>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper resultSelector_:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMapSingle(_:mapper:resultSelector_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlattenKt")))
@interface AppFlattenKt : AppBase
+ (id<AppObservable>)flatten:(id<AppMaybe>)receiver __attribute__((swift_name("flatten(_:)")));
+ (id<AppObservable>)flatten_:(id<AppMaybe>)receiver __attribute__((swift_name("flatten(__:)")));
+ (id<AppObservable>)flatten__:(id<AppSingle>)receiver __attribute__((swift_name("flatten(___:)")));
+ (id<AppObservable>)flatten___:(id<AppSingle>)receiver __attribute__((swift_name("flatten(____:)")));
+ (id<AppObservable>)flatten____:(id<AppObservable>)receiver __attribute__((swift_name("flatten(_____:)")));
+ (id<AppObservable>)flatten_____:(id<AppObservable>)receiver __attribute__((swift_name("flatten(______:)")));
+ (id<AppObservable>)flatten______:(id<AppObservable>)receiver __attribute__((swift_name("flatten(_______:)")));
+ (id<AppObservable>)flatten_______:(id<AppObservable>)receiver __attribute__((swift_name("flatten(________:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MapKt")))
@interface AppMapKt : AppBase
+ (id<AppMaybe>)map:(id<AppMaybe>)receiver mapper:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("map(_:mapper:)")));
+ (id<AppSingle>)map:(id<AppSingle>)receiver mapper_:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("map(_:mapper_:)")));
+ (id<AppObservable>)map:(id<AppObservable>)receiver mapper__:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("map(_:mapper__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MapIterableKt")))
@interface AppMapIterableKt : AppBase
+ (id<AppMaybe>)mapIterable:(id<AppMaybe>)receiver mapper:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapIterable(_:mapper:)")));
+ (id<AppMaybe>)mapIterableTo:(id<AppMaybe>)receiver collectionSupplier:(id (^)(void))collectionSupplier mapper:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapIterableTo(_:collectionSupplier:mapper:)")));
+ (id<AppSingle>)mapIterable:(id<AppSingle>)receiver mapper_:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapIterable(_:mapper_:)")));
+ (id<AppSingle>)mapIterableTo:(id<AppSingle>)receiver collectionSupplier:(id (^)(void))collectionSupplier mapper_:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapIterableTo(_:collectionSupplier:mapper_:)")));
+ (id<AppObservable>)mapIterable:(id<AppObservable>)receiver mapper__:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapIterable(_:mapper__:)")));
+ (id<AppObservable>)mapIterableTo:(id<AppObservable>)receiver collectionSupplier:(id (^)(void))collectionSupplier mapper__:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapIterableTo(_:collectionSupplier:mapper__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MapNotNullKt")))
@interface AppMapNotNullKt : AppBase
+ (id<AppMaybe>)mapNotNull:(id<AppMaybe>)receiver mapper:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapNotNull(_:mapper:)")));
+ (id<AppMaybe>)mapNotNull:(id<AppSingle>)receiver mapper_:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapNotNull(_:mapper_:)")));
+ (id<AppObservable>)mapNotNull:(id<AppObservable>)receiver mapper__:(id _Nullable (^)(id _Nullable))mapper __attribute__((swift_name("mapNotNull(_:mapper__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NotNullKt")))
@interface AppNotNullKt : AppBase
+ (id<AppMaybe>)notNull:(id<AppMaybe>)receiver __attribute__((swift_name("notNull(_:)")));
+ (id<AppMaybe>)notNull_:(id<AppSingle>)receiver __attribute__((swift_name("notNull(__:)")));
+ (id<AppObservable>)notNull__:(id<AppObservable>)receiver __attribute__((swift_name("notNull(___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OfTypeKt")))
@interface AppOfTypeKt : AppBase
+ (id<AppMaybe>)ofType:(id<AppMaybe>)receiver __attribute__((swift_name("ofType(_:)")));
+ (id<AppMaybe>)ofType_:(id<AppSingle>)receiver __attribute__((swift_name("ofType(__:)")));
+ (id<AppObservable>)ofType__:(id<AppObservable>)receiver __attribute__((swift_name("ofType(___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OnErrorReturnKt")))
@interface AppOnErrorReturnKt : AppBase
+ (id<AppMaybe>)onErrorReturn:(id<AppMaybe>)receiver valueSupplier:(id _Nullable (^)(AppKotlinThrowable *))valueSupplier __attribute__((swift_name("onErrorReturn(_:valueSupplier:)")));
+ (id<AppMaybe>)onErrorReturnValue:(id<AppMaybe>)receiver value:(id _Nullable)value __attribute__((swift_name("onErrorReturnValue(_:value:)")));
+ (id<AppSingle>)onErrorReturn:(id<AppSingle>)receiver valueSupplier_:(id _Nullable (^)(AppKotlinThrowable *))valueSupplier __attribute__((swift_name("onErrorReturn(_:valueSupplier_:)")));
+ (id<AppSingle>)onErrorReturnValue:(id<AppSingle>)receiver value_:(id _Nullable)value __attribute__((swift_name("onErrorReturnValue(_:value_:)")));
+ (id<AppObservable>)onErrorReturn:(id<AppObservable>)receiver valueSupplier__:(id _Nullable (^)(AppKotlinThrowable *))valueSupplier __attribute__((swift_name("onErrorReturn(_:valueSupplier__:)")));
+ (id<AppObservable>)onErrorReturnValue:(id<AppObservable>)receiver value__:(id _Nullable)value __attribute__((swift_name("onErrorReturnValue(_:value__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SwitchIfEmptyKt")))
@interface AppSwitchIfEmptyKt : AppBase
+ (id<AppMaybe>)switchIfEmpty:(id<AppMaybe>)receiver other:(id<AppMaybe>)other __attribute__((swift_name("switchIfEmpty(_:other:)")));
+ (id<AppSingle>)switchIfEmpty:(id<AppMaybe>)receiver other_:(id<AppSingle>)other __attribute__((swift_name("switchIfEmpty(_:other_:)")));
+ (id<AppObservable>)switchIfEmpty:(id<AppObservable>)receiver otherObservable:(id<AppObservable> (^)(void))otherObservable __attribute__((swift_name("switchIfEmpty(_:otherObservable:)")));
+ (id<AppObservable>)switchIfEmpty:(id<AppObservable>)receiver otherObservable_:(id<AppObservable>)otherObservable __attribute__((swift_name("switchIfEmpty(_:otherObservable_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MaybeWrapperKt")))
@interface AppMaybeWrapperKt : AppBase
+ (AppMaybeWrapper<id> *)wrap_:(id<AppMaybe>)receiver __attribute__((swift_name("wrap(__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZipWithKt")))
@interface AppZipWithKt : AppBase
+ (id<AppMaybe>)zipWith:(id<AppMaybe>)receiver other:(id<AppMaybe>)other mapper:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("zipWith(_:other:mapper:)")));
+ (id<AppSingle>)zipWith:(id<AppSingle>)receiver other:(id<AppSingle>)other mapper_:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("zipWith(_:other:mapper_:)")));
+ (id<AppObservable>)zipWith:(id<AppObservable>)receiver other:(id<AppObservable>)other mapper__:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("zipWith(_:other:mapper__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SingleByEmitterKt")))
@interface AppSingleByEmitterKt : AppBase
+ (id<AppSingle>)singleOnSubscribe:(void (^)(id<AppSingleEmitter>))onSubscribe __attribute__((swift_name("single(onSubscribe:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlatMapMaybeKt")))
@interface AppFlatMapMaybeKt : AppBase
+ (id<AppMaybe>)flatMapMaybe:(id<AppSingle>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapMaybe(_:mapper:)")));
+ (id<AppMaybe>)flatMapMaybe:(id<AppSingle>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMapMaybe(_:mapper:resultSelector:)")));
+ (id<AppObservable>)flatMapMaybe:(id<AppObservable>)receiver mapper_:(id<AppMaybe> (^)(id _Nullable))mapper __attribute__((swift_name("flatMapMaybe(_:mapper_:)")));
+ (id<AppObservable>)flatMapMaybe:(id<AppObservable>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper resultSelector_:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("flatMapMaybe(_:mapper:resultSelector_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SingleWrapperKt")))
@interface AppSingleWrapperKt : AppBase
+ (AppSingleWrapper<id> *)wrap__:(id<AppSingle>)receiver __attribute__((swift_name("wrap(___:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DisposableExtKt")))
@interface AppDisposableExtKt : AppBase
+ (id<AppDisposable>)addTo:(id<AppDisposable>)receiver compositeDisposable:(AppCompositeDisposable *)compositeDisposable __attribute__((swift_name("addTo(_:compositeDisposable:)")));
+ (id<AppDisposable>)setTo:(id<AppDisposable>)receiver disposableWrapper:(AppDisposableWrapper *)disposableWrapper __attribute__((swift_name("setTo(_:disposableWrapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DisposableScopeBuilderKt")))
@interface AppDisposableScopeBuilderKt : AppBase
+ (id<AppDisposableScope>)DisposableScope __attribute__((swift_name("DisposableScope()")));
+ (id<AppDisposableScope>)disposableScopeBlock:(void (^)(id<AppDisposableScope>))block __attribute__((swift_name("disposableScope(block:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DisposableScopeExtKt")))
@interface AppDisposableScopeExtKt : AppBase
+ (void)doOnDispose:(id<AppDisposableScope>)receiver block:(void (^)(void))block __attribute__((swift_name("doOnDispose(_:block:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UncaughtErrorHandlerKt")))
@interface AppUncaughtErrorHandlerKt : AppBase
+ (void)resetReaktiveUncaughtErrorHandler __attribute__((swift_name("resetReaktiveUncaughtErrorHandler()")));
@property (class) void (^reaktiveUncaughtErrorHandler)(AppKotlinThrowable *) __attribute__((swift_name("reaktiveUncaughtErrorHandler")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HandleSourceErrorKt")))
@interface AppHandleSourceErrorKt : AppBase
+ (void)handleReaktiveErrorError:(AppKotlinThrowable *)error onError:(void (^ _Nullable)(AppKotlinThrowable *))onError __attribute__((swift_name("handleReaktiveError(error:onError:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CombineLatestKt")))
@interface AppCombineLatestKt : AppBase
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 mapper:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:source5:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:source5:source6:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:source5:source6:source7:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 source8:(id<AppObservable>)source8 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:source5:source6:source7:source8:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 source8:(id<AppObservable>)source8 source9:(id<AppObservable>)source9 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:source5:source6:source7:source8:source9:mapper:)")));
+ (id<AppObservable>)combineLatestSource1:(id<AppObservable>)source1 source2:(id<AppObservable>)source2 source3:(id<AppObservable>)source3 source4:(id<AppObservable>)source4 source5:(id<AppObservable>)source5 source6:(id<AppObservable>)source6 source7:(id<AppObservable>)source7 source8:(id<AppObservable>)source8 source9:(id<AppObservable>)source9 source10:(id<AppObservable>)source10 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("combineLatest(source1:source2:source3:source4:source5:source6:source7:source8:source9:source10:mapper:)")));
+ (id<AppObservable>)combineLatestSources:(AppKotlinArray<id<AppObservable>> *)sources mapper:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("combineLatest(sources:mapper:)")));
+ (id<AppObservable>)combineLatest:(id)receiver mapper:(id _Nullable (^)(NSArray<id> *))mapper __attribute__((swift_name("combineLatest(_:mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObservableByEmitterKt")))
@interface AppObservableByEmitterKt : AppBase
+ (id<AppObservable>)observableOnSubscribe:(void (^)(id<AppObservableEmitter>))onSubscribe __attribute__((swift_name("observable(onSubscribe:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IntervalKt")))
@interface AppIntervalKt : AppBase
+ (id<AppObservable>)observableIntervalPeriodMillis:(int64_t)periodMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("observableInterval(periodMillis:scheduler:)")));
+ (id<AppObservable>)observableIntervalStartDelayMillis:(int64_t)startDelayMillis periodMillis:(int64_t)periodMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("observableInterval(startDelayMillis:periodMillis:scheduler:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AutoConnectKt")))
@interface AppAutoConnectKt : AppBase
+ (id<AppObservable>)autoConnect:(id<AppConnectableObservable>)receiver subscriberCount:(int32_t)subscriberCount __attribute__((swift_name("autoConnect(_:subscriberCount:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BufferCountSkipKt")))
@interface AppBufferCountSkipKt : AppBase
+ (id<AppObservable>)buffer:(id<AppObservable>)receiver count:(int32_t)count skip:(int32_t)skip __attribute__((swift_name("buffer(_:count:skip:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CollectKt")))
@interface AppCollectKt : AppBase
+ (id<AppSingle>)collect:(id<AppObservable>)receiver initialCollection:(id _Nullable)initialCollection accumulator:(id _Nullable (^)(id _Nullable, id _Nullable))accumulator __attribute__((swift_name("collect(_:initialCollection:accumulator:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcatMapKt")))
@interface AppConcatMapKt : AppBase
+ (id<AppObservable>)concatMap:(id<AppObservable>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper __attribute__((swift_name("concatMap(_:mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcatMapMaybeKt")))
@interface AppConcatMapMaybeKt : AppBase
+ (id<AppObservable>)concatMapMaybe:(id<AppObservable>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper __attribute__((swift_name("concatMapMaybe(_:mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcatMapSingleKt")))
@interface AppConcatMapSingleKt : AppBase
+ (id<AppObservable>)concatMapSingle:(id<AppObservable>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper __attribute__((swift_name("concatMapSingle(_:mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConcatWithKt")))
@interface AppConcatWithKt : AppBase
+ (id<AppObservable>)concatWith:(id<AppObservable>)receiver other:(id<AppObservable>)other __attribute__((swift_name("concatWith(_:other:)")));
+ (id<AppObservable>)concatWithValue:(id<AppObservable>)receiver value:(id _Nullable)value __attribute__((swift_name("concatWithValue(_:value:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DebounceWithSelectorKt")))
@interface AppDebounceWithSelectorKt : AppBase
+ (id<AppObservable>)debounce:(id<AppObservable>)receiver debounceSelector:(id<AppCompletable> (^)(id _Nullable))debounceSelector __attribute__((swift_name("debounce(_:debounceSelector:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DebounceKt")))
@interface AppDebounceKt : AppBase
+ (id<AppObservable>)debounce:(id<AppObservable>)receiver timeoutMillis:(int64_t)timeoutMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("debounce(_:timeoutMillis:scheduler:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DistinctUntilChangedKt")))
@interface AppDistinctUntilChangedKt : AppBase
+ (id<AppObservable>)distinctUntilChanged:(id<AppObservable>)receiver keySelector:(id _Nullable (^)(id _Nullable))keySelector comparator:(AppBoolean *(^)(id _Nullable, id _Nullable))comparator __attribute__((swift_name("distinctUntilChanged(_:keySelector:comparator:)")));
+ (id<AppObservable>)distinctUntilChanged:(id<AppObservable>)receiver comparator:(AppBoolean *(^)(id _Nullable, id _Nullable))comparator __attribute__((swift_name("distinctUntilChanged(_:comparator:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirstOrCompleteKt")))
@interface AppFirstOrCompleteKt : AppBase
+ (id<AppMaybe>)firstOrComplete:(id<AppObservable>)receiver __attribute__((swift_name("firstOrComplete(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirstOrDefaultKt")))
@interface AppFirstOrDefaultKt : AppBase
+ (id<AppSingle>)firstOrDefault:(id<AppObservable>)receiver defaultValueSupplier:(id _Nullable (^)(void))defaultValueSupplier __attribute__((swift_name("firstOrDefault(_:defaultValueSupplier:)")));
+ (id<AppSingle>)firstOrDefault:(id<AppObservable>)receiver defaultValue:(id _Nullable)defaultValue __attribute__((swift_name("firstOrDefault(_:defaultValue:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirstOrErrorKt")))
@interface AppFirstOrErrorKt : AppBase
+ (id<AppSingle>)firstOrError:(id<AppObservable>)receiver errorSupplier:(AppKotlinThrowable *(^)(void))errorSupplier __attribute__((swift_name("firstOrError(_:errorSupplier:)")));
+ (id<AppSingle>)firstOrError:(id<AppObservable>)receiver error:(AppKotlinThrowable *)error __attribute__((swift_name("firstOrError(_:error:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PublishKt")))
@interface AppPublishKt : AppBase
+ (id<AppConnectableObservable>)publish:(id<AppObservable>)receiver __attribute__((swift_name("publish(_:)")));
+ (id<AppObservable>)publish:(id<AppObservable>)receiver selector:(id<AppObservable> (^)(id<AppObservable>))selector __attribute__((swift_name("publish(_:selector:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReduceKt")))
@interface AppReduceKt : AppBase
+ (id<AppMaybe>)reduce:(id<AppObservable>)receiver reducer:(id _Nullable (^)(id _Nullable, id _Nullable))reducer __attribute__((swift_name("reduce(_:reducer:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RefCountKt")))
@interface AppRefCountKt : AppBase
+ (id<AppObservable>)refCount:(id<AppConnectableObservable>)receiver subscriberCount:(int32_t)subscriberCount __attribute__((swift_name("refCount(_:subscriberCount:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReplayKt")))
@interface AppReplayKt : AppBase
+ (id<AppConnectableObservable>)replay:(id<AppObservable>)receiver __attribute__((swift_name("replay(_:)")));
+ (id<AppConnectableObservable>)replay:(id<AppObservable>)receiver bufferSize:(int32_t)bufferSize __attribute__((swift_name("replay(_:bufferSize:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SampleKt")))
@interface AppSampleKt : AppBase
+ (id<AppObservable>)sample:(id<AppObservable>)receiver windowMillis:(int64_t)windowMillis scheduler:(id<AppScheduler>)scheduler __attribute__((swift_name("sample(_:windowMillis:scheduler:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScanKt")))
@interface AppScanKt : AppBase
+ (id<AppObservable>)scan:(id<AppObservable>)receiver getSeed:(id _Nullable (^)(void))getSeed accumulate:(id _Nullable (^)(id _Nullable, id _Nullable))accumulate __attribute__((swift_name("scan(_:getSeed:accumulate:)")));
+ (id<AppObservable>)scan:(id<AppObservable>)receiver accumulate:(id _Nullable (^)(id _Nullable, id _Nullable))accumulate __attribute__((swift_name("scan(_:accumulate:)")));
+ (id<AppObservable>)scan:(id<AppObservable>)receiver seed:(id _Nullable)seed accumulator:(id _Nullable (^)(id _Nullable, id _Nullable))accumulator __attribute__((swift_name("scan(_:seed:accumulator:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObservableEmitterSerializeKt")))
@interface AppObservableEmitterSerializeKt : AppBase
+ (id<AppObservableEmitter>)serialize_:(id<AppObservableEmitter>)receiver __attribute__((swift_name("serialize(__:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShareKt")))
@interface AppShareKt : AppBase
+ (id<AppObservable>)share:(id<AppObservable>)receiver __attribute__((swift_name("share(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkipKt")))
@interface AppSkipKt : AppBase
+ (id<AppObservable>)skip:(id<AppObservable>)receiver count:(int64_t)count __attribute__((swift_name("skip(_:count:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StartWithKt")))
@interface AppStartWithKt : AppBase
+ (id<AppObservable>)startWith:(id<AppObservable>)receiver other:(id<AppObservable>)other __attribute__((swift_name("startWith(_:other:)")));
+ (id<AppObservable>)startWithValue:(id<AppObservable>)receiver value:(id _Nullable)value __attribute__((swift_name("startWithValue(_:value:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SwitchMapKt")))
@interface AppSwitchMapKt : AppBase
+ (id<AppObservable>)switchMap:(id<AppObservable>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper __attribute__((swift_name("switchMap(_:mapper:)")));
+ (id<AppObservable>)switchMap:(id<AppObservable>)receiver mapper:(id<AppObservable> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("switchMap(_:mapper:resultSelector:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SwitchMapCompletableKt")))
@interface AppSwitchMapCompletableKt : AppBase
+ (id<AppCompletable>)switchMapCompletable:(id<AppObservable>)receiver mapper:(id<AppCompletable> (^)(id _Nullable))mapper __attribute__((swift_name("switchMapCompletable(_:mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SwitchMapMaybeKt")))
@interface AppSwitchMapMaybeKt : AppBase
+ (id<AppObservable>)switchMapMaybe:(id<AppObservable>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper __attribute__((swift_name("switchMapMaybe(_:mapper:)")));
+ (id<AppObservable>)switchMapMaybe:(id<AppObservable>)receiver mapper:(id<AppMaybe> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("switchMapMaybe(_:mapper:resultSelector:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SwitchMapSingleKt")))
@interface AppSwitchMapSingleKt : AppBase
+ (id<AppObservable>)switchMapSingle:(id<AppObservable>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper __attribute__((swift_name("switchMapSingle(_:mapper:)")));
+ (id<AppObservable>)switchMapSingle:(id<AppObservable>)receiver mapper:(id<AppSingle> (^)(id _Nullable))mapper resultSelector:(id _Nullable (^)(id _Nullable, id _Nullable))resultSelector __attribute__((swift_name("switchMapSingle(_:mapper:resultSelector:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TakeObservableKt")))
@interface AppTakeObservableKt : AppBase
+ (id<AppObservable>)take:(id<AppObservable>)receiver limit:(int32_t)limit __attribute__((swift_name("take(_:limit:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TakeUntilPredicateKt")))
@interface AppTakeUntilPredicateKt : AppBase
+ (id<AppObservable>)takeUntil:(id<AppObservable>)receiver predicate:(AppBoolean *(^)(id _Nullable))predicate __attribute__((swift_name("takeUntil(_:predicate:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TakeUntilObservableKt")))
@interface AppTakeUntilObservableKt : AppBase
+ (id<AppObservable>)takeUntil:(id<AppObservable>)receiver other:(id<AppObservable>)other __attribute__((swift_name("takeUntil(_:other:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TakeWhilePredicateKt")))
@interface AppTakeWhilePredicateKt : AppBase
+ (id<AppObservable>)takeWhile:(id<AppObservable>)receiver predicate:(AppBoolean *(^)(id _Nullable))predicate __attribute__((swift_name("takeWhile(_:predicate:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThrottleKt")))
@interface AppThrottleKt : AppBase
+ (id<AppObservable>)throttle:(id<AppObservable>)receiver windowMillis:(int64_t)windowMillis __attribute__((swift_name("throttle(_:windowMillis:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ToListKt")))
@interface AppToListKt : AppBase
+ (id<AppSingle>)toList:(id<AppObservable>)receiver __attribute__((swift_name("toList(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ToMapKt")))
@interface AppToMapKt : AppBase
+ (id<AppSingle>)toMap:(id<AppObservable>)receiver keySelector:(id _Nullable (^)(id _Nullable))keySelector __attribute__((swift_name("toMap(_:keySelector:)")));
+ (id<AppSingle>)toMap:(id<AppObservable>)receiver keySelector:(id _Nullable (^)(id _Nullable))keySelector valueSelector:(id _Nullable (^)(id _Nullable))valueSelector __attribute__((swift_name("toMap(_:keySelector:valueSelector:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WithLatestFromKt")))
@interface AppWithLatestFromKt : AppBase
+ (id<AppObservable>)withLatestFrom:(id<AppObservable>)receiver other1:(id<AppObservable>)other1 other2:(id<AppObservable>)other2 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("withLatestFrom(_:other1:other2:mapper:)")));
+ (id<AppObservable>)withLatestFrom:(id<AppObservable>)receiver other1:(id<AppObservable>)other1 other2:(id<AppObservable>)other2 other3:(id<AppObservable>)other3 mapper:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))mapper __attribute__((swift_name("withLatestFrom(_:other1:other2:other3:mapper:)")));
+ (id<AppObservable>)withLatestFrom:(id<AppObservable>)receiver other:(id<AppObservable>)other mapper:(id _Nullable (^)(id _Nullable, id _Nullable))mapper __attribute__((swift_name("withLatestFrom(_:other:mapper:)")));
+ (id<AppObservable>)withLatestFrom:(id<AppObservable>)receiver others:(id)others mapper:(id _Nullable (^)(id _Nullable, NSArray<id> *))mapper __attribute__((swift_name("withLatestFrom(_:others:mapper:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObservableWrapperKt")))
@interface AppObservableWrapperKt : AppBase
+ (AppObservableWrapper<id> *)wrap___:(id<AppObservable>)receiver __attribute__((swift_name("wrap(____:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConstantsKt")))
@interface AppConstantsKt : AppBase
@property (class, readonly) int64_t MICROS_IN_MILLI __attribute__((swift_name("MICROS_IN_MILLI")));
@property (class, readonly) int64_t MICROS_IN_SECOND __attribute__((swift_name("MICROS_IN_SECOND")));
@property (class, readonly) int64_t MILLIS_IN_SECOND __attribute__((swift_name("MILLIS_IN_SECOND")));
@property (class, readonly) int64_t NANOS_IN_MICRO __attribute__((swift_name("NANOS_IN_MICRO")));
@property (class, readonly) int64_t NANOS_IN_MILLI __attribute__((swift_name("NANOS_IN_MILLI")));
@property (class, readonly) int64_t NANOS_IN_SECOND __attribute__((swift_name("NANOS_IN_SECOND")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreezeKt")))
@interface AppFreezeKt : AppBase
+ (BOOL)isFrozen:(id _Nullable)receiver __attribute__((swift_name("isFrozen(_:)")));
+ (id)ensureNeverFrozen:(id)receiver __attribute__((swift_name("ensureNeverFrozen(_:)")));
+ (id _Nullable)freeze:(id _Nullable)receiver __attribute__((swift_name("freeze(_:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConditionExtKt")))
@interface AppConditionExtKt : AppBase
+ (id _Nullable)use:(id<AppCondition>)receiver block:(id _Nullable (^)(id<AppCondition>))block __attribute__((swift_name("use(_:block:)")));
+ (BOOL)waitFor:(id<AppCondition>)receiver timeoutNanos:(int64_t)timeoutNanos predicate:(AppBoolean *(^)(void))predicate __attribute__((swift_name("waitFor(_:timeoutNanos:predicate:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StateKt")))
@interface AppStateKt : AppBase
@property (class, readonly) AppMoviesState *defaultMoviesState __attribute__((swift_name("defaultMoviesState")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelectorsKt_")))
@interface AppSelectorsKt_ : AppBase
@property (class, readonly) AppSelector<AppFracturedState *, AppBoolean *> *isMovieAddedSelector __attribute__((swift_name("isMovieAddedSelector")));
@property (class, readonly) AppSelector<AppFracturedState *, NSArray<AppMovie *> *> *moviesSelector __attribute__((swift_name("moviesSelector")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DIKt")))
@interface AppDIKt : AppBase
@property (class, readonly) id<AppKodein_di_coreKodein> kodein __attribute__((swift_name("kodein")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EffectsKt_")))
@interface AppEffectsKt_ : AppBase
@property (class, readonly) AppEffectFn<AppMovieActionsMovieAdded *> *movieAddEffect __attribute__((swift_name("movieAddEffect")));
@property (class, readonly) AppEffects *movieEffects __attribute__((swift_name("movieEffects")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReducersKt_")))
@interface AppReducersKt_ : AppBase
@property (class, readonly) AppReducer<AppMoviesState *> *movieReducer __attribute__((swift_name("movieReducer")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StoreKt_")))
@interface AppStoreKt_ : AppBase
+ (AppStore<AppFracturedState *> *)appGlobalStore __attribute__((swift_name("appGlobalStore()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BindKodeinKt")))
@interface AppBindKodeinKt : AppBase
+ (void)bindKodein:(id<AppKodein_di_coreKodeinMainBuilder>)receiver __attribute__((swift_name("bindKodein(_:)")));
@end;

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol AppKotlinKDeclarationContainer
@required
@end;

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol AppKotlinKAnnotatedElement
@required
@end;

__attribute__((swift_name("KotlinKClassifier")))
@protocol AppKotlinKClassifier
@required
@end;

__attribute__((swift_name("KotlinKClass")))
@protocol AppKotlinKClass <AppKotlinKDeclarationContainer, AppKotlinKAnnotatedElement, AppKotlinKClassifier>
@required
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface AppKotlinArray<T> : AppBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(AppInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<AppKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface AppKotlinPair<__covariant A, __covariant B> : AppBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (A _Nullable)component1 __attribute__((swift_name("component1()")));
- (B _Nullable)component2 __attribute__((swift_name("component2()")));
- (AppKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinTriple")))
@interface AppKotlinTriple<__covariant A, __covariant B, __covariant C> : AppBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second third:(C _Nullable)third __attribute__((swift_name("init(first:second:third:)"))) __attribute__((objc_designated_initializer));
- (A _Nullable)component1 __attribute__((swift_name("component1()")));
- (B _Nullable)component2 __attribute__((swift_name("component2()")));
- (C _Nullable)component3 __attribute__((swift_name("component3()")));
- (AppKotlinTriple<A, B, C> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second third:(C _Nullable)third __attribute__((swift_name("doCopy(first:second:third:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@property (readonly) C _Nullable third __attribute__((swift_name("third")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface AppKotlinUnit : AppBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinAware")))
@protocol AppKodein_di_coreKodeinAware
@required
@property (readonly) id<AppKodein_di_coreKodein> kodein __attribute__((swift_name("kodein")));
@property (readonly) id<AppKodein_di_coreKodeinContext> kodeinContext __attribute__((swift_name("kodeinContext")));
@property (readonly) AppKodein_di_coreKodeinTrigger * _Nullable kodeinTrigger __attribute__((swift_name("kodeinTrigger")));
@end;

__attribute__((swift_name("Kodein_di_coreKodein")))
@protocol AppKodein_di_coreKodein <AppKodein_di_coreKodeinAware>
@required
@property (readonly) id<AppKodein_di_coreKodeinContainer> container __attribute__((swift_name("container")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBindBuilder")))
@protocol AppKodein_di_coreKodeinBindBuilder
@required
@property (readonly) id<AppKodein_di_coreTypeToken> contextType __attribute__((swift_name("contextType")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBindBuilderWithContext")))
@protocol AppKodein_di_coreKodeinBindBuilderWithContext <AppKodein_di_coreKodeinBindBuilder>
@required
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBindBuilderWithScope")))
@protocol AppKodein_di_coreKodeinBindBuilderWithScope <AppKodein_di_coreKodeinBindBuilder>
@required
@property (readonly) id<AppKodein_di_coreScope> scope __attribute__((swift_name("scope")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBuilder")))
@protocol AppKodein_di_coreKodeinBuilder <AppKodein_di_coreKodeinBindBuilderWithContext, AppKodein_di_coreKodeinBindBuilderWithScope>
@required
- (id<AppKodein_di_coreKodeinBuilderDirectBinder>)BindTag:(id _Nullable)tag overrides:(AppBoolean * _Nullable)overrides __attribute__((swift_name("Bind(tag:overrides:)")));
- (id<AppKodein_di_coreKodeinBuilderTypeBinder>)BindType:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag overrides:(AppBoolean * _Nullable)overrides __attribute__((swift_name("Bind(type:tag:overrides:)")));
- (void)RegisterContextTranslatorTranslator:(id<AppKodein_di_coreContextTranslator>)translator __attribute__((swift_name("RegisterContextTranslator(translator:)")));
- (id<AppKodein_di_coreKodeinBuilderConstantBinder>)constantTag:(id)tag overrides:(AppBoolean * _Nullable)overrides __attribute__((swift_name("constant(tag:overrides:)")));
- (void)importModule:(AppKodein_di_coreKodeinModule *)module allowOverride:(BOOL)allowOverride __attribute__((swift_name("import(module:allowOverride:)")));
- (void)importAllModules:(AppKotlinArray<AppKodein_di_coreKodeinModule *> *)modules allowOverride:(BOOL)allowOverride __attribute__((swift_name("importAll(modules:allowOverride:)")));
- (void)importAllModules:(id)modules allowOverride_:(BOOL)allowOverride __attribute__((swift_name("importAll(modules:allowOverride_:)")));
- (void)importOnceModule:(AppKodein_di_coreKodeinModule *)module allowOverride:(BOOL)allowOverride __attribute__((swift_name("importOnce(module:allowOverride:)")));
- (void)onReadyCb:(void (^)(id<AppKodein_di_coreDKodein>))cb __attribute__((swift_name("onReady(cb:)")));
@property (readonly) id<AppKodein_di_coreKodeinContainerBuilder> containerBuilder __attribute__((swift_name("containerBuilder")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinMainBuilder")))
@protocol AppKodein_di_coreKodeinMainBuilder <AppKodein_di_coreKodeinBuilder>
@required
- (void)extendDkodein:(id<AppKodein_di_coreDKodein>)dkodein allowOverride:(BOOL)allowOverride copy:(id<AppKodein_di_coreCopy>)copy __attribute__((swift_name("extend(dkodein:allowOverride:copy:)")));
- (void)extendKodein:(id<AppKodein_di_coreKodein>)kodein allowOverride:(BOOL)allowOverride copy:(id<AppKodein_di_coreCopy>)copy __attribute__((swift_name("extend(kodein:allowOverride:copy:)")));
@property id<AppKodein_di_coreExternalSource> _Nullable externalSource __attribute__((swift_name("externalSource"))) __attribute__((deprecated("Use externalSources instead")));
@property (readonly) NSMutableArray<id<AppKodein_di_coreExternalSource>> *externalSources __attribute__((swift_name("externalSources")));
@property BOOL fullDescriptionOnError __attribute__((swift_name("fullDescriptionOnError")));
@end;

__attribute__((swift_name("KotlinIterator")))
@protocol AppKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinContainer")))
@protocol AppKodein_di_coreKodeinContainer
@required
- (NSArray<id (^)(id _Nullable)> *)allFactoriesKey:(AppKodein_di_coreKodeinKey<id, id, id> *)key context:(id _Nullable)context overrideLevel:(int32_t)overrideLevel __attribute__((swift_name("allFactories(key:context:overrideLevel:)")));
- (NSArray<id (^)(void)> *)allProvidersKey:(AppKodein_di_coreKodeinKey<id, AppKotlinUnit *, id> *)key context:(id _Nullable)context overrideLevel:(int32_t)overrideLevel __attribute__((swift_name("allProviders(key:context:overrideLevel:)")));
- (id (^)(id _Nullable))factoryKey:(AppKodein_di_coreKodeinKey<id, id, id> *)key context:(id _Nullable)context overrideLevel:(int32_t)overrideLevel __attribute__((swift_name("factory(key:context:overrideLevel:)")));
- (id (^ _Nullable)(id _Nullable))factoryOrNullKey:(AppKodein_di_coreKodeinKey<id, id, id> *)key context:(id _Nullable)context overrideLevel:(int32_t)overrideLevel __attribute__((swift_name("factoryOrNull(key:context:overrideLevel:)")));
- (id (^)(void))providerKey:(AppKodein_di_coreKodeinKey<id, AppKotlinUnit *, id> *)key context:(id _Nullable)context overrideLevel:(int32_t)overrideLevel __attribute__((swift_name("provider(key:context:overrideLevel:)")));
- (id (^ _Nullable)(void))providerOrNullKey:(AppKodein_di_coreKodeinKey<id, AppKotlinUnit *, id> *)key context:(id _Nullable)context overrideLevel:(int32_t)overrideLevel __attribute__((swift_name("providerOrNull(key:context:overrideLevel:)")));
@property (readonly) id<AppKodein_di_coreKodeinTree> tree __attribute__((swift_name("tree")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinContext")))
@protocol AppKodein_di_coreKodeinContext
@required
@property (readonly) id<AppKodein_di_coreTypeToken> type __attribute__((swift_name("type")));
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kodein_di_coreKodeinTrigger")))
@interface AppKodein_di_coreKodeinTrigger : AppBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)trigger __attribute__((swift_name("trigger()")));
@property (readonly) NSMutableArray<id<AppKotlinLazy>> *properties __attribute__((swift_name("properties")));
@end;

__attribute__((swift_name("Kodein_di_coreDKodeinAware")))
@protocol AppKodein_di_coreDKodeinAware
@required
@property (readonly) id<AppKodein_di_coreDKodein> dkodein __attribute__((swift_name("dkodein")));
@end;

__attribute__((swift_name("Kodein_di_coreDKodeinBase")))
@protocol AppKodein_di_coreDKodeinBase <AppKodein_di_coreDKodeinAware>
@required
- (id (^)(id _Nullable))FactoryArgType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("Factory(argType:type:tag:)")));
- (id (^ _Nullable)(id _Nullable))FactoryOrNullArgType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("FactoryOrNull(argType:type:tag:)")));
- (id)InstanceType:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("Instance(type:tag:)")));
- (id)InstanceArgType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag arg:(id _Nullable)arg __attribute__((swift_name("Instance(argType:type:tag:arg:)")));
- (id _Nullable)InstanceOrNullType:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("InstanceOrNull(type:tag:)")));
- (id _Nullable)InstanceOrNullArgType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag arg:(id _Nullable)arg __attribute__((swift_name("InstanceOrNull(argType:type:tag:arg:)")));
- (id<AppKodein_di_coreDKodein>)OnContext:(id<AppKodein_di_coreKodeinContext>)context __attribute__((swift_name("On(context:)")));
- (id (^)(void))ProviderType:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("Provider(type:tag:)")));
- (id (^)(void))ProviderArgType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag arg:(id _Nullable (^)(void))arg __attribute__((swift_name("Provider(argType:type:tag:arg:)")));
- (id (^ _Nullable)(void))ProviderOrNullType:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("ProviderOrNull(type:tag:)")));
- (id (^ _Nullable)(void))ProviderOrNullArgType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag arg:(id _Nullable (^)(void))arg __attribute__((swift_name("ProviderOrNull(argType:type:tag:arg:)")));
@property (readonly) id<AppKodein_di_coreKodeinContainer> container __attribute__((swift_name("container")));
@property (readonly) id<AppKodein_di_coreKodein> kodein __attribute__((swift_name("kodein")));
@property (readonly) id<AppKodein_di_coreKodein> lazy __attribute__((swift_name("lazy")));
@end;

__attribute__((swift_name("Kodein_di_coreDKodein")))
@protocol AppKodein_di_coreDKodein <AppKodein_di_coreDKodeinBase>
@required
@end;

__attribute__((swift_name("Kodein_di_coreCopy")))
@protocol AppKodein_di_coreCopy
@required
- (NSSet<AppKodein_di_coreKodeinKey<id, id, id> *> *)keySetTree:(id<AppKodein_di_coreKodeinTree>)tree __attribute__((swift_name("keySet(tree:)")));
@end;

__attribute__((swift_name("Kodein_di_coreExternalSource")))
@protocol AppKodein_di_coreExternalSource
@required
- (id (^ _Nullable)(id _Nullable))getFactoryKodein:(id<AppKodein_di_coreBindingKodein>)kodein key:(AppKodein_di_coreKodeinKey<id, id, id> *)key __attribute__((swift_name("getFactory(kodein:key:)")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBuilderDirectBinder")))
@protocol AppKodein_di_coreKodeinBuilderDirectBinder
@required
- (void)fromBinding:(id<AppKodein_di_coreKodeinBinding>)binding __attribute__((swift_name("from(binding:)")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBuilderTypeBinder")))
@protocol AppKodein_di_coreKodeinBuilderTypeBinder
@required
- (void)withBinding:(id<AppKodein_di_coreKodeinBinding>)binding __attribute__((swift_name("with(binding:)")));
@end;

__attribute__((swift_name("Kodein_di_coreTypeToken")))
@protocol AppKodein_di_coreTypeToken
@required
- (void)checkIsReifiedDisp:(id)disp __attribute__((swift_name("checkIsReified(disp:)")));
- (NSString *)fullDispString __attribute__((swift_name("fullDispString()")));
- (NSString *)fullErasedDispString __attribute__((swift_name("fullErasedDispString()")));
- (AppKotlinArray<id<AppKodein_di_coreTypeToken>> *)getGenericParameters __attribute__((swift_name("getGenericParameters()")));
- (id<AppKodein_di_coreTypeToken> _Nullable)getRaw __attribute__((swift_name("getRaw()")));
- (NSArray<id<AppKodein_di_coreTypeToken>> *)getSuper __attribute__((swift_name("getSuper()")));
- (BOOL)isAssignableFromTypeToken:(id<AppKodein_di_coreTypeToken>)typeToken __attribute__((swift_name("isAssignableFrom(typeToken:)")));
- (BOOL)isGeneric __attribute__((swift_name("isGeneric()")));
- (BOOL)isWildcard __attribute__((swift_name("isWildcard()")));
- (NSString *)simpleDispString __attribute__((swift_name("simpleDispString()")));
- (NSString *)simpleErasedDispString __attribute__((swift_name("simpleErasedDispString()")));
@end;

__attribute__((swift_name("Kodein_di_coreContextTranslator")))
@protocol AppKodein_di_coreContextTranslator
@required
- (id _Nullable)translateCtx:(id _Nullable)ctx __attribute__((swift_name("translate(ctx:)")));
@property (readonly) id<AppKodein_di_coreTypeToken> contextType __attribute__((swift_name("contextType")));
@property (readonly) id<AppKodein_di_coreTypeToken> scopeType __attribute__((swift_name("scopeType")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBuilderConstantBinder")))
@protocol AppKodein_di_coreKodeinBuilderConstantBinder
@required
- (void)WithValueType:(id<AppKodein_di_coreTypeToken>)valueType value:(id)value __attribute__((swift_name("With(valueType:value:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kodein_di_coreKodeinModule")))
@interface AppKodein_di_coreKodeinModule : AppBase
- (instancetype)initWithAllowSilentOverride:(BOOL)allowSilentOverride init:(void (^)(id<AppKodein_di_coreKodeinBuilder>))init __attribute__((swift_name("init(allowSilentOverride:init:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("You should name your modules, for debug purposes.")));
- (instancetype)initWithName:(NSString *)name allowSilentOverride:(BOOL)allowSilentOverride prefix:(NSString *)prefix init:(void (^)(id<AppKodein_di_coreKodeinBuilder>))init __attribute__((swift_name("init(name:allowSilentOverride:prefix:init:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (BOOL)component2 __attribute__((swift_name("component2()")));
- (NSString *)component3 __attribute__((swift_name("component3()")));
- (void (^)(id<AppKodein_di_coreKodeinBuilder>))component4 __attribute__((swift_name("component4()")));
- (AppKodein_di_coreKodeinModule *)doCopyName:(NSString *)name allowSilentOverride:(BOOL)allowSilentOverride prefix:(NSString *)prefix init:(void (^)(id<AppKodein_di_coreKodeinBuilder>))init __attribute__((swift_name("doCopy(name:allowSilentOverride:prefix:init:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL allowSilentOverride __attribute__((swift_name("allowSilentOverride")));
@property (readonly, getter=doInit) void (^init)(id<AppKodein_di_coreKodeinBuilder>) __attribute__((swift_name("init")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *prefix __attribute__((swift_name("prefix")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinContainerBuilder")))
@protocol AppKodein_di_coreKodeinContainerBuilder
@required
- (void)bindKey:(AppKodein_di_coreKodeinKey<id, id, id> *)key binding:(id<AppKodein_di_coreKodeinBinding>)binding fromModule:(NSString * _Nullable)fromModule overrides:(AppBoolean * _Nullable)overrides __attribute__((swift_name("bind(key:binding:fromModule:overrides:)")));
- (void)extendContainer:(id<AppKodein_di_coreKodeinContainer>)container allowOverride:(BOOL)allowOverride copy:(NSSet<AppKodein_di_coreKodeinKey<id, id, id> *> *)copy __attribute__((swift_name("extend(container:allowOverride:copy:)")));
- (void)onReadyCb:(void (^)(id<AppKodein_di_coreDKodein>))cb __attribute__((swift_name("onReady(cb:)")));
- (void)registerContextTranslatorTranslator:(id<AppKodein_di_coreContextTranslator>)translator __attribute__((swift_name("registerContextTranslator(translator:)")));
- (id<AppKodein_di_coreKodeinContainerBuilder>)subBuilderAllowOverride:(BOOL)allowOverride silentOverride:(BOOL)silentOverride __attribute__((swift_name("subBuilder(allowOverride:silentOverride:)")));
@end;

__attribute__((swift_name("Kodein_di_coreScope")))
@protocol AppKodein_di_coreScope
@required
- (AppKodein_di_coreScopeRegistry *)getRegistryContext:(id _Nullable)context __attribute__((swift_name("getRegistry(context:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kodein_di_coreKodeinKey")))
@interface AppKodein_di_coreKodeinKey<__contravariant C, __contravariant A, __covariant T> : AppBase
- (instancetype)initWithContextType:(id<AppKodein_di_coreTypeToken>)contextType argType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("init(contextType:argType:type:tag:)"))) __attribute__((objc_designated_initializer));
- (id<AppKodein_di_coreTypeToken>)component1 __attribute__((swift_name("component1()")));
- (id<AppKodein_di_coreTypeToken>)component2 __attribute__((swift_name("component2()")));
- (id<AppKodein_di_coreTypeToken>)component3 __attribute__((swift_name("component3()")));
- (id _Nullable)component4 __attribute__((swift_name("component4()")));
- (AppKodein_di_coreKodeinKey<C, A, T> *)doCopyContextType:(id<AppKodein_di_coreTypeToken>)contextType argType:(id<AppKodein_di_coreTypeToken>)argType type:(id<AppKodein_di_coreTypeToken>)type tag:(id _Nullable)tag __attribute__((swift_name("doCopy(contextType:argType:type:tag:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<AppKodein_di_coreTypeToken> argType __attribute__((swift_name("argType")));
@property (readonly) NSString *bindDescription __attribute__((swift_name("bindDescription")));
@property (readonly) NSString *bindFullDescription __attribute__((swift_name("bindFullDescription")));
@property (readonly) id<AppKodein_di_coreTypeToken> contextType __attribute__((swift_name("contextType")));
@property (readonly, getter=description_) NSString *description __attribute__((swift_name("description")));
@property (readonly) NSString *fullDescription __attribute__((swift_name("fullDescription")));
@property (readonly) NSString *internalDescription __attribute__((swift_name("internalDescription")));
@property (readonly) id _Nullable tag __attribute__((swift_name("tag")));
@property (readonly) id<AppKodein_di_coreTypeToken> type __attribute__((swift_name("type")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinTree")))
@protocol AppKodein_di_coreKodeinTree
@required
- (NSArray<AppKotlinTriple<AppKodein_di_coreKodeinKey<id, id, id> *, AppKodein_di_coreKodeinDefinition<id, id, id> *, id<AppKodein_di_coreContextTranslator>> *> *)findKey:(AppKodein_di_coreKodeinKey<id, id, id> *)key overrideLevel:(int32_t)overrideLevel all:(BOOL)all __attribute__((swift_name("find(key:overrideLevel:all:)")));
- (NSArray<AppKotlinTriple<AppKodein_di_coreKodeinKey<id, id, id> *, NSArray<AppKodein_di_coreKodeinDefinition<id, id, id> *> *, id<AppKodein_di_coreContextTranslator>> *> *)findSearch:(AppKodein_di_coreSearchSpecs *)search __attribute__((swift_name("find(search:)")));
- (AppKotlinTriple<AppKodein_di_coreKodeinKey<id, id, id> *, NSArray<AppKodein_di_coreKodeinDefinition<id, id, id> *> *, id<AppKodein_di_coreContextTranslator>> * _Nullable)getKey:(AppKodein_di_coreKodeinKey<id, id, id> *)key __attribute__((swift_name("get(key:)")));
@property (readonly) NSDictionary<AppKodein_di_coreKodeinKey<id, id, id> *, NSArray<AppKodein_di_coreKodeinDefinition<id, id, id> *> *> *bindings __attribute__((swift_name("bindings")));
@property (readonly) NSArray<id<AppKodein_di_coreExternalSource>> *externalSources __attribute__((swift_name("externalSources")));
@property (readonly) NSArray<id<AppKodein_di_coreContextTranslator>> *registeredTranslators __attribute__((swift_name("registeredTranslators")));
@end;

__attribute__((swift_name("KotlinLazy")))
@protocol AppKotlinLazy
@required
- (BOOL)isInitialized __attribute__((swift_name("isInitialized()")));
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end;

__attribute__((swift_name("Kodein_di_coreWithContext")))
@protocol AppKodein_di_coreWithContext
@required
@property (readonly) id _Nullable context __attribute__((swift_name("context")));
@end;

__attribute__((swift_name("Kodein_di_coreSimpleBindingKodein")))
@protocol AppKodein_di_coreSimpleBindingKodein <AppKodein_di_coreDKodein, AppKodein_di_coreWithContext>
@required
- (id (^)(id _Nullable))overriddenFactory __attribute__((swift_name("overriddenFactory()")));
- (id (^ _Nullable)(id _Nullable))overriddenFactoryOrNull __attribute__((swift_name("overriddenFactoryOrNull()")));
@end;

__attribute__((swift_name("Kodein_di_coreBindingKodein")))
@protocol AppKodein_di_coreBindingKodein <AppKodein_di_coreSimpleBindingKodein>
@required
@end;

__attribute__((swift_name("Kodein_di_coreBinding")))
@protocol AppKodein_di_coreBinding
@required
- (id (^)(id _Nullable))getFactoryKodein:(id<AppKodein_di_coreBindingKodein>)kodein key_:(AppKodein_di_coreKodeinKey<id, id, id> *)key __attribute__((swift_name("getFactory(kodein:key_:)")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBinding")))
@protocol AppKodein_di_coreKodeinBinding <AppKodein_di_coreBinding>
@required
- (NSString *)factoryFullName __attribute__((swift_name("factoryFullName()")));
- (NSString *)factoryName __attribute__((swift_name("factoryName()")));
@property (readonly) id<AppKodein_di_coreTypeToken> argType __attribute__((swift_name("argType")));
@property (readonly) id<AppKodein_di_coreTypeToken> contextType __attribute__((swift_name("contextType")));
@property (readonly) id<AppKodein_di_coreKodeinBindingCopier> _Nullable copier __attribute__((swift_name("copier")));
@property (readonly) id<AppKodein_di_coreTypeToken> createdType __attribute__((swift_name("createdType")));
@property (readonly, getter=description_) NSString *description __attribute__((swift_name("description")));
@property (readonly) NSString *fullDescription __attribute__((swift_name("fullDescription")));
@property (readonly) id<AppKodein_di_coreScope> _Nullable scope __attribute__((swift_name("scope")));
@property (readonly) BOOL supportSubTypes __attribute__((swift_name("supportSubTypes")));
@end;

__attribute__((swift_name("Kodein_di_coreScopeCloseable")))
@protocol AppKodein_di_coreScopeCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end;

__attribute__((swift_name("Kodein_di_coreScopeRegistry")))
@interface AppKodein_di_coreScopeRegistry : AppBase <AppKodein_di_coreScopeCloseable>
- (void)clear __attribute__((swift_name("clear()")));
- (void)close __attribute__((swift_name("close()")));
- (id)getOrCreateKey:(id)key sync:(BOOL)sync creator:(AppKodein_di_coreReference<id> *(^)(void))creator __attribute__((swift_name("getOrCreate(key:sync:creator:)")));
- (id _Nullable (^ _Nullable)(void))getOrNullKey:(id)key __attribute__((swift_name("getOrNull(key:)")));
- (void)removeKey:(id)key __attribute__((swift_name("remove(key:)")));
- (id)values __attribute__((swift_name("values()")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinDefining")))
@interface AppKodein_di_coreKodeinDefining<C, A, T> : AppBase
- (instancetype)initWithBinding:(id<AppKodein_di_coreKodeinBinding>)binding fromModule:(NSString * _Nullable)fromModule __attribute__((swift_name("init(binding:fromModule:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<AppKodein_di_coreKodeinBinding> binding __attribute__((swift_name("binding")));
@property (readonly) NSString * _Nullable fromModule __attribute__((swift_name("fromModule")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kodein_di_coreKodeinDefinition")))
@interface AppKodein_di_coreKodeinDefinition<C, A, T> : AppKodein_di_coreKodeinDefining<C, A, T>
- (instancetype)initWithBinding:(id<AppKodein_di_coreKodeinBinding>)binding fromModule:(NSString * _Nullable)fromModule tree:(id<AppKodein_di_coreKodeinTree>)tree __attribute__((swift_name("init(binding:fromModule:tree:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithBinding:(id<AppKodein_di_coreKodeinBinding>)binding fromModule:(NSString * _Nullable)fromModule __attribute__((swift_name("init(binding:fromModule:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) id<AppKodein_di_coreKodeinTree> tree __attribute__((swift_name("tree")));
@end;

__attribute__((swift_name("Kodein_di_coreSearchSpecs")))
@interface AppKodein_di_coreSearchSpecs : AppBase
- (instancetype)initWithContextType:(id<AppKodein_di_coreTypeToken> _Nullable)contextType argType:(id<AppKodein_di_coreTypeToken> _Nullable)argType type:(id<AppKodein_di_coreTypeToken> _Nullable)type tag:(id _Nullable)tag __attribute__((swift_name("init(contextType:argType:type:tag:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property id<AppKodein_di_coreTypeToken> _Nullable argType __attribute__((swift_name("argType")));
@property id<AppKodein_di_coreTypeToken> _Nullable contextType __attribute__((swift_name("contextType")));
@property id _Nullable tag __attribute__((swift_name("tag")));
@property id<AppKodein_di_coreTypeToken> _Nullable type __attribute__((swift_name("type")));
@end;

__attribute__((swift_name("Kodein_di_coreKodeinBindingCopier")))
@protocol AppKodein_di_coreKodeinBindingCopier
@required
- (id<AppKodein_di_coreKodeinBinding>)doCopyBuilder:(id<AppKodein_di_coreKodeinContainerBuilder>)builder __attribute__((swift_name("doCopy(builder:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kodein_di_coreReference")))
@interface AppKodein_di_coreReference<__covariant T> : AppBase
- (instancetype)initWithCurrent:(T)current next:(T _Nullable (^)(void))next __attribute__((swift_name("init(current:next:)"))) __attribute__((objc_designated_initializer));
- (T)component1 __attribute__((swift_name("component1()")));
- (T _Nullable (^)(void))component2 __attribute__((swift_name("component2()")));
- (AppKodein_di_coreReference<T> *)doCopyCurrent:(T)current next:(T _Nullable (^)(void))next __attribute__((swift_name("doCopy(current:next:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) T current __attribute__((swift_name("current")));
@property (readonly) T _Nullable (^next)(void) __attribute__((swift_name("next")));
@end;

#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
