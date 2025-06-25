#include "rey.h"
#include <iostream>

void Rey::dibuja()
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

void Rey::set_color(bool a)
{
	if (a == true)
		color = true;
	if (a == false)
		color = false;
}

void Rey::set_pos(const VECTOR2D& pos)
{
	posicion_pieza = pos;
}


void Rey::muevepieza(double x, double y)
{
	std::cout << "[REY] Moviendo a (" << x << "," << y << ")\n";
	posicion_pieza.x = x;
	posicion_pieza.y = y;
}

bool Rey::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) {
	int rey_x = casilla_actual.x - 2;
	int rey_y = casilla_actual.y - 2;

	for (int dx = 0; dx < 3; ++dx) {
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) continue;
			int x = rey_x + dx - 1;
			int y = rey_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				if (control[x][y] != nullptr) {
					return true;
				}
			}
		}
	}
	return false;  
}



bool Rey::puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
	int i = static_cast<int>(round((pos.x + 7.0f) / 2.0f));
	int j = static_cast<int>(round((pos.y - 2.5f) / 2.0f));

	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0) continue;
			int ni = i + dx;
			int nj = j + dy;
			if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
				Pieza* p = control[ni][nj];
				if (p != nullptr && p->get_color() != this->color) {
					std::cout << "[DEBUG] " << (color ? "Rey blanco" : "Rey rojo")
						<< " ve enemigo en (" << ni << "," << nj << ")\n";
					return true;
				}
			}
		}
	}
	return false;
}







