#include "ETSIDI.h"
#include <iostream>
#include "mundo.h"
#include "raton.h"
#include<freeglut.h>
#include <string>
#include <random>
#include "tablero.h"

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

enum EstadoPantalla { MENU_START, MENU_MODOS, JUEGO, MENU_FINAL, MENU_INFO};
EstadoPantalla estado = MENU_START;
int modoSeleccionado = 0;
enum Turno { BLANCO, ROJO };
static bool pieza_seleccionada = false;




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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -5, 20);  
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

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
        float ancho_marcador = 6.0f;
        float alto_marcador = 2.0f;
        ETSIDI::setFont("fuente/OpenSans_Condensed-Bold.ttf", 22);
        char buffer1[20], buffer2[20];
        sprintf(buffer1, "%02d:%02d", tiempo_jugador1 / 60, tiempo_jugador1 % 60);
        sprintf(buffer2, "%02d:%02d", tiempo_jugador2 / 60, tiempo_jugador2 % 60);
        
        //temporizadores
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        ETSIDI::setTextColor(1, 1, 1);

        ETSIDI::printxy(buffer1, -13.5f, 16.7f);
        ETSIDI::printxy(buffer2, -13.5f, -1.0f);
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);

        


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
    if (estado == JUEGO && !fin_partida) {
        unsigned int tiempo_actual = glutGet(GLUT_ELAPSED_TIME);
        if (tiempo_actual - ultimo_tiempo_actualizado >= 1000) {
            if (mundo.get_turno() == BLANCO)
                tiempo_jugador1--;
            else
                tiempo_jugador2--;
            std::cout << "[DEBUG] Tiempo jugador 1: " << tiempo_jugador1 << std::endl;
            ultimo_tiempo_actualizado = tiempo_actual;

            // Comprobación por tiempo agotado
            if (tiempo_jugador1 <= 0 || tiempo_jugador2 <= 0) {
                fin_partida = true;
                jugador_que_pierde = (tiempo_jugador1 <= 0) ? 1 : 2;
                estado = MENU_FINAL;
                ETSIDI::stopMusica();
                ETSIDI::play("sonido/final.mp3");
            }

            // Si no se ha terminado por tiempo, comprobamos fichas
            if (!fin_partida) {
                int fichas_blancas = 0, fichas_rojas = 0;

                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (mundo.getControl()[i][j] != nullptr)
                        {
                            if (mundo.getControl()[i][j]->get_color()) 
                                fichas_blancas++;
                            else
                                fichas_rojas++;
                        }
                    }
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

bool es_pieza_con_captura(Pieza* pieza, const std::vector<std::pair<Pieza*, VECTOR2D>>& capturables) {
    for (const auto& par : capturables) {
        if (par.first == pieza) return true;
    }
    return false;
}

void mouseClick(int button, int state, int x, int y) {
    // 1) Convertir píxel → coordenadas de mundo
    float x_normal = ((x / 800.0f) * 30.0f) - 15.0f;
    float y_normal = ((600.0f - y) / 600.0f) * 25.0f - 5.0f;

    // 2) MENÚS
    if (estado == MENU_START && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x_normal > -10 && x_normal < 10 && y_normal > -5 && y_normal < 10) {
            estado = MENU_MODOS;
            glutPostRedisplay();
        }
        return;
    }
    if (estado == MENU_MODOS && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // modo1
        if (x_normal > -8 && x_normal < 8 && y_normal > 13 && y_normal < 15.5) {
            modoSeleccionado = 1; tiempo_jugador1 = tiempo_jugador2 = 60;
        }
        // modo2
        else if (x_normal > -8 && x_normal < 8 && y_normal > 8.5 && y_normal < 11) {
            modoSeleccionado = 2; tiempo_jugador1 = tiempo_jugador2 = 180;
        }
        // modo3
        else if (x_normal > -8 && x_normal < 8 && y_normal > 4 && y_normal < 6.5) {
            modoSeleccionado = 3; tiempo_jugador1 = tiempo_jugador2 = 300;
        }
        // info
        else if (x_normal > 11 && x_normal < 13.5 && y_normal > -2 && y_normal < 0.5) {
            estado = MENU_INFO;
            glutPostRedisplay();
            return;
        }
        else {
            return; // fuera de botones
        }
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

    // 3) JUEGO – sólo entramos si ya estamos en JUEGO
    if (estado != JUEGO || button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;
    // … tras comprobar estado==JUEGO y botón pulsado …

    auto capturables = mundo.piezas_con_captura();
    mundo.getTablero().limpiarResaltados();

    for (auto& par : capturables) {
        Pieza* atacante = par.first;
        VECTOR2D dest = par.second;

        // DEBUG: qué par estamos procesando
        std::cout
            << "[DEBUG] atacante en ("
            << atacante->get_pos().x << "," << atacante->get_pos().y
            << "), destino lógico = ("
            << dest.x << "," << dest.y << ")\n";

        // cálculo índices
        int col_at = int((atacante->get_pos().x - mundo.getTablero().coordenadas.x) / 2 + .5f);
        int fil_at = int((atacante->get_pos().y - mundo.getTablero().coordenadas.y) / 2 + .5f);
        int col_de = int((dest.x - mundo.getTablero().coordenadas.x) / 2 + .5f);
        int fil_de = int((dest.y - mundo.getTablero().coordenadas.y) / 2 + .5f);

        std::cout
            << "[DEBUG] índices → atacante("
            << col_at << "," << fil_at
            << "), destino("
            << col_de << "," << fil_de
            << ")\n";

        // resalto si están en rango
        if (col_at >= 0 && col_at < 8 && fil_at >= 0 && fil_at < 8)
            mundo.getTablero().agregarResaltado(col_at, fil_at);

        if (col_de >= 0 && col_de < 8 && fil_de >= 0 && fil_de < 8)
            mundo.getTablero().agregarResaltado(col_de, fil_de);
    }

    glutPostRedisplay();




    // 3.2) Calcular casilla clicada
    raton.posicion.x = x_normal;
    raton.posicion.y = y_normal;
    VECTOR2D centro = raton.elige_casilla();
    if (centro.x == 0.0f && centro.y == 0.0f) {
        std::cout << "[INFO] Click fuera del tablero\n";
        return;
    }
    int i = static_cast<int>(raton.casilla.x) - 1;
    int j = static_cast<int>(raton.casilla.y) - 1;
    if (!mundo.casillaValida(i, j)) {
        std::cout << "[INFO] Casilla vacía o inválida\n";
        return;
    }

    // 3.3) Primer clic: seleccionar pieza
    if (!pieza_seleccionada) {
        Pieza* p = mundo.getControl()[i][j];
        if (!p || p->get_color() != mundo.get_turno()) {
            std::cout << "[INFO] Selección inválida\n";
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

    // 3.4) Segundo clic: mover o capturar
    if (posicion_central_click.x == centro.x &&
        posicion_central_click.y == centro.y) {
        // deselecciona
        pieza_seleccionada = false;
        mundo.casilla_seleccionada = false;
        return;
    }
    // preparar para mover
    mundo.set_posicion_central_click(centro);
    mundo.set_posicion_central_click_anterior(posicion_central_click_anterior);
    mundo.set_casilla_actual(raton.casilla);
    mundo.set_casilla_anterior(raton.casilla_anterior);

    // si hay capturas forzosas, obligar a destino enemigo
    if (!capturables.empty()) {
        Pieza* dest = mundo.getControl()[i][j];
        if (!dest || dest->get_color() == mundo.get_turno()) {
            std::cout << "[INFO] Debes capturar una pieza enemiga\n";
            pieza_seleccionada = false;
            return;
        }
    }

    // ejecuta la jugada
   // … después de validar captura o movimiento …
    mundo.mueve();

    // **Aquí** eliminamos cualquier resaltado pendiente
    mundo.getTablero().limpiarResaltados();
    glutPostRedisplay();

    pieza_seleccionada = false;

}






