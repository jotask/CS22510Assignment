#include "Config.h"

/**
 * Constructor that take the arguments passed to the program when it run
 *
 * @arg argc: the number of arguments passed
 * @arg argv: the arguments passed when the program runs
 */
Config::Config(const int argc, char* argv[]) {

    readArguments(argc, argv);

}

/**
 * Destructor of this class
 */
Config::~Config() {

}

/**
 * Read the arguments and creates the customized configuration from the values
 *
 * @arg argc: the number of arguments passed
 * @arg argv: the arguments passed when the program runs
 */
void Config::readArguments(const int argc, char* argv[]){

    // Check if have more than one value. This is because for default the program have always
    // one arguments and his his name and his path
    if (argc > 1) {

        // Go throw all the arguments
        for (int i = 1; i < argc; i++) {

            // Store the arguments on a string
            const std::string buff = argv[i];

            // Store the command for know if is a value argument
            const std::string command = getCommand(buff);

            if(buff == "-debug"){

                // Enable debug
                config.debug = true;

            }else if(command == "-delay"){

                // Store the delay value
                float delay;
                delay = getFloat(buff);

                // Small check because delay can't be negative
                if(delay > 0.0)
                    config.delay = delay;

            }else if(buff == "-screen"){

                // Set if we want store each step on an image
                config.saveScreenShoots = true;

            }else if(command == "-poses"){

                // Get and save the file for the poses file
                std::string pose;
                pose = getString(buff);
                config.posesFile = pose;

            }else if(command == "-ranges"){

                // Get and save the ranges file for the ranges
                std::string range;
                range = getString(buff);
                config.rangesFile = range;

            }else if(command == "-dWidth"){

                // The world width length
                // Its unsigned because the world can't have negative dimensions
                unsigned int width;
                width = getUnsignedInt(buff);
                config.displayWidth = width;

            }else if(command == "-dHeight"){

                // The world height length
                // Its unsigned because the world can't have negative dimensions
                unsigned int height;
                height = getUnsignedInt(buff);
                config.displayHeight = height;

            }

        }
    }

}

/**
 * Get the float value from an string
 *
 * @arg buff: The buffer where we want extract the value
 *
 * @return: The float value from the argument
 */
float Config::getFloat(std::string buff){

    // Initial position
    size_t pos = 0;

    // Find where is the delimiter
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        // Delete everything
        buff.erase(0, pos + DELIMITER.length());
    }

    // return the value finded
    // atof convert an string to a double
    return (float) std::atof(buff.c_str());
}

/**
 * Get the unsigned int value from an string
 *
 * @arg buff: The buffer where we want extract the value
 *
 * @return: The unsigned int value from the argument
 */
unsigned int Config::getUnsignedInt(std::string buff){

    // Initial position
    size_t pos = 0;

    // Find where is the delimiter
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        buff.erase(0, pos + DELIMITER.length());
    }

    // Store the value and make sure that the result is absolute,so
    // is not eny possibility to this number be negative
    unsigned int result;
    result = (unsigned int) abs(atoi(buff.c_str()));
    return result;

}

/**
 * From a string get the command for if is a argument with value
 *
 * @arg buff: the string where we want to extract the command
 *
 * @return: the command without his value from the buffer string
 */
std::string Config::getCommand(std::string buff){

    // Initial position
    size_t pos = 0;

    // A string for store the command
    std::string command;

    // Find the command on the buffer and stor
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        command = buff.substr(0, pos);
        buff.erase(0, pos + DELIMITER.length());
    }

    // return the command founded
    return command;
}

/**
 * From a string return the value assigned to the command
 *
 * @arg buff: the string where we need to extract the value
 *
 * @return: the value from the string
 */
std::string Config::getString(std::string buff){

    // Initial position
    size_t pos = 0;

    // Find the value
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        buff.erase(0, pos + DELIMITER.length());
    }

    // Return the value defined
    return buff;
}

/**
 * Get the configuration created
 */
configuration Config::getConfig(){
    return config;
}


