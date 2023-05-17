#include "Sphere.h"
#include <GL/glut.h>
#include "../gui_glut/gui.h"

const Color Sphere::DEFAULT_COLOR = Color(1, 0, 0);
const double Sphere::DEFAULT_RADIUS = 0.5;
const int Sphere::DEFAULT_SLICES = 100;
const int Sphere::DEFAULT_STACKS = 100;

Sphere::Sphere(Color color, bool semi, double radius, int slices, int stacks) {
    this->radius = radius;
    this->slices = slices;
    this->stacks = stacks;
    this->color = color;
    this->semi = semi;
}

void Sphere::_draw(set<Object*>& hierarchy) {
    if(!this->semi)
        glutSolidSphere(this->radius, this->slices, this->stacks);
    else {
        glPushMatrix();
            GLdouble plane[4] = {0.0, 0.0, -1.0, 0.0};
            glClipPlane(GL_CLIP_PLANE0, plane);
            glEnable(GL_CLIP_PLANE0);
            glutSolidSphere(this->radius, this->slices, this->stacks);
            glDisable(GL_CLIP_PLANE0);
        glPopMatrix();
    }
}