#ifndef CS22510_SIMULATION_H
#define CS22510_SIMULATION_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/System/Time.hpp>
#include "World.h"
#include "Robot.h"
#include "Config.h"

using namespace std;

class Simulation {

public:
    Simulation(Robot&, const configuration&);
    ~Simulation();

    bool hasToSimulate();

    World* getWorld();
    Robot* getRobot();

    bool simulateStep();

    bool isFinishedSimulation();

    void updateInformation();
    void step();
    void render();

private:

    World* world;
    Robot* robot;

    float WAIT;
    clock_t nextTime;

    vector< Util::Pose > posesReaded;
    vector< vector<double> > rangesReaded;

    void readPoses(const std::string );
    void readRanges(const std::string );

};


#endif //CS22510_SIMULATION_H
