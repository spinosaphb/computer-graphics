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
static bool& enable_transform = glutGUI::trans_obj;
static float tfactor = 2;

vector<pair<ObjectType, Object*>> getScenario(){
    return {
        make_pair(CUBE, new Cube(Color(0.1, 0.1, 0.65), Point(), true)),
        make_pair(PILL, new Pill(Color(0.99, 1, 0), true)),
        make_pair(POWER_PILL, new PowerPill(Color(0.99, 1, 0), true)),
        make_pair(FRUIT, new Fruit(true)),
        make_pair(PHANTOM, new Phantom(ghost::RED, true)),
        make_pair(PHANTOM, new Phantom(ghost::PINK, true)),
        make_pair(PHANTOM, new Phantom(ghost::BLUE, true)),
        make_pair(PHANTOM, new Phantom(ghost::ORANGE, true)),
        make_pair(PACMAN, new Pacman(true)),
        make_pair(GATE, new Gate(true)),
        make_pair(MAP, new Map(true))
    };
}

vector<pair<ObjectType, Object*>> objects = getScenario();


static int object_idx = 0;

void drawWall(Cube& cube) {
    cube.translate(2.5, .25, 2);
    cube.scale(.125, .0625, .125);
    cube.draw();
}

void drawPill(Pill& pill) {
    pill.translate(3,0.25,1);
    pill.scale(.125,.125,.125);
    pill.draw();
}

void drawPowerPill(PowerPill& superpill) {
    superpill.translate(2,0.25,1);
    superpill.scale(.125,.125,.125);
    superpill.draw();
}

void drawFruit(Fruit& fruit) {
    fruit.translate(2.5, .25, 0);
    fruit.scale(0.25, 0.25, 0.25);
    fruit.draw();
}

void drawPacman(Pacman& pacman) {
    pacman.translate(2.5, .25, -2);
    pacman.scale(.25,.25,.25);
    pacman.draw();
}

void drawPhantom(Phantom& phantom) {
    float pos[] = {1.75, 2.25, 2.75, 3.25};
    phantom.translate(pos[phantom.colorFlag] , .25, -1);
    phantom.scale(0.25,0.25,0.25);
    phantom.draw();
}

void drawPhatoms(map<ghost::PhantomColor, Phantom>& phantoms) {
    ghost::PhantomColor pcs[] = {ghost::RED, ghost::PINK, ghost::BLUE, ghost::ORANGE};
    float pos[] = {1.75, 2.25, 2.75, 3.25};
    for(int i = 0; i < 4; i++){
        Phantom& p = phantoms[pcs[i]];
        p.translate(pos[i], .25, -1);
        p.scale(0.25,0.25,0.25);
        p.draw();
    }
}

void drawGate(Gate& gate) {
    gate.translate(2.5, .25, -3);
    gate.scale(0.25, 0.25, 0.25);
    gate.draw();
}

void drawPacManMap(Map& map_){
    map_.scale(.75,.75,.75);
    map_.translate(-1,.1,0);
    map_.draw();
}


void drawObject(Object*& obj) {
    switch(obj->selfType) {
        case CUBE: drawWall((Cube&)*obj); break;
        case PILL: drawPill((Pill&)*obj); break;
        case POWER_PILL: drawPowerPill((PowerPill&)*obj); break;
        case FRUIT: drawFruit((Fruit&)*obj); break;
        case PHANTOM: drawPhantom((Phantom&)*obj); break;
        case PACMAN: drawPacman((Pacman&)*obj); break;
        case GATE: drawGate((Gate&)*obj); break;
        case MAP: drawPacManMap((Map&)*obj); break;
    }
}


