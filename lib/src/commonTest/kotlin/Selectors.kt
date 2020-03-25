import com.fuzz.kedux.compose
import com.fuzz.kedux.createSelector

val nameSelector = createSelector<GlobalState, String> { state -> state.name }

val locationSelector = createSelector<GlobalState, Location?> { state -> state.location }

val locationIdSelector = locationSelector.compose { state -> state?.id }

val locationProductSelector = locationSelector.compose { state -> state?.product }

val locationProductIdSelector = locationProductSelector.compose { state -> state?.id }
