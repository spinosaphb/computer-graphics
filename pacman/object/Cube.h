#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

class Cube : public Object {
public:
    Cube(Color color = Color(), Point point = Point());

    ~Cube();

    void _draw();
    void draw();
};

#endif