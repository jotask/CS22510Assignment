//
// Created by Jota on 02/03/2016.
//

#ifndef CS22510_SENSOR_H
#define CS22510_SENSOR_H


class Sensor {
public:
    Sensor(int, int);
    ~Sensor();

    double getRead();
    double setRead(double);

private:

    int orientation;
    int degree;
    double read;

};


#endif //CS22510_SENSOR_H
