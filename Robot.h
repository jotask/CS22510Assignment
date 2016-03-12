#ifndef CS22510_ROBOT_H
#define CS22510_ROBOT_H

#include <array>
#include <vector>
#include "World.h"
#include "Vector2.h"
#include "Sensor.h"

class Robot {
public:

    // Constructor for the robot
    Robot(World & world, const configuration&);

    // Destructor for the robot
    ~Robot();

    // Position for the robot
    Vector2* getPosition();

    // Set the position of the robot
    void setPosition(unsigned int, unsigned int);

    // Get the orientation of the robot
    int getOrientation();

    // Set the orientation of the robot
    void setOrientation(int);

    // Get how many sensors this robots have
    unsigned int getNumberOfSensors();

    // The the world were the robot is
    World* getWorld();

    // Get the reference of all the sensor of this robot
     std::vector<Sensor*>& getSensors();

private:

    // A pointer to the world that the robot exist
    World *world;

    // The position of the robot on the virutal world
    Vector2 position;

    // The orientation of this robot
    int orientation;

    const unsigned int NUMBER_SENSORS;

    std::vector<Sensor*> sensors;

};

#endif //CS22510_ROBOT_H
