#ifndef GATE_H
#define GATE_H

#include <Object.h>
#include <Cube.h>
#include <Pyramid.h>

class Gate : public Object {
public:
    Gate(bool drawOrigin = false, float originSize = 2);
    ~Gate();
    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));
private:
    void _drawFlag(set<Object*>& hierarchy);
};

#endif
