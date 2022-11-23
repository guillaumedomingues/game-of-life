# only for cmake --version >= 3.24.2
cmake_minimum_required(VERSION 3.24.2)

# project name
project(bisect_gameoflife)

# creates the variable EXEC and sets it to hello
set(EXEC game_of_life)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 20)

# I../includes
#include_directories(includes)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# compiles the files defined by SOURCES to generate the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})
