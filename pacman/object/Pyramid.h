#ifndef PYRAMIDE_H
#define PYRAMIDE_H

#include <Object.h>

class Pyramid : public Object {
public:
    Pyramid(Color color = Color(0,0,1));
    ~Pyramid();
    void _draw();
};

#endif
