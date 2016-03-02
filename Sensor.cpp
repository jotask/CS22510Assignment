//
// Created by Jota on 02/03/2016.
//

#include "Sensor.h"

Sensor::Sensor(int orientation, int degree) {
    this ->  orientation = orientation;
    this -> degree = degree;
}

Sensor::~Sensor() {

}

double Sensor::setRead(double readed) {
    this -> read = readed;
}

double Sensor::getRead() {
    return this -> read;
}