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
	//fin del codigo incluido
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
