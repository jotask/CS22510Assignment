//
// Created by jota on 10/03/16.
//

#include "Config.h"

using namespace std;

Config::Config(const int argc, char* argv[]) {

    readArguments(argc, argv);

}

Config::~Config() {

}

void Config::print() {

    cout << "Debug: " << config.debug << endl;
    cout << "Delay: " << config.delay << endl;
    cout << "SaveScreen: " << config.saveScreenShoots << endl;
    cout << "Poses: " << config.posesFile << endl;
    cout << "Ranges: " << config.rangesFile << endl;

    cout << "Title: " << config.displayTitle << endl;
    cout << "Width: " << config.displayWidth << endl;
    cout << "Height: " << config.displayHeight << endl;
    cout << "Fps: " << config.displayFps << endl;

}

void Config::readArguments(const int argc, char* argv[]){

    if (argc > 1) {
        for (int i = 0; i < argc; i++) {

            const std::string buff = argv[i];
            std::string command = getCommand(buff);

            if(buff == "-debug"){

                config.debug = true;

            }else if(command == "-delay"){

                float delay;
                delay = getFloat(buff);

                if(delay > 0.0)
                    config.delay = delay;

            }else if(buff == "-screen"){

                config.saveScreenShoots = true;

            }else if(command == "-poses"){

                std::string pose;
                pose = getString(buff);

                config.posesFile = pose;

            }else if(command == "-ranges"){

                std::string range;
                range = getString(buff);

                config.rangesFile = range;

            }else if(command == "-dWidth"){

                unsigned int width;
                width = getUnsignedInt(buff);

                config.displayWidth = width;

            }else if(command == "-dHeight"){

                unsigned int height;
                height = getUnsignedInt(buff);

                config.displayHeight = height;

            }else if(command == "-fps"){

                unsigned int fps;
                fps = getUnsignedInt(buff);

                config.displayFps = fps;

            }

        }
    }

    cout << endl;

}
float Config::getFloat(std::string buff){
    size_t pos = 0;
    std::string token;
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        token = buff.substr(0, pos);
        buff.erase(0, pos + DELIMITER.length());
    }
    return std::atof(buff.c_str());
}

unsigned int Config::getUnsignedInt(std::string buff){
    size_t pos = 0;
    std::string token;
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        token = buff.substr(0, pos);
        buff.erase(0, pos + DELIMITER.length());
    }
    return atoi(buff.c_str());

}

std::string Config::getCommand(std::string buff){
    size_t pos = 0;
    std::string token;
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        token = buff.substr(0, pos);
        buff.erase(0, pos + DELIMITER.length());
    }
    return token;
}

std::string Config::getString(std::string buff){
    size_t pos = 0;
    std::string token;
    while ((pos = buff.find(DELIMITER)) != std::string::npos) {
        token = buff.substr(0, pos);
        buff.erase(0, pos + DELIMITER.length());
    }
    return buff;
}

configuration Config::getConfig(){
    return config;
}


