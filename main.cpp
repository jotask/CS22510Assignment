//
// Created by Jose Vives on 29/02/2016.
//

#include <iostream>
#include "World.h"
#include "Robot.h"
#include "Simulation.h"

using namespace std;

int main() {

    const char posesFilename[] = "data/poses.txt";
    const char rangesFilename[] = "data/ranges.txt";

    World world;

    Robot robot (world);

    Simulation simulation (robot, posesFilename, rangesFilename);

    if(simulation.hasToSimulate()){
        cout << "Error reading the files for the simulation" << endl;
        return 1;
    }

    while(!simulation.isFinishedSimulation()){
        cout << "simulation in process" << endl;
    }

    cout << "Simulation finished" << endl;

    return 0;

}