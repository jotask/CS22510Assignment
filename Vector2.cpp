#include "Vector2.h"

/**
 * Initialize this class with custom value for the position
 *
 * @arg x: The x position
 * @arg y: The y position
 */
Vector2::Vector2(unsigned int x, unsigned int y) {
    this -> set(x, y);
}

/**
 * Default constructor for this class. This initialize this class on a position 0, 0. The defautl position.
 */
Vector2::Vector2() {
    this -> set(0, 0);
}

/**
 * Default destructor
 */
Vector2::~Vector2() {
}

/**
 * Get a copy of the x position
 *
 * @return: the x position
 */
unsigned int Vector2::getX() {
    return this -> x;
}

/**
 * Get a copy of the Y position
 *
 * @return: the y position
 */
unsigned int Vector2::getY() {
    return this -> y;
}

/**
 * Set the x position
 *
 * @param x: the new x position
 */
void Vector2::setX(unsigned int x) {
    this -> x = x;
}

/**
 * Set the y position
 *
 * @param y: the new position
 */
void Vector2::setY(unsigned int y) {
    this -> y = y;
}

/**
 * Set both values at the same time
 *
 * @arg x: the new x position
 * @arg y: the new y position
 */
void Vector2::set(unsigned int x, unsigned int y){
    this -> setX(x);
    this -> setY(y);
}
