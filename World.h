//
// Created by Jose Vives on 29/02/2016.
//

#ifndef CS22510_WORLD_H
#define CS22510_WORLD_H

class World {

public:
    World();
    ~World();
    void printWorld(void);

private:
    static const int WORLD_WIDTH = 5;
    static const int WORLD_HEIGHT = 5;
    bool world [WORLD_WIDTH][WORLD_HEIGHT];
};

#endif //CS22510_WORLD_H
