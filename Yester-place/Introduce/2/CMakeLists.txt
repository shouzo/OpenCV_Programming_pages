cmake_minimum_required(VERSION 2.8)
project( Introduce_2 )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Introduce_2 Introduce_2.cpp )
target_link_libraries( Introduce_2 ${OpenCV_LIBS} )
