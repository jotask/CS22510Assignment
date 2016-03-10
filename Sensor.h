#ifndef CS22510_SENSOR_H
#define CS22510_SENSOR_H


class Sensor {
public:
    static constexpr double INFINITE = 2.5;

    Sensor(int, int);
    ~Sensor();

    double getRead();
    void setRead(double);

    int getDegree();
    int getOrientation();

private:

    int orientation;
    int degree;
    double read;

};


#endif //CS22510_SENSOR_H
