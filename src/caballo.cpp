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
	std::vector<VECTOR2D> posiciones; //posiciones de control de las piezas negras
	for (int i = 1; i < control.size(); i++)
	{
		if (casillaValida(pos.x + i, pos.y, control)) //no se salga de la matriz
		{
			if (control[pos.x + i][pos.y] == nullptr) //recorre la fila en horizontal
			{
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y) }); //posiciones donde el caballo puede moverse
			}
			else if (control[pos.x + i][pos.y] != nullptr && control[pos.x + i][pos.y]->get_color() == false) //detecta pipeza negra
			{
				break;
			}
		}
	}
	for (int i = 1; i < control.size(); i++)
	{
		if (casillaValida(pos.x - i, pos.y, control))
		{
			if (control[pos.x - i][pos.y] == nullptr)
			{
				posiciones.push_back({ static_cast<double> (pos.x - i), static_cast <double> (pos.y) }); //posiciones donde el caballo puede moverse
			}
			else if (control[pos.x - i][pos.y] != nullptr && control[pos.x - i][pos.y]->get_color() == true) 
			{
				posiciones.push_back({ static_cast<double> (pos.x - i), static_cast<double> (pos.y) });
				break;
			}
		}
	}
	return posiciones;
}

