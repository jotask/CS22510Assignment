//
// Created by Jose Vives on 29/02/2016.
//

#ifndef CS22510_ROBOT_H
#define CS22510_ROBOT_H


#include <array>
#include <vector>
#include "World.h"
#include "Vector2.h"
#include "Sensor.h"

class Robot {
public:
    Robot(World & world);
    ~Robot();

    static const int NUMBER_SENSORS = 8;

    Vector2* getPosition();
    void setPosition(int, int);

    int getOrientation();
    void setOrientation(int);

    World* getWorld();

    void update();

     std::vector<Sensor>& getSensors();

private:
    World *world;
    Vector2* position;
    int orientation;

    std::vector<Sensor> sensors;

    double convertDegreeToRadian(double);

};

#endif //CS22510_ROBOT_H
