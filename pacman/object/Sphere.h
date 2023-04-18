#include "Object.h"

class Sphere : public Object {
public:
    Sphere();
    Sphere(Color color);
    Sphere(Color color, Point point);
    Sphere(Color color, Point point, float radius);
    // ~Sphere();
    // Functions
    void draw();

private:
    // Attributes
    Color color;
    Point point;
    float radius;
};