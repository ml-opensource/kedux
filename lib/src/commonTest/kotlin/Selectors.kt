import com.fuzz.kedux.createSelector
import kotlinx.coroutines.CoroutineScope

fun CoroutineScope.getNameSelector() = createSelector<GlobalState, String>(this) { state -> state.name }

fun CoroutineScope.getNamedChangedSelector() = createSelector<GlobalState, Boolean>(this) { state -> state.nameChanged }

fun CoroutineScope.getLocationSelector() = createSelector<GlobalState, Location?>(this) { state -> state.location }

fun CoroutineScope.getLocationIdSelector() = getLocationSelector().compose { state -> state?.id }

fun CoroutineScope.getLocationProductSelector() = getLocationSelector().compose { state -> state?.product }

fun CoroutineScope.getLocationProductIdSelector() = getLocationProductSelector().compose { state -> state?.id }
