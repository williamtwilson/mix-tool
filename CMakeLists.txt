cmake_minimum_required(VERSION 3.7.0)
project (mix)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-Wall)

add_subdirectory(Source)

add_subdirectory(googletest)

set(SOURCES 
    Runtime 
    NoOperation
    EnterA Enter1 Enter2 Enter3 Enter4 Enter5 Enter6 EnterX
    LoadA Load1 Load2 Load3 Load4 Load5 Load6 LoadX
    StoreA Store1 Store2 Store3 Store4 Store5 Store6 StoreX)

add_executable(mix main.cpp)
target_link_libraries(mix ${SOURCES})

add_subdirectory(Tests)

