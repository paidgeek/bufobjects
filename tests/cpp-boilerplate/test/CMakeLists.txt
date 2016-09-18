project(test)
add_subdirectory(lib/googletest/googletest)
include_directories(lib/googletest/googletest/include lib/googletest/googletest/src)

file(GLOB TEST_SOURCES "*.cc")
add_executable(unittests ${TEST_SOURCES})

target_link_libraries(unittests gtest gtest_main)
include_directories("../src")
