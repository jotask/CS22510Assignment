//
// Created by jota on 05/03/16.
//

#ifndef CS22510_RESOURCES_H
#define CS22510_RESOURCES_H


class Resources {
public:
    class Poses{
    public:
        Poses(double x, double y, double o){
            this -> x = x;
            this -> y = y;
            this -> o = o;
        };

        int getX(){ return this -> x;};
        int getY(){ return this -> y;};
        int getO(){ return this -> o;};
    private:
        int x;
        int y;
        int o;

    };
    enum Cell{
        EMPTY, OBSTACLE, ROBOT
    };
private:

};


#endif //CS22510_RESOURCES_H
