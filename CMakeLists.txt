cmake_minimum_required(VERSION 3.0)

Project(TICTACTOE)
add_subdirectory(src)
SET(BUILD_TESTS OFF CACHE BOOL "Build standard units tests using Check..Remember that Check is a requirement to build this")
if(BUILD_TESTS)
enable_testing()
add_subdirectory(tests)
endif()
