//
// Created by Jose Vives on 29/02/2016.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "World.h"
#include "Robot.h"

const std::string path = "data/";
const std::string posesFilename = "poses.txt";
const std::string rangesFilename = "ranges.txt";

using namespace std;

void readPoses(Robot* robot){

    std::ifstream infile(path + posesFilename);
    if(!infile.is_open()){
        std::cout << "file not found" << std::endl;
        infile.close();
        return;
    }

    std::string line;
    while(std::getline(infile, line)){
        std::istringstream iss(line);
        double x, y;
        int orientation;
        if(!(iss >> x >> y >> orientation)){
            break;
        }
        std::cout << "x: " << x << " y:" << y << " o: " << orientation << std::endl;
        robot -> nextMove(x, y, orientation);
    }

    infile.close();

}

void readRanges(Robot* robot){

    std::ifstream infile(path + rangesFilename);
    if(!infile.is_open()){
        std::cout << "file not found" << std::endl;
        infile.close();
        return;
    }

    std::string line;
    while(std::getline(infile, line)){

        std::istringstream iss (line);

        array<double, Robot::NUMBER_SENSORS> tmp;

        for(int i = 0; i < Robot::NUMBER_SENSORS; i++){
            iss >> tmp[i];
        }

//        robot -> setRanges(tmp);

    }

    infile.close();

}

int main() {

    World* world;
    world = new World();

    Robot* robot;
    robot = new Robot(world);

    readRanges(robot);

    cout << "FINISH!" << endl;

    return 0;
}