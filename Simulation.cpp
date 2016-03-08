#include <iostream>
#include <math.h>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(Robot& robot, const char* posesFile, const char* rangesFile) {

    // Set variables for this instance
    this -> world = robot.getWorld();
    this -> robot = &robot;

    // Read the files for set up the simulation
    this -> readPoses(posesFile);
    this -> readRanges(rangesFile);

    this -> nextTime = clock() + (WAIT * CLOCKS_PER_SEC);

}

Simulation::~Simulation() { }

bool Simulation::hasToSimulate() {
    return (!posesReaded.empty() && !rangesReaded.empty() && posesReaded.size() == rangesReaded.size());
}

void Simulation::simulateStep() {
    if(clock() >= nextTime){
        nextTime = clock() + (WAIT * CLOCKS_PER_SEC);
        this->updateInformation();
        this->step();
        //    this -> render();
    }
}

void Simulation::updateInformation() {

    // TODO Use QUEUE rather than vector

    Util::Pose &pose = posesReaded.front();
    vector<double> &ranges = rangesReaded.front();

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
    vector<Sensor>& sensors = robot -> getSensors();

    // Update robot sensors reading values
    for(int i = 0; i < sensors . size(); i++){
        sensors . at(i) . setRead(ranges[i]);
    }

    posesReaded.erase(posesReaded.begin());
    rangesReaded.erase(rangesReaded.begin());

}

void Simulation::step() {

    vector<Sensor>& sensors = robot -> getSensors();

    for(int i = 0; i < sensors.size(); i++){
        Sensor& s = sensors.at(i);

        double valueRead = s.getRead();

        if(valueRead == Sensor::INFINITE) {
            continue;
        }

        double orientationRadian;
        orientationRadian = Util::degreeToRadian(robot->getOrientation() + s.getDegree());

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
    return ((this -> posesReaded.empty()) && (this -> rangesReaded.empty()));
}

void Simulation::readRanges(const char* file) {

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

        rangesReaded.push_back(tmp);

    }

    infile.close();

}

void Simulation::readPoses(const char* posesFile){

    ifstream infile(posesFile);
    if(!infile.is_open()){
        std::cout << "file not found" << std::endl;
        infile.close();
        return;
    }

    std::string line;
    while(std::getline(infile, line)){
        std::istringstream iss(line);

//        vector<double> tmp(3);
//        for(int i = 0; i < 3; i++){
//            iss >> tmp[i];
//
//        }

        Util::Pose pose;
        iss >> pose.x;
        iss >> pose.y;
        iss >> pose.o;

        posesReaded.push_back(pose);
    }

    infile.close();

    return;

}


World* Simulation::getWorld() {
    return world;
}

Robot* Simulation::getRobot() {
    return robot;
}
