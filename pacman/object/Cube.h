#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

class Cube : public Object {
public:
    Cube(Color color = Color(0.1,0.1,0.6), Point point = Point());

    ~Cube();

    void _draw();
};

#endif