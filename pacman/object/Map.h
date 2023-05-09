#ifndef MAP_H
#define MAP_H

#include <Object.h>
#include <Cube.h>
#include <Pill.h>
#include <Gate.h>
#include <Pacman.h>
#include <Phantom.h>
#include <Fruit.h>

namespace pmap {
    enum MapObject {
        VOID,
        WALL,
        PILL,
        POWER_PILL,
        GATE,
        FRUIT,
        PACMAN,
        PHANTOM
    };
}

class Map : public Object {
public:
    Map(float size = .1f, bool drawOrigin = false, float originSize = 2);
    ~Map();
    void _draw();
private:
    float size;

    static const int ROWS = 31;
    static const int COLS = 28;
    static int map[ROWS][COLS];

    static ghost::PhantomColor phantomColors[];

    void _drawWall(float x, float z, int i);
    void _drawPill(float x, float z);
    void _drawPowerPill(float x, float z);
    void _drawGate(float x, float z);
    void _drawPhantom(float x, float z, int value);
    void _drawPacman(float x, float z);
    void _drawFruit(float x, float z);

};

#endif