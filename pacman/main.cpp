#include <iostream>

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

using namespace std;

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
static int perspective_idx = 0;
static int ortho_idx = 0;
static float ortho_factor = 4;

//-------------------viewPorts------------------
bool viewports = false;
bool scissored = false;

//-------------------sombra-------------------
bool shadow_on_planes = false;
static bool draw_shadow = false;
bool light_type = true;
float k = 0.0;

//-------------------light-------------------
Point light_default = Point(0, 2, 0);

static string OBJECTS_FILENAME = "objects.pacman";


void saveCameraState(){
    string filename = "camera.pacman";
    ofstream file;
    file.open(filename, ios::app);
    file << "glutGUI::cam->e.x = " << glutGUI::cam->e.x << ";" << endl;
    file << "glutGUI::cam->e.y = " << glutGUI::cam->e.y << ";" << endl;
    file << "glutGUI::cam->e.z = " << glutGUI::cam->e.z << ";" << endl;
    file << "glutGUI::cam->c.x = " << glutGUI::cam->c.x << ";" << endl;
    file << "glutGUI::cam->c.y = " << glutGUI::cam->c.y << ";" << endl;
    file << "glutGUI::cam->c.z = " << glutGUI::cam->c.z << ";" << endl;
    file << "glutGUI::cam->u.x = " << glutGUI::cam->u.x << ";" << endl;
    file << "glutGUI::cam->u.y = " << glutGUI::cam->u.y << ";" << endl;
    file << "glutGUI::cam->u.z = " << glutGUI::cam->u.z << ";" << endl;
    file << endl;
    file.close();
}


void persp_cam_1(){
    glutGUI::cam->e.x = 2.57946;
    glutGUI::cam->e.y = 0.447501;
    glutGUI::cam->e.z = -3.34196;
    glutGUI::cam->c.x = 2.58955;
    glutGUI::cam->c.y = 0.735287;
    glutGUI::cam->c.z = 0.697798;
    glutGUI::cam->u.x = -0.000177465;
    glutGUI::cam->u.y = 0.997472;
    glutGUI::cam->u.z = -0.0710579;
}

void persp_cam_2(){
    glutGUI::cam->e.x = 3.35668;
    glutGUI::cam->e.y = 0.393931;
    glutGUI::cam->e.z = -3.26421;
    glutGUI::cam->c.x = 2.58955;
    glutGUI::cam->c.y = 0.735287;
    glutGUI::cam->c.z = 0.697798;
    glutGUI::cam->u.x = 0.0160218;
    glutGUI::cam->u.y = 0.996442;
    glutGUI::cam->u.z = -0.0827484;
}

void persp_cam_3(){
    glutGUI::cam->e.x = 3.51747;
    glutGUI::cam->e.y = 0.636584;
    glutGUI::cam->e.z = -3.24324;
    glutGUI::cam->c.x = 2.58955;
    glutGUI::cam->c.y = 0.735287;
    glutGUI::cam->c.z = 0.697798;
    glutGUI::cam->u.x = 0.00558545;
    glutGUI::cam->u.y = 0.999703;
    glutGUI::cam->u.z = -0.0237224;
}

