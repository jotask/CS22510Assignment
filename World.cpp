#include <iostream>
#include <tgmath.h>
#include "World.h"

using namespace std;

World::World() {

    // Initialize the world with an empty grid
    for(int x = 0; x < World::WORLD_WIDTH; x++){
        for(int y = 0; y < World::WORLD_HEIGHT; y++){
            this -> world[x][y] = Util::Cell::EMPTY ;
        }
    }

}

World::~World() { }

void World::printWorld() {
    // Print the world
    for(int x = 0; x < World::WORLD_WIDTH; x++){
        for(int y = 0; y < World::WORLD_HEIGHT; y++){
            cout << '[';
            switch (world[x][y]){
                case Util::Cell::OBSTACLE:
                    cout << 'O';
                    break;
                case Util::Cell::ROBOT:
                    cout << 'R';
                    break;
                case Util::Cell:: EMPTY:
                    cout << ' ';
                default:
                    break;
            }
            cout << ']';
        }
        cout << endl;
    }

    cout << endl << endl;
}

Util::Cell World::getValueAt(int x, int y) {
    return this -> world[x][y];
}

void World::setValueAt(int x, int y, Util::Cell type) {
    string t = "";
    switch (type){
        case Util::Cell::EMPTY:
            t = "EMPTY";
            break;
        case Util::Cell::ROBOT:
            t = "ROBOT";
            break;
        case Util::Cell::OBSTACLE:
            t = "OBSTACLE";
            break;
    }
//    cout << "X: " << x << " Y: " << y << " Type: " << t << endl;
    this -> world[x][y] = type;
}
