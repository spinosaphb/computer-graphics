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

#include <fstream>
#include <sstream>

float px = 0.0;
float py = 0.0;
float raio = 0.5;
float theta = 0.0;
#define WIDTH 10
#define HEIGHT 10

vector<CameraDistante> getCameras();
vector<pair<ObjectType, Object*>> getScenario();

vector<CameraDistante> cameras = getCameras();
vector<pair<ObjectType, Object*>> objects = getScenario();

static bool enable_select = false;
static bool& enable_transform = glutGUI::trans_obj;
static float tfactor = 2;

static int object_idx = 0;
static int camera_idx = 0;

static string OBJECTS_FILENAME = "objects.pacman";

void writeCamDebug()
{
  std::ofstream myfile;

  myfile.open("camera.txt", std::ofstream::out | std::ofstream::app); // Open the file in append mode

  if (myfile.is_open())
  {
    myfile << "glutGUI::cam->e.x=" << glutGUI::cam->e.x << "\n";
    myfile << "glutGUI::cam->e.y=" << glutGUI::cam->e.y << "\n";
    myfile << "glutGUI::cam->e.z=" << glutGUI::cam->e.z << "\n";
    myfile << "glutGUI::cam->c.x=" << glutGUI::cam->c.x << "\n";
    myfile << "glutGUI::cam->c.y=" << glutGUI::cam->c.y << "\n";
    myfile << "glutGUI::cam->c.z=" << glutGUI::cam->c.z << "\n";
    myfile << "glutGUI::cam->u.x=" << glutGUI::cam->u.x << "\n";
    myfile << "glutGUI::cam->u.y=" << glutGUI::cam->u.y << "\n";
    myfile << "glutGUI::cam->u.z=" << glutGUI::cam->u.z << "\n";
    myfile.close(); // Close the file
    std::cout << "Camera salva" << std::endl;
  }
  else
  {
    std::cout << "Erro ao abrir arquivo" << std::endl;
  }
}

string handleObjectName(pair<ObjectType, Object*>& obj){
    stringstream ss;
    if (obj.first == PHANTOM) ss << obj.first << " " << ((Phantom*) obj.second)->colorFlag;
    else ss << obj.first;
    return ss.str();
}

void serializeObjects(vector<pair<ObjectType, Object*>>& objects, string filename = OBJECTS_FILENAME){
    ofstream file;
    file.open(filename);
    for(auto& obj : objects)
        file << handleObjectName(obj) << endl << *(obj.second) << endl;
    file.close();
}

void deserializeObjects(vector<pair<ObjectType, Object*>>& objects, string filename = OBJECTS_FILENAME){
    ifstream file;
    string line;
    int type_;
    Object* obj;

    file.open(filename);

    for(auto& obj : objects) 
        delete obj.second;
    objects.clear();

    while(getline(file, line)){
        stringstream ss(line);
        ss >> type_;
        ObjectType type_obj = (ObjectType) type_;
        if(type_obj == PHANTOM){
            int colorFlag; 
            ss >> colorFlag;
            obj = new Phantom((ghost::PhantomColor) colorFlag);
        } else {
            obj = (type_obj == CUBE) ?  (Object*) new Cube(Color(0.1, 0.1, 0.65), Point(), true)
                : (type_obj == PILL) ? (Object*) new Pill(Color(0.99, 1, 0), true)
                : (type_obj == POWER_PILL) ? (Object*) new PowerPill(Color(0.99, 1, 0), true)
                : (type_obj == FRUIT) ? (Object*) new Fruit(true)
                : (type_obj == PACMAN) ? (Object*) new Pacman(true)
                : (type_obj == GATE) ? (Object*) new Gate(true)
                : (type_obj == MAP) ? (Object*) new Map(true)
                : nullptr;
            if (obj == nullptr) continue;
        }
        getline(file, line);
        stringstream(line) >> *obj;
        objects.push_back(make_pair(type_obj, obj));
    }

    file.close();
}

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
            
            Object* new_obj = (current->selfType == CUBE) ?  (Object*) new Cube((Cube&)*current)
                : (current->selfType == PILL) ? (Object*) new Pill((Pill&)*current)
                : (current->selfType == POWER_PILL) ? (Object*)new PowerPill((PowerPill&)*current)
                : (current->selfType == FRUIT) ? (Object*) new Fruit((Fruit&)*current)
                : (current->selfType == PHANTOM) ? (Object*) new Phantom((Phantom&)*current)
                : (current->selfType == PACMAN) ? (Object*) new Pacman((Pacman&)*current)
                : (current->selfType == GATE) ? (Object*) new Gate((Gate&)*current)
                : (current->selfType == MAP) ? (Object*) new Map((Map&)*current)
                : nullptr;

            if(new_obj != nullptr)
                objects.push_back(make_pair(current->selfType, new_obj));
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
    
    case '@':
        camera_idx = ++camera_idx > cameras.size()-1 ? 0 : camera_idx;
        *glutGUI::cam = cameras[camera_idx];
        break;

    case '$':
        serializeObjects(objects);
        break;

    case '%':
        deserializeObjects(objects);
        break;
    
    default:
        break;
    }
}

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

vector<CameraDistante> getCameras(){
    return {
        CameraDistante(Vetor3D(0.225, 4.675, 7.911), Vetor3D(0.391, 0.334, -0.027), Vetor3D(0.010, 0.877, -0.479)),
        CameraDistante(Vetor3D(0.491, 3.291, -8.580), Vetor3D(0.391, 0.334, -0.027), Vetor3D(-0.003, 0.945, 0.326)),
        CameraDistante(Vetor3D(9.043, 2.989, -0.098), Vetor3D(0.391, 0.334, -0.027), Vetor3D(-0.293, 0.956, 0.002)),
        CameraDistante(Vetor3D(0.684, 1.774, 3.793), Vetor3D(2.041, 0.385, 0.353), Vetor3D(0.129, 0.936, -0.327)),
        CameraDistante(Vetor3D(0.104, 10.915, 1.678), Vetor3D(-0.009, 0.713, -0.063), Vetor3D(-0.064, 0.168, -0.983)),
        CameraDistante(Vetor3D(0.900, 1.116, 0.453), Vetor3D(0.928, 1.101, 0.414), Vetor3D(0.175, 0.953, -0.243)),
        CameraDistante(Vetor3D(-4.171, 2.606, 3.454), Vetor3D(-2.245, 0.615, 1.155), Vetor3D(0.355, 0.833, -0.423)),
        CameraDistante(Vetor3D(-2.166, 1.104, 0.898), Vetor3D(-2.135, 1.079, 0.868), Vetor3D(0.371, 0.858, -0.354))
    };
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,draw,teclado, glutGUI::defaultMouseButton, "Pacman World");
}
