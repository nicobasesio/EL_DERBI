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

		// Verifica que esté dentro del tablero
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
	int movx = std::abs(posicion_pieza.x - destino.x);
	int movy = std::abs(posicion_pieza.y - destino.y);

	
	if (!((movx == 4 && movy == 2) || (movx == 2 && movy == 4)))
	{
		std::cout << "\n[DEBUG] Movimiento invalido para el caballo\n" << std::endl;
		return false;
	}


	int x = static_cast<int>(round((destino.x + 7.0f) / 2.0f));
	int y = static_cast<int>(round((destino.y - 2.5f) / 2.0f));

	if (!casillaValida(x, y, control))
	{
		std::cout << "[DEBUG] Casilla destino fuera del tablero\n";
		return false;
	}

	// Comprobar si hay pieza enemiga
	Pieza* objetivo = control[x][y];
	capturo = false;

	if (objetivo != nullptr)
{
    capturo = true;
    haComidoPieza = true;
    std::cout << "[DEBUG] Caballo capturo una pieza\n";
}


	// Realizar el movimiento
	muevepieza(destino.x, destino.y);
	return true;
}


bool Caballo::puede_comer_enemigo(const VECTOR2D& origen,const VECTOR2D& destino,const std::vector<std::vector<Pieza*>>& control) {
	// 1) Convertir origen físico a índices de tablero
	int xi = static_cast<int>(std::round((origen.x + 7.0f) / 2.0f));
	int yi = static_cast<int>(std::round((origen.y - 2.5f) / 2.0f));

	// 2) Indices destino (ya en [0..7])
	int xf = static_cast<int>(std::round(destino.x));
	int yf = static_cast<int>(std::round(destino.y));

	// 3) Calcular desplazamientos relativos
	int dx = xf - xi;
	int dy = yf - yi;

	// 4) Movimientos válidos del caballo
	const int movesX[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };
	const int movesY[8] = { 2,  1, -1, -2, -2, -1,  1,  2 };

	bool esMovimientoValido = false;
	for (int k = 0; k < 8; ++k) {
		if (dx == movesX[k] && dy == movesY[k]) {
			esMovimientoValido = true;
			break;
		}
	}
	if (!esMovimientoValido) {
		return false;
	}

	// 5) En destino debe haber pieza enemiga
	Pieza* objetivo = control[xf][yf];
	return objetivo && objetivo->get_color() != this->color;
}

