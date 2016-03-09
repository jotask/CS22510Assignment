//
// Created by Jota on 29/02/2016.
//

#include <iostream>
#include "Vector2.h"

Vector2::Vector2(int x, int y) {
    this -> init(x, y);
}

Vector2::Vector2() {
    this -> init(0, 0);
}

Vector2::~Vector2() {
}

void Vector2::init(int x, int y) {
    this->setX(x);
    this->setY(y);
}

int Vector2::getX() {
    return this -> x;
}

int Vector2::getY() {
    return this -> y;
}

void Vector2::setX(int x) {
    this -> x = x;
}

void Vector2::setY(int y) {
    this -> y = y;
}

void Vector2::set(int x, int y){
    this -> setX(x);
    this -> setY(y);
}
