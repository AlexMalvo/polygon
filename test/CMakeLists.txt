cmake_minimum_required(VERSION 3.10)

set(TEST_SOURCES
        test_bfs.cpp
        test_dfs.cpp
        test_dijkstra.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} PRIVATE graph_lib)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
