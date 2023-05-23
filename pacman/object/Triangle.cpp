#include <Triangle.h>
#include <GL/glut.h>

Triangle::Triangle(Color color, bool doubleSided, Point p1, Point p2, Point p3, Point normal) {
    this->color = color;
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->normal = normal;
    this->doubleSided = doubleSided;
    this->selfType = ObjectType::TRIANGLE;
}

Triangle::~Triangle() {}

void Triangle::_draw(set<Object*>& __attribute__((hierarchy))) {
    if (this->doubleSided)
        glDisable(GL_CULL_FACE);
    glBegin(GL_POLYGON);
        glNormal3f(this->normal.x, this->normal.y, this->normal.z);
        glVertex3f(this->p1.x, this->p1.y, this->p1.z);
        glVertex3f(this->p2.x, this->p2.y, this->p2.z);
        glVertex3f(this->p3.x, this->p3.y, this->p3.z);
    glEnd();
}