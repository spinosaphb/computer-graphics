#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <string>
#include <limits>
#include <stack>

using namespace std;

enum Transformation{
    TRANSLATE = 1,
    ROTATE = 2,
    SCALE = 3
};

struct Point {
    float x;
    float y;
    float z;
    float a;

    Point(float x=0, float y=0, float z=0, float a=0): x(x), y(y), z(z), a(a) {}
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
    Matrix matrix;

    void draw(int unstacks = INFINITY);
    
    void translate(float x, float y, float z, bool prefixed = false);
    void rotate(float angle, float x, float y, float z, bool prefixed = false);
    void scale(float x, float y, float z, bool prefixed = false);
    Object(bool drawOrigin = false, float originSize = 2);

protected:
    void setColor(Color);
    void addTransformation(Transformation, Point, bool prefixed);
    void applyPrefixTransformations();
    void clearPrefixTransformations();
    void applyTransformations(int unstacks = INFINITY);
    virtual void _draw();
    stack<pair<Transformation, Point>> tstack; // transformations stack
    stack<pair<Transformation, Point>> ptstack; // prefixed transformations stack
    Color color;
    bool drawOrigin = false;
    float originSize = 2;
};

#endif