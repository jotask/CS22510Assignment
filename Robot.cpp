//
// Created by Jose Vives on 29/02/2016.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include "Robot.h"

using namespace std;

Robot::Robot(World *world) {
    this->world = world;
    this -> position = new Vector2(0, 0);
    this -> orientation = 0;


    // Initialize all the sensors on the robot
    int degree;
    int separation;

    degree = 0;
    separation = 360 / NUMBER_SENSORS;

    // Add all sensors to the robot
    for(int i = 0; i  < NUMBER_SENSORS; i++){
        this -> sensors . push_back(Sensor(i, degree));
        degree += separation;
    }

}

Robot::~Robot() {
    std::cout << "Robot destroyed" << std::endl;
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

void Robot::update(){

    // Get all sensor from this robot
    vector<Sensor> sensors = this -> getSensors();

    if(sensors.empty()){
        cout << "This robot doesn't have any Sensor registered" << std::endl;
        return;
    }

    double minX, minY, maxX, maxY;
    minX = 0.0;
    minY = 0.0;
    maxX = (double)(World::CELL_SIZE * (double) World::WORLD_WIDTH);
    maxY = (double)(World::CELL_SIZE * (double) World::WORLD_HEIGHT);

    // Go throw all sensors
    for(int i = 0; i < Robot::NUMBER_SENSORS; i++){

        // Get the current sensor
        Sensor* sensor = &sensors[i];

        // Read the value given from this sensor
        double reading = sensor -> getRead();

        // Check if the sensor give us an INFINITE reading
        // If have infinite reading value skip this sensor and continue to the next sensor if we have
        if(reading == Sensor::INFINITE){
            continue;
        }

        // Convert the orientations (degrees) to a radian
        double orientationsRadian;
        orientationsRadian = this -> convertDegreeToRadian(sensor -> getDegree());

        // Get the coordinates of the obstacle
        double obstacleX, obstacleY;
        obstacleX = reading * cos(orientationsRadian);
        obstacleY = reading * sin(orientationsRadian);

        if(!((obstacleX >= minX && obstacleX < maxX) && (obstacleY >= minY && obstacleY < maxY))){
//            cout << "continue: " << obstacleX << " " << obstacleY << endl;
            continue;
        }

        // Convert the real world coordinates to virtual world coordinates
        int worldX, worldY;
        worldX = this -> getWorld() -> convertToWorldCoordinates(obstacleX);
        worldY = this -> getWorld() -> convertToWorldCoordinates(obstacleY);

        // Check if the virtual coordinates are not outside our virtual world
        // I mean, check for not make an ArrayOutOfBounds exception
        if(!((worldX >= 0) && (worldX < World::WORLD_WIDTH) && (worldY >= 0) && (worldY < World::WORLD_HEIGHT))){
            cout << "Is bigger!!!" << endl;
            continue;
        }

        // Change this value on the grid world
        this -> getWorld() -> setValueAt(worldX, worldY, true);

        cout << "xx: " << worldX << " yy: " << worldY << endl;

        cout << endl;

    }

}

double Robot::convertDegreeToRadian(double degree){
    return degree * (M_PI / 180);
}

World* Robot::getWorld(){
    return this -> world;
}

vector<Sensor> Robot::getSensors(){
    return this -> sensors;
}