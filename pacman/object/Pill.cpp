#include "Pill.h"


Pill::Pill(Color color, bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->color = color;
    this->name = "Pill";
}

Pill::~Pill() {}

void Pill::_draw(set<Object*>& hierarchy) {
    Cube cube1 = Cube(this->color, this->matrix.t);
    Cube cube2 = Cube(this->color, this->matrix.t);
    
    cube1.scale(.65, 1, .65);
    cube2.scale(1, .65, 1);
    cube1.draw(INFINITY, hierarchy);
    cube2.draw(INFINITY, hierarchy);
}

PowerPill::PowerPill(Color color, bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->color = color;
    this->pill = Pill(color);
    this->_makeAnimation();
}

PowerPill::~PowerPill() {}

void PowerPill::_draw(set<Object*>& hierarchy) {
    static float distance = 1.0;
    static bool up = true;

    if (up) {
        distance += .01;
        if (distance > 1.5)
            up = false;
    } else {
        distance -= .01;
        if (distance < 1.0)
            up = true;
    }
    
    
    this->pill.draw(INFINITY, hierarchy);
    
    Pyramid pyramid = Pyramid(this->color);
    
    // top spike
    pyramid.translate(0, distance, 0);
    pyramid.scale(.5, .5, .5);
    pyramid.draw(INFINITY, hierarchy);

    // bottom spike
    pyramid.translate(0, -1 * distance, 0);
    pyramid.rotate(180, 1, 0, 0);
    pyramid.scale(.5, .5, .5);
    pyramid.draw(INFINITY, hierarchy);

    // left spike
    pyramid.translate(-1 * distance, 0, 0);
    pyramid.rotate(90, 0, 0, 1);
    pyramid.scale(.5, .5, .5);
    pyramid.draw(INFINITY, hierarchy);

    // right spike
    pyramid.translate(distance, 0, 0);
    pyramid.rotate(-90, 0, 0, 1);
    pyramid.scale(.5, .5, .5);
    pyramid.draw();

    // front spike
    pyramid.translate(0, 0, distance);
    pyramid.rotate(90, 1, 0, 0);
    pyramid.scale(.5, .5, .5);
    pyramid.draw(INFINITY, hierarchy);

    // back spike
    pyramid.translate(0, 0, -1 * distance);
    pyramid.rotate(-90, 1, 0, 0);
    pyramid.scale(.5, .5, .5);
    pyramid.draw(INFINITY, hierarchy);

}


void PowerPill::_makeAnimation() {
    static bool up = true;
    static float sf = 1; // scale factor
    static float inc = .01 * this->moveFactor;
    if (up) {
        sf += inc;
        if (sf > 1.1) up = false;
    } else {
        sf -= inc;
        if (sf < .9) up = true;
    }
    
    this->scale(sf, sf, sf);
}