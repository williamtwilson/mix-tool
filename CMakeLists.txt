cmake_minimum_required(VERSION 3.7.0)
project (mix)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed.
Please create a directory and run cmake from there, passing the path
to this source directory as the last argument.
This process created the file `CMakeCache.txt` and the directory `CMakeFiles`.
Please delete them.")
endif()

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR})

add_definitions(-Wall)

add_subdirectory(Source)

add_subdirectory(googletest)

set(SOURCES 
    Runtime 
    NoOperation Add
    StoreJ StoreZero Jump JumpSaveJ JumpOnOverflow JumpOnNoOverflow)


add_executable(mix main.cpp)
target_link_libraries(mix ${SOURCES})

add_subdirectory(Tests)

