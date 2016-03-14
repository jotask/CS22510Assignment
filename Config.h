#ifndef CS22510_CONFIG_H
#define CS22510_CONFIG_H

#include <iostream>

/**
 * Struct that holds all the information that the application needs for his configuration.
 * The struct holds the default information for the program. Meaning that if any argument has been
 * passed throw the main function, we don't change any value and we create initialize everything to
 * his default.
 */
typedef struct config{

    // Enable/Disable debug information
    bool debug = false;

    // Delay for the simulation
    float delay = 1;

    // Enable or disable save each step result to an image
    bool saveScreenShoots = false;

    // Path to the file for the poses
    std::string posesFile = "data/poses.txt";

    // Path to the file for the ranges
    std::string rangesFile = "data/ranges.txt";

    // Display bar title
    const std::string displayTitle = "Robot Simulation";

    // Display Width
    unsigned int displayWidth = 600;

    // Display Height
    unsigned int displayHeight = 600;

    // Number of sensor the robot have
    unsigned int numberSensors = 8;

    // Width for the virtual world
    unsigned int worldWidth = 50;

    // Height for the virtual world
    unsigned int worldHeight = 50;

    // The size of the cell
    double cellSize = 0.2;

} configuration;

/**
 * Class for make the configuration for all the program.
 */
class Config{
public:
    // Constructor
    Config(const int, char**);

    // Destructor
    ~Config();

    // Get a copy of the configuration
    configuration getConfig();

private:

    // Constant for know which is the delimiter used on the arguments
    const std::string DELIMITER = "=";

    // The configuration struct
    configuration config;

    // Read all arguments and read his values
    void readArguments(const int, char**);

    // Convert an string to a his nature command without parameter
    std::string getCommand(std::string);

    // From a string return the value as an int
    unsigned int getUnsignedInt(std::string);

    // From a string return his value as a string
    std::string getString(std::string );

    // From a string return his value has a float
    float getFloat(std::string);

};

#endif //CS22510_CONFIG_H
