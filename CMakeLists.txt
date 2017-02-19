cmake_minimum_required(VERSION 3.7.0)
project (mix)

set(CMAKE_CXX_STANDARD 14)
file(GLOB src
    "Source/*.cpp"
    "Source/Commands/*.cpp"
)

add_executable(mix main.cpp ${src})

