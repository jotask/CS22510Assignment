#ifndef CS22510_VECTOR2_H
#define CS22510_VECTOR2_H

/**
 * This class holds the coordinates for a 2D world
 */
class Vector2 {
public:
    // Constructor for this class
    Vector2();
    Vector2(unsigned int, unsigned int);

    // Destructor for this class
    ~Vector2();

    // Get the value on X
    unsigned int getX(void);

    // Get the value on Y
    unsigned int getY(void);

    // Set the value on X
    void setX(unsigned int);

    // Set the value on Y
    void setY(unsigned int);

    // Set X and Y at the same time
    void set(unsigned int, unsigned int);

private:

    // X and Y. Those are unsigned because they can't have negative values
    unsigned int x;
    unsigned int y;

};


#endif //CS22510_VECTOR2_H
