#include <iostream>
#include "World.h"

using namespace std;

World::World() {

    // Initialize the world with an empty grid
    for(int x = 0; x < World::WORLD_WIDTH; x++){
        for(int y = 0; y < World::WORLD_HEIGHT; y++){
            this -> world[x][y] = Resources::Cell::EMPTY ;
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
                case Resources::Cell::OBSTACLE:

                    cout << 'O';
                    break;
                case Resources::Cell::ROBOT:
                    cout << 'R';
                    break;
                case Resources::Cell:: EMPTY:
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

int World::convertToWorldCoordinates(double x) {
    int index;
    index = 0;

    double current;
    current = 0.0;

//    cout << "before" << endl;
    while(current < x){
        current += World::CELL_SIZE;
        index++;
//        cout << "------------------------" << x << " ======== " << current << endl;
    }
//    cout << "after" << endl;

    return index;
}

bool World::getValueAt(int x, int y) {
    return this -> world[x][y];
}

void World::setValueAt(int x, int y, Resources::Cell type) {
//    cout << "X: " << x << " Y: " << y << " V: " << value << endl;
    this -> world[x][y] = type;
}