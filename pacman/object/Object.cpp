#include "Object.h"
#include <GL/glut.h>
#include <gui_glut/gui.h>
#include <iostream>
#include <sstream>

stack<pair<Transformation, Point>> Object::ststack = std::stack<pair<Transformation, Point>>();

Object* Object::selectedObject = nullptr;

Object::Object(bool drawOrigin, float originSize) {
    this->tstack = std::stack<pair<Transformation, Point>>();
    this->drawOrigin = drawOrigin;
    this->originSize = originSize;
}

void Object::_draw(set<Object*>& hierarchy) {
    // Do nothing
}

void Object::applyPrefixTransformations() {
    stack <pair<Transformation, Point>> tmpstack;

    while(!this->ptstack.empty()) {
        tmpstack.push(this->ptstack.top());
        this->ptstack.pop();
    }

    while(!tmpstack.empty()) {
        this->applyTransformation(tmpstack.top());
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
        this->applyTransformation(tmpstack.top());
        tmpstack.pop();
    }
}

void Object::applyTransformation(pair<Transformation, Point> tp){
    auto tr = tp.first;
    auto p = tp.second;
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
}

void Object::addTransformation(Transformation t, Point p, TTransformation tt) {
    (   tt == PREFIXED 
        ? this->ptstack : tt == STANDARD 
        ? this->tstack : this->ststack
    ).push(pair<Transformation, Point>(t, p));
}

void Object::translate(float x, float y, float z, bool prefixed) {
    this->addTransformation(TRANSLATE, Point(x, y, z), prefixed ? PREFIXED : STANDARD);
}

void Object::rotate(float angle, float x, float y, float z, bool prefixed) {
    this->addTransformation(ROTATE, Point(x, y, z, angle), prefixed ? PREFIXED : STANDARD);
}

void Object::scale(float x, float y, float z, bool prefixed) {
    this->addTransformation(SCALE, Point(x, y, z), prefixed ? PREFIXED : STANDARD);
}

void Object::mtranslate(float x, float y, float z) {
    Point p = Point(x, y, z);
    this->matrix.t += p;
    this->addTransformation(TRANSLATE, p, TSTATIC);
}

void Object::mrotate(float angle, float x, float y, float z) {
    Point p = Point(x, y, z, angle);
    this->matrix.r += p;
    this->addTransformation(ROTATE, p, TSTATIC);
}

void Object::mscale(float x, float y, float z) {
    Point p = Point(x, y, z);
    this->matrix.s += p;
    this->addTransformation(SCALE, p, TSTATIC);
}

void Object::setColor(Color color) {
    GUI::setColor(color.r, color.g, color.b);
}


void Object::draw(int unstacks, set<Object*>& hierarchy) {
    if(this->drawOrigin) GUI::drawOrigin(this->originSize);
    hierarchy.insert(this);
    cout << "(draw): selected object pointer: " << Object::selectedObject 
        << " | " << "gate pointer: " << this->printHierarchy(hierarchy) << " | " << this->name << endl;

    if(hierarchy.find(this->selectedObject) != hierarchy.end())
        this->setColor(Color(1,1,1));
    else
        this->setColor(this->color);
    glPushMatrix();
        this->applyPrefixTransformations();
        glPushMatrix();
            this->applyTransformations(unstacks);
            this->_draw(hierarchy);
        glPopMatrix();
    glPopMatrix();
}

Point& Object::operator[](Transformation t) {
    switch (t) {
    case TRANSLATE:
        return this->selectedObject->matrix.t;
    case ROTATE:
        return this->selectedObject->matrix.r;
    case SCALE:
        return this->selectedObject->matrix.s;
    }
}

string Object::printHierarchy(set<Object*>& hierarchy) {
    
    std::stringstream ss;
    
    ss << "[";

    // Iterate over each element in the set
    for (auto it = hierarchy.begin(); it != hierarchy.end(); ++it) {
        ss << *it; // Print the current element

        // Print a comma if it's not the last element
        if (std::next(it) != hierarchy.end()) {
            ss << ", ";
        }
    }

    ss << "]\n";

    return ss.str();
}