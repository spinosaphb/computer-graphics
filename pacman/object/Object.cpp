#include "Object.h"
#include <GL/glut.h>

Object::Object() {
    this->tqueue = std::queue<pair<Transformation, Point>>();
}

void Object::draw() {
  // TODO: implement
}

void Object::applyTransformations() {
    while(!this->tqueue.empty()) {
        auto tr = this->tqueue.front().first;
        auto p = this->tqueue.front().second;
        switch (tr) {
        case TRANSLATE:
            glTranslatef(p.x, p.y, p.z);
            break;
        case ROTATE:
            glRotatef(p.a, p.x, p.y, p.z);
            break;
        case SCALE:
            glScalef(p.x, p.y, p.z);
            break;
        }
        this->tqueue.pop();
    }
        
}

void Object::addTransformation(Transformation t, Point p) {   
    this->tqueue.push(pair<Transformation, Point>(t, p));
}

void Object::translate(float x, float y, float z) {
    this->addTransformation(TRANSLATE, Point(x, y, z));
}

void Object::rotate(float angle, float x, float y, float z) {
    this->addTransformation(ROTATE, Point(x, y, z, angle));
}

void Object::scale(float x, float y, float z) {
    this->addTransformation(SCALE, Point(x, y, z));
}

