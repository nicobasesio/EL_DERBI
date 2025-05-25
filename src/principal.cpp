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
    static bool pieza_seleccionada = false;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Transformar coordenadas de pantalla a coordenadas del mundo
        if ((x >= 15 && x <= 400) && (y >= 13 && y <= 575 * 18 / 21 + 13)) {
            raton.posicion.x = (14.0 * x - 5600.0) / 385.0;
            raton.posicion.y = ((-18.0 * y) + (575.0 * 18 * 18 / 21 + 13 * 18)) / (575.0 * 18 / 21);
        }
        else if ((x > 400 && x <= 785) && (y >= 13 && y <= 575 * 18 / 21 + 13)) {
            raton.posicion.x = (-14.0 * x + 5600.0) / -385.0;
            raton.posicion.y = ((-18.0 * y + 575.0 * 18 * 18 / 21 + 13 * 18)) / (575.0 * 18 / 21);
        }
        else if ((x > 400 && x <= 785) && (y >= (575 * 18 / 21) + 13 && y <= 588)) {
            raton.posicion.x = (-14.0 * x + 5600.0) / -385.0;
            raton.posicion.y = ((3.0 * y - 3 * (575 * 18 / 21 + 13))) / (575.0 * 18 / 21 - 575.0);
        }
        else if ((x >= 15 && x <= 400) && (y >= (575 * 18 / 21) + 13 && y <= 588)) {
            raton.posicion.x = (14.0 * x - 5600.0) / 385.0;
            raton.posicion.y = ((3.0 * y - 3 * (575 * 18 / 21 + 13))) / (575.0 * 18 / 21 - 575.0);
        }
        else {
            mundo.casilla_seleccionada = false;
            return;
        }

        VECTOR2D centro = raton.elige_casilla();
        int i = static_cast<int>(raton.casilla.x) - 1;
        int j = static_cast<int>(raton.casilla.y) - 1;

        // Verificar si la casilla es válida
        if (!mundo.casillaValida(i, j)) {
            std::cout << "[INFO] Casilla vacía o inválida, no se puede seleccionar\n";
            return;
        }

        if (!pieza_seleccionada) {
            // Primer clic: seleccionar pieza
            if (mundo.getControl()[i][j] == nullptr) {
                std::cout << "[INFO] Casilla vacía, no se puede seleccionar\n";
                return;
            }

            if (mundo.getControl()[i][j]->get_color() != mundo.turno) {
                std::cout << "[INFO] No puedes mover piezas del otro color\n";
                return;
            }

            // Selección válida
            posicion_central_click = centro;
            posicion_central_click_anterior = centro;
            mundo.set_posicion_central_click(centro);
            mundo.set_posicion_central_click_anterior(centro);
            mundo.casilla_seleccionada = true;
            pieza_seleccionada = true;
        }
        else {
            // Segundo clic: intentar mover
            posicion_central_click = centro;

            if (posicion_central_click.x == posicion_central_click_anterior.x &&
                posicion_central_click.y == posicion_central_click_anterior.y) {
                std::cout << "[INFO] Casilla deseleccionada\n";
                mundo.casilla_seleccionada = false;
                pieza_seleccionada = false;
                return;
            }

            mundo.set_posicion_central_click(posicion_central_click);
            mundo.set_posicion_central_click_anterior(posicion_central_click_anterior);
            mundo.set_casilla_actual(raton.casilla);
            mundo.set_casilla_anterior(raton.casilla_anterior);

            if (!mundo.casilla_seleccionada) {
                std::cout << "[INFO] No hay casilla seleccionada, no se puede mover\n";
                pieza_seleccionada = false;
                return;
            }

            mundo.casilla_seleccionada = true;
            mundo.mueve();
            pieza_seleccionada = false;
        }
    }
}

