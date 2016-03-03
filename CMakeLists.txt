cmake_minimum_required(VERSION 3.3)
project(CS22510)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp World.cpp World.h Robot.cpp Robot.h Vector2.cpp Vector2.h Sensor.cpp Sensor.h)
add_executable(CS22510 ${SOURCE_FILES})