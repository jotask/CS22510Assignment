
# CS22510 Assignment: Robot Simulation

This program read two files, stores his values and initialize a simulation for a robot and his sensor, and build a world with obstacle from the data readed from his sensors

## Installation

Go to the terminal and run `make` command. This read the Makefile and they know everything they need to compile.

## Usage

On a terminal use the follow command: `./Assignment` for run the program

## Files Included

### World.h World.cpp
This files contains the definition and declaration for the world. It stores the world and all the calculation and logic needed.

### Robot.h Robot.cpp
This files contains the definition and declaration for the robot class and all the logic he need, like all his sensors, his position, the world that below, etc.

### Sensor.h Sensor.cpp
This files contains the definition and declaration for the sensor class. This class contains all the information that a sensor needs.

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
