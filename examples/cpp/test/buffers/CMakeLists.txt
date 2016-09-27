project(test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE TEST_SOURCES "**.cc" "**.h")
add_executable(bufferstest ${TEST_SOURCES})
