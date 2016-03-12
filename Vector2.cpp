#include "Vector2.h"

Vector2::Vector2(unsigned int x, unsigned int y) {
    this -> init(x, y);
}

Vector2::Vector2() {
    this -> init(0, 0);
}

Vector2::~Vector2() {
}

void Vector2::init(unsigned int x, unsigned int y) {
    this->setX(x);
    this->setY(y);
}

unsigned int Vector2::getX() {
    return this -> x;
}

unsigned int Vector2::getY() {
    return this -> y;
}

void Vector2::setX(unsigned int x) {
    this -> x = x;
}

void Vector2::setY(unsigned int y) {
    this -> y = y;
}

void Vector2::set(unsigned int x, unsigned int y){
    this -> setX(x);
    this -> setY(y);
}
