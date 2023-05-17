#include <iostream>

using namespace std;

#include <gui.h>
#include <Sphere.h>
#include <Cube.h>
#include <Pill.h>
#include <Fruit.h>
#include <Circle.h>
#include <Pacman.h>
#include <Phantom.h>
#include <Pyramid.h>
#include <Gate.h>
#include <Map.h>
#include <model3ds.h>
#include <array>
#include <tuple>
#include <vector>

float px = 0.0;
float py = 0.0;
float raio = 0.5;
float theta = 0.0;
#define WIDTH 7.0
#define HEIGHT 9.0

static bool enable_select = false;

Cube cube = Cube(Color(0.1, 0.1, 0.65));
Pill pill = Pill(Color(0.99, 1, 0));
PowerPill superpill = PowerPill(Color(0.99, 1, 0));
Fruit fruit = Fruit();
Pacman pacman = Pacman();
map<ghost::PhantomColor, Phantom> phantoms = {
    {ghost::RED, Phantom(ghost::RED)},
    {ghost::PINK, Phantom(ghost::PINK)},
    {ghost::BLUE, Phantom(ghost::BLUE)},
    {ghost::ORANGE, Phantom(ghost::ORANGE)}
};

Gate gate = Gate();
Map map_ = Map();

vector<Object*> objects = {
    &cube,
    &pill,
    &superpill,
    &fruit,
    &pacman,
    &phantoms[ghost::RED],
    &phantoms[ghost::PINK],
    &phantoms[ghost::BLUE],
    &phantoms[ghost::ORANGE],
    &gate,
    &map_
};

static int object_idx = 0;

void drawWall() {
    cube.translate(2.5, .25, 2);
    cube.scale(.125, .0625, .125);
    cube.draw();
}

void drawPill() {
    pill.translate(3,0.25,1);
    pill.scale(.125,.125,.125);
    pill.draw();
}

void drawPowerPill() {
    superpill.translate(2,0.25,1);
    superpill.scale(.125,.125,.125);
    superpill.draw();
}

void drawFruit() {
    fruit.translate(2.5, .25, 0);
    fruit.scale(0.25, 0.25, 0.25);
    fruit.draw();
}

void drawPacman() {
    pacman.translate(2.5, .25, -2);
    pacman.scale(.25,.25,.25);
    pacman.draw();
}

void drawPhatoms() {
    ghost::PhantomColor pcs[] = {ghost::RED, ghost::PINK, ghost::BLUE, ghost::ORANGE};
    float pos[] = {1.75, 2.25, 2.75, 3.25};
    for(int i = 0; i < 4; i++){
        Phantom p = phantoms[pcs[i]];
        p.translate(pos[i], .25, -1);
        p.scale(0.25,0.25,0.25);
        p.draw();
    }
}

void drawGate() {
    gate.translate(2.5, .25, -3);
    gate.scale(0.25, 0.25, 0.25);
    gate.draw();
}

void drawPacManMap(){
    map_.scale(.75,.75,.75);
    map_.translate(-1,.1,0);
    map_.draw();
}


void draw() {

    GUI::displayInit();

    GUI::setLight(0, 0,2,0, true, false);

    GUI::setColor(.1,.1,.1);
    GUI::drawFloor(WIDTH, HEIGHT);
    GUI::drawOriginAL(1, 0.1);

    Object::selectObject(enable_select ? &gate : nullptr);

    cout << "(main): selected object pointer: " << Object::selectedObject 
         << " | " << "gate pointer: " << &gate << endl;

    // drawPacManMap();
    
    //glTranslatef(0, 0, .25);
    // drawWall();
    // drawPill();
    // drawPowerPill();
    // drawFruit();
    // drawPhatoms();
    // drawPacman();
    drawGate();
    
    GUI::displayEnd();

}

void teclado(unsigned char tecla, int mx, int my) {
    GUI::keyInit(tecla, mx,my);

    switch (tecla) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'a':
        px -= 0.1;
        break;
    case 'd':
        px += 0.1;
        break;
    case 's':
        py -= 0.1;
        break;
    case 'w':
        py += 0.1;
        break;
    case 'S':
        enable_select = !enable_select;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,draw,teclado, glutGUI::defaultMouseButton, "Pacman World");
}
