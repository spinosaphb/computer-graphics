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

float px = 0.0;
float py = 0.0;
float raio = 0.5;
float theta = 0.0;
#define WIDTH 7.0
#define HEIGHT 9.0


void drawPill() {
    Pill sp = Pill(Color(0.99, 1, 0));
    sp.translate(3,0.25,2,true);
    sp.scale(.125,.125,.125, true);
    sp.draw();
}

void drawPowerPill() {
    PowerPill sp = PowerPill(Color(0.99, 1, 0));
    sp.translate(2,0.25,2, true);
    sp.scale(.125,.125,.125, true);
    sp.draw();
}

void drawFruit() {
    Fruit fruit = Fruit();
    fruit.translate(2.5, .25, 1, true);
    fruit.scale(0.25, 0.25, 0.25, true);
    fruit.draw();
}

void drawPacman() {
    Pacman pacman = Pacman();
    pacman.translate(2.5, .25, -1, true);
    pacman.scale(.25,.25,.25, true);
    pacman.draw();
}

void drawPhatoms() {
    ghost::PhantomColor pcs[] = {ghost::RED, ghost::PINK, ghost::BLUE, ghost::ORANGE};
    float pos[] = {1.75, 2.25, 2.75, 3.25};
    for(int i = 0; i < 4; i++){
        Phantom p = Phantom(pcs[i]);
        p.translate(pos[i], .25, 0, true);
        p.scale(0.25,0.25,0.25, true);
        p.draw();
    }
}

void drawGate() {
    Gate g = Gate();
    g.translate(2.5, .25, -2, true);
    g.scale(0.25, 0.25, 0.25, true);
    g.draw();
}


void drawPacManMap(){
    Map map = Map();
    map.scale(.5,.5,.5);
    map.translate(-1,.1,0);
    map.draw();
}


void draw() {

    GUI::displayInit();

    GUI::setLight(0, 0,2,0, true, false);

    GUI::setColor(.1,.1,.1);
    GUI::drawFloor(WIDTH, HEIGHT);
    GUI::drawOriginAL(1, 0.1);

    drawPacManMap();
    drawPill();
    drawPowerPill();
    drawFruit();
    drawPhatoms();
    drawPacman();
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
        //raio += 0.01;
        break;
    case 's':
        py -= 0.1;
        break;
    case 'w':
        py += 0.1;
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
