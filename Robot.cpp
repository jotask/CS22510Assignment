//
// Created by Jose Vives on 29/02/2016.
//

#include <iostream>
#include "Robot.h"

Robot::Robot(World& world, const configuration& config) : NUMBER_SENSORS(config.numberSensors) {

    this-> world = &world;
    this -> position.set(0,0);
    this -> orientation = 0;


    // Initialize all the sensors on the robot
    int degree;
    int separation;

    degree = 0;
    separation = 360 / NUMBER_SENSORS;

    // Add all sensors to the robot
    for(unsigned int i = 0; i  < NUMBER_SENSORS; i++){
        Sensor* s = new Sensor(i, degree);
        this -> sensors . push_back(s);
        degree += separation;
    }

}

Robot::~Robot() {
    for(Sensor* s: sensors){
        delete(s);
    }
}

Vector2* Robot::getPosition() {
    return &position;
}

void Robot::setPosition(unsigned int x, unsigned int y) {
    this -> position.set(x, y);
}

int Robot::getOrientation(){
    return this -> orientation;
}

void Robot::setOrientation(int orientation) {
    this -> orientation = orientation;
}

World* Robot::getWorld(){
    return this -> world;
}

std::vector<Sensor*>& Robot::getSensors(){
    return this -> sensors;
}

unsigned int Robot::getNumberOfSensors() {
    return this -> NUMBER_SENSORS;
}