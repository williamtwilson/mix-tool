add_library(Sign Sign.cpp)

add_library(Word Word.cpp)
target_link_libraries(Word Sign)

add_library(Register Register.cpp)
target_link_libraries(Register Word)

add_library(Memory Memory.cpp)
target_link_libraries(Memory Word)

add_library(Machine Machine.cpp)
target_link_libraries(Machine Memory Register)

add_subdirectory(Commands)

