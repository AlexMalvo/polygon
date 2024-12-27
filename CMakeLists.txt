cmake_minimum_required(VERSION 3.10)

project(Lab8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB LIB_SOURCES
        src/graph.cpp
        src/bfs.cpp
        src/dfs.cpp
        src/dijkstra.cpp
)

add_library(graph_lib STATIC ${LIB_SOURCES})

add_executable(graph_search src/main.cpp)
target_link_libraries(graph_search PRIVATE graph_lib)

enable_testing()
add_subdirectory(test)
