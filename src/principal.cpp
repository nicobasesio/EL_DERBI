#include "ETSIDI.h"
#include <iostream>
#include "mundo.h"
#include "raton.h"
#include <freeglut.h>
#include <string>
#include <random>
#include "tablero.h"
#include "VECTOR2D.h"
#include "efectos.h"

int windowWidth = 800;
int windowHeight = 600;
const float worldLeft = -15.0f;
const float worldRight = 15.0f;
const float worldBottom = -5.0f;
const float worldTop = 20.0f;
const std::string TITULO      = "ETSIDI";
int               letrasMostradas = 0;
float             tiempoAcumulado = 0.0f;
const float       INTERVALO       = 0.3f;  // segundos entre cada letra
using namespace std;

Mundo mundo;
Raton raton;
Tablero tablero;
VECTOR2D posicion_central_click{};
VECTOR2D posicion_central_click_anterior{};

int tiempo_jugador1; // en segundos
int tiempo_jugador2;
bool fin_partida = false;
unsigned int ultimo_tiempo_actualizado = 0;
int jugador_que_pierde = 0;
bool leyenda_visible = false;
bool guia_visible = false;
const int UMBRAL_TENSION = 20;
bool tension_activa = false;

enum EstadoPantalla { MENU_START, MENU_MODOS, JUEGO, MENU_FINAL, MENU_INFO };
EstadoPantalla estado = MENU_START;
int modoSeleccionado = 0;
enum Turno { BLANCO, ROJO };
static bool pieza_seleccionada = false;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x_t, int y_t);
void mouseClick(int button, int state, int x, int y);
void display();

std::string imagen_arbitro = "imagenes/arbitroamarillo.png";
unsigned int tiempo_cambio_arbitro = 0;


EfectoEspecial efectoEspecial;

