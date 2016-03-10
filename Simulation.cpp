#include <iostream>
#include <math.h>
#include "Simulation.h"

using namespace std;

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

    // TODO Use QUEUE rather than vector

    Util::Pose &pose = posesRead.front();
    vector<double> &ranges = rangesRead.front();

    // Remove robot from old map position
    this-> world->setValueAt(robot->getPosition()->getX(), robot->getPosition()->getY(), Util::EMPTY);

    // Update robot position and orientation
    int x, y;
    x = Util::realToVirtual(pose.x);
    y = Util::realToVirtual(pose.y);
    robot -> setPosition(x, y);
    robot -> setOrientation(pose.o);

    // Let know to the map where is the robot now
    this-> world->setValueAt(robot->getPosition()->getX(), robot->getPosition()->getY(), Util::ROBOT);

    // Get all sensors from the robot
    vector<Sensor*>& sensors = robot -> getSensors();

    // Update robot sensors reading values
    for(unsigned int i = 0; i < sensors . size(); i++){
        sensors . at(i) -> setRead(ranges[i]);
    }

    posesRead.erase(posesRead.begin());
    rangesRead.erase(rangesRead.begin());

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
        orientationRadian = Util::degreeToRadian(robot->getOrientation() + s->getDegree());

        double xr, xy;
        xr = Util::virtualToReal(robot->getPosition()->getX());
        xy = Util::virtualToReal(robot->getPosition()->getY());

        double obstacleX, obstacleY;

        obstacleX = (xr + (valueRead * cos(orientationRadian)));
        obstacleY = (xy + (valueRead * sin(orientationRadian)));

        int oX, oY;
        oX = Util::realToVirtual(obstacleX);
        oY = Util::realToVirtual(obstacleY);

        world->setValueAt(oX, oY, Util::Cell::OBSTACLE);

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

    std::string line;
    while(std::getline(infile, line)){

        std::istringstream iss (line);

        vector<double> tmp(Robot::NUMBER_SENSORS);

        for(int i = 0; i < Robot::NUMBER_SENSORS; i++){
            iss >> tmp[i];
        }

        rangesRead.push_back(tmp);

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

        Util::Pose pose;
        iss >> pose.x;
        iss >> pose.y;
        iss >> pose.o;

        posesRead.push_back(pose);
    }

    infile.close();

}


World* Simulation::getWorld() {
    return world;
}

Robot* Simulation::getRobot() {
    return robot;
}
