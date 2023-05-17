#ifndef FRUIT_H
#define FRUIT_H

#include <Object.h>
#include <Cube.h>
#include <Pill.h>

class Fruit : public Object {
public:
    Fruit(Color cherryColor = Color(1, 0, .5), Color stalkColor = Color(0, 1, 0), bool drawOrigin = false, float originSize = 2);
    ~Fruit();
    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));

private:

    Color cherryColor;
    Color stalkColor;

};

#endif