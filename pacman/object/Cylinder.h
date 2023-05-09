#ifndef CYLINDER_H
#define CYLINDER_H

#include <Object.h>

class Cylinder : public Object {
public:
    Cylinder(Color color = Color(1,0,0), float base = 1.0, float top = 1.0, float height = 1.5, int slices = 20, int stacks = 20);
    ~Cylinder();
    void _draw();
private:
    float base;
    float top;
    float height;
    int slices;
    int stacks;
};

#endif