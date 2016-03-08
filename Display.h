#ifndef CS22510_DISPLAY_H
#define CS22510_DISPLAY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "Simulation.h"

class Display {
public:
    Display(unsigned int, unsigned int, const char*, unsigned int, Simulation&);
    ~Display();

    void loop();
    void setInterval();


private:

    static const bool isDebug = false;

    sf::RenderWindow* window;
    Simulation* simulation;

    void update();
    void render();

};


#endif //CS22510_DISPLAY_H
