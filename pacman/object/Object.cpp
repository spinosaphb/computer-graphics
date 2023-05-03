#include "Object.h"
#include <GL/glut.h>
#include <gui_glut/gui.h>

Object::Object() {
    this->tstack = std::stack<pair<Transformation, Point>>();
}

void Object::_draw() {
    // Do nothing
}

void Object::applyPrefixTransformations() {
    stack <pair<Transformation, Point>> tmpstack;

    while(!this->ptstack.empty()) {
        tmpstack.push(this->ptstack.top());
        this->ptstack.pop();
    }

    while(!tmpstack.empty()) {
        auto tr = tmpstack.top().first;
        auto p = tmpstack.top().second;
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
        this->ptstack.push(tmpstack.top());
        tmpstack.pop();
    }
}

void Object::clearPrefixTransformations() {
    this->ptstack = std::stack<pair<Transformation, Point>>();
}

void Object::applyTransformations(int unstacks) {
    
    stack <pair<Transformation, Point>> tmpstack;

    for(int i = 0; i < unstacks && !this->tstack.empty(); i++) {
        tmpstack.push(this->tstack.top());
        this->tstack.pop();
    }

    while(!tmpstack.empty()) {
        auto tr = tmpstack.top().first;
        auto p = tmpstack.top().second;
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
        tmpstack.pop();
    }
}

void Object::addTransformation(Transformation t, Point p, bool prefixed) {   
    (prefixed ? this->ptstack : this->tstack).push(pair<Transformation, Point>(t, p));
}

void Object::translate(float x, float y, float z, bool prefixed) {
    this->addTransformation(TRANSLATE, Point(x, y, z), prefixed);
}

void Object::rotate(float angle, float x, float y, float z, bool prefixed) {
    this->addTransformation(ROTATE, Point(x, y, z, angle), prefixed);
}

void Object::scale(float x, float y, float z, bool prefixed) {
    this->addTransformation(SCALE, Point(x, y, z), prefixed);
}

void Object::setColor(Color color) {
    GUI::setColor(color.r, color.g, color.b);
}


void Object::draw(int unstacks) {
    glPushMatrix();
        this->setColor(this->color);
        this->applyPrefixTransformations();
        this->applyTransformations(unstacks);
        this->_draw();
    glPopMatrix();
}