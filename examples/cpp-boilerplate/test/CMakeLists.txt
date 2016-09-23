project(test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE TEST_SOURCES "*.cc" "*.h")
file(GLOB_RECURSE SRC_SOURCES "../src/*.cc" "../src/*.h")
add_executable(unittests ${TEST_SOURCES} ${SRC_SOURCES})

include_directories("../src")
