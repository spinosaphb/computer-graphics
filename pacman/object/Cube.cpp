#include "Cube.h"
#include <GL/glut.h>

Cube::Cube(Color color, Point point) : Object() {
    this->matrix.t = point;
    this->color = color;
}

Cube::~Cube() {}

void Cube::_draw() {
    glBegin(GL_QUADS);
        // Front face
        glNormal3f(0, 0, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, -1, 1);

        // Back face
        glNormal3f(0, 0, -1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);
        // Top face
        glNormal3f(0, 1, 0);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, 1);
        // Bottom face
        glNormal3f(0, -1, 0);
        glVertex3f(1, -1, 1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        // Left face
        glNormal3f(-1, 0, 0);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, -1, -1);
        // Right face
        glNormal3f(1, 0, 0);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, 1);

    glEnd();
}

void Cube::draw() {
    glPushMatrix();
        this->applyTransformations();
        this->_draw();
    glPopMatrix();
}

