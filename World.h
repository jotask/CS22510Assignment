#ifndef CS22510_WORLD_H
#define CS22510_WORLD_H

#include "Config.h"
#include "Util.hpp"

class World {

public:
    World(const configuration&);
    ~World();

    const unsigned int WORLD_WIDTH;
    const unsigned int WORLD_HEIGHT;
    const double CELL_SIZE;

    void printWorld(void);


    double virtualToReal(const int&);
    unsigned int realToVirtual(const double&);

    util::Cell getValueAt(int, int);
    void setValueAt(int, int, util::Cell);

private:

    util::Cell** world;

};

#endif //CS22510_WORLD_H
