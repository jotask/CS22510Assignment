cmake_minimum_required(VERSION 3.2)
project(CS22510)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Util.hpp Util.cpp World.cpp World.h Robot.cpp Robot.h Vector2.cpp Vector2.h Sensor.cpp Sensor.h Simulation.cpp Simulation.h Display.cpp Display.h Config.h Config.cpp )

# Define sources and executable
set(EXECUTABLE_NAME "Assignment")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
