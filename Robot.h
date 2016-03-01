//
// Created by Jose Vives on 29/02/2016.
//

#ifndef CS22510_ROBOT_H
#define CS22510_ROBOT_H


#include <array>
#include <vector>
#include "World.h"
#include "Vector2.h"

class Robot {
public:
    Robot(World * world);
    ~Robot();

    static const int NUMBER_SENSORS = 8;

    void setRanges(std::vector<double>&);

    Vector2 getPosition();
    void setPosition(int, int);

    int getOrientation();
    void setOrientation(int);

    std::vector<double> readSensors();

private:
    World *world;
    Vector2* position;
    int orientation;
    std::vector<double> sensors;

};

#endif //CS22510_ROBOT_H
