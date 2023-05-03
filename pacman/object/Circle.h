#ifndef CIRCLE_H
#define CIRCLE_H

#include <Sphere.h>
#include <GL/glut.h>

class Circle : public Sphere {
public:
    Circle(
        Color color = Color(), 
        float cx = 0, float cy = 0,
        double radius = Circle::DEFAULT_RADIUS,
        int stacks = Circle::DEFAULT_STACKS);
    void _draw();

private:
    // Attributes
    float cx;
    float cy;
    double radius;
    int stacks;
};

#endif