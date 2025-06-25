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
	//fin del codigo incluido
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

bool Reina::puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
	int x = static_cast<int>(round((pos.x + 7.0f) / 2.0f));
	int y = static_cast<int>(round((pos.y - 2.5f) / 2.0f));

	// Ocho direcciones: líneas + diagonales
	int dx[] = { 1, 1, -1, -1, 0, 0, -1, 1 };
	int dy[] = { 1, -1, 1, -1, -1, 1, 0, 0 };

	for (int dir = 0; dir < 8; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			Pieza* objetivo = control[nx][ny];
			if (objetivo != nullptr) {
				if (objetivo->get_color() != this->color) return true;
				else break;
			}
			nx += dx[dir];
			ny += dy[dir];
		}
	}

	return false;
}