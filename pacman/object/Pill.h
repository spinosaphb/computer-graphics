#ifndef PILL_H
#define PILL_H
#include <Object.h>
#include <Cube.h>
#include <Pyramid.h>
#include <GL/glut.h>

class Pill : public Object {
public:
    Pill(Color color = Color(), bool drawOrigin = false, float originSize = 2);
    ~Pill();
    void _draw();
};

class PowerPill : public Object {
public:
    PowerPill(Color color = Color(), bool drawOrigin = false, float originSize = 2);
    ~PowerPill();
    void _draw();
private:
    Pill pill;
    void _makeAnimation();
};

#endif