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

//--------------------------------------------------
int tiempo_jugador1; // en segundos
int tiempo_jugador2;
bool fin_partida = false;
unsigned int ultimo_tiempo_actualizado = 0;
int jugador_que_pierde = 0;

enum EstadoPantalla { MENU_START, MENU_MODOS, JUEGO, MENU_FINAL };
EstadoPantalla estado = MENU_START;
int modoSeleccionado = 0;
enum Turno { BLANCO, ROJO };
static bool pieza_seleccionada = false;

//-----------------------------------------------------




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
    ETSIDI::playMusica("sonido/musica.mp3", true); // música de fondo del menú

    mundo.inicializa_tab();

    glutMainLoop();
    return 0;
}

void OnDraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (estado == MENU_START) {
        // Dibuja el fondo del menú
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu1.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.005);	// izda abajo
        glTexCoord2d(1, 1); glVertex3d(14, -3, 0.005);	// dcha abajo
        glTexCoord2d(1, 0); glVertex3d(14, 18, 0.005);	// dcha arriba
        glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.005);// izda arriba
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    }
    else if (estado == MENU_MODOS) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu2.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.005);
        glTexCoord2d(1, 1); glVertex3d(14, -3, 0.005);
        glTexCoord2d(1, 0); glVertex3d(14, 18, 0.005);
        glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.005);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

    }

    else if (estado == JUEGO) {
        mundo.dibuja();
        glColor3f(1, 1, 1);
        char buffer1[20], buffer2[20];
        sprintf(buffer1, "Jugador 1: %02d:%02d", tiempo_jugador1 / 60, tiempo_jugador1 % 60);
        sprintf(buffer2, "Jugador 2: %02d:%02d", tiempo_jugador2 / 60, tiempo_jugador2 % 60);
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::printxy(buffer1, -14, 19);
        ETSIDI::printxy(buffer2, 5, 19);

    }
    else if (estado == MENU_FINAL) {
        std::string imagen_final = (jugador_que_pierde == 1) ? "imagenes/real_madrid_gana.png" : "imagenes/atletico_gana.png";
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(imagen_final.c_str()).id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.005);
        glTexCoord2d(1, 1); glVertex3d(14, -3, 0.005);
        glTexCoord2d(1, 0); glVertex3d(14, 18, 0.005);
        glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.005);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::printxy(jugador_que_pierde == 1 ? "\u00a1El tiempo del Jugador 1 se ha agotado!" : "\u00a1El tiempo del Jugador 2 se ha agotado!", -10, 17);
        ETSIDI::printxy("Pulsa cualquier tecla para volver al menu", -10, 1);
    }

    glutSwapBuffers();


}

void OnTimer(int value) {
    if (estado == JUEGO && !fin_partida) {
        unsigned int tiempo_actual = glutGet(GLUT_ELAPSED_TIME);
        if (tiempo_actual - ultimo_tiempo_actualizado >= 1000) {
            if (mundo.turno == BLANCO)
                tiempo_jugador1--;
            else
                tiempo_jugador2--;
            ultimo_tiempo_actualizado = tiempo_actual;
            if (tiempo_jugador1 <= 0 || tiempo_jugador2 <= 0) {
                fin_partida = true;
                jugador_que_pierde = tiempo_jugador1 <= 0 ? 1 : 2;
                estado = MENU_FINAL;
                ETSIDI::stopMusica();
                ETSIDI::play("sonido/final.mp3");
            }
        }
    }

    glutTimerFunc(33, OnTimer, 0);
    glutPostRedisplay();
}


void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
    if (estado == MENU_FINAL) {
        estado = MENU_START;
        fin_partida = false;
        jugador_que_pierde = 0;
        tiempo_jugador1 = tiempo_jugador2 = 0;
        ETSIDI::playMusica("sonido/musica.mp3", true);
    }

}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void mouseClick(int button, int state, int x, int y) {


    if (estado == MENU_START && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Coordenadas aproximadas del botón START 

        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            float x_normal = ((x / 800.0f) * 30.0f) - 15.0f;
            float y_normal = ((600.0f - y) / 600.0f) * 25.0f - 5.0f;

            if (estado == MENU_START) {
                std::cout << "Click en pantalla: (" << x << "," << y << ") => mundo: (" << x_normal << "," << y_normal << ")\n";
                if (x_normal > -10 && x_normal < 10 && y_normal > -5 && y_normal < 10) {
                    estado = MENU_MODOS;
                    ETSIDI::stopMusica();
                    ETSIDI::play("sonido/Inicio.mp3");
                    glutPostRedisplay();
                }
                return;
            }

            if (estado == MENU_MODOS) {
                std::cout << "Click en selección de modo: (" << x_normal << "," << y_normal << ")\n";

                // Detectar Modo 1
                if (x_normal > -6 && x_normal < 6 && y_normal > 8 && y_normal < 11) {
                    modoSeleccionado = 1;
                    estado = JUEGO;
                    mundo.inicializa();  // o mundo.inicializaModo1();
                    return;
                }

                // Detectar Modo 2
                if (x_normal > -6 && x_normal < 6 && y_normal > 4 && y_normal < 7) {
                    modoSeleccionado = 2;
                    estado = JUEGO;
                    mundo.inicializa();  // o mundo.inicializaModo2();
                    return;
                }

                // Detectar Modo 3
                if (x_normal > -6 && x_normal < 6 && y_normal > 0 && y_normal < 3) {
                    modoSeleccionado = 3;
                    estado = JUEGO;
                    mundo.inicializa();  // o mundo.inicializaModo3();
                    return;
                }

                return;
            }
        }
    }

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
