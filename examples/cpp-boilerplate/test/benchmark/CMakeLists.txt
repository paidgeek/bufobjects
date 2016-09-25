project(test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(flatbuffers/include)

file(GLOB BM_SOURCES "*.cc" "*.h")
file(GLOB BM_SOURCES_GEN "gen/*.cc" "gen/*.h")
add_executable(benchmark ${BM_SOURCES} ${BM_SOURCES_GEN})