void OnResize(int w, int h) {
    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(worldLeft, worldRight, worldBottom, worldTop);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("MiJuego");
    glutReshapeFunc(OnResize);
    OnResize(windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -5, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(OnDraw);
    glutTimerFunc(33, OnTimer, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutMouseFunc(mouseClick);

    mundo.inicializa();
    ETSIDI::playMusica("sonido/musica.mp3", true);
    mundo.inicializa_tab();

    glutMainLoop();
    return 0;
}

void dibujarArbitro() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(imagen_arbitro.c_str()).id);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHTING);
    glColor4f(1, 1, 1, 1);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3d(9, 5, 0.01);
    glTexCoord2d(1, 1); glVertex3d(13, 5, 0.01);
    glTexCoord2d(1, 0); glVertex3d(13, 12, 0.01);
    glTexCoord2d(0, 0); glVertex3d(9, 12, 0.01);
    glEnd();
    glDisable(GL_ALPHA_TEST);
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void OnDraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (estado == MENU_START) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu1.png").id);
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

    if (estado == MENU_MODOS) {
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

    if (estado == JUEGO) {
        mundo.dibuja();

        // Mostrar efecto especial (balón o bonus)
        if (efectoEspecial.activo)
            efectoEspecial.dibuja();

        ETSIDI::setFont("fuente/OpenSans_Condensed-Bold.ttf", 22);
        char buffer1[20], buffer2[20];
        sprintf(buffer1, "%02d:%02d", tiempo_jugador1 / 60, tiempo_jugador1 % 60);
        sprintf(buffer2, "%02d:%02d", tiempo_jugador2 / 60, tiempo_jugador2 % 60);

        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        ETSIDI::setTextColor(255, 255,255);
        ETSIDI::printxy(buffer1, -13.5f, 16.7f);
        ETSIDI::printxy(buffer2, -13.5f, -1.0f);
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);

        dibujarArbitro();
        ETSIDI::setTextColor(255, 255, 255);
        float x0 = -5.0f,y0 = 18.0f, esp = 2.0f;
        for (int i = 0; i < letrasMostradas; ++i) {
            std::string letra = TITULO.substr(i, 1);
            ETSIDI::printxy(letra.c_str(), x0 + i * esp, y0);
        }

        if (guia_visible) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/guia.png").id);
            glDisable(GL_LIGHTING);
            glColor4f(1, 1, 1, 1.0f);
            glBegin(GL_POLYGON);
            glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.1);
            glTexCoord2d(1, 1); glVertex3d(14, -3, 0.1);
            glTexCoord2d(1, 0); glVertex3d(14, 18, 0.1);
            glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.1);
            glEnd();
            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }

        if (leyenda_visible) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/leyenda.png").id);
            glDisable(GL_LIGHTING);
            glColor4f(1, 1, 1, 1.0f);
            glBegin(GL_POLYGON);
            glTexCoord2d(0, 1); glVertex3d(-14, -3, 0.11);
            glTexCoord2d(1, 1); glVertex3d(14, -3, 0.11);
            glTexCoord2d(1, 0); glVertex3d(14, 18, 0.11);
            glTexCoord2d(0, 0); glVertex3d(-14, 18, 0.11);
            glEnd();
            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
    }

    if (estado == MENU_INFO) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu3.png").id);
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

    if (estado == MENU_FINAL) {
        std::string imagen_final = (jugador_que_pierde == 1) ? "imagenes/madridgana.png" : "imagenes/atleticogana.png";
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

    const float dt = 33.0f / 1000.0f;              // intervalos de ~33 ms
    tiempoAcumulado += dt;
    if (tiempoAcumulado >= INTERVALO && letrasMostradas < (int)TITULO.size()) {
        letrasMostradas++;
        tiempoAcumulado = 0.0f;
    }
    if (estado == JUEGO && !fin_partida) {
        unsigned int tiempo_actual = glutGet(GLUT_ELAPSED_TIME);
        if (tiempo_actual - ultimo_tiempo_actualizado >= 1000) {
            if (mundo.get_turno() == BLANCO)
                tiempo_jugador1--;
            else
                tiempo_jugador2--;

            std::cout << "[DEBUG] Tiempo jugador 1: " << tiempo_jugador1 << std::endl;
            ultimo_tiempo_actualizado = tiempo_actual;

            bool queda_1_10 = (tiempo_jugador1 > 0 && tiempo_jugador1 <= UMBRAL_TENSION) ||
                (tiempo_jugador2 > 0 && tiempo_jugador2 <= UMBRAL_TENSION);

            if (queda_1_10 && !tension_activa) {
                tension_activa = true;
                ETSIDI::stopMusica();
                ETSIDI::playMusica("sonido/tension.mp3", true);
            }

            if ((tiempo_jugador1 <= 0 || tiempo_jugador2 <= 0) && tension_activa) {
                fin_partida = true;
                jugador_que_pierde = (tiempo_jugador1 <= 0) ? 1 : 2;
                estado = MENU_FINAL;
                ETSIDI::stopMusica();
                tension_activa = false;
                ETSIDI::play("sonido/final.mp3");
            }

            if (!fin_partida) {
                int fichas_blancas = 0, fichas_rojas = 0;
                for (int i = 0; i < 8; ++i)
                    for (int j = 0; j < 8; ++j)
                        if (mundo.getControl()[i][j] != nullptr) {
                            if (mundo.getControl()[i][j]->get_color())
                                fichas_blancas++;
                            else
                                fichas_rojas++;
                        }

                if (fichas_blancas == 0) {
                    jugador_que_pierde = 2;
                    fin_partida = true;
                    estado = MENU_FINAL;
                    ETSIDI::stopMusica();
                    ETSIDI::play("sonido/final.mp3");
                }
                else if (fichas_rojas == 0) {
                    jugador_que_pierde = 1;
                    fin_partida = true;
                    estado = MENU_FINAL;
                    ETSIDI::stopMusica();
                    ETSIDI::play("sonido/final.mp3");
                }
            }
           
            

        }
    }
    if (!imagen_arbitro.empty() && imagen_arbitro != "imagenes/arbitro.png") {
        unsigned int ahora = glutGet(GLUT_ELAPSED_TIME);
        if (ahora - tiempo_cambio_arbitro >= 2000) { 
            imagen_arbitro = "imagenes/arbitro.png";
        }
    }
    if (efectoEspecial.activo)
        efectoEspecial.mueve();

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
    else if (estado == JUEGO) {
        if (key == 'g' || key == 'G') {
            guia_visible = !guia_visible;
            glutPostRedisplay();
        }
        if (key == 'l' || key == 'L') {
            leyenda_visible = !leyenda_visible;
            glutPostRedisplay();
        }
    }
}



