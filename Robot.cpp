//
// Created by Jose Vives on 29/02/2016.
//

#include <iostream>
#include "Robot.h"

Robot::Robot(World *world) {
    this->world = world;
    this -> position = new Vector2(0, 0);
}
Robot::~Robot() {
    std::cout << "Robot destroyed" << std::endl;
}

void Robot::nextMove(double x, double y, int orientation) {
    this -> position -> set(x, y);
    this -> orientation = orientation;

}

void Robot::setRanges(std::array<double, Robot::NUMBER_SENSORS> &ranges){
    this -> sensors = ranges;

}

Vector2 Robot::getPosition() {
    return *position;
}
