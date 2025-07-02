#include "rey.h"
#include <iostream>
#include "ETSIDI.h"
#include "efectos.h"

extern int tiempo_jugador1;
extern int tiempo_jugador2;
extern EfectoEspecial efectoEspecial;

void Rey::dibuja() {
    glPushMatrix();
    glTranslated(posicion_pieza.x, posicion_pieza.y, 0.001);
    if (tipo == "balon") {
        ETSIDI::Sprite balon("imagenes/balon.png", 1.0f);
        balon.setCenter(0.75f, 0.75f);
        balon.setPos(posicion_pieza.x, posicion_pieza.y);
        balon.draw();
    }
    else {
        if (color == 0) sprite2.draw(); // rojas
        else            sprite.draw();  // blancas
    }
    glPopMatrix();
    glFlush();
}

void Rey::set_color(bool a) { color = a; }
void Rey::set_pos(const VECTOR2D& pos) { posicion_pieza = pos; }
void Rey::setTipo(const std::string& t) { tipo = t; }

void Rey::muevepieza(double x, double y) {
    std::cout << "[REY] Moviendo a (" << x << "," << y << ")\n";
    posicion_pieza.x = x;
    posicion_pieza.y = y;
}

bool Rey::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) {
    int rey_x = casilla_actual.x - 2;
    int rey_y = casilla_actual.y - 2;
    for (int dx = 0; dx < 3; ++dx) {
        for (int dy = 0; dy < 3; ++dy) {
            if (dx == 1 && dy == 1) continue;
            int x = rey_x + dx - 1;
            int y = rey_y + dy - 1;
            if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (control[x][y] != nullptr) return true;
            }
        }
    }
    return false;
}

bool Rey::puede_comer_enemigo(const VECTOR2D& origen,
    const VECTOR2D& destino,
    const std::vector<std::vector<Pieza*>>& control) {
    // 1) Índices del rey (origen físico → [0..7])
    int i = static_cast<int>(std::round((origen.x + 7.0f) / 2.0f));
    int j = static_cast<int>(std::round((origen.y - 2.5f) / 2.0f));

    // 2) Ídem para destino
    int xf = static_cast<int>(std::round(destino.x));
    int yf = static_cast<int>(std::round(destino.y));

    // 3) Solo vecinas (±1 en x/y, sin (0,0))
    int dx = xf - i;
    int dy = yf - j;
    if ((std::abs(dx) > 1 || std::abs(dy) > 1) || (dx == 0 && dy == 0))
        return false;

    // 4) Comprobación y debug
    Pieza* p = control[xf][yf];
    if (p && p->get_color() != this->color) {
        std::cout << "[DEBUG] "
            << (color ? "Rey blanco" : "Rey rojo")
            << " ve enemigo en (" << xf << "," << yf << ")\n";
        return true;
    }
    return false;
}

bool Rey::mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo) {
    int movx = std::abs(posicion_pieza.x - destino.x);
    int movy = std::abs(posicion_pieza.y - destino.y);

    if (movx <= 2 && movy <= 2 && !(movx == 0 && movy == 0)) {
        int i = static_cast<int>((destino.x + 8.0) / 2.0);
        int j = static_cast<int>((destino.y - 1.0) / 2.0);

        if (i >= 0 && i < 8 && j >= 0 && j < 8) {
            Pieza* objetivo = control[i][j];

            if (objetivo != nullptr) {
                capturo = true;

                // Si come a enemigo → efecto especial
                if (objetivo->get_color() != this->color) {
                    objetivo->setTipo("balon");

                    efectoEspecial.activo = true;
                    efectoEspecial.tipo = "balon";
                    efectoEspecial.escala = 2.0f;
                    efectoEspecial.posicion = { -20.0f, 8.0f };
                    efectoEspecial.destino = { 20.0f, 8.0f };
                    efectoEspecial.tiempoRestante = 2.0f;
                    efectoEspecial.rotacion = 0.0f;
                    ETSIDI::play("sonido/bonus.wav");

                    if (color == true) tiempo_jugador2 += 10;
                    else               tiempo_jugador1 += 10;
                }

            }

            muevepieza(destino.x, destino.y);
            return true;
        }
    }

    return false;
}


void Rey::dibuja_pieza() { dibuja(); }

