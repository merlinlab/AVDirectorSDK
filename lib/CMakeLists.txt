cmake_minimum_required(VERSION 3.6)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)


#versioning
set(CPACK_PACKAGE_VERSION_MAJOR 18)
set(CPACK_PACKAGE_VERSION_MINOR 08)
set(CPACK_PACKAGE_VERSION_PATCH 11)

set(target_dir "bin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -D__LIBAVRESAMPLE__ -std=c99")


project(merlin_core_lib)

include_directories(".")
find_package(FFmpeg REQUIRED)

if(FFMPEG_FOUND)
  message("Found FFMPEG/LibAV libraries")
  # All sources that also need to be tested in unit tests go into a static library
  file(GLOB merlin_src src/*.cc src/*.hpp src/*.c src/*.h)
  add_library(merlin_core_lib STATIC ${merlin_src})
  target_include_directories(merlin_core_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  target_include_directories(merlin_core_lib PUBLIC ${FFMPEG_INCLUDE_DIR})
else()
  message("Can't find libavcodec, libavformat or libavutil. Add them!")
endif()


# The main program
add_executable(merlin_core_demo main.cpp)
target_link_libraries(merlin_core_demo PUBLIC merlin_core_lib ${FFMPEG_LIBRARIES})
