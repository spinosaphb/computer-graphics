#include "Sphere.h"
#include <GL/glut.h>
#include "../gui_glut/gui.h"

Sphere::Sphere() {
    this->color = Color();
}

Sphere::Sphere(Color color) {
    this->color = color;
}

// Sphere::~Sphere() {}

Sphere::Sphere(Color color, Point point) {
    this->point = point;
    this->color = color;
}

Sphere::Sphere(Color color, Point point, float radius) {
    this->point = point;
    this->color = color;
    this->radius = radius;
}

void Sphere::_draw() {
    GUI::drawSphere(this->point.x,this->point.y,this->point.z,this->radius);
}

void Sphere::draw() {
    this->_draw();
}
