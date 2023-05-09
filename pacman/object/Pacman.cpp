#include <Pacman.h>
#include <Sphere.h>
#include <Circle.h>
#include <Pill.h>
#include <gui_glut/gui.h>

Pacman::Pacman(Color color, bool drawOrigin, float originSize, float mouthAngle) : Object(drawOrigin, originSize) {
    this->color = color;
    this->topBody = TopBody(color);
    this->bottomBody = BottomBody(color);
    this->defaultMouthAngle = mouthAngle;
}

Pacman::~Pacman() {}

void Pacman::_draw() {

    static float mouthAngle = this->defaultMouthAngle;
    static bool mouthRotate = true;

    this->topBody.rotate(mouthAngle*-1, 1, 0, 0);
    this->bottomBody.rotate(mouthAngle, 1, 0, 0);
    
    if(mouthAngle == 0)
        mouthRotate = false;
    else if(mouthAngle == 60)
        mouthRotate = true;
    
    if(mouthRotate && mouthAngle > 0)
        mouthAngle--;
    else if(!mouthRotate && mouthAngle < 60)
        mouthAngle++;
    this->topBody.draw();
    this->bottomBody.draw();
}

TopBody::TopBody(Color color) {
    this->color = color;
}

TopBody::~TopBody() {}
void TopBody::_draw() {

    Sphere ssphere = Sphere(this->color, true);
    Circle circle = Circle(Color(0,0,0));
    Pill eye = Pill(Color(0,0,0));
    
    ssphere.rotate(90, 1, 0, 0);
    ssphere.draw();

    circle.rotate(90, 1, 0, 0);
    circle.draw();
    
    eye.scale(.1, .1, .1, true);
    eye.rotate(-60, 0 , 1, 0);
    eye.translate(0, 2, 4);
    eye.rotate(-25, 1, 0, 0);
    eye.draw(3);

    eye.rotate(60, 0 , 1, 0);
    eye.translate(0, 2, 4);
    eye.rotate(-25, 1, 0, 0);
    eye.draw();
}


BottomBody::BottomBody(Color color) {
    this->color = color;
}

BottomBody::~BottomBody() {}

void BottomBody::_draw() {

    Sphere ssphere = Sphere(this->color, true);
    Circle circle = Circle(Color(0,0,0));
    

    ssphere.rotate(-90, 1, 0, 0);
    ssphere.draw();

    circle.rotate(-90, 1, 0, 0);
    circle.draw(); 
}