set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/thirdparty")

add_executable(tests testmain.cpp ${PROJECT_SOURCES})
target_link_libraries(tests PRIVATE catch)
