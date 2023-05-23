#include <Cylinder.h>
#include <gui.h>

Cylinder::Cylinder(Color color, float base, float top, float height, int slices, int stacks) {
    this->color = color;
    this->base = base;
    this->top = top;
    this->height = height;
    this->slices = slices;
    this->stacks = stacks;
    this->selfType = ObjectType::CYLINDER;
}

Cylinder::~Cylinder() {}

void Cylinder::_draw(set<Object*>& __attribute__((hierarchy))) {
    gluCylinder(gluNewQuadric(), this->base, this->top, this->height, this->slices, this->stacks);
}