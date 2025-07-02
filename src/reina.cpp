#include "reina.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "mundo.h" 
#include "pieza.h"

void Reina::muevepieza(double x, double y)
{
	posicion_pieza.x = x;
	posicion_pieza.y = y;
}


bool Reina::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else
		return false;

}



void Reina::set_pos_pieza(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;
}


void Reina::dibuja_pieza()
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

void Reina::set_color_pieza(bool a)
{
	if (a == true)
		color = true;
	if (a == false)
		color = false;
}


bool Reina::caminoLibre(VECTOR2D origen, VECTOR2D destino, const std::vector<std::vector<Pieza*>>& control) {
	int x1 = static_cast<int>((origen.x + 8.0) / 2.0);
	int y1 = static_cast<int>((origen.y - 1.0) / 2.0);
	int x2 = static_cast<int>((destino.x + 8.0) / 2.0);
	int y2 = static_cast<int>((destino.y - 1.0) / 2.0);

	int dx = (x2 > x1) ? 1 : (x2 < x1 ? -1 : 0);
	int dy = (y2 > y1) ? 1 : (y2 < y1 ? -1 : 0);

	x1 += dx;
	y1 += dy;

	while (x1 != x2 || y1 != y2) {
		if (!casillaValida(x1, y1, control)) return false;
		if (control[x1][y1] != nullptr) return false;
		x1 += dx;
		y1 += dy;
	}

	return true;
}



bool Reina::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) {
	int reina_x = casilla_actual.x - 2;
	int reina_y = casilla_actual.y - 2;
	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas alrededor de la reina
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = reina_x + dx - 1;
			int y = reina_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {

					return true;
				}
			}
		}
	}
}


bool Reina::mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo) {
	// Cálculo del desplazamiento en cada eje
	int dx = static_cast<int>(destino.x - posicion_pieza.x);
	int dy = static_cast<int>(destino.y - posicion_pieza.y);
	int abs_dx = std::abs(dx);
	int abs_dy = std::abs(dy);

	// Sólo permitimos movimientos rectos o diagonales
	if ((dx == 0 || dy == 0 || abs_dx == abs_dy) &&
		caminoLibre(get_pos(), destino, control))
	{
		// Convertimos coordenadas de mundo a índices de matriz
		int i = static_cast<int>((destino.x + 8.0) / 2.0);
		int j = static_cast<int>((destino.y - 1.0) / 2.0);

		// Verificamos que la casilla esté dentro del tablero
		if (i >= 0 && i < 8 && j >= 0 && j < 8) {
			// Si hay pieza enemiga, marcamos captura
			if (control[i][j] != nullptr) {
				capturo = true;
			}
			// Movemos la reina
			muevepieza(destino.x, destino.y);
			return true;
		}
	}

	
	return false;
}



bool Reina::puede_comer_enemigo(const VECTOR2D& origen,const VECTOR2D& destino,const std::vector<std::vector<Pieza*>>& control) {
	// 1) Convertir origen físico a índices de tablero
	int xi = static_cast<int>(std::round((origen.x + 7.0f) / 2.0f));
	int yi = static_cast<int>(std::round((origen.y - 2.5f) / 2.0f));

	// 2) Índices destino (ya en [0..7])
	int xf = static_cast<int>(std::round(destino.x));
	int yf = static_cast<int>(std::round(destino.y));

	// 3) Cálculo de desplazamiento
	int dx = xf - xi;
	int dy = yf - yi;

	// 4) Comprobar que está en línea recta (fila o columna) o diagonal
	if (dx != 0 && dy != 0 && std::abs(dx) != std::abs(dy)) {
		return false;
	}

	// 5) Determinar paso unitario
	int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
	int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

	// 6) Recorrer camino desde la casilla siguiente hasta la anterior a destino
	for (int x = xi + stepX, y = yi + stepY;
		x != xf || y != yf;
		x += stepX, y += stepY) {
		if (control[x][y] != nullptr) {
			return false; // bloqueado
		}
	}

	// 7) En destino debe haber pieza enemiga
	Pieza* objetivo = control[xf][yf];
	return objetivo && objetivo->get_color() != this->color;
}