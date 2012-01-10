#CMake Configuration
cmake_minimum_required(VERSION 2.8)

#Compiler Configuration
set(CMAKE_CXX_COMPILER /opt/local/bin/g++-mp-4.7)
#set(CMAKE_CXX_FLAGS "-std=c++11")

#Project Configuration
project(coding_dojo_18)
enable_testing()

#Adding external libraries
find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#Program Configuration
set(EXE_NAME test_${CMAKE_PROJECT_NAME})

add_executable(${EXE_NAME} CodingDojo18Test.cpp)
target_link_libraries(${EXE_NAME} ${Boost_LIBRARIES})

#Adding Test
add_test(${EXE_NAME} ${CMAKE_BINARY_DIR}/${EXE_NAME})
