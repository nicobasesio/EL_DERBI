#include "alfil.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "mundo.h" 
#include "pieza.h"



void Alfil::muevepieza(double x, double y)
{
	posicion_pieza.x = x;
	posicion_pieza.y = y;
}

void Alfil::set_pos_pieza(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;
}

void Alfil::dibuja_pieza()
{
	glPushMatrix();
	glTranslated(posicion_pieza.x, posicion_pieza.y, 0.001);
	if (color == 0)
		sprite2.draw();			//rojas
	if (color == 1)
		sprite.draw();		// blancas
	glPopMatrix();
	glFlush();
}

void Alfil::set_color_pieza(bool a)
{
	if (a == TRUE)
		color = TRUE;
	if (a == FALSE)
		color = FALSE;
}

bool Alfil::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) { //Detecta si hay pieza que se puede comer el peon
	int alfil_X = casilla_actual.x - 2;
	int alfil_y = casilla_actual.y - 2;

	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas al rededor del peon
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = alfil_X + dx - 1;
			int y = alfil_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {
					//std::cout << "Hay pieza comible para el rey en control[" << x << "," << y << "]\n";
					return true;
				}
			}
		}
	}
}


bool Alfil::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {   // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
	return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

//para que no pueda saltar piezas
bool Alfil::rutaDiagonalLibre(int x1, int y1, int x2, int y2, const std::vector<std::vector<Pieza*>>& control) {
	int dx = (x2 > x1) ? 1 : -1;
	int dy = (y2 > y1) ? 1 : -1;

	x1 += dx;
	y1 += dy;

	while (x1 != x2 && y1 != y2) {
		std::cout << "[DEBUG] Evaluando (" << x1 << "," << y1 << ")...\n";

		if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8) {
			std::cout << "[ERROR] Coordenada fuera de tablero\n";
			return false;
		}

		if (control[x1][y1] != nullptr) {
			std::cout << "[BLOQUEADO] Hay una pieza en (" << x1 << "," << y1 << ")\n";
			return false;
		}

		x1 += dx;
		y1 += dy;
	}

	return true;
}

bool Alfil::puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
	int x = static_cast<int>(round((pos.x + 7.0f) / 2.0f));
	int y = static_cast<int>(round((pos.y - 2.5f) / 2.0f));

	// Cuatro diagonales
	int dx[] = { 1, 1, -1, -1 };
	int dy[] = { 1, -1, 1, -1 };

	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			Pieza* objetivo = control[nx][ny];
			if (objetivo != nullptr) {
				if (objetivo->get_color() != this->color) return true;
				else break; // bloqueado por pieza aliada
			}
			nx += dx[dir];
			ny += dy[dir];
		}
	}

	return false;
}
