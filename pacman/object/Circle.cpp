#include <Circle.h>
#include <gui.h>

Circle::Circle(Color color, float cx, float cy, double radius, int stacks) {
    this->cx = cx;
    this->cy = cy;
    this->radius = radius;
    this->stacks = stacks;
    this->color = color;
    this->name = "Circle";
}

void Circle::_draw(set<Object*>& hierarchy) {
    glBegin(GL_POLYGON);
        for (int i = 0; i < this->stacks; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(this->stacks);
            float x = this->radius * cosf(theta);  // x-coordinate of the vertex
            float y = this->radius * sinf(theta);  // y-coordinate of the vertex
            glNormal3f(0, 0, 1);
            glVertex2f(x + this->cx, y + this->cy);  // specify the vertex
        }
    glEnd();
}