#include "Sensor.h"

/**
 * Constructor for the sensor class
 *
 * @arg degree: the degree from the robot
 */
Sensor::Sensor(int degree) {
    this -> degree = degree;
}

/**
 * Destructor the sensor
 */
Sensor::~Sensor() {}

/**
 * Set the value for when we go to read the sensor
 *
 * @arg read: the value for when we go to read
 */
void Sensor::setRead(double read) {
    this -> read = read;
}

/**
 * Read the distance from the sensor. The distance of one object if is detected
 */
double Sensor::getRead() {
    return this -> read;
}

/**
 * Get the degree of this sensor on the robot
 */
int Sensor::getDegree(){
    return this -> degree;
}