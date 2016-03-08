//
// Created by jota on 05/03/16.
//

#ifndef CS22510_SIMULATION_H
#define CS22510_SIMULATION_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "World.h"
#include "Robot.h"

using namespace std;

class Simulation {

public:
    Simulation(Robot&, const char*, const char*);
    ~Simulation();

    bool hasToSimulate();

    World* getWorld();
    Robot* getRobot();

    void simulateStep();

    bool isFinishedSimulation();

    void updateInformation();
    void step();
    void render();

private:

    World* world;
    Robot* robot;

    vector< vector<double> > posesReaded;
    vector< vector<double> > rangesReaded;

    void readPoses(const char*);
    void readRanges(const char*);

};


#endif //CS22510_SIMULATION_H
