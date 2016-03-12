#include <iostream>
#include <math.h>
#include "Simulation.h"

/**
 * Constructor for this class
 *
 * @arg robot: the robot for the simulation
 * @the configuration for some parameters
 */
Simulation::Simulation(Robot& robot, const configuration& config) : WAIT(config.delay) {


    // Set variables for this instance
    this -> world = robot.getWorld();
    this -> robot = &robot;

    // Read the files for set up the simulation
    this -> readPoses(config.posesFile);
    this -> readRanges(config.rangesFile);

    // Know the time for the next step
    this -> nextTime = clock() + (WAIT * CLOCKS_PER_SEC);

}

/**
 * Destructor for this class
 */
Simulation::~Simulation() {
}

/**
 * Check if the poses and the ranges ara the same size and they are not empty
 *
 * @return: if is everything ok and we have thing to simulate
 */
bool Simulation::hasToSimulate() {
    return (!posesRead.empty() && !rangesRead.empty() && posesRead.size() == rangesRead.size());
}

/**
 * Simulate one step if the time has been passed. If has been passed, update the information, and do all the logic.
 * If is has passed the time, update the current time to the next time for the sumulation
 *
 * @return: if we have been update or make a step
 */
bool Simulation::simulateStep() {
    // Know if we need to make a step on the simulation
    if(clock() >= nextTime){

        // Update the information
        this->updateInformation();

        // Make the step
        this->step();

        // Know when is the next time to make a step
        nextTime = clock() + (WAIT * CLOCKS_PER_SEC);

        // return for know that we have been update the simulation
        return true;

    }

    // We didn't did anything
    return false;
}

/**
 * Update the information. This simulate that the robot has been moved. This change the position of the robot
 * on the world, and change the read value for each sensor
 */
void Simulation::updateInformation() {

    // Get the next pose
    util::Pose &pose = posesRead.front();

    // Get the next ranges for the sensor
    std::vector<double> &ranges = rangesRead.front();

    // Remove robot from old map position
    this-> world->setValueAt(robot->getPosition()->getX(), robot->getPosition()->getY(), util::Cell::EMPTY);

    // Update robot position and orientation
    unsigned int x, y;
    x = world -> realToVirtual(pose.x);
    y = world -> realToVirtual(pose.y);
    robot -> setPosition(x, y);
    robot -> setOrientation(pose.o);

    // Let know to the map where is the robot now
    this-> world->setValueAt(robot->getPosition()->getX(), robot->getPosition()->getY(), util::Cell::ROBOT);

    // Get all sensors from the robot
    std::vector<Sensor*>& sensors = robot -> getSensors();

    // Update robot sensors reading values
    for(unsigned int i = 0; i < sensors . size(); i++){
        sensors . at(i) -> setRead(ranges[i]);
    }

    // Remove the first element on each queue. For the next time we update, get the following information needed
    posesRead.pop();
    rangesRead.pop();

}

/**
 * Simulate one step on the simulation. Go throw all sensors on the robot, read his values. And decide if
 * an obstacle has been found
 */
void Simulation::step() {

    // A references of all sensors on the robot
    std::vector<Sensor*>& sensors = robot -> getSensors();

    // See all sensors from the robot
    for(unsigned int i = 0; i < sensors.size(); i++){

        // Pointer to the actual sensor
        Sensor* s = sensors.at(i);

        // Read the value on the sensor
        double valueRead = s -> getRead();

        // Check if the sensor has read an INFINITE value. If they give us infinite, we skip to the next sensor
        if(valueRead == Sensor::INFINITE) {
            continue;
        }

        // Convert the orientation of the robot to radians
        double orientationRadian;
        orientationRadian = util::degreeToRadian(robot->getOrientation() + s->getDegree());

        // Convert the robot position to real coordinates
        double xr, xy;
        xr = world -> virtualToReal(robot->getPosition()->getX());
        xy = world -> virtualToReal(robot->getPosition()->getY());

        // Get the obstacle coordinate in real coordinates
        double obstacleX, obstacleY;
        obstacleX = (xr + (valueRead * cos(orientationRadian)));
        obstacleY = (xy + (valueRead * sin(orientationRadian)));

        // Convert the obtacle real coordinates to virtual coordinates
        unsigned int oX, oY;
        oX = world -> realToVirtual(obstacleX);
        oY = world -> realToVirtual(obstacleY);

        // Save this  obstacle on the world
        world->setValueAt(oX, oY, util::Cell::OBSTACLE);

    }

}

/**
 * Know if the simulation has been finished. We know if is finished by checking if the queue are empty
 *
 * @return:  if the simulation has been finished
 */
bool Simulation::isFinishedSimulation() {
    return ((this ->posesRead.empty()) && (this ->rangesRead.empty()));
}

/**
 * Read the file where is the data of all ranges and store this values on an queue for the simulation
 *
 * @arg file: the file where all data exist
 */
void Simulation::readRanges(const std::string file) {

    // The file
    std::ifstream infile(file);

    // Check if the file has been found
    if(!infile.is_open()){
        // If the file has not been found close the file (just in case) and exit the function
        std::cout << "file not found: " << file << std::endl;
        infile.close();
        return;
    }

    // Get how many sensor the robot have
    unsigned int numberSensors = robot -> getNumberOfSensors();

    // String for this line
    std::string line;

    // Go throw all lines on the file
    while(std::getline(infile, line)){

        // IstringStream for this file
        std::istringstream iss (line);

        // Create a vector for all the values
        std::vector<double> tmp(numberSensors);

        // Save this values on the vector
        for(unsigned int i = 0; i < numberSensors; i++){
            iss >> tmp[i];
        }

        // Save all values on the queue
        rangesRead.push(tmp);

    }

    // Close the file
    infile.close();

}


/**
 * Read the file where is the data of all poses and store this values on an queue for the simulation
 *
 * @arg file: the file where all data exist
 */
void Simulation::readPoses(const std::string posesFile){

    // The file
    std::ifstream infile(posesFile);

    // Check if the file has been found
    if(!infile.is_open()){
        // If the file has not been found close the file (just in case) and exit the function
        std::cout << "file not found: " << posesFile << std::endl;
        infile.close();
        return;
    }

    // String for store each line
    std::string line;

    // Go trow all lines on the file
    while(std::getline(infile, line)){

        // IstringStream for this file
        std::istringstream iss(line);

        // Save this values on a struct
        util::Pose pose;
        iss >> pose.x;
        iss >> pose.y;
        iss >> pose.o;

        // Store this information on the queue
        posesRead.push(pose);

    }

    // Close the file
    infile.close();

}

/**
 * Get the world
 *
 * @return: a pointer to the world
 */
World* Simulation::getWorld() {
    return world;
}
