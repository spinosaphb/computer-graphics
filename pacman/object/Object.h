
struct Point {
    float x;
    float y;
    float z;

    Point(float x=0, float y=0, float z=0): x(x), y(y), z(z) {}
};

class Object {
public:
    virtual void draw();
protected:
    Point point;
};