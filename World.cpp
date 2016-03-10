#include <iostream>
#include "World.h"

using namespace std;

World::World() {

    // Initialize the world with an empty grid
    for(unsigned int x = 0; x < World::WORLD_WIDTH; x++){
        for(unsigned int y = 0; y < World::WORLD_HEIGHT; y++){
            this -> world[x][y] = Util::Cell::EMPTY ;
        }
    }

}

World::~World() {
}

void World::printWorld() {
    // Print the world
    for(unsigned int x = 0; x < World::WORLD_WIDTH; x++){
        for(unsigned int y = 0; y < World::WORLD_HEIGHT; y++){
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
    this -> world[x][y] = type;
}
