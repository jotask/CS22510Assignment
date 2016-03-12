#include "World.h"

World::World(const configuration& config) : WORLD_WIDTH(config.worldWidth), WORLD_HEIGHT(config.worldHeight),
CELL_SIZE(config.cellSize){

    world = new util::Cell*[WORLD_WIDTH];
    for(unsigned int i = 0; i < WORLD_WIDTH; i++){
        world[i] = new util::Cell[WORLD_HEIGHT];
    }

    // Initialize the world with an empty grid
    for(unsigned int x = 0; x < World::WORLD_WIDTH; x++){
        for(unsigned int y = 0; y < World::WORLD_HEIGHT; y++){
            this -> world[x][y] = util::Cell::EMPTY ;
        }
    }

}

World::~World() {

    for(unsigned int i = 0; i < WORLD_WIDTH; i++){
        delete world[i];
    }

    delete [] world;
}

void World::printWorld() {
    // Print the world
    for(unsigned int x = 0; x < World::WORLD_WIDTH; x++){
        for(unsigned int y = 0; y < World::WORLD_HEIGHT; y++){
            std::cout << '[';
            switch (world[x][y]){
                case util::Cell::OBSTACLE:
                    std::cout << 'O';
                    break;
                case util::Cell::ROBOT:
                    std::cout << 'R';
                    break;
                case util::Cell:: EMPTY:
                    std::cout << ' ';
                default:
                    break;
            }
            std::cout << ']';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;
}

util::Cell World::getValueAt(int x, int y) {
    return this -> world[x][y];
}

void World::setValueAt(unsigned int x, unsigned int y, util::Cell type) {
    if(x < WORLD_WIDTH && y < WORLD_HEIGHT)
        this -> world[x][y] = type;
}

double World::virtualToReal(const int &a) {
    double tmp;
    tmp = ((a * ((CELL_SIZE) * (WORLD_WIDTH))) / (WORLD_WIDTH));
    return tmp;
}

unsigned int World::realToVirtual(const double &a) {
    unsigned int tmp;
    tmp = (unsigned int) ((WORLD_WIDTH * a) / (CELL_SIZE * (WORLD_WIDTH)));
    return tmp;
}