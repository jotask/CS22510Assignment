#ifndef CS22510_WORLD_H
#define CS22510_WORLD_H

#include "Util.h"

class World {

public:
    World();
    ~World();

    static const int WORLD_WIDTH = 50;
    static const int WORLD_HEIGHT = 50;
    static constexpr double CELL_SIZE = 0.2;

    void printWorld(void);

    Util::Cell getValueAt(int, int);
    void setValueAt(int, int, Util::Cell);

private:

    Util::Cell world [WORLD_WIDTH][WORLD_HEIGHT];

};

#endif //CS22510_WORLD_H
