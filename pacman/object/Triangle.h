#include <Object.h>

class Triangle : public Object {
public:
    Triangle(
        Color color = Color(1,0,0),
        bool doubleSided = false, 
        Point p1 = Point(1,0,0),
        Point p2 = Point(0,2,0),
        Point p3 = Point(-1,0,0),
        Point normal = Point(0,1,1)
    );
    ~Triangle();
    void _draw();
private:
    Point p1, p2, p3, normal;
    bool doubleSided;
};