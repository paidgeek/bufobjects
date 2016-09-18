project(test)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/include lib/googletest/src)

file(GLOB TEST_SOURCES "*.cc")
add_executable(unittests ${TEST_SOURCES})

target_link_libraries(unittests gtest gtest_main)
include_directories("../src")
