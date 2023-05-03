#ifndef PACMAN_H
#define PACMAN_H

#include <Object.h>

class TopBody : public Object {
public:
    TopBody(Color color = Color(1,1,0));
    ~TopBody();
    void _draw();
};

class BottomBody : public Object {
public:
    BottomBody(Color color = Color(1,1,0));
    ~BottomBody();
    void _draw();
};

class Pacman : public Object {
public:
    Pacman(Color color = Color(1,1,0), float mouthAngle = 60);
    ~Pacman();
    void _draw();

private:
    void _drawPacmanBody(Color bc, Color mc = Color(0,0,0));
    TopBody topBody;
    BottomBody bottomBody;
    float defaultMouthAngle;
};




#endif