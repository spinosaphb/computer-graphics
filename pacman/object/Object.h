#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <string>
#include <limits>
#include <stack>
#include <iostream>
#include <set>

using namespace std;

enum Transformation{
    TRANSLATE = 1,
    ROTATE = 2,
    SCALE = 3
};

enum TTransformation {
    STANDARD,
    PREFIXED,
    TSTATIC
};

struct Point {
    float x;
    float y;
    float z;
    float a;

    Point(float x=0, float y=0, float z=0, float a=0): x(x), y(y), z(z), a(a) {}

    void operator+=(const Point& p) {
        this->x += p.x;
        this->y += p.y;
        this->z += p.z;
    }
};

struct Color {
    float r;
    float g;
    float b;

    Color(float r=1, float g=0.6, float b=0): r(r), g(g), b(b) {}
};

struct Matrix {
    Point t;
    Point r;
    Point s;

    Matrix(
        Point t=Point(1,1,1),
        Point r=Point(1,1,1),
        Point s=Point(1,1,1)
    ): t(t), r(r), s(s) {}
};


#define INFINITY numeric_limits<float>::infinity()

class Object {
public:
    void draw(int unstacks = INFINITY, set<Object*>& hierarchy = *(new set<Object*>()));
    
    void translate(float x, float y, float z, bool prefixed = false);
    void rotate(float angle, float x, float y, float z, bool prefixed = false);
    void scale(float x, float y, float z, bool prefixed = false);
    
    void mtranslate(float x, float y, float z);
    void mrotate(float angle, float x, float y, float z);
    void mscale(float x, float y, float z);
    

    Object(bool drawOrigin = false, float originSize = 2);

    Point& operator[](Transformation t);

    static void selectObject(Object* object) {
        selectedObject = object;
    }

protected:
    Matrix matrix;
    void setColor(Color);
    void addTransformation(Transformation, Point, TTransformation);
    void applyPrefixTransformations();
    void clearPrefixTransformations();
    void applyTransformations(int unstacks = INFINITY);
    void applyTransformation(pair<Transformation, Point> tp);
    virtual void _draw(set<Object*>& hierarchy = *(new set<Object*>()));
    stack<pair<Transformation, Point>> tstack; // transformations stack
    stack<pair<Transformation, Point>> ptstack; // prefixed transformations stack
    static stack<pair<Transformation, Point>> ststack; // static stack
    Color color;
    bool drawOrigin = false;
    float originSize = 2;
    float moveFactor = 0.1;

public:
    static Object* selectedObject;
    string name;

private:
    static string printHierarchy(set<Object*>& hierarchy);
};

#endif