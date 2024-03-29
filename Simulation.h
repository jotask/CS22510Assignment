#ifndef CS22510_SIMULATION_H
#define CS22510_SIMULATION_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <SFML/System/Time.hpp>
#include <queue>
#include "World.h"
#include "Robot.h"
#include "Config.h"

class Simulation {

public:
    // Constructor for the simulation
    Simulation(Robot&, const configuration&);

    // Destructor for the simulation
    ~Simulation();

    // Know and check if everything is ok and if have thing to simulate
    bool hasToSimulate();

    // Get the world pointer
    World* getWorld();

    // Simulate one step
    bool simulateStep();

    // Know if the simulation has finished
    bool isFinishedSimulation();

    // Update all the information
    void updateInformation();

    // Make one step on the simulation
    void step();

private:

    // The world where we are going to update and draw on the screen
    World* world;

    // The robot that we are going to update and draw on the screen
    Robot* robot;

    // The time we go to wait on the step on the simulation
    const std::chrono::milliseconds WAIT;

    // Variable for get the time from the clock
    std::chrono::system_clock systemClock;

    // The last time when we enter the function
    std::chrono::system_clock::time_point lastRun;

    // Queue of all the poses left
    std::queue<util::Pose> posesRead;

    // Queue where we know all the ranges for the simulation
    std::queue< std::vector<double> > rangesRead;

    // Read an convert the poses on the file
    void readPoses(const std::string );

    // Read and convert all the ranges on the file
    void readRanges(const std::string );

    // Update the time for the next step for the simulation
    void updateTime();

};


#endif //CS22510_SIMULATION_H
