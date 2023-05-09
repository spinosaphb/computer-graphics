#include <Pyramid.h>
#include <gui.h>

Pyramid::Pyramid(Color color) {
    this->color = color;
}

Pyramid::~Pyramid() {}

void Pyramid::_draw() {
    GUI::setColor(this->color.r, this->color.g, this->color.b);
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