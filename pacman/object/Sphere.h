#include "Object.h"

struct Color {
    float red;
    float green;
    float blue;

    Color(float red=1, float green=0.6, float blue=0): red(red), green(green), blue(blue) {}
};

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