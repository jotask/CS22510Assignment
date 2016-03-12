#include <iostream>
#include <math.h>
#include "Simulation.h"

Simulation::Simulation(Robot& robot, const configuration& config) {

    this -> WAIT = config.delay;

    // Set variables for this instance
    this -> world = robot.getWorld();
    this -> robot = &robot;

    // Read the files for set up the simulation
    this -> readPoses(config.posesFile);
    this -> readRanges(config.rangesFile);

    this -> nextTime = clock() + (WAIT * CLOCKS_PER_SEC);

}

Simulation::~Simulation() {
}

bool Simulation::hasToSimulate() {
    return (!posesRead.empty() && !rangesRead.empty() && posesRead.size() == rangesRead.size());
}

bool Simulation::simulateStep() {
    if(clock() >= nextTime){
        nextTime = clock() + (WAIT * CLOCKS_PER_SEC);
        this->updateInformation();
        this->step();
        return true;
        //    this -> render();
    }
    return false;
}

void Simulation::updateInformation() {

    util::Pose &pose = posesRead.front();
    vector<double> &ranges = rangesRead.front();

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
    vector<Sensor*>& sensors = robot -> getSensors();

    // Update robot sensors reading values
    for(unsigned int i = 0; i < sensors . size(); i++){
        sensors . at(i) -> setRead(ranges[i]);
    }

    posesRead.pop();
    rangesRead.pop();

}

void Simulation::step() {

    vector<Sensor*>& sensors = robot -> getSensors();

    for(unsigned int i = 0; i < sensors.size(); i++){
        Sensor* s = sensors.at(i);

        double valueRead = s -> getRead();

        if(valueRead == Sensor::INFINITE) {
            continue;
        }

        double orientationRadian;
        orientationRadian = util::degreeToRadian(robot->getOrientation() + s->getDegree());

        double xr, xy;
        xr = world -> virtualToReal(robot->getPosition()->getX());
        xy = world -> virtualToReal(robot->getPosition()->getY());

        double obstacleX, obstacleY;

        obstacleX = (xr + (valueRead * cos(orientationRadian)));
        obstacleY = (xy + (valueRead * sin(orientationRadian)));

        unsigned int oX, oY;
        oX = world -> realToVirtual(obstacleX);
        oY = world -> realToVirtual(obstacleY);

        world->setValueAt(oX, oY, util::Cell::OBSTACLE);

    }

}

void Simulation::render() {

    world -> printWorld();

}

bool Simulation::isFinishedSimulation() {
    return ((this ->posesRead.empty()) && (this ->rangesRead.empty()));
}

void Simulation::readRanges(const std::string file) {

    std::ifstream infile(file);
    if(!infile.is_open()){
        std::cout << "file not found: " << file << std::endl;
        infile.close();
        return;
    }

    unsigned int numberSensors = robot -> getNumberOfSensors();

    std::string line;
    while(std::getline(infile, line)){

        std::istringstream iss (line);

        vector<double> tmp(numberSensors);

        for(unsigned int i = 0; i < numberSensors; i++){
            iss >> tmp[i];
        }

        rangesRead.push(tmp);

    }

    infile.close();

}

void Simulation::readPoses(const std::string posesFile){

    ifstream infile(posesFile);
    if(!infile.is_open()){
        std::cout << "file not found" << std::endl;
        infile.close();
        return;
    }

    std::string line;
    while(std::getline(infile, line)){
        std::istringstream iss(line);

        util::Pose pose;
        iss >> pose.x;
        iss >> pose.y;
        iss >> pose.o;

        posesRead.push(pose);
    }

    infile.close();

}


World* Simulation::getWorld() {
    return world;
}

Robot* Simulation::getRobot() {
    return robot;
}
