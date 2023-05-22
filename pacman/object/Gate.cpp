#include <Gate.h>
#include <Triangle.h>
#include <Cube.h>
#include <Circle.h>
#include <Pyramid.h>
#include <Pill.h>
#include <array>
#include <tuple>
#include <gui.h>

Gate::Gate(bool drawOrigin, float originSize) : Object(drawOrigin, originSize) {
    this->color = Color(1,0,0);
    this->selfType = ObjectType::GATE;
}

Gate::~Gate() {}


void Gate::_drawFlag(set<Object*>& hierarchy) {
    // flag
    Triangle t = Triangle(Color(.7, .7, .7),true);

    Point tps[] = {Point(-1.75, 2, 0), Point(1.75, 2, 0)};

    static float angle = 0;
    static bool rotate = true;

    for(auto tp: tps){
        t.translate(tp.x, tp.y, tp.z);
        t.rotate(-90, 0, 0, 1);
        // start rotate
        if(angle == -60)
            rotate = false;
        else if (angle == 60)
            rotate = true;
        if(rotate && angle > -60)
            angle--;
        else if(!rotate && angle < 60)
            angle++;
        t.rotate(angle, 1, 0, 0);
        // end rotate
        t.scale(.2, .2, .2);
        t.draw(INFINITY, hierarchy);
    }
    
}

void Gate::_draw(set<Object*>& hierarchy) {

    // flag
    this->_drawFlag(hierarchy);

    // flag pole
    Pyramid p = Pyramid(Color(0.0, 0.5, 0.0));
    
    p.scale(.25,.25,.25, true);
    p.translate(-7,6,0);
    p.draw(INFINITY, hierarchy);

    p.translate(7,6,0);
    p.draw(INFINITY, hierarchy);

    // flag sphere
    Pill sp = Pill(Color(1.0, 0.75, 0.0));
    sp.scale(.25,.25,.25, true);
    sp.translate(-7,5,0);
    sp.draw(INFINITY, hierarchy);

    sp.translate(7,5,0);
    sp.draw(INFINITY, hierarchy);

    // gate
    Cube gate = Cube(Color(0, 0.39, 0.75));
    gate.scale(1, 1, .25, true);
    gate.translate(-1,0,0);
    gate.draw(INFINITY, hierarchy);

    gate.translate(1,0,0);
    gate.draw(INFINITY, hierarchy);

    // gate Brazilian flag
    std::array<std::tuple<int, int>, 4> gateDecPositions = {
        std::make_tuple(1, 2),
        std::make_tuple(1, -2),
        std::make_tuple(-1, 2),
        std::make_tuple(-1, -2)
    };

    for(const tuple<int, int>& t : gateDecPositions){
        int x = get<0>(t);
        int z = get<1>(t);

        Cube c = Cube(Color(0.0, 0.5, 0.0));
        c.scale(.8, .8, 0.1, true);
        c.translate(x,0,z);
        c.draw(INFINITY, hierarchy);

        Triangle tr = Triangle(Color(1.0, 0.75, 0.0));
        tr.scale(0.75,0.75,0.75, true);
        tr.translate(0,0,.82/z);
        if(z<0) tr.rotate(180, 1, 0, 0);
        tr.rotate(90*x, 0, 0, 1);
        tr.draw(INFINITY, hierarchy);

        Circle ci = Circle(Color(0.0, 0.39, 0.75));
        ci.scale(1.15,1.15,1.15, true);
        ci.translate(0,0,.54/z);
        if(z<0) ci.rotate(180, 1, 0, 0);
        ci.draw(INFINITY, hierarchy);
    }

}
