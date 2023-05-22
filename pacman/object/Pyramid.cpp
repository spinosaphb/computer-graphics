#include <Pyramid.h>
#include <gui.h>

Pyramid::Pyramid(Color color) {
    this->color = color;
    this->selfType = ObjectType::PYRAMID;
}

Pyramid::~Pyramid() {}

void Pyramid::_draw(set<Object*>& hierarchy) {
    glBegin(GL_POLYGON);
        glNormal3f(0,1,1);
        glVertex3f(1,0,1);
        glVertex3f(0,1,0);
        glVertex3f(-1,0,1);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,1,-1);
        glVertex3f(-1,0,-1);
        glVertex3f(0,1,0);
        glVertex3f(1,0,-1);
    glEnd();
    //lateral direita
    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(1,0,1);
        glVertex3f(1,0,-1);
        glVertex3f(0,1,0);
    glEnd();
    //lateral esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(-1,0,1);
        glVertex3f(0,1,0);
        glVertex3f(-1,0,-1);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f( 1,0, 1);
        glVertex3f(-1,0, 1);
        glVertex3f(-1,0,-1);
        glVertex3f( 1,0,-1);
    glEnd();
}