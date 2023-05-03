#ifndef SCOREPOINT_H
#define SCOREPOINT_H
#include "Object.h"
#include "Cube.h"
#include <GL/glut.h>

class ScorePoint : public Object {
public:
    ScorePoint(Color color = Color(), Point point = Point());
    ~ScorePoint();
    void _draw();
};

#endif