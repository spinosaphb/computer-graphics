#include <iostream>

using namespace std;

#include <gui.h>
#include <Sphere.h>
#include <model3ds.h>

float px = 0.0;
float py = 0.0;
float raio = 0.5;
float theta = 0.0;
#define WIDTH 7.0
#define HEIGHT 9.0

// 0: empty space, 1: wall, 2: dot, 3: power-up, 4: Ghost House Door, 5: Fruit
int pacmanMap[31][28] = {
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
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 1, 1, 1, 4, 4, 1, 1, 1, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 12
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 13
    {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, // 14
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 15
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 16
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 17
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0}, // 18
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1}, // 19
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 20
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 21
    {1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1}, // 22
    {1, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3, 1}, // 23
    {1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1}, // 24
    {1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1}, // 25
    {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1}, // 26
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1}, // 27
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1}, // 28
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 29
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 30
};

void piramide()
{
    //glBegin(GL_LINES);
    //    glVertex3f(0,0,0);
    //    glVertex3f(-1,1,0);
    //glEnd();
    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,1,1);
        glVertex3f(1,0,1);
        glVertex3f(0,1,0);
        glVertex3f(-1,0,1);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,1,-1);
        glVertex3f(-1,0,-1);
        glVertex3f(0,1,0);
        glVertex3f(1,0,-1);
    glEnd();
    //lateral direita
    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(1,0,1);
        glVertex3f(1,0,-1);
        glVertex3f(0,1,0);
    glEnd();
    //lateral esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(-1,0,1);
        glVertex3f(0,1,0);
        glVertex3f(-1,0,-1);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f( 1,0, 1);
        glVertex3f(-1,0, 1);
        glVertex3f(-1,0,-1);
        glVertex3f( 1,0,-1);
    glEnd();
}

Vetor3D rotacaoZ( Vetor3D v, float theta ) {
    Vetor3D vt;
    float thetaRad = theta*PI/180;
    vt.x = cos(thetaRad)*v.x - sin(thetaRad)*v.y;
    vt.y = sin(thetaRad)*v.x + cos(thetaRad)*v.y;
    vt.z = v.z;
    return vt;
}

Vetor3D translacao( Vetor3D v, Vetor3D desl ) {
    Vetor3D vt;
    vt.x = v.x + desl.x;
    vt.y = v.y + desl.y;
    vt.z = v.z + desl.z;
    return vt;
}

void transformacoesSemMatriz() {
    //testando transformar um objeto (um simples triangulo, por exemplo)

    //translacao
    //glBegin(GL_POLYGON);
    //    glNormal3f(0,0,1);
    //    glVertex3f( 0+px,0+py, 0);
    //    glVertex3f( 1+px,0+py, 0);
    //    glVertex3f( 0+px,1+py, 0);
    //glEnd();

    //rotacao
    // //theta += 1;
    //float thetaRad = theta*PI/180;
    //glBegin(GL_POLYGON);
    //    glNormal3f(0,0,1);
    //    //glVertex3f( 0,0, 0);
    //    glVertex3f( cos(thetaRad)*0 - sin(thetaRad)*0, sin(thetaRad)*0 + cos(thetaRad)*0, 0);
    //    //glVertex3f( 1,0, 0);
    //    glVertex3f( cos(thetaRad)*1 - sin(thetaRad)*0, sin(thetaRad)*1 + cos(thetaRad)*0, 0);
    //    //glVertex3f( 0,1, 0);
    //    glVertex3f( cos(thetaRad)*0 - sin(thetaRad)*1, sin(thetaRad)*0 + cos(thetaRad)*1, 0);
    //glEnd();

    //aplicando funcoes de transformacao nos vertices do objeto

    //exemplo de um triangulo 2D
    //Vetor3D v1 = Vetor3D(0,0,0);
    //Vetor3D v2 = Vetor3D(1,0,0);
    //Vetor3D v3 = Vetor3D(0,1,0);

    //exemplo de um objeto afastado da origem
    //Vetor3D v1 = Vetor3D(1,0,0);
    //Vetor3D v2 = Vetor3D(2,0,0);
    //Vetor3D v3 = Vetor3D(1.5,1,0);

    //exemplo guardando tbm o vetor normal do triangulo
    //Vetor3D vN = Vetor3D(0,0,1);
    //Vetor3D v1 = Vetor3D(0,0,0);
    //Vetor3D v2 = Vetor3D(1,0,0);
    //Vetor3D v3 = Vetor3D(0,1,0);

    //exemplo da face frontal da nossa piramide
    Vetor3D vN = Vetor3D(0,1,1);
    Vetor3D v1 = Vetor3D(1,0,1);
    Vetor3D v2 = Vetor3D(0,1,0);
    Vetor3D v3 = Vetor3D(-1,0,1);

    Vetor3D desl = Vetor3D( px,py,0 ); //          R.(T.vi)
    v1 = translacao(v1,desl);
    v2 = translacao(v2,desl);
    v3 = translacao(v3,desl);

    vN = rotacaoZ(vN,theta);
    v1 = rotacaoZ(v1,theta);
    v2 = rotacaoZ(v2,theta);
    v3 = rotacaoZ(v3,theta);

    glBegin(GL_POLYGON);
        glNormal3f( vN.x, vN.y, vN.z );
        glVertex3f( v1.x, v1.y, v1.z );
        glVertex3f( v2.x, v2.y, v2.z );
        glVertex3f( v3.x, v3.y, v3.z );
    glEnd();
}


