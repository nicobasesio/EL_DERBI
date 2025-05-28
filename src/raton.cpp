#include "raton.h"
#include "freeglut.h"
#include <iostream>
#include<mundo.h>

extern Mundo mundo;

VECTOR2D Raton::elige_casilla() {
    // Guardamos las anteriores solo si se encuentra una casilla válida
    VECTOR2D nueva_casilla = casilla;
    VECTOR2D nuevo_centro = posicion_centro_casilla;

    // COLUMNAS (x)
    if (posicion.x > -8 && posicion.x < -6) { nueva_casilla.x = 1.0; nuevo_centro.x = -7.0; }
    else if (posicion.x > -6 && posicion.x < -4) { nueva_casilla.x = 2.0; nuevo_centro.x = -5.0; }
    else if (posicion.x > -4 && posicion.x < -2) { nueva_casilla.x = 3.0; nuevo_centro.x = -3.0; }
    else if (posicion.x > -2 && posicion.x < 0) { nueva_casilla.x = 4.0; nuevo_centro.x = -1.0; }
    else if (posicion.x > 0 && posicion.x < 2) { nueva_casilla.x = 5.0; nuevo_centro.x = 1.0; }
    else if (posicion.x > 2 && posicion.x < 4) { nueva_casilla.x = 6.0; nuevo_centro.x = 3.0; }
    else if (posicion.x > 4 && posicion.x < 6) { nueva_casilla.x = 7.0; nuevo_centro.x = 5.0; }
    else if (posicion.x > 6 && posicion.x < 8) { nueva_casilla.x = 8.0; nuevo_centro.x = 7.0; }
    else { nueva_casilla.x = 0.0; }

    // FILAS (y)
    if (posicion.y > 15 && posicion.y < 17.5) { nueva_casilla.y = 8.0; nuevo_centro.y = 16.5; }
    else if (posicion.y > 13 && posicion.y < 15.5) { nueva_casilla.y = 7.0; nuevo_centro.y = 14.5; }
    else if (posicion.y > 11.5 && posicion.y < 13.5) { nueva_casilla.y = 6.0; nuevo_centro.y = 12.5; }
    else if (posicion.y > 9.5 && posicion.y < 11.5) { nueva_casilla.y = 5.0; nuevo_centro.y = 10.5; }
    else if (posicion.y > 7.5 && posicion.y < 9.5) { nueva_casilla.y = 4.0; nuevo_centro.y = 8.5; }
    else if (posicion.y > 5.5 && posicion.y < 7.5) { nueva_casilla.y = 3.0; nuevo_centro.y = 6.5; }
    else if (posicion.y > 4 && posicion.y < 5.5) { nueva_casilla.y = 2.0; nuevo_centro.y = 4.5; }
    else if (posicion.y > 2 && posicion.y < 4) { nueva_casilla.y = 1.0; nuevo_centro.y = 2.5; }
    else { nueva_casilla.y = 0.0; }

    // Si la casilla está fuera del tablero, no hacemos nada
    if (nueva_casilla.x == 0.0 || nueva_casilla.y == 0.0) {
        std::cout << "[DEBUG] Click fuera del tablero\n";
        return { 0.0, 0.0 };
    }

    // Solo si es una casilla válida se actualizan las referencias
    casilla_anterior = casilla;
    casilla = nueva_casilla;
    posicion_centro_casilla = nuevo_centro;

    // Dibujar casilla seleccionada (rojo)
    glColor3ub(220, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(posicion_centro_casilla.x - 1, posicion_centro_casilla.y - 1, 0.0f);
    glVertex3f(posicion_centro_casilla.x - 1, posicion_centro_casilla.y + 1, 0.0f);
    glVertex3f(posicion_centro_casilla.x + 1, posicion_centro_casilla.y + 1, 0.0f);
    glVertex3f(posicion_centro_casilla.x + 1, posicion_centro_casilla.y - 1, 0.0f);
    glEnd();

    return posicion_centro_casilla;
}
