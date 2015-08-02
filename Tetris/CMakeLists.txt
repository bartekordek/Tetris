cmake_minimum_required (VERSION 2.6)
project(Tetris)


#set(Boost_INCLUDE_DIR /usr/include)
#set(Boost_LIBRARY_DIR /usr/local/lib)

find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package(SDL REQUIRED)
if ( NOT SDL_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

SET(CMAKE_CXX_FLAGS "-std=c++0x")

include_directories(inc)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

file(GLOB SOURCES "src/*.cpp")
set(MAIN_FILE main.cpp)

add_executable(Tetris.exe ${MAIN_FILE} ${SOURCES})
target_link_libraries( Tetris.exe ${Boost_LIBRARIES})
