#include "Util.hpp"

namespace util {

    /**
     *  Convert degree to radian
     *
     *  @arg degree: the the degree for convert
     *
     *  @return: the radian from the degree passed
     */
    double degreeToRadian(const int degree){
        return degree * (util::PI / 180);
    }

}
