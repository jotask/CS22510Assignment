#ifndef CS22510_UTIL_HPP
#define CS22510_UTIL_HPP

namespace util{

    // Struct for store poses
    struct Pose{
        double x, y;
        int o;
    };

    // All the possible cell tpyes
    enum Cell {
        EMPTY,
        OBSTACLE,
        ROBOT
    };

    // Number pi for the radian calculation
    constexpr double PI = 3.141592653589793;

    // Convert degrees to radian
    double degreeToRadian(const int);

};

#endif //CS22510_UTIL_HPP
