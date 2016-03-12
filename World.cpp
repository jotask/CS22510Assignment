#include "World.h"

/**
 * Constructor for this class. This initialize all the constants and creates the world
 *
 * @arg config: reference to the configuration
 */
World::World(const configuration& config) : WORLD_WIDTH(config.worldWidth), WORLD_HEIGHT(config.worldHeight),
CELL_SIZE(config.cellSize){

    // Create the world on the heap
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

/**
 * Destructor for this class. This deallocate the world on the heap
 */
World::~World() {

    // Deallocate the world
    for(unsigned int i = 0; i < WORLD_WIDTH; i++)
        delete world[i];
    delete [] world;
}

/**
 * Get the value from one specified cell. This check if the dimension is inside our world dimensions.
 * If not it return an empty cell. This can be improve by some invalid cell or something similar
 *
 * @arg x: the x position
 * @arg y: the y position
 *
 * @return: the value of the selected position
 */
util::Cell World::getValueAt(unsigned int x, unsigned int y) {
    if(x < WORLD_WIDTH && y < WORLD_HEIGHT)
        return this -> world[x][y];
    return util::Cell::EMPTY;
}

/**
 * Set one cell from our world. This check if the dimension is inside our world dimensions
 *
 * @arg x: the x position for the cell we want modified
 * @arg y: the y position for the cell we want modified
 * @arg type: the new type for the cell on x and y
 */
void World::setValueAt(unsigned int x, unsigned int y, util::Cell type) {
    if(x < WORLD_WIDTH && y < WORLD_HEIGHT)
        this -> world[x][y] = type;
}

/**
 * Convert a virtual position to a real coordinate
 *
 * @return: the real coordinate
 */
double World::virtualToReal(const int &a) {
    double tmp;
    tmp = ((a * ((CELL_SIZE) * (WORLD_WIDTH))) / (WORLD_WIDTH));
    return tmp;
}

/**
 * Convert a real coordinate to an virtual coordinate
 *
 * @return: the virtual coordinate
 */
unsigned int World::realToVirtual(const double &a) {
    unsigned int tmp;
    tmp = (unsigned int) ((WORLD_WIDTH * a) / (CELL_SIZE * (WORLD_WIDTH)));
    return tmp;
}