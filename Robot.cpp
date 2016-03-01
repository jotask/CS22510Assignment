//
// Created by Jose Vives on 29/02/2016.
//

#include <iostream>
#include "Robot.h"

Robot::Robot(World *world) {
    this->world = world;
    this -> position = new Vector2(0, 0);
    this -> orientation = 0;
}
Robot::~Robot() {
    std::cout << "Robot destroyed" << std::endl;
}

void Robot::setRanges(std::vector<double> &ranges){
    this -> sensors = ranges;
}

Vector2 Robot::getPosition() {
    return *position;
}

void Robot::setPosition(int x, int y) {
    Vector2 * p;
    p = this -> position;
    p -> set(x, y);
}

int Robot::getOrientation(){
    return this -> orientation;
}

void Robot::setOrientation(int orientation) {
    this -> orientation = orientation;
}

std::vector<double> Robot::readSensors(){
    return this -> sensors;
};
