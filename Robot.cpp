//
// Created by Jose Vives on 29/02/2016.
//

#include <iostream>
#include "Robot.h"

using namespace std;

Robot::Robot(World *world) {
    this->world = world;
}
Robot::~Robot() {
    cout << "Robot destroyed" << endl;
}
