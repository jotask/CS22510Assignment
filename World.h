#ifndef CS22510_WORLD_H
#define CS22510_WORLD_H

#include "Config.h"
#include "Util.hpp"

class World {

public:
    // Constructor for this class
    World(const configuration&);

    // Destructor for this class
    ~World();

    // The world width
    const unsigned int WORLD_WIDTH;

    // The world height
    const unsigned int WORLD_HEIGHT;

    // The cell size
    const double CELL_SIZE;

    // Convert virtual coordinates to real coordinates
    double virtualToReal(const int&);

    // Convert real coordinates to virtual coordinates
    unsigned int realToVirtual(const double&);

    // Get the value from a specified cell
    util::Cell getValueAt(unsigned int, unsigned int);

    // Set the value from a specified cell
    void setValueAt(unsigned int, unsigned int, util::Cell);

private:

    // The world as an 2D array of Cells
    util::Cell** world;

};

#endif //CS22510_WORLD_H
