#ifndef FRUIT_H
#define FRUIT_H

#include <Object.h>
#include <Cube.h>
#include <Pill.h>

class Fruit : public Object {
public:
    Fruit(Color cherryColor = Fruit::FRUIT_COLOR, Color stalkColor = Fruit::STALK_COLOR, bool drawOrigin = false, float originSize = 2);
    ~Fruit();
    void _draw();

private:
    static const Color FRUIT_COLOR;
    static const Color STALK_COLOR;

    Color cherryColor;
    Color stalkColor;

};

#endif