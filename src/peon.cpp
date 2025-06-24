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

	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas al rededor del peon
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = peon_X + dx - 1;
			int y = peon_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {
					//std::cout << "Hay pieza comible para el rey en control[" << x << "," << y << "]\n";
					return true;
				}
			}
		}
	}
}


bool Peon::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {   // Para que no se salga del tamaño de la matriz control
	return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

bool Peon::puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
	int x = static_cast<int>(round((pos.x + 7.0f) / 2.0f));
	int y = static_cast<int>(round((pos.y - 2.5f) / 2.0f));

	int dx[] = { -1, 1 };
	int dy = (color ? 1 : -1);  // blanco sube, rojo baja

	for (int i = 0; i < 2; ++i) {
		int nx = x + dx[i];
		int ny = y + dy;

		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			Pieza* objetivo = control[nx][ny];
			if (objetivo != nullptr && objetivo->get_color() != color) {
				return true;
			}
		}
	}
	return false;
}
