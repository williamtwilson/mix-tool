add_library(Command Command.cpp)
target_link_libraries(Command Machine)

set(COMMANDS 
    NoOperation Add
    StoreZero Jump JumpSaveJ JumpOnOverflow JumpOnNoOverflow)


foreach(LIB ${COMMANDS})
    add_library(${LIB} ${LIB}.cpp)
    target_link_libraries(${LIB} Command)
endforeach()

add_library(CommandStore CommandStore.cpp)
target_link_libraries(CommandStore ${Commands})

