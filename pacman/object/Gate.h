#ifndef GATE_H
#define GATE_H

#include <Object.h>
#include <Cube.h>
#include <Pyramid.h>

class Gate : public Object {
public:
    Gate(Color color = Color(1,0,0), bool drawOrigin = false, float originSize = 2);
    ~Gate();
    void _draw();
private:
    void _drawFlag();
};

#endif
