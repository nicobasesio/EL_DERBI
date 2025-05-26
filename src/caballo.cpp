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
std::vector<VECTOR2D> Caballo:: get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos) {
	std::vector<VECTOR2D> a; 
	return a;
}