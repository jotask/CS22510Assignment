#ifndef CS22510_WORLD_H
#define CS22510_WORLD_H

#include "Resources.h"

class World {

public:
    World();
    ~World();

    static const int WORLD_WIDTH = 50;
    static const int WORLD_HEIGHT = 50;
    static constexpr double CELL_SIZE = 0.2;

    void printWorld(void);
    int convertToWorldCoordinates(double x);

    bool getValueAt(int, int);
    void setValueAt(int, int, Resources::Cell);

private:

    Resources::Cell world [WORLD_WIDTH][WORLD_HEIGHT];

};

#endif //CS22510_WORLD_H