void drawCube() {
    glBegin(GL_QUADS);
        // Front face
        glNormal3f(0, 0, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, -1, 1);

        // Back face
        glNormal3f(0, 0, -1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);
        // Top face
        glNormal3f(0, 1, 0);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, 1);
        // Bottom face
        glNormal3f(0, -1, 0);
        glVertex3f(1, -1, 1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        // Left face
        glNormal3f(-1, 0, 0);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, -1, -1);
        // Right face
        glNormal3f(1, 0, 0);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, 1);

    glEnd();
}

void drawPoint() {
    glPushMatrix();
        glScalef(.5, 1, 0.5);
        drawCube();
    glPopMatrix();
    glPushMatrix();
        glScalef(1, 0.65, 1);
        drawCube();
    glPopMatrix();
}

void drawFruit() {
    glPushMatrix();
        glRotatef(-30, 1, 1, 0);
        glPushMatrix();
            GUI::setColor(1, 0, .5);
            glScalef(.3, .3, .3);
            glTranslatef(-1, 0, 0);
            drawPoint();
        glPopMatrix();

        glPushMatrix();
            GUI::setColor(1, 0, .5);
            glScalef(.3, .3, .3);
            glTranslatef(2, 0, 0);
            drawPoint();
        glPopMatrix();

        // draw cherry stalk
        glPushMatrix();
            GUI::setColor(0, 1, 0); // green color for stalk
            glTranslatef(0, .8, 0);
            glRotatef(-30, 0, 0, 1);
            glScalef(.2, 2.5, .2);
            glScalef(.3, .3, .3);
            drawCube();
        glPopMatrix();

        // draw cherry stalk
        glPushMatrix();
            GUI::setColor(0, 1, 0); // green color for stalk
            glTranslatef(.37, .5, 0);
            glRotatef(45,0,0,1);
            glScalef(.2, 1.6, .2);
            glScalef(.3, .3, .3);
            drawCube();
        glPopMatrix();

   glPopMatrix();
}

void drawPacManMap() {
//  for (int i = 0; i < 31; i++) {
//    for (int j = 0; j < 28; j++) {
//      if (pacmanMap[i][j] != 0) {
//        glPushMatrix();
//        glTranslatef(j, -i, 0); // position the cube based on the i, j index
//        drawCube(); // draw the cube
//        glPopMatrix();
//      }
//    }
//  }
    // Define the size of each cube
    const float cubeSize = 0.10f;
    // Iterate over the pacmanMap matrix
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 28; j++) {
            // Get the current value in the matrix
            int value = pacmanMap[i][j];

            // Determine the position of the cube based on the matrix indices
            float x = (j - 14) * cubeSize;
            float z = (16 - i) * cubeSize;

            // Draw a cube if the value is 1, which represents a wall
            if (value == 1) {
                glPushMatrix();
                GUI::setColor(0.1+(i/40),0.1+(i/40),0.65+(i/40), 1,true);
                glTranslatef(x*2, 1.0, z*-2);
                glScalef(cubeSize, cubeSize, cubeSize);
                drawCube();
                glPopMatrix();
            }

            else if (value == 2) {
                glPushMatrix();
                GUI::setColor(0.99, 1, 0, 1,true);
                glTranslatef(x*2, 1.0, z*-2);
                glScalef(cubeSize/2, cubeSize/2, cubeSize/2);
                drawPoint();
                glPopMatrix();
            }
            else if (value == 5) {
                glPushMatrix();
                    glTranslatef(x*2, 1.0, z*-2);
                    glScalef(0.25, 0.25, 0.25);
                    drawFruit();
                glPopMatrix();
            }
        }
    }
}


void draw() {

    GUI::displayInit();

    GUI::setLight(0, 0,2,0, true, false);

    GUI::setColor(.5,.5,.5);
    GUI::drawFloor(WIDTH, HEIGHT);
    GUI::drawOriginAL(1, 0.1);

//    Sphere sphere = Sphere(color, point, raio);
//    sphere.draw();
//    glPushMatrix();
//    glTranslatef(2,0,-3);
//    piramide();
//    glPopMatrix();

//    float factor = 4.0;
//    float fscale = 1/factor;
//    float leftWidth = -(WIDTH/2.0*(factor-fscale));
//    float rightWidth = WIDTH/2.0*factor;
//    float leftHeight = -(HEIGHT/2.0*(factor-fscale));

//    for(float i=leftWidth; i <= rightWidth; i+=1.5){
//        glPushMatrix();
//            GUI::setColor(0.1+(i/40),0.1+(i/40),0.65+(i/40), 1,true);
//            glScalef(fscale,fscale,fscale);
//            glTranslatef(i,1,leftHeight);
//            drawCube();
//        glPopMatrix();
//    }
    drawPacManMap();
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
    
    

    GUI gui = GUI(800,600,draw,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//    //if () {
//    //    break;
//    //}
//}





















//adicionar:
//-deslocar cubo com o teclado
//-deslocar cubo com o mouse
//-primitivas OpenGL (glBegin, glEnd)
//-glNormal, iluminação

//-leitor 3DS
//-usar as transformacoes matriciais do proprio OpenGL
//-push/popMatrix (podem ser usados um dentro do outro - nocao de pilha)

//-ordem das transformacoes
//  -translacao e rotacao
//  -testar escala!!!
//-interpretacao de uma composicao de transformacoes já definida
//      <----------- globais
//  -   T.Rz.Ry.Rx.S . v
//      -----------> locais
//  -direita->esquerda: Transfs globais
//  -esquerda->direita: Transfs locais
