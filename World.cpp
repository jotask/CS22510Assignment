//
// Created by Jose Vives on 29/02/2016.
//

#include <iostream>
#include "World.h"

using namespace std;

World::World() {

    // Initialize the world with an empty grid
    for(int x = 0; x < World::WORLD_WIDTH; x++){
        for(int y = 0; y < World::WORLD_HEIGHT; y++){
            this -> world[x][y] = false;
        }
    }
}

World::~World() {
    cout << "World destroyed" << endl;
}

void World::printWorld() {
    // Print the world
    for(int x = 0; x < World::WORLD_WIDTH; x++){
        for(int y = 0; y < World::WORLD_HEIGHT; y++){
            if(world[x][y]){
                cout << '#';
            }else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}