//
// Created by jota on 10/03/16.
//

#ifndef CS22510_CONFIG_H
#define CS22510_CONFIG_H

#include <iostream>

typedef struct config{
    bool debug = false;
    float delay = 0.5;
    bool saveScreenShoots = false;
    std::string posesFile = "data/poses.txt";
    std::string rangesFile = "data/ranges.txt";

    std::string displayTitle = "Simulation";
    unsigned int displayWidth = 600;
    unsigned int displayHeight = 600;
    unsigned int displayFps = 30;

} configuration;

class Config{
public:
    Config(const int, char**);
    ~Config();

    configuration getConfig();

    void print();

private:

    const std::string DELIMITER = ":";

    configuration config;

    void readArguments(const int, char**);

    std::string getCommand(std::string);

    unsigned int getUnsignedInt(std::string);

    std::string getString(std::string );

    float getFloat(std::string);

};

#endif //CS22510_CONFIG_H
