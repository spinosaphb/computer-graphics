
struct Point {
    float x;
    float y;
    float z;

    Point(float x=0, float y=0, float z=0): x(x), y(y), z(z) {}
};

struct Color {
    float red;
    float green;
    float blue;

    Color(float red=1, float green=0.6, float blue=0): red(red), green(green), blue(blue) {}
};

class Object {
public:
    virtual void draw();
protected:
    Point point;
};