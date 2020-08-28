import com.fuzz.kedux.createSelector

val nameSelector by lazy { createSelector<GlobalState, String>(testScope) { state -> state.name } }

val namedChangedSelector by lazy { createSelector<GlobalState, Boolean>(testScope) { state -> state.nameChanged } }

val locationSelector by lazy { createSelector<GlobalState, Location?>(testScope) { state -> state.location } }

val locationIdSelector by lazy { locationSelector.compose { state -> state?.id } }

val locationProductSelector by lazy { locationSelector.compose { state -> state?.product } }

val locationProductIdSelector by lazy { locationProductSelector.compose { state -> state?.id } }
