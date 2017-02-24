cxx_executable(machine_integrationtest . gtest_main)
target_link_libraries(machine_integrationtest ${SOURCES})

cxx_executable(runtime_integrationtest . gtest_main)
target_link_libraries(runtime_integrationtest ${SOURCES})

