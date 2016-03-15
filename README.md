
# CS22510 Assignment: Robot Simulation

This code has been written for CS22510 for Aberystwyth University. We have been requested to build a robot simulation that reads data for his sensor and builds a grid representing the world discovered. The poses and the data from his sensors are provided from two differents files. This program read two files, stores his values and initialize a simulation for a robot and his sensor and build a world with obstacle from the data read from his sensors.

## Tools and Library's used

**cmake**: version 3.2

Everything you need to know for [install cmake](https://cmake.org/install) on you machine can be found on the [official website](https://cmake.org//)

**sfml**: version 2.3

For download the SFML library you can follow the tutorial from the [SFML page](http://www.sfml-dev.org/tutorials/2.3/start-linux.php) for install this library

## Installation

### Recommendation

> Before compiling the code I recommend run the follow command `cmake CMakeList.txt`. This command uses the CMake for build a custom Makefile custom for each Operating System.

On the terminal, run `make` command (you need to be in the directory where the file "Makefile" exists). This compiles all code and builds the executable ready to run the program.

## Usage

On a terminal go to the compiled program and use the follow command for run it: `./Assignment`

Once the program has been opened you can see the simulation on the screen created. To stop the simulation just close the screen.

The program can have parameters that can be changed by passing arguments when it runs.

## Arguments

`-debug`
Enable the debug information. At the moment only draw the border of each cell in the world. For know where are each cell.

`-delay`
Set the delay for each simulation step. Example: the following argument `-delay=2.5` set the delay for each step in the simulation to be 2.5 seconds.

`-savescreen`
Store on an image each step of the simulation. The files are stored in the data folder

`-poses`
Set the file for the poses data. Example: `-poses=data/poses.txt` set the program read that file for the poses information

`-ranges`
Set the file for the ranges data. Example: `-ranges=data/ranges.txt` set the program read that file for the ranges information

`-sensors`
Set how many sensors the robot is going to have. Example: `-sensors=3` set the robot is going to have only 3 sensors build in.

`-dWidth`
Set the screen width. Example `-dWidth=250` set the width of the screen to 250 pixels width

`-dHeight`
Set the screen height. Example `-dHeight=250` set the height of the screen to 250 pixels height

`-cellsize`
Set the size of the cell for the world. Example `-cellsize=0.75` set the cell size to 0.75 meters

`-wWidth`
Set the world width. Example `-wWidth=25` set the world width to 25. The world has 25 cells on the x-axis.

`-wHeight`
Set the world height. Example `-wHeight=25` set the world height to 25. The world has 25 cells on the y-axis.

If any argument has been passed to the program. They have the following default values.
> Debug is disabled

> Does not make a screenshot for each step in the simulation

> The delay is 1 seconds

> The default poses file is "data/poses.txt"

> The default ranges files is "data/ranges.txt"

> The width of the screen is 600 pixels

> The height of the screen is 600 pixels

> A robot has 8 sensors for default

> The world has 50 cells long and 50 cells high

> The size of each cell is 0.2 meters.

## Files Included

#### World.h World.cpp
This file contains the definition and declaration for the world. It stores the world and all the calculation and logic needed.

#### Robot.h Robot.cpp
This file contains the definition and declaration for the robot class and all the logic he needs, like all his sensors, his position, the world that below, etc.

#### Sensor.h Sensor.cpp
This file contains the definition and declaration for the sensor class. This class contains all the information that a sensor needs.

#### Display.h Display.cc
This file contains the definition and declaration for the Display class. This class holds and handle all the logic needed for creating the windows, handle his events and draw everything on the screen

#### Vector.h Vector.cpp
This file contains the definition and declaration for the Vector class. This class is a simple class for store the position of on robot.

#### Config.h Config.cpp
This file contains the definition and declaration for the config class. This class read all the arguments passed to the program when it runs and build a configuration for setting all the values for the program run.

#### Util.hpp Util.cpp
This file contains the definition and declaration of one namespace. This namespace is used to store an enum of each type of cell possible, a struct for a pose and the logic for convert a degree to radians.

#### Main.cpp
Where the main function live. Here is where everything starts and ends.

## Credits

All the program has been written by Jose Vives Iznardo for an assignment for Aberystwyth University. The data files and the formula for know the absolute position of an obstacle from the information given from the sensor are supported by the description of the assignment

## License

The MIT License (MIT)

Copyright (c) 2016 Jose Vives Iznardo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
