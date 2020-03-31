import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.filter
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.ofType
import com.badoo.reaktive.observable.wrap
import com.fuzz.kedux.Action
import com.fuzz.kedux.Effect
import com.fuzz.kedux.NoAction
import kotlinx.cinterop.ObjCClass
import kotlinx.cinterop.getOriginalKotlinClass

fun <T : Any> ObservableWrapper<Any>.filterInstance(kClass: ObjCClass): Observable<T> =
        filter { it::class.isInstance(getOriginalKotlinClass(kClass)) }
                .map { it as T }

/**
 * Description: Used to enclose
 */
class EffectCreator<A : Any>(private val actionKClass: ObjCClass) {

    fun <R : Any> createEffect(
            mapper: (ObservableWrapper<A>) -> Observable<R>
    ): Effect<R> =
            { actions: ObservableWrapper<Any> ->
                mapper(actions.filterInstance<A>(actionKClass).wrap()).wrap()
            }

    fun createSilentEffect(
            mapper: (ObservableWrapper<A>) -> Observable<Unit>
    ): Effect<NoAction> =
            { actions: ObservableWrapper<Any> -> mapper(actions.filterInstance<A>(actionKClass).wrap()).map { NoAction }.wrap() }

}

class ActionTypeGrouping {
    inline fun <T, P, R, RP> createActionTypeEffect(
            crossinline mapper: (ObservableWrapper<Action<T, P>>) -> Observable<Action<R, RP>>
    ): Effect<Action<R, RP>> =
            { actions: ObservableWrapper<Any> -> mapper(actions.ofType<Action<T, P>>().wrap()).wrap() }

}