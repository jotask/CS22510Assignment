#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"
#include "Robot.h"
#include "Simulation.h"
#include "Display.h"

using namespace std;

/**
 * Main function where all start
 * Here is instantiate all the main classes
 *
 * @arg argc: number of arguments passed to the program
 * @arg argv: an array of all arguments catched
 */
int main(int argc, char* argv[]) {

    // Build the configuration for the application
    Config* config = new Config (argc, argv);

    // Save a copy of the configuration
    const configuration c = config -> getConfig();

    // Delete the configuration class. We don't need this anymore in our program life
    delete config;

    // Instantiate the world
    World world;

    // Instantiate the robot
    Robot robot (world);

    // Instantiate the simulation handler
    Simulation simulation (robot, c);

    // Quick check for see if the files are correct and everything is ready for the simulation
    if(!simulation.hasToSimulate()){
        cout << "Error reading the files for the simulation" << endl;
        return 1;
    }

    // Instantiate the display
    Display display (c, simulation);

    // Init the animation
    display.loop();

    // Successfully exit the program
    return 0;

}