void ortho_view_front() {
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 0;
    glutGUI::cam->e.z = 4*ortho_factor;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void ortho_view_back() {
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 0;
    glutGUI::cam->e.z = -4*ortho_factor;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void ortho_view_left() {
    glutGUI::cam->e.x = -4*ortho_factor;
    glutGUI::cam->e.y = 0;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void ortho_view_right() {
    glutGUI::cam->e.x = 4*ortho_factor;
    glutGUI::cam->e.y = 0;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void ortho_view_top() {
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 4*ortho_factor;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 0;
    glutGUI::cam->u.z = -1;
}


void ortho_axo_iso() { // Orthographic axonometric isometric
    glutGUI::cam->e.x = 4;
    glutGUI::cam->e.y = 2;
    glutGUI::cam->e.z = 3;
    glutGUI::cam->c.x = 1;
    glutGUI::cam->c.y = -.5;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void ortho_axo_dimetric() { // Orthographic axonometric dimetric
    glutGUI::cam->e.x = 4;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 3;
    glutGUI::cam->c.x = 1;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void ortho_axo_trimetric() { // Orthographic axonometric trimetric
    glutGUI::cam->e.x = 4;
    glutGUI::cam->e.y = 0;
    glutGUI::cam->e.z = 3;
    glutGUI::cam->c.x = 1;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

std::vector<void (*)()> perspectives = {&persp_cam_1, &persp_cam_2, &persp_cam_3};
std::vector<void (*)()> orthos = {
    &ortho_view_front,
    &ortho_view_left,
    &ortho_view_back,
    &ortho_view_right,
    &ortho_view_top,

    &ortho_axo_iso,
    &ortho_axo_dimetric,
    &ortho_axo_trimetric
};


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

void drawWall(Cube& cube) {cube.translate(2.5, .25, 2)->scale(.125, .0625, .125)->draw();}
void drawPill(Pill& pill) {pill.translate(3,0.25,1)->scale(.125,.125,.125)->draw();}
void drawPowerPill(PowerPill& superpill) {superpill.translate(2,0.25,1)->scale(.125,.125,.125)->draw();}
void drawFruit(Fruit& fruit) {fruit.translate(2.5, .25, 0)->scale(0.25, 0.25, 0.25)->draw();}
void drawPacman(Pacman& pacman) {pacman.translate(2.5, .25, -2)->scale(.25,.25,.25)->draw();}
void drawGate(Gate& gate) {gate.translate(2.5, .25, -3)->scale(0.25, 0.25, 0.25)->draw();}
void drawPacManMap(Map& map_){map_.scale(.75,.75,.75)->translate(-1,.1,0)->draw();}

void drawPhantom(Phantom& phantom) {
    float pos[] = {1.75, 2.25, 2.75, 3.25};
    phantom.translate(pos[phantom.colorFlag] , .25, -1)
          ->scale(0.25,0.25,0.25)
          ->draw();
}

void drawPhatoms(map<ghost::PhantomColor, Phantom>& phantoms) {
    ghost::PhantomColor pcs[] = {ghost::RED, ghost::PINK, ghost::BLUE, ghost::ORANGE};
    float pos[] = {1.75, 2.25, 2.75, 3.25};
    for(int i = 0; i < 4; i++){
        Phantom& p = phantoms[pcs[i]];
        p.translate(pos[i], .25, -1)
        ->scale(0.25,0.25,0.25)
        ->draw();
    }
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

void displayInner() {

    GUI::setLight(0, glutGUI::lx,glutGUI::ly,glutGUI::lz, true, false);
    GUI::drawOrigin(1);
    GUI::setColor(0.6,0.6,0.6, 1,true);

    glPushMatrix();
    glTranslated(0.0,k,0.0);
    GUI::drawFloor(10,8,0.1,0.1);

    glPopMatrix();

    for (int i = 0; i < objects.size(); ++i) {
        glPushMatrix();
            drawObject(objects[i].second);
        glPopMatrix();
    }

    float lightPos[4] = {1.5+glutGUI::lx,1.5+glutGUI::ly,1.5+glutGUI::lz, light_type};

    glPushMatrix();
        GLfloat sombra[4][4];
        GUI::shadowMatrixYk(sombra,lightPos,k);
        glMultTransposeMatrixf( (GLfloat*)sombra );
        glDisable(GL_LIGHTING);
        glColor3d(0.0,0.0,0.0);
        if (draw_shadow) {
            bool aux = glutGUI::draw_eixos;
            glutGUI::draw_eixos = false;
                glPushMatrix();
                    drawObject(objects[object_idx].second);
                glPopMatrix();
            glutGUI::draw_eixos = aux;
        }

        glEnable(GL_LIGHTING);
    glPopMatrix();
    //-------------------sombra-------------------
}

void shadow_hover( GLfloat plano[4], float lightPos[4] ) {
    bool aux = glutGUI::draw_eixos;
    glutGUI::draw_eixos = false;

    glDisable(GL_LIGHTING);
    glColor3d(0.0,0.0,0.0);

    GLfloat sombra[4][4];

    glPushMatrix();
        GUI::shadowMatrix(sombra,plano,lightPos);
        glMultTransposeMatrixf( (GLfloat*)sombra );
            drawObject(objects[object_idx].second);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}


void sombraPlano() {
    float lightPos[4] = {glutGUI::lx,glutGUI::ly,glutGUI::lz, light_type ? 1.0f : 0.0f};

    // GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,light_type);
    GLfloat plano_chao[4] = {0,1,0, -0.001};
    shadow_hover(plano_chao, lightPos);

    // lateral
    GUI::setColor(1, 0.98, 0.98);
    glPushMatrix();
        GUI::drawBox(-5,0,-4, -4.77,5,0);
    glPopMatrix();
    GLfloat plano_lateral[4] = {1,0,0, 4.77-0.001};
    shadow_hover(plano_lateral, lightPos);

    // frente
    GUI::setColor(1, 0.98, 0.98);
    glPushMatrix();
        GUI::drawBox(-4.77,0,-4, 0,5,-3.77);
    glPopMatrix();
    GLfloat plano_frente[4] = {0,0,1, 3.77-0.001};
    shadow_hover(plano_frente, lightPos);

    // inclinado
    GUI::setColor(1, 0.98, 0.98);
    glPushMatrix();
        glTranslatef(-4.2,0,-2);
        glRotatef(-45, 0,0,1);
        GUI::drawQuad(1,4);
    glPopMatrix();
    GLfloat plano_inclinado[4] = {1,1,0, 4.2-0.001};
    shadow_hover(plano_inclinado, lightPos);
}


void desenha_viewports_gerais() {
    GUI::displayInit();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z,glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z,glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);
    displayInner();

    glLoadIdentity();
    glViewport(0, glutGUI::height/2, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(0,10,0, 0,0,0, 0,0,1);
    displayInner();

    glLoadIdentity();
    glViewport(glutGUI::width/2, 0, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(0,1,-10, 0,1,0, 0,1,0);
    displayInner();

    glLoadIdentity();
    glViewport(glutGUI::width/2, glutGUI::height/2, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(10,1,0, 0,1,0, 0,1,0);
    displayInner();
}


void draw() {

    GUI::displayInit();

    if(!viewports)
       displayInner();
    else
       desenha_viewports_gerais();

    if (shadow_on_planes)
        sombraPlano();

    Object::selectObject(enable_select ? objects[object_idx].second : nullptr);
    objects[object_idx].second->transformColor = enable_transform;

    if(enable_transform){
        (*objects[object_idx].second)[TRANSLATE] += Point(glutGUI::dtx, glutGUI::dty, glutGUI::dtz)*tfactor;
        (*objects[object_idx].second)[ROTATE] += Point(glutGUI::dax, glutGUI::day, glutGUI::daz)*tfactor;
        (*objects[object_idx].second)[SCALE] += Point(glutGUI::dsx, glutGUI::dsy, glutGUI::dsz)*tfactor;
    }

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
    case 'b':
        if(enable_transform)
            (*objects[object_idx].second)[TRANSLATE][paxis::Z]-=0.1;
        break;
    case 'f':
        if(enable_transform)
            (*objects[object_idx].second)[TRANSLATE][paxis::Z]+=0.1;
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

        glutGUI::lx = light_default.x;
        glutGUI::ly = light_default.y;
        glutGUI::lz = light_default.z;

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

    case '(':
        draw_shadow = enable_select && !draw_shadow;
        break;

    case ')':
        shadow_on_planes = enable_select && !shadow_on_planes;
        break;

    case 'i':
        light_type = !light_type;
        break;

    case 'v':
        viewports = !viewports;
        break;

    case 'n':
        glutGUI::perspective = !glutGUI::perspective;
        break;

    case '\'':
        glutGUI::pontosDeFuga = !glutGUI::pontosDeFuga;
        break;

    case '*':
        // iterate over perspective cameras
        (*perspectives[perspective_idx])();
        perspective_idx = ++perspective_idx > perspectives.size()-1 ? 0 : perspective_idx;
        break;
    
    case '!':
        // iterate over ortho cameras
        (*orthos[ortho_idx])();
        ortho_idx = ++ortho_idx > orthos.size()-1 ? 0 : ortho_idx;
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

void drawControlPoints(){
    for (size_t i=0; i < objects.size(); i++) {
        glPushName(i+1);
            drawObject(objects[i].second);
        glPopName();
    }
}

int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];
    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);
    GUI::displayInit();
    drawControlPoints();
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}

void mouse(int button, int state, int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            int pick = picking( x, y, 5, 5 );
            if (pick != 0) {
                if(!enable_transform)
                    enable_select = !enable_select;
                if (enable_select) {
                    object_idx = pick-1;
                    Object::selectObject(objects[object_idx].second);
                    glutGUI::lbpressed = false;
                }else{
                    shadow_on_planes = false;
                    draw_shadow = false;
                }
            }
        }
    }
}


int main()
{
    cout << "Hello World!" << endl;

    glutGUI::lx = 0;
    glutGUI::ly = 2;
    glutGUI::lz = 0;

    GUI gui = GUI(800,600,draw,teclado, mouse, "Pacman World");
}
