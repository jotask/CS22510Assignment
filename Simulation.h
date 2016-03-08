#ifndef CS22510_SIMULATION_H
#define CS22510_SIMULATION_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/System/Time.hpp>
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

    const float WAIT = 0.5;
    clock_t nextTime;

    vector< Util::Pose > posesReaded;
    vector< vector<double> > rangesReaded;

    void readPoses(const char*);
    void readRanges(const char*);

};


#endif //CS22510_SIMULATION_H
