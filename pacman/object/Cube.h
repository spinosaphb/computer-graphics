#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

class Cube : public Object {
public:
    Cube(Color color = Color(0.1,0.1,0.6), Point point = Point(), bool drawOrigin = false, float originSize = 2);

    ~Cube();

    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));
};

#endif