#ifndef CS22510_SENSOR_H
#define CS22510_SENSOR_H


class Sensor {
public:
    // The infinite range for an sensor
    static constexpr double INFINITE = 2.5;

    // Constructor
    Sensor(int);

    // Destructor
    ~Sensor();

    // Read the value from the sensor
    double getRead();

    // Set the value for reading the sensor
    void setRead(double);

    // Get the degree for the sensor
    int getDegree();

private:

    // The degree of this sensor
    int degree;

    // the read value for this sensor
    double read;

};


#endif //CS22510_SENSOR_H
