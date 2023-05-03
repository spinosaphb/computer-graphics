#include "ScorePoint.h"


ScorePoint::ScorePoint(Color color, Point point) {
    this->color = color;
    this->matrix.t = point;
}

ScorePoint::~ScorePoint() {}

void ScorePoint::_draw() {
    Cube cube1 = Cube(this->color, this->matrix.t);
    Cube cube2 = Cube(this->color, this->matrix.t);
    
    cube1.scale(.65, 1, .65);
    cube2.scale(1, .65, 1);
    cube1.draw();
    cube2.draw();
}
