#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    Sphere(Color color = Sphere::DEFAULT_COLOR, bool semi = false, double radius = Sphere::DEFAULT_RADIUS, 
           int slices = Sphere::DEFAULT_SLICES, int stacks = Sphere::DEFAULT_STACKS);
    void _draw();

private:
    float radius;
    int slices;
    int stacks;
    bool semi;

protected:
    static const Color DEFAULT_COLOR;
    static const int DEFAULT_SLICES;
    static const int DEFAULT_STACKS;
    static const double DEFAULT_RADIUS;
};

#endif