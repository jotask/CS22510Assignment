//
// Created by jota on 05/03/16.
//

#ifndef CS22510_UTIL_H
#define CS22510_UTIL_H


class Util {

public:

    static double degreeToRadian(int degree){
        return degree * (PI / 180);
    }

private:

    // TODO more accurate value
    static constexpr double PI = 3.14159265;

};


#endif //CS22510_UTIL_H
