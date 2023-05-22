#include <Phantom.h>
#include <Sphere.h>
#include <Cylinder.h>
#include <Circle.h>
#include <gui.h>

Phantom::Phantom(ghost::PhantomColor color, bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->color = this->phantomColors.at(color);
    this->colorFlag = color;
    this->selfType = ObjectType::PHANTOM;
}

Phantom::~Phantom() {}

void Phantom::_draw(set<Object*>& hierarchy) {
    // Draw head
    glScalef(1, .75, 1);
    glTranslatef(0, .25, 0);
    Sphere head = Sphere(this->color, true);
    head.rotate(90, 1, 0, 0);
    head.draw(INFINITY, hierarchy);

    // Draw body
    Cylinder body = Cylinder(this->color);
    body.scale(.5,.5,.5, true);
    body.translate(0, 0.1, 0);
    body.rotate(90, 1,0,0);
    body.draw(INFINITY, hierarchy);

    // Draw bottom
    Circle bottom = Circle(this->color);
    bottom.translate(0,-0.7,0);
    bottom.rotate(90, 1, 0, 0);
    bottom.draw(INFINITY, hierarchy);

    // Moviment eyes rotation
    static bool moveRight = true;
    static float eyeRotation = 0;
    static float inc = .25*this->moveFactor;
    if(moveRight) {
        eyeRotation += inc;
        if(eyeRotation >= 5)
            moveRight = false;
    } else {
        eyeRotation -= inc;
        if(eyeRotation <= -5)
            moveRight = true;
    }

    // Draw ires
    Sphere eye = Sphere(Color(0,0,0), true);
    // Left ires
    eye.scale(.2,.2,.2, true);
    (this->colorFlag % 2) 
        ? eye.rotate(eyeRotation, 1, 0, 0, true) 
        : eye.rotate(eyeRotation, 0, 1, 0, true);
    eye.translate(-1.5, 0, 2.3);
    eye.rotate(-10, 0, 1, 0);
    eye.rotate(180, 0, 1, 0);
    eye.draw(INFINITY, hierarchy);
    // Right ires
    eye.translate(1.5, 0, 2.3);
    eye.rotate(10, 0, 1, 0);
    eye.rotate(180, 0, 1, 0);
    eye.draw(INFINITY, hierarchy);

    //Draw pupile
    Sphere pupile = Sphere(Color(1,1,1), true);
    // Left pupile
    pupile.scale(.35,.35,.35, true);
    pupile.rotate(15, 0, 1, 0);
    pupile.translate(-1, 0, .8);
    pupile.rotate(-45, 0, 1, 0);
    pupile.rotate(180, 0, 1, 0);
    pupile.draw(INFINITY, hierarchy);

    // Right pupile
    pupile.rotate(-15, 0, 1, 0);
    pupile.translate(1, 0, .8);
    pupile.rotate(45, 0, 1, 0);
    pupile.rotate(180, 0, 1, 0);
    pupile.draw(INFINITY, hierarchy);
}