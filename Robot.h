#ifndef CS22510_ROBOT_H
#define CS22510_ROBOT_H

#include <array>
#include <vector>
#include "World.h"
#include "Vector2.h"
#include "Sensor.h"

class Robot {
public:
    Robot(World & world, const configuration&);
    ~Robot();

    Vector2* getPosition();
    void setPosition(unsigned int, unsigned int);

    int getOrientation();
    void setOrientation(int);

    unsigned int getNumberOfSensors();

    World* getWorld();

     std::vector<Sensor*>& getSensors();

private:
    World *world;
    Vector2 position;
    int orientation;

    const unsigned int NUMBER_SENSORS;

    std::vector<Sensor*> sensors;

};

#endif //CS22510_ROBOT_H