void mouseClick(int button, int state, int x, int y) {
    float x_normal = worldLeft + (float)x / windowWidth * (worldRight - worldLeft);
    float y_normal = worldBottom + (float)(windowHeight - y) / windowHeight * (worldTop - worldBottom);


    if (estado == MENU_START && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x_normal > -10 && x_normal < 10 && y_normal > -5 && y_normal < 10) {
            estado = MENU_MODOS;
            glutPostRedisplay();
        }
        return;
    }

    if (estado == MENU_MODOS && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x_normal > -8 && x_normal < 8 && y_normal > 13 && y_normal < 15.5)
            modoSeleccionado = 1, tiempo_jugador1 = tiempo_jugador2 = 60;
        else if (x_normal > -8 && x_normal < 8 && y_normal > 8.5 && y_normal < 11)
            modoSeleccionado = 2, tiempo_jugador1 = tiempo_jugador2 = 180;
        else if (x_normal > -8 && x_normal < 8 && y_normal > 4 && y_normal < 6.5)
            modoSeleccionado = 3, tiempo_jugador1 = tiempo_jugador2 = 300;
        else if (x_normal > 11 && x_normal < 13.5 && y_normal > -2 && y_normal < 0.5) {
            estado = MENU_INFO;
            glutPostRedisplay();
            return;
        }
        else return;

        ETSIDI::stopMusica();
        estado = JUEGO;
        mundo.inicializa();
        glutPostRedisplay();
        return;
    }

    if (estado == MENU_INFO && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x_normal > -14 && x_normal < -11.5 && y_normal > 16 && y_normal < 18.5) {
            estado = MENU_MODOS;
            glutPostRedisplay();
        }
        return;
    }

    if (estado != JUEGO || button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    auto capturables = mundo.piezas_con_captura();
    mundo.getTablero().limpiarResaltados();

    for (auto& par : capturables) {
        Pieza* atacante = par.first;
        VECTOR2D dest = par.second;

        int col_at = int((atacante->get_pos().x - mundo.getTablero().coordenadas.x) / 2 + .5f);
        int fil_at = int((atacante->get_pos().y - mundo.getTablero().coordenadas.y) / 2 + .5f);
        int col_de = static_cast<int>(dest.x);
        int fil_de = static_cast<int>(dest.y);


        if (col_at >= 0 && col_at < 8 && fil_at >= 0 && fil_at < 8)
            mundo.getTablero().agregarResaltado(col_at, fil_at);

        if (col_de >= 0 && col_de < 8 && fil_de >= 0 && fil_de < 8)
            mundo.getTablero().agregarResaltado(col_de, fil_de);
    }

    glutPostRedisplay();

    raton.posicion.x = x_normal;
    raton.posicion.y = y_normal;
    VECTOR2D centro = raton.elige_casilla();
    if (centro.x == 0.0f && centro.y == 0.0f) return;

    int i = static_cast<int>(raton.casilla.x) - 1;
    int j = static_cast<int>(raton.casilla.y) - 1;
    if (!mundo.casillaValida(i, j))
    {
        imagen_arbitro = "imagenes/arbitroamarillo.png";
        tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
        ETSIDI::play("sonido/pitido.mp3");
        return;
    }

    if (!pieza_seleccionada) {
        Pieza* p = mundo.getControl()[i][j];
        if (!p || p->get_color() != mundo.get_turno())
        {
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
            return;
        }

        posicion_central_click = centro;
        posicion_central_click_anterior = centro;
        mundo.set_posicion_central_click(centro);
        mundo.set_posicion_central_click_anterior(centro);
        mundo.casilla_seleccionada = true;
        pieza_seleccionada = true;
        return;
    }

    if (posicion_central_click.x == centro.x && posicion_central_click.y == centro.y) {
        pieza_seleccionada = false;
        mundo.casilla_seleccionada = false;
        return;
    }

    mundo.set_posicion_central_click(centro);
    mundo.set_posicion_central_click_anterior(posicion_central_click_anterior);
    mundo.set_casilla_actual(raton.casilla);
    mundo.set_casilla_anterior(raton.casilla_anterior);

    if (!capturables.empty()) {
        Pieza* dest = mundo.getControl()[i][j];
        if (!dest || dest->get_color() == mundo.get_turno()) {
            pieza_seleccionada = false;
            return;
        }
    }

    mundo.mueve();
    mundo.getTablero().limpiarResaltados();
    glutPostRedisplay();
    pieza_seleccionada = false;
}

