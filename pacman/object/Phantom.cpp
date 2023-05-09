#include <Phantom.h>
#include <Sphere.h>
#include <Cylinder.h>
#include <Circle.h>
#include <gui.h>

Phantom::Phantom(ghost::PhantomColor color, bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->color = this->phantomColors.at(color);
    this->scale(1,.75,1);
}

Phantom::~Phantom() {}

void Phantom::_draw() {
    // Draw head
    glTranslatef(0, .25, 0);
    Sphere head = Sphere(this->color, true);
    head.rotate(90, 1, 0, 0);
    head.draw();

    // Draw body
    Cylinder body = Cylinder(this->color);
    body.scale(.5,.5,.5, true);
    body.translate(0, 0.1, 0);
    body.rotate(90, 1,0,0);
    body.draw();

    // Draw bottom
    Circle bottom = Circle(this->color);
    bottom.translate(0,-0.7,0);
    bottom.rotate(90, 1, 0, 0);
    bottom.draw();

    // Draw ires
    Sphere eye = Sphere(Color(0,0,0), true);
    // Left ires
    eye.scale(.2,.2,.2, true);
    eye.translate(-1.5, 0, 2.3);
    eye.rotate(-10, 0, 1, 0);
    eye.rotate(180, 0, 1, 0);
    eye.draw();
    // Right ires
    eye.translate(1.5, 0, 2.3);
    eye.rotate(10, 0, 1, 0);
    eye.rotate(180, 0, 1, 0);
    eye.draw();

    //Draw pupile
    Sphere pupile = Sphere(Color(1,1,1), true);
    // Left pupile
    pupile.scale(.35,.35,.35, true);
    pupile.rotate(15, 0, 1, 0);
    pupile.translate(-1, 0, .8);
    pupile.rotate(-45, 0, 1, 0);
    pupile.rotate(180, 0, 1, 0);
    pupile.draw();

    // Right pupile
    pupile.rotate(-15, 0, 1, 0);
    pupile.translate(1, 0, .8);
    pupile.rotate(45, 0, 1, 0);
    pupile.rotate(180, 0, 1, 0);
    pupile.draw();
}