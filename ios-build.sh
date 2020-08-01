./gradlew -p "./" copyFramework \
-Pconfiguration.build.dir="../podsource/debug"          \
-Pkotlin.build.type="DEBUG"                      \
-Pkotlin.target="ios"


# ./gradlew -p "./" copyFramework \
# -Pconfiguration.build.dir="../podsource/release"          \
# -Pkotlin.build.type="RELEASE"                      \
# -Pkotlin.target="ios"

