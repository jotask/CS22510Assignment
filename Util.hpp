#ifndef CS22510_UTIL_HPP
#define CS22510_UTIL_HPP

namespace util{

    struct Pose{
        double x, y;
        int o;
    };

    enum Cell {
        EMPTY,
        OBSTACLE,
        ROBOT
    };

    constexpr double PI = 3.141592653589793;

    double degreeToRadian(const int);

};

#endif //CS22510_UTIL_HPP
