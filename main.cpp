//
// Created by Jose Vives on 29/02/2016.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "World.h"
#include "Robot.h"

const std::string path = "data/";
const std::string posesFilename = "poses.txt";
const std::string rangesFilename = "ranges.txt";

using namespace std;

vector< vector<double> > readPoses(){

    vector< vector<double> > posesReaded;

    ifstream infile(path + posesFilename);
    if(!infile.is_open()){
        std::cout << "file not found" << std::endl;
        infile.close();
        return posesReaded;
    }

    std::string line;
    while(std::getline(infile, line)){
        std::istringstream iss(line);
        double x, y;
        int orientation;

        vector<double> tmp(3);

        for(int i = 0; i < 3; i++){
            iss >> tmp[i];
        }

        posesReaded.push_back(tmp);
    }

    infile.close();

    return posesReaded;

}

vector< vector<double> > readRanges() {

    vector< vector<double> > rangesReaded;

    std::ifstream infile(path + rangesFilename);
    if(!infile.is_open()){
        std::cout << "file not found" << std::endl;
        infile.close();
        return rangesReaded;
    }

    std::string line;
    while(std::getline(infile, line)){

        std::istringstream iss (line);

        vector<double> tmp(Robot::NUMBER_SENSORS);

        for(int i = 0; i < Robot::NUMBER_SENSORS; i++){
            iss >> tmp[i];
        }

        rangesReaded.push_back(tmp);

    }

    infile.close();

    return rangesReaded;

}

void setRobot(Robot* robot, vector<double> p, vector<double> *r){
    // FIXME convert to grid coordinates
    int x, y, orientation;
    x = p[0];
    y = p[1];
    orientation = p[2];
    robot -> setPosition(x, y);
    robot -> setOrientation(orientation);
    robot -> setRanges(*r);
}

int main() {

    vector< vector<double> > poses;
    poses = readPoses();

    vector< vector<double> > ranges;
    ranges = readRanges();

    if(poses.size() != ranges.size()){
        cout << "something is wrong" << endl;
        return -1;
    }

    World* world;
    world = new World();

    Robot* robot;
    robot = new Robot(world);

    while(!poses.empty() && !ranges.empty()){

        world -> printWorld();

        setRobot(robot, poses.front(), &ranges.front());
        poses.erase(poses.begin());
        ranges.erase(ranges.begin());

    }

    return 0;
}