#include <iostream>
#include "Robot.h"

/**
 * Constructor for the robot
 *
 * @arg world: The world where the robot is going to live. This is a reference because can't be NULL
 * @arg config: The configuration for set some parameters
 */
Robot::Robot(World& world, const configuration& config) : NUMBER_SENSORS(config.numberSensors) {

    // Save the pointer to the world where we live
    this-> world = &world;

    // Initialize the initial position to zero, zero
    this -> position.set(0,0);

    // Set the initial orientation to zero
    this -> orientation = 0;


    // Initialize all the sensors on the robot
    int degree;
    int separation;
    degree = 0;
    separation = 360 / NUMBER_SENSORS;

    // Add all sensors to the robot
    for(unsigned int i = 0; i  < NUMBER_SENSORS; i++){
        Sensor* s = new Sensor(degree);
        this -> sensors . push_back(s);
        degree += separation;
    }

}

/**
 * Destructor to this class. Deallocate all the sensor on the heap
 */
Robot::~Robot() {
    for(Sensor* s: sensors){
        delete(s);
    }
}

/**
 * Get a pointer to the position of this robot
 *
 * @return: a pointer to the position
 */
Vector2* Robot::getPosition() {
    return &position;
}

/**
 * Change the position of the robot on the world
 *
 * @arg x: the new x position
 * @arg y: the new y position
 */
void Robot::setPosition(unsigned int x, unsigned int y) {
    this -> position.set(x, y);
}

/**
 * Get the orientation of this robot on the world
 *
 * @return the orientation
 */
int Robot::getOrientation(){
    return this -> orientation;
}

/**
 * Change the orientation of the robot
 *
 * @arg orientation: the new orientation for the robot
 */
void Robot::setOrientation(int orientation) {
    this -> orientation = orientation;
}

/**
 * Get a pointer to world were the robot lives
 *
 * @return: the pointer to the world
 */
World* Robot::getWorld(){
    return this -> world;
}

/**
 * Get all the sensor that this robot have
 *
 * @return: reference of vector<Sensor*>
 */
std::vector<Sensor*>& Robot::getSensors(){
    return this -> sensors;
}

/**
 * Get the number of sensors that his robot have
 */
unsigned int Robot::getNumberOfSensors() {
    return this -> NUMBER_SENSORS;
}