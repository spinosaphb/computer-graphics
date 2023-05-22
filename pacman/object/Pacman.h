#ifndef PACMAN_H
#define PACMAN_H

#include <Object.h>

class TopBody : public Object {
public:
    TopBody(Color color = Color(1,1,0));
    ~TopBody();
    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));
};

class BottomBody : public Object {
public:
    BottomBody(Color color = Color(1,1,0));
    ~BottomBody();
    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));
};

class Pacman : public Object {
public:
    Pacman(bool drawOrigin = false, float originSize = 2,  float mouthAngle = 60);
    ~Pacman();
    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));

private:
    void _drawPacmanBody(Color bc, Color mc = Color(0,0,0));
    TopBody topBody;
    BottomBody bottomBody;
    float defaultMouthAngle;
};




#endif