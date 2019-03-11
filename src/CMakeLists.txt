cmake_minimum_required(VERSION 3.6)

project(av_director_lib)

# All sources that also need to be tested in unit tests go into a static library
add_library(av_director_lib STATIC av_director_content.cc av_director_content.hpp)
target_include_directories(hello_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# The main program
add_executable(av_director_demo main.cpp)
target_link_libraries(av_director_demo PRIVATE av_director_lib)
