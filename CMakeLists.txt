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
    LoadA Load1 Load2 Load3 Load4 Load5 Load6 LoadX
    LoadANegative Load1Negative Load2Negative Load3Negative Load4Negative Load5Negative Load6Negative LoadXNegative
    StoreA Store1 Store2 Store3 Store4 Store5 Store6 StoreX
    StoreJ StoreZero Jump JumpSaveJ JumpOnOverflow JumpOnNoOverflow
    EnterA IncrementA Enter1 Increment1 Enter2 Increment2 Enter3 Increment3 Enter4 Increment4 Enter5 Increment5 Enter6 Increment6 EnterX IncrementX)

add_executable(mix main.cpp)
target_link_libraries(mix ${SOURCES})

add_subdirectory(Tests)

