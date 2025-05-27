#include "rey.h"

void Rey::dibuja()
{
	glPushMatrix();
	glTranslated(posicion_pieza.x, posicion_pieza.y, 0.001);
	if (color == 0)
		sprite2.draw();			//negras
	if (color == 1)
		sprite.draw();		// blancas
	//fin del codigo incluido
	glPopMatrix();
	glFlush();
}

void Rey::set_color(bool a)
{
	if (a == true)
		color = true;
	if (a == false)
		color = false;
}

void Rey::set_pos(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;
}

void Rey::muevepieza(double x, double y)
{
	
	posicion_pieza.x = x;
	posicion_pieza.y = y;
}

bool Rey::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) { //Detecta si hay pieza que se puede comer el rey
	int rey_x = casilla_actual.x - 2;
	int rey_y = casilla_actual.y - 2;

	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas al rededor del rey
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = rey_x + dx - 1;
			int y = rey_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {
					//std::cout << "Hay pieza comible para el rey en control[" << x << "," << y << "]\n";
					return true;
				}
			}
		}
	}
}

