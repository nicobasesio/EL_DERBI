#include <stdio.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include "mundo.h" 
#include "pieza.h"
#include "peon.h"

void Peon::muevepieza(double x, double y)
{

	posicion_pieza.x = x;
	posicion_pieza.y = y;
}


void Peon::set_pos_pieza(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;

}

void Peon::dibuja_pieza()
{
	glPushMatrix();
	glTranslated(posicion_pieza.x, posicion_pieza.y, 0.001);
	if (color == 0)
		sprite2.draw();			//rojas
	if (color == 1)
		sprite.draw();		// blancas
	//fin del codigo incluido
	glPopMatrix();
	glFlush();
}
void Peon::set_color_pieza(bool a)
{
	if (a == true)
		color = true;
	if (a == false)
		color = false;
}

bool Peon::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) { //Detecta si hay pieza que se puede comer el peon
	int peon_X = casilla_actual.x - 2;
	int peon_y = casilla_actual.y - 2;

	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas alrededor del peon
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = peon_X + dx - 1;
			int y = peon_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {
					return true;
				}
			}
		}
	}
}


bool Peon::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {   // Para que no se salga del tamaño de la matriz control
	return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

bool Peon::mover(VECTOR2D destino,std::vector<std::vector<Pieza*>>& control, bool& capturo)
{
    // 1) Convertir posición gráfica a índices de casilla (0–7)
    int oi = static_cast<int>((posicion_pieza.x + 8.0f) / 2.0f);
    int oj = static_cast<int>((posicion_pieza.y - 1.0f) / 2.0f);
    int di = static_cast<int>((destino.x + 8.0f) / 2.0f);
    int dj = static_cast<int>((destino.y - 1.0f) / 2.0f);

    // 2) Verificar que destino esté dentro del tablero
    if (di < 0 || di >= 8 || dj < 0 || dj >= 8)
        return false;

    // 3) Diferencias en casillas
    int delta_i = di - oi;   // columnas
    int delta_j = dj - oj;   // filas
    int movx = std::abs(delta_i);
    float movy = std::abs(delta_j);

    // 4) Dirección y fila inicial según color
    bool esBlanco = get_color();
    int  dir = esBlanco ? +1 : -1;
    int  startRow = esBlanco ? 1 : 6;

    // 5) Avance vertical (sin captura)
    // — un paso
    if (movx == 0 && delta_j == dir && control[di][dj] == nullptr) {
        capturo = false;
        muevepieza(destino.x, destino.y);
        return true;
    }
    // — dos pasos en la primera jugada
    if (movx == 0 && delta_j == 2 * dir && oj == startRow) {
        int jm = oj + dir; // casilla intermedia
        if (control[di][jm] == nullptr && control[di][dj] == nullptr) {
            capturo = false;
            muevepieza(destino.x, destino.y);
            return true;
        }
        else {
            return false;
        }
    }

    // 6) Captura diagonal (ahora permite comer pieza propia o enemiga)
    if (movx == 1 && delta_j == dir) {
        Pieza* objetivo = control[di][dj];
        if (objetivo != nullptr) {
            // capturamos aunque la pieza sea del mismo color
            capturo = true;
            muevepieza(destino.x, destino.y);
            return true;
        }
    }

    // 7) Ningún caso válido
    return false;
}


bool Peon::puede_comer_enemigo(const VECTOR2D& origen, const VECTOR2D& destino, const std::vector<std::vector<Pieza*>>& control) {
    // Paso 1: convertir la posición física del peón a índices de tablero
    int xi = static_cast<int>(std::round((origen.x + 7.0f) / 2.0f));
    int yi = static_cast<int>(std::round((origen.y - 2.5f) / 2.0f));

    // Paso 2: extraer índices de destino (ya vienen en coordenadas [0..7])
    int xf = static_cast<int>(std::round(destino.x));
    int yf = static_cast<int>(std::round(destino.y));

    // Sólo nos importan las dos diagonales inmediatas
    int dx = xf - xi;
    int dy = yf - yi;
    int sentido = (color ? +1 : -1);  // blanco sube, rojo baja

    // Comprobar desplazamiento diagonal de 1 casilla en la dirección adecuada
    if (std::abs(dx) == 1 && dy == sentido) {
        Pieza* objetivo = control[xf][yf];
        if (objetivo && objetivo->get_color() != color) {
            return true;
        }
    }
    return false;
}
