#include <Map.h>


Map::Map(bool drawOrigin, float originSize, float size) : Object(drawOrigin, originSize) {
    this->size = size;
    this->selfType = ObjectType::MAP;
}

Map::~Map() {}

int Map::map[31][28] = {
//   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 0
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 1
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 2
    {1, 3, 1, 0, 0, 1, 2, 1, 0, 0, 0, 1, 2, 1, 1, 2, 1, 0, 0, 0, 1, 2, 1, 0, 0, 1, 3, 1}, // 3
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 4
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 5
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 6
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 7
    {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1}, // 8
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 9
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 10
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 11
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 1, 1, 1, 4, 0, 1, 1, 1, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 12
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 13
    {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 8, 9, 7, 10, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, // 14
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 15
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 16
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 17
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 18
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 19
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 20
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 21
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 22
    {1, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 6, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3, 1}, // 23
    {1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1}, // 24
    {1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1}, // 25
    {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1}, // 26
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1}, // 27
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1}, // 28
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 29
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 30
};

ghost::PhantomColor Map::phantomColors[] = {
    ghost::RED,
    ghost::PINK,
    ghost::BLUE,
    ghost::ORANGE
};

void Map::_draw(set<Object*>& hierarchy) {
    // define the size of each cube
    // iterate over the pacmanMap matrix
    for(int i = 0; i < this->ROWS; i++)
        for(int j = 0; j < this->COLS; j++){
            // get the current value in the matrix
            int value = this->map[i][j];

            // determine the position of the cube based on the matrix indices
            float x = (j - 14) * this->size;
            float z = (15.5 - i) * this->size;

            // draw a cube if the value is 1, which represents a wall
            (value == pmap::WALL) ? this->_drawWall(x, z, hierarchy) // draw wall
                : (value == pmap::PILL) ? this->_drawPill(x, z, hierarchy) // draw pill
                : (value == pmap::POWER_PILL) ? this->_drawPowerPill(x, z, hierarchy) // draw power pill
                : (value == pmap::GATE) ? this->_drawGate(x, z, hierarchy) // draw gate
                : (value == pmap::FRUIT) ? this->_drawFruit(x, z, hierarchy) // draw fruit
                : (value == pmap::PACMAN) ? this->_drawPacman(x, z, hierarchy) // draw pacman
                : (value >= pmap::PHANTOM && value <= pmap::PHANTOM+4) ? this->_drawPhantom(x, z, value, hierarchy) // draw phantom
                : [](){}(); // do nothing
        }
}

void Map::_drawWall(float x, float z, set<Object*>& hierarchy){
    Cube wall = Cube(Color(0.1, 0.1, 0.65));
    wall.translate(x*2, 0, z*-2, true);
    wall.scale(this->size, this->size/1.5, this->size);
    wall.draw(INFINITY, hierarchy);
}

void Map::_drawPill(float x, float z, set<Object*>& hierarchy){
    Pill pill = Pill(Color(0.99, 1, 0));
    pill.translate(x*2, 0, z*-2, true);
    pill.scale(this->size/2, this->size/2, this->size/2);
    pill.draw(INFINITY, hierarchy);
}

void Map::_drawPowerPill(float x, float z, set<Object*>& hierarchy){
    PowerPill pill = PowerPill(Color(0.99, 1, 0));
    pill.translate(x*2, 0, z*-2, true);
    pill.scale(this->size/2, this->size/2, this->size/2);
    pill.draw(INFINITY, hierarchy);
}

void Map::_drawGate(float x, float z, set<Object*>& hierarchy){
    Gate gate = Gate();
    gate.translate(x*2, 0, z*-2, true);
    gate.scale(this->size, this->size, this->size);
    gate.translate(1,0,0);
    gate.draw(INFINITY, hierarchy);
}

void Map::_drawFruit(float x, float z, set<Object*>& hierarchy){
    Fruit fruit = Fruit();
    fruit.translate(x*2, 0, z*-2, true);
    fruit.scale(0.15, 0.15, 0.15);
    fruit.draw(INFINITY, hierarchy);
}

void Map::_drawPacman(float x, float z, set<Object*>& hierarchy){
    Pacman pacman = Pacman();
    pacman.translate(x*2, 0, z*-2, true);
    pacman.scale(0.2, 0.2, 0.2);
    pacman.rotate(-90, 0, 1, 0);
    pacman.draw(INFINITY, hierarchy);
}

void Map::_drawPhantom(float x, float z, int value, set<Object*>& hierarchy){
    Phantom phantom = Phantom(this->phantomColors[value-pmap::PHANTOM]);
    phantom.translate(x*2, 0, z*-2, true);
    phantom.scale(0.2, 0.2, 0.2);
    phantom.draw(INFINITY, hierarchy);
}
