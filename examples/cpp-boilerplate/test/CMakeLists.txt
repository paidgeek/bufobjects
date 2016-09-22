project(test)

file(GLOB TEST_SOURCES "*.cc" "*.h")
add_executable(unittests ${TEST_SOURCES})

include_directories("../src")
