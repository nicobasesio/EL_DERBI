#include "ETSIDI.h"
#include <iostream>
#include "mundo.h"
#include "raton.h"
#include<freeglut.h>
#include <string>
#include <random>
using namespace std;

Mundo mundo;
Raton raton;
Tablero tablero;
VECTOR2D posicion_central_click{};
VECTOR2D posicion_central_click_anterior{};

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void display();

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("MiJuego");

    // Modo 2D ortográfico
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -5, 20);  // Cámara 2D
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desactivar iluminación (no usamos normales ni materiales)
    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    // Registrar callbacks
    glutDisplayFunc(OnDraw);
    glutTimerFunc(33, OnTimer, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutMouseFunc(mouseClick);

    // Inicializa mundo
    mundo.inicializa();
    mundo.inicializa_tab();

    glutMainLoop();
    return 0;
}
void OnDraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    mundo.dibuja();

    glutSwapBuffers();
}

void OnTimer(int value) {
    // Actualiza y redibuja
    glutTimerFunc(33, OnTimer, 0);
    glutPostRedisplay();
}


void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void mouseClick(int button, int state, int x, int y) {

    // Manejar eventos de clic del ratón
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        // Cuadrante arriba izquierda
        if ((x >= 15 && x <= 400) && (y >= 13 && y <= 575 * 18 / 21 + 13)) {
            raton.posicion.x = (static_cast<double>(14) * x - 5600) / 385;
            raton.posicion.y = static_cast<double>(static_cast<double>((-18 * y) + (575 * 18 * 18 / 21 + 13 * 18)) / (575 * 18 / 21));
        }
        // Cuadrante arriba derecha
        if ((x > 400 && x <= 785) && (y >= 13 && y <= 575 * 18 / 21 + 13)) {
            raton.posicion.x = (static_cast<double>(-14) * x + 5600) / -385;
            raton.posicion.y = double((double(-18 * y + 575 * 18 * 18 / 21 + 13 * 18)) / (575 * 18 / 21));
        }
        // Cuadrante abajo derecha
        if ((x > 400 && x <= 785) && (y >= (575 * 18 / 21) + 13 && y <= 588)) {
            raton.posicion.x = (static_cast<double>(-14) * x + 5600) / -385;
            raton.posicion.y = double((double(3 * y - 3 * (575 * 18 / 21 + 13))) / (575 * 18 / 21 - 575));
        }
        // Cuadrante abajo izquierda
        if ((x >= 15 && x <= 400) && (y >= (575 * 18 / 21) + 13 && y <= 588)) {
            raton.posicion.x = (static_cast<double>(14) * x - 5600) / 385;
            raton.posicion.y = double((double(3 * y - 3 * (575 * 18 / 21 + 13))) / (575 * 18 / 21 - 575));
        }


        /*PROCESO QUE SE SIGUIÓ PARA SINCRONIZAR LAS COORDENADAS QUE LEE EL RATÓN Y LAS QUE LEEN LAS CASILLAS*/
        //std::cout << "Posicion del clic: (" << raton.posicion.x << ", " << raton.posicion.y << ")" << std::endl;
        posicion_central_click_anterior.x = posicion_central_click.x;//para guardar la posicion anterior del click. Se usa para el movimiento de piezas
        posicion_central_click_anterior.y = posicion_central_click.y;
        posicion_central_click = raton.elige_casilla(); //la funcion reconoce el centro de la casilla clickeada
        //std::cout << "Raton lee: (" << x << ", " << y << ")" << std::endl;
        //std::cout << "Pos central click: (" << posicion_central_click.x << "," << posicion_central_click.y << ")"<<std::endl;
        //std::cout << "Pos central click anterior: (" << posicion_central_click_anterior.x << "," << posicion_central_click_anterior.y << ")" << std::endl;



        mundo.set_posicion_central_click(posicion_central_click);
        mundo.set_posicion_central_click_anterior(posicion_central_click_anterior);
        mundo.set_casilla_actual(raton.casilla);    // Se pasa la casilla actual de principa.cpp a mundo.cpp
        mundo.set_casilla_anterior(raton.casilla_anterior);// Se pasa la casilla anterior de principa.cpp a mundo.cpp
    }
}