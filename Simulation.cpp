#include <iostream>
#include <math.h>
#include "Simulation.h"
#include "Util.h"

using namespace std;

Simulation::Simulation(Robot& robot, const char* posesFile, const char* rangesFile) {

    // Set variables for this instance
    this -> world = robot.getWorld();
    this -> robot = &robot;

    // Read the files for set up the simulation
    this -> readPoses(posesFile);
    this -> readRanges(rangesFile);

}

Simulation::~Simulation() { }

bool Simulation::hasToSimulate() {
    return (!posesReaded.empty() && !rangesReaded.empty() && posesReaded.size() == rangesReaded.size());
}

void Simulation::simulateStep() {

    this -> updateInformation();
    this -> step();
    this -> render();

}

void Simulation::updateInformation() {

    // TODO Use QUEUE rather than vector

    vector<double> &pose = posesReaded.front();
    vector<double> &ranges = rangesReaded.front();

    // Update robot position and orientation
    int x, y, o;
    x = Util::realToVirtual(pose[0]);
    y = Util::realToVirtual(pose[1]);
    o = pose[2];
    robot -> setPosition(x, y);
    robot -> setOrientation(o);

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

        cout << endl;

    }

}

void Simulation::render() {

//    int x, y;
//
//    x = this -> robot->getPosition()->getX();
//    y = this -> robot->getPosition()->getY();
//
//    world -> setValueAt(x, y, Resources::Cell::ROBOT);

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

        vector<double> tmp(3);
        for(int i = 0; i < 3; i++){
            iss >> tmp[i];
        }

        posesReaded.push_back(tmp);
    }

    infile.close();

    return;

}

