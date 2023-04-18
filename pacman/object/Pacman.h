#include "Object.h"

class Pacman : public Object {
public:
    Pacman();
    Pacman(Point point);
    Pacman(Point point, float radius);
    Pacman(Point point, float radius, Color color);
    // ~Pacman();
    // Functions
    void draw();
    void move();
};