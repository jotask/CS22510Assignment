//
// Created by Jose Vives on 29/02/2016.
//

#ifndef CS22510_ROBOT_H
#define CS22510_ROBOT_H


#include <array>
#include "World.h"
#include "Vector2.h"

class Robot {
public:
    Robot(World * world);
    ~Robot();

    static const int NUMBER_SENSORS = 8;

    void nextMove(double x, double y, int orientation);
    void setRanges(std::array<double, Robot::NUMBER_SENSORS>&);

    Vector2 getPosition();
    void setPosition(int, int);

private:
    World *world;
    Vector2* position;
    int orientation;
    std::array<double, Robot::NUMBER_SENSORS> sensors;

};

#endif //CS22510_ROBOT_H
