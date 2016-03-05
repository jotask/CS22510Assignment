//
// Created by jota on 05/03/16.
//

#include <iostream>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(World* world, Robot* robot, const char* posesFile, const char* rangesFile) {
    this -> world = world;
    this -> robot = robot;
    this -> isFinished = false;

    this -> readPoses(posesFile);
    this -> readRanges(rangesFile);

    if(this -> posesReaded.empty()) {
        cout << "ERROR 1" << endl;
    }
    if(this -> rangesReaded.empty()){
        cout << "ERROR 2" << endl;
    }

}

Simulation::~Simulation() {
    cout << "Simulation deleted" << endl;
}

void Simulation::simulate() {
    cout << "Updating Simulation" << endl;
    while(!posesReaded.empty() && !rangesReaded.empty()){

        world -> printWorld();

        this -> updateInformation(robot, &posesReaded.front(), &rangesReaded.front());

        posesReaded.erase(posesReaded.begin());
        rangesReaded.erase(rangesReaded.begin());

        robot -> update();

    }
}

void Simulation::updateInformation(Robot* robot, vector<double>* p, vector<double>* r) {
    // FIXME convert to grid coordinates
    int x, y, orientation;

    World* world;
    world = robot -> getWorld();

    x = world -> convertToWorldCoordinates(p[0]);
    y = world -> convertToWorldCoordinates(p[1]);

//    cout << "x:" << p[0] << " y:" << p[1] << endl;
//    cout << "x:" << x << " y:" << y << endl << endl;

    orientation = (int)&p[2];
    robot -> setPosition(x, y);
    robot -> setOrientation(orientation);

    // Set the values for all the sensors for the robot, for simulation
    Sensor* sensors;
    robot -> getSensors();
    for(int i = 0; i < Robot::NUMBER_SENSORS; i++){
        double tmp;
        tmp = r -> at(i);
        sensors -> setRead(tmp);
    }
}

bool Simulation::isFinishedSimulation() {
    return this ->isFinished;
}

void Simulation::readRanges(const char* file) {

    vector< vector<double>* >* rangesReaded;

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

        rangesReaded -> push_back(&tmp);

    }

    infile.close();

}

void Simulation::readPoses(const char* posesFile){

    vector< vector<double> > posesReaded;

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

