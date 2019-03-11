add_executable(tests testmain.cpp ${PROJECT_SOURCES})
target_link_libraries(tests PRIVATE catch)
