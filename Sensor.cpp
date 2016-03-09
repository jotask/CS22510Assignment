//
// Created by Jota on 02/03/2016.
//

#include <iostream>
#include "Sensor.h"

Sensor::Sensor() {
    this -> orientation = -1;
    this -> degree = -1;
}

Sensor::Sensor(int orientation, int degree) {
    this ->  orientation = orientation;
    this -> degree = degree;
}

Sensor::~Sensor() {
    std::cout << "~Sensor()" << std::endl;
}

void Sensor::setRead(double readed) {
    this -> read = readed;
}

double Sensor::getRead() {
    return this -> read;
}

int Sensor::getDegree(){
    return this -> degree;
}

int Sensor::getOrientation() {
    return this -> orientation;
}