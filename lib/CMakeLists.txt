cmake_minimum_required(VERSION 3.6)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)


#versioning
set(CPACK_PACKAGE_VERSION_MAJOR 18)
set(CPACK_PACKAGE_VERSION_MINOR 08)
set(CPACK_PACKAGE_VERSION_PATCH 11)

set(target_dir "bin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -D__LIBAVRESAMPLE__ -std=c99")


project(av_director_lib)

include_directories(".")
find_package(FFmpeg REQUIRED)

if(FFMPEG_FOUND)
  message("Found FFMPEG/LibAV libraries")
  # All sources that also need to be tested in unit tests go into a static library
  add_library(av_director_lib STATIC src/av_director_context.cc src/av_director_context.hpp)
  target_include_directories(av_director_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  target_include_directories(av_director_lib PUBLIC ${FFMPEG_INCLUDE_DIR})
  target_link_libraries(av_director_lib ${FFMPEG_LIBAVCODEC})
else()
  message("Can't find libavcodec, libavformat or libavutil. Add them!")
endif()


# The main program
add_executable(av_director_demo main.cpp)
target_link_libraries(av_director_demo PUBLIC av_director_lib ${FFMPEG_LIBAVCODEC})
