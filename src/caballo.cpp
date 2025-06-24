#include "caballo.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "mundo.h"
#include "pieza.h"


void Caballo::muevepieza(double x, double y)
{
	posicion_pieza.x = x;
	posicion_pieza.y = y;


}

bool Caballo::piezaAhogada(std::vector<VECTOR2D> posiciones)
{
	if (posiciones.size() == 0)
		return true;
	else
		return false;
}

bool Caballo::casillaValida(int i, int j, std::vector<std::vector<Pieza*>>control)
{
	return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

void Caballo::set_pos_pieza(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;
}

void Caballo::dibuja_pieza()
{
	glPushMatrix();
	glTranslated(posicion_pieza.x, posicion_pieza.y, 0.001);
	if (color == 0)
		sprite2.draw();
	if (color == 1)
		sprite.draw();

	glPopMatrix();
	glFlush();
}

void Caballo::set_color_pieza(bool a)
{
	if (a == TRUE)
		color = TRUE;
	if (a == FALSE)
		color = FALSE;
}

std::vector<VECTOR2D> Caballo::get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos)
{
	std::vector<VECTOR2D> posiciones;

	// Todos los movimientos posibles del caballo en forma de L
	int movimientos[8][2] = {
		{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
		{-2, -1}, {-1, -2}, {1, -2}, {2, -1}
	};

	for (int i = 0; i < 8; ++i)
	{
		int x = pos.x - 1 + movimientos[i][0];
		int y = pos.y - 1 + movimientos[i][1];

		if (casillaValida(x, y, control))
		{
			// Permitir moverse a cualquier casilla, incluso si hay pieza del mismo color
			posiciones.push_back({ static_cast<double>(x + 1), static_cast<double>(y + 1) });
		}
	}

	return posiciones;
}



bool Caballo::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) {
	// Movimientos posibles del caballo
	const int movimientos[8][2] = {
		{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
		{-2, -1}, {-1, -2}, {1, -2}, {2, -1}
	};

	for (int i = 0; i < 8; ++i) {
		int x = casilla_actual.x + movimientos[i][0];
		int y = casilla_actual.y + movimientos[i][1];

		
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			if (control[x][y] != nullptr) {
				
				return true;
			}
		}
	}

	return false;
}

bool Caballo::puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
	int x = static_cast<int>(round((pos.x + 7.0f) / 2.0f));
	int y = static_cast<int>(round((pos.y - 2.5f) / 2.0f));

	int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			Pieza* objetivo = control[nx][ny];
			if (objetivo != nullptr && objetivo->get_color() != color) {
				return true;
			}
		}
	}
	return false;
}