//
// Created by Jose Vives on 29/02/2016.
//

#ifndef CS22510_ROBOT_H
#define CS22510_ROBOT_H


#include "World.h"

class Robot {
public:
    Robot(World * world);
    ~Robot();

private:
    World *world;
};

#endif //CS22510_ROBOT_H
