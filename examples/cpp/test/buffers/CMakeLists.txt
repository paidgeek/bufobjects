project(bufobjects)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB TEST_SOURCES "*.cc" "*.h")
file(GLOB_RECURSE RPG_SOURCES "rpg/*.cc" "rpg/*.h")

add_executable(bufferstest ${TEST_SOURCES} ${RPG_SOURCES})
