#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"
#include "Robot.h"
#include "Simulation.h"
#include "Display.h"
#include "Config.h"

using namespace std;

int main(int argc, char* argv[]) {

    Config* config = new Config (argc, argv);
//    config -> print();

    configuration c = config -> getConfig();

    delete config;

    World world (c);
    Robot robot (world, c);
    Simulation simulation (robot, c);

    if(!simulation.hasToSimulate()){
        cout << "Error reading the files for the simulation" << endl;
        return 1;
    }

    Display display (c, simulation);

    display.loop();

    return 0;

}