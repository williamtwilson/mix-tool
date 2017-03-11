add_library(Command Command.cpp)
target_link_libraries(Command Machine)

set(COMMANDS 
    NoOperation Add
    LoadA Load1 Load2 Load3 Load4 Load5 Load6 LoadX
    LoadANegative Load1Negative Load2Negative Load3Negative Load4Negative Load5Negative Load6Negative LoadXNegative
    StoreA Store1 Store2 Store3 Store4 Store5 Store6 StoreX
    StoreJ StoreZero Jump JumpSaveJ JumpOnOverflow JumpOnNoOverflow
    EnterA IncrementA Enter1 Increment1 Enter2 Enter3 Enter4 Enter5 Enter6 EnterX)

foreach(LIB ${COMMANDS})
    add_library(${LIB} ${LIB}.cpp)
    target_link_libraries(${LIB} Command)
endforeach()

add_library(CommandStore CommandStore.cpp)
target_link_libraries(CommandStore ${Commands})

