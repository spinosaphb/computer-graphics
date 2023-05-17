#ifndef PHANTOM_H
#define PHANTOM_H

#include <Object.h>
#include <map>

namespace ghost {
    enum PhantomColor {
        RED,
        PINK,
        BLUE,
        ORANGE
    };
}


class Phantom : public Object {
public:
    Phantom(ghost::PhantomColor color = ghost::RED, bool drawOrigin = false, float originSize = 2);
    ~Phantom();
    void _draw(set<Object*>& hierarchy = *(new set<Object*>()));

private:
    map<ghost::PhantomColor, Color> phantomColors = {
        {ghost::RED, Color(1, 0, 0)},
        {ghost::PINK, Color(0, 0.76, 0.79)},
        {ghost::BLUE, Color(1, 0.75, 0.79)},
        {ghost::ORANGE, Color(1, 0.65, 0)}
    };
    ghost::PhantomColor colorFlag;
};

#endif
