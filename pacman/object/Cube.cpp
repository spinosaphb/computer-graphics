#include "Cube.h"
#include <GL/glut.h>

Cube::Cube(Color color, Point point, bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->matrix.t = point;
    this->color = color;
    this->selfType = ObjectType::CUBE;
}

Cube::~Cube() {}

void Cube::_draw(set<Object*>& hierarchy) {
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


