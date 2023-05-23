#include <Fruit.h>
#include <gui_glut/gui.h>

Fruit::Fruit(bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->selfType = ObjectType::FRUIT;
}

Fruit::~Fruit() {}


void Fruit::_draw(set<Object*>& hierarchy) {
    // draw cherry
    glRotatef(-30, 1, 1, 0);
    Pill cherry = Pill(this->cherryColor);
    // draw the first cherry on the left
    cherry.scale(.3, .3, .3, true);
    cherry.translate(-1, 0, 0);
    cherry.draw(1, hierarchy);

    // draw the second cherry on the right
    cherry.translate(2, 0, 0);
    cherry.draw(MAX_UNSTACKS, hierarchy);

    // draw cherry stalk
    Cube stalk = Cube(this->stalkColor);

    // draw the first stalk
    stalk.translate(0, .8, 0);
    stalk.rotate(-30, 0, 0, 1);
    stalk.scale(.2, 2.5, .2);
    stalk.scale(.3, .3, .3);
    stalk.draw(MAX_UNSTACKS, hierarchy);

    // draw the second stalk
    stalk.translate(.37, .5, 0);
    stalk.rotate(45, 0, 0, 1);
    stalk.scale(.2, 1.6, .2);
    stalk.scale(.3, .3, .3);
    stalk.draw(MAX_UNSTACKS, hierarchy);
}