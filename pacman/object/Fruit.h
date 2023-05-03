#ifndef FRUIT_H
#define FRUIT_H

#include <Object.h>
#include <Cube.h>
#include <ScorePoint.h>

class Fruit : public Object {
public:
    Fruit(Color cherryColor = Fruit::FRUIT_COLOR, Color stalkColor = Fruit::STALK_COLOR);
    ~Fruit();
    void _draw();

private:
    static const Color FRUIT_COLOR;
    static const Color STALK_COLOR;

    Color cherryColor;
    Color stalkColor;

};

#endif