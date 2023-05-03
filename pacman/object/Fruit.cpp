#include <Fruit.h>
#include <gui_glut/gui.h>

const Color Fruit::FRUIT_COLOR = Color(1, 0, .5);
const Color Fruit::STALK_COLOR = Color(0, 1, 0);

Fruit::Fruit(Color cherryColor, Color stalkColor) : Object() {
    this->cherryColor = cherryColor;
    this->stalkColor = stalkColor;
    this->rotate(-30, 1, 1, 0);
}

Fruit::~Fruit() {}


void Fruit::_draw() {
    // draw cherry
    ScorePoint cherry = ScorePoint(this->cherryColor);
    // draw the first cherry on the left
    cherry.scale(.3, .3, .3);
    cherry.translate(-1, 0, 0);
    cherry.draw(1);

    // draw the second cherry on the right
    cherry.translate(2, 0, 0);
    cherry.draw();

    // draw cherry stalk
    Cube stalk = Cube(this->stalkColor);

    // draw the first stalk
    stalk.translate(0, .8, 0);
    stalk.rotate(-30, 0, 0, 1);
    stalk.scale(.2, 2.5, .2);
    stalk.scale(.3, .3, .3);
    stalk.draw();

    // draw the second stalk
    stalk.translate(.37, .5, 0);
    stalk.rotate(45, 0, 0, 1);
    stalk.scale(.2, 1.6, .2);
    stalk.scale(.3, .3, .3);
    stalk.draw();
}