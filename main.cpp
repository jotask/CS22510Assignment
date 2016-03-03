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

    World* world;
    world = robot -> getWorld();

    x = world -> convertToWorldCoordinates(p[0]);
    y = world -> convertToWorldCoordinates(p[1]);

//    cout << "x:" << p[0] << " y:" << p[1] << endl;
//    cout << "x:" << x << " y:" << y << endl << endl;

    orientation = (int)p[2];
    robot -> setPosition(x, y);
    robot -> setOrientation(orientation);

    // Set the values for all the sensors for the robot, for simulation
    Sensor* sensors;
    robot -> getSensors();
    for(int i = 0; i < Robot::NUMBER_SENSORS; i++){
        double tmp;
        tmp = r -> at(i);
        sensors -> setRead(tmp);
    }
}

void information(World* world, double test){
    cout << "O: " << test << " C: " << world -> convertToWorldCoordinates(test) << endl;
}

int main() {

//    vector< vector<double> > poses;
//    poses = readPoses();
//
//    vector< vector<double> > ranges;
//    ranges = readRanges();
//
//    if(poses.size() != ranges.size()){
//        cout << "something is wrong" << endl;
//        return -1;
//    }

    World* world;
    world = new World();

    Robot* robot;
    robot = new Robot(world);

//    while(!poses.empty() && !ranges.empty()){
//
////        world -> printWorld();
//
//        setRobot(robot, poses.front(), &ranges.front());
//        poses.erase(poses.begin());
//        ranges.erase(ranges.begin());
//
//        robot -> update();
//
//    }

    for(int i = 0; i < World::WORLD_WIDTH; i++){
        for(int j = 0; j < World::WORLD_HEIGHT; j++){
            world -> setValueAt(i, j, true);
        }
    }

    world -> printWorld();

    return 0;

}