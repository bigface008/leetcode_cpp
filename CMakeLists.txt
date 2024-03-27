cmake_minimum_required(VERSION 3.27)
project(leetcode_cpp)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.1.1
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/fmt)
FetchContent_MakeAvailable(fmt)

include_directories("./dependencies")
include_directories("./utils")

link_libraries(fmt::fmt-header-only)

add_library(utils STATIC
        utils/leetcode_utils.hpp
        utils/list_node.cpp
        utils/list_node.h)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/utils)

link_libraries(utils)

add_executable(longest_substr leetcode/longest_substr.cpp)
