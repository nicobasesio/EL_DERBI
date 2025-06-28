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

bool Alfil::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) { 
	int alfil_X = casilla_actual.x - 2;
	int alfil_y = casilla_actual.y - 2;

	for (int dx = 0; dx < 3; ++dx) {  
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = alfil_X + dx - 1;
			int y = alfil_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  
				if (control[x][y] != nullptr) {
					return true;
				}
			}
		}
	}
}


bool Alfil::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {  
	return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

bool Alfil::mover(VECTOR2D destino,std::vector<std::vector<Pieza*>>& control,bool& capturo)
{
	// 1) Convertir posición gráfica a índices de casilla (0–7)
	int oi = static_cast<int>((posicion_pieza.x + 8.0) / 2.0);
	int oj = static_cast<int>((posicion_pieza.y - 1.0) / 2.0);
	int di = static_cast<int>((destino.x + 8.0) / 2.0);
	int dj = static_cast<int>((destino.y - 1.0) / 2.0);

	// 2) Verificar que destino esté dentro del tablero
	if (di < 0 || di >= 8 || dj < 0 || dj >= 8)
		return false;

	// 3) Calcular desplazamiento en casillas
	int delta_i = di - oi;
	int delta_j = dj - oj;
	int movx = std::abs(delta_i);
	int movy = std::abs(delta_j);

	// 4) Sólo movimiento estrictamente diagonal y no quedarse en la misma casilla
	if (movx == movy && movx > 0) {
		int paso_i = (delta_i > 0 ? +1 : -1);
		int paso_j = (delta_j > 0 ? +1 : -1);

		// 5) Comprobar que no haya piezas intermedias bloqueando la diagonal
		for (int k = 1; k < movx; ++k) {
			int ii = oi + paso_i * k;
			int jj = oj + paso_j * k;
			if (control[ii][jj] != nullptr)
				return false;
		}

		// 6) Marcar captura si en destino hay una pieza enemiga
		if (control[di][dj] != nullptr)
			capturo = true;

		// 7) Mover gráficamente la pieza
		muevepieza(destino.x, destino.y);
		return true;
	}

	// No es un movimiento diagonal válido
	return false;
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
