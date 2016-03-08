//
// Created by jota on 05/03/16.
//

#ifndef CS22510_UTIL_H
#define CS22510_UTIL_H

#include "World.h"

class Util {

public:

    struct Pose{
        double x, y;
        int o;
    };

    enum Cell {
        EMPTY,
        OBSTACLE,
        ROBOT
    };

    static double degreeToRadian(int degree){
        return degree * (PI / 180);
    }

    static double virtualToReal(const int a) {
        double tmp;
        tmp = ( ( a * (0.2 * 50 ) ) / (50) );
        return tmp;
    }

    static int realToVirtual(const double a){
        int tmp;
        tmp = ( (50 * a) / (0.2 * 50 ) );
        return tmp;
    }

private:

    // TODO more accurate value
    static constexpr double PI = 3.14159265;

};


#endif //CS22510_UTIL_H
