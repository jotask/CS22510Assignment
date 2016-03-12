#ifndef CS22510_VECTOR2_H
#define CS22510_VECTOR2_H


class Vector2 {
public:
    Vector2();
    Vector2(unsigned int, unsigned int);
    ~Vector2();

    unsigned int getX(void);
    unsigned int getY(void);
    void setX(unsigned int);
    void setY(unsigned int);
    void set(unsigned int, unsigned int);

private:
    unsigned int x;
    unsigned int y;
    void init(unsigned int, unsigned int);

};


#endif //CS22510_VECTOR2_H
