//
// Created by Jota on 29/02/2016.
//

#ifndef CS22510_VECTOR2_H
#define CS22510_VECTOR2_H


class Vector2 {
public:
    Vector2();
    Vector2(int, int);
    ~Vector2();

    int getX(void);
    int getY(void);
    void setX(int);
    void setY(int);

private:
    int x;
    int y;
    void init(int, int);

};


#endif //CS22510_VECTOR2_H
