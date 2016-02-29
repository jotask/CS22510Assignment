//
// Created by Jose Vives on 29/02/2016.
//

#include "World.h"
#include "Robot.h"

int main() {

    World* world;
    world = new World();

    Robot* robot;
    robot = new Robot(world);

    // Destroy everything
    world -> ~World();

    return 0;
}