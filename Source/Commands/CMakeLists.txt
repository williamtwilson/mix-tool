add_library(Command Command.cpp)
target_link_libraries(Command Machine)

add_library(NoOperation NoOperation.cpp)
target_link_libraries(NoOperation Command)


add_library(EnterA EnterA.cpp)
target_link_libraries(EnterA Command)

add_library(Enter1 Enter1.cpp)
target_link_libraries(Enter1 Command)

add_library(Enter2 Enter2.cpp)
target_link_libraries(Enter2 Command)

add_library(Enter3 Enter3.cpp)
target_link_libraries(Enter3 Command)

add_library(Enter4 Enter4.cpp)
target_link_libraries(Enter4 Command)

add_library(Enter5 Enter5.cpp)
target_link_libraries(Enter5 Command)

add_library(Enter6 Enter6.cpp)
target_link_libraries(Enter6 Command)

add_library(EnterX EnterX.cpp)
target_link_libraries(EnterX Command)


add_library(LoadA LoadA.cpp)
target_link_libraries(LoadA Command)

add_library(Load1 Load1.cpp)
target_link_libraries(Load1 Command)

add_library(Load2 Load2.cpp)
target_link_libraries(Load2 Command)

add_library(Load3 Load3.cpp)
target_link_libraries(Load3 Command)

add_library(Load4 Load4.cpp)
target_link_libraries(Load4 Command)

add_library(Load5 Load5.cpp)
target_link_libraries(Load5 Command)

add_library(Load6 Load6.cpp)
target_link_libraries(Load6 Command)

add_library(LoadX LoadX.cpp)
target_link_libraries(LoadX Command)

add_library(StoreA StoreA.cpp)
target_link_libraries(StoreA Command)

add_library(Store1 Store1.cpp)
target_link_libraries(Store1 Command)

add_library(Store2 Store2.cpp)
target_link_libraries(Store2 Command)

add_library(Store3 Store3.cpp)
target_link_libraries(Store3 Command)

add_library(Store4 Store4.cpp)
target_link_libraries(Store4 Command)

add_library(Store5 Store5.cpp)
target_link_libraries(Store5 Command)

add_library(Store6 Store6.cpp)
target_link_libraries(Store6 Command)

add_library(StoreX StoreX.cpp)
target_link_libraries(StoreX Command)