void draw() {

    GUI::displayInit();

    GUI::setLight(0, 0,2,0, true, false);

    GUI::setColor(.1,.1,.1);
    GUI::drawFloor(WIDTH, HEIGHT);
    GUI::drawOriginAL(1, 0.1);

    Object::selectObject(enable_select ? objects[object_idx].second : nullptr);
    objects[object_idx].second->transformColor = enable_transform;

    if(enable_transform){
        (*objects[object_idx].second)[TRANSLATE] += Point(glutGUI::dtx, glutGUI::dty, glutGUI::dtz)*tfactor;
        (*objects[object_idx].second)[ROTATE] += Point(glutGUI::dax, glutGUI::day, glutGUI::daz)*tfactor;
        (*objects[object_idx].second)[SCALE] += Point(glutGUI::dsx, glutGUI::dsy, glutGUI::dsz)*tfactor;
    }
    
    for(auto& obj : objects) drawObject(obj.second);
    
    GUI::displayEnd();

}

void teclado(unsigned char tecla, int mx, int my) {
    GUI::keyInit(tecla, mx,my);

    switch (tecla) {
    case 't':
        enable_transform = enable_select && !enable_transform;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'a':
        if(enable_transform)
            (*objects[object_idx].second)[TRANSLATE][paxis::X]-=0.1;
        else if(enable_select)
            object_idx = --object_idx < 0 ? objects.size()-1 : object_idx;
        
        break;
    case 'd':
        if(enable_transform)
            (*objects[object_idx].second)[TRANSLATE][paxis::X]+=0.1;
        else if(enable_select)
            object_idx = ++object_idx > objects.size()-1 ? 0 : object_idx;
        break;
    case 's':
        if(enable_transform)
            (*objects[object_idx].second)[TRANSLATE][paxis::Y]-=0.1;
        break;
    case 'w':
        if(enable_transform)
            (*objects[object_idx].second)[TRANSLATE][paxis::Y]+=0.1;
        break;
    case 'S':
        enable_select = !enable_select;
        enable_transform &= enable_select;
        break;
    case 'D':
        if(enable_select) {
            auto current = objects[object_idx].second;
            objects.erase(objects.begin() + object_idx);
            delete current;
            object_idx = ++object_idx > objects.size()-1 ? 0 : object_idx;
        }
        break;
    // reset scenario
    case 'R':
        for(auto& obj : objects) delete obj.second;
        objects.clear();
        objects = getScenario();
        object_idx = 0;
        break;

    case '=':
        if(enable_select) {
            auto current = objects[object_idx].second;
            
            void* new_obj = (current->selfType == CUBE) ?  (void*) new Cube((Cube&)*current)
                : (current->selfType == PILL) ? (void*) new Pill((Pill&)*current)
                : (current->selfType == POWER_PILL) ? (void*) new PowerPill((PowerPill&)*current)
                : (current->selfType == FRUIT) ? (void*) new Fruit((Fruit&)*current)
                : (current->selfType == PHANTOM) ? (void*) new Phantom((Phantom&)*current)
                : (current->selfType == PACMAN) ? (void*) new Pacman((Pacman&)*current)
                : (current->selfType == GATE) ? (void*) new Gate((Gate&)*current)
                : (current->selfType == MAP) ? (void*) new Map((Map&)*current)
                : nullptr;

            if(new_obj != nullptr)
                objects.push_back(make_pair(current->selfType, (Object*) new_obj));
        }    
        break;
    
    case '1': objects.push_back(make_pair(CUBE, new Cube())); break;
    case '2': objects.push_back(make_pair(PILL, new Pill())); break;
    case '3': objects.push_back(make_pair(POWER_PILL, new PowerPill())); break;
    case '4': objects.push_back(make_pair(FRUIT, new Fruit())); break;
    case '5': objects.push_back(make_pair(PHANTOM, new Phantom(ghost::RED))); break;
    case '6': objects.push_back(make_pair(PHANTOM, new Phantom(ghost::PINK))); break;
    case '7': objects.push_back(make_pair(PHANTOM, new Phantom(ghost::BLUE))); break;
    case '8': objects.push_back(make_pair(PHANTOM, new Phantom(ghost::ORANGE))); break;
    case '9': objects.push_back(make_pair(PACMAN, new Pacman())); break;
    case '0': objects.push_back(make_pair(GATE, new Gate())); break;
    case '-': objects.push_back(make_pair(MAP, new Map())); break;
        
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,draw,teclado, glutGUI::defaultMouseButton, "Pacman World");
}
