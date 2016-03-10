#include "Sensor.h"

Sensor::Sensor(int orientation, int degree) {
    this ->  orientation = orientation;
    this -> degree = degree;
}

Sensor::~Sensor() {}

void Sensor::setRead(double read) {
    this -> read = read;
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