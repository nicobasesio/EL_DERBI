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


bool Caballo::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) {
	// Movimientos posibles del caballo
	const int movimientos[8][2] = {
		{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
		{-2, -1}, {-1, -2}, {1, -2}, {2, -1}
	};

	for (int i = 0; i < 8; ++i) {
		int x = casilla_actual.x + movimientos[i][0];
		int y = casilla_actual.y + movimientos[i][1];

		// Verifica que est� dentro del tablero
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			if (control[x][y] != nullptr) {

				return true;
			}
		}
	}

	return false;
}

bool Caballo::mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo)
{
	int oi = static_cast<int>((posicion_pieza.x + 8.0) / 2.0);
	int oj = static_cast<int>((posicion_pieza.y - 1.0) / 2.0);
	int di = static_cast<int>((destino.x + 8.0) / 2.0);
	int dj = static_cast<int>((destino.y - 1.0) / 2.0);

	// 2) Verificar que destino est� dentro del tablero
	if (di < 0 || di >= 8 || dj < 0 || dj >= 8)
	{
		std::cout << "[DEBUG] Casilla destino fuera del tablero\n";
		return false;
	}
	int delta_i = std::abs(di - oi);
	int delta_j = std::abs(dj - oj);

	if (!((delta_i == 2 && delta_j == 1) || (delta_i == 1 && delta_j == 2)))
	{
		std::cout << "[DEBUG] Movimiento invalido para el caballo\n";
		return false;
	}
	capturo = false;
	Pieza* objetivo = control[di][dj];
	if (objetivo != nullptr)
	{
		if (objetivo->get_color() != color)
		{
			capturo = true;
			haComidoPieza = true;
			std::cout << "[DEBUG] Caballo capturo una pieza\n";
			
		}
		else
		{
			std::cout << "[DEBUG] No puedes capturar tu propia pieza\n";
			return false;
		}
	}

	control[oi][oj] = nullptr;
	control[di][dj] = this;

	muevepieza(destino.x, destino.y);

	return true;
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

