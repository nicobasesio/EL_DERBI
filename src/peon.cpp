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

bool Peon::piezaAhogada(std::vector<VECTOR2D> posiciones)
{
	if (posiciones.size() == 0)
		return true;
	else
		return false;
}

bool Peon::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {   // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
	return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

std::vector<VECTOR2D> Peon::get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos) { // pos es la casilla que ocupa la torre en nuestra matriz de control
	haComidoPieza = false; // por defecto no come pieza. En caso de que tenga la posibilidad de hacerlo, su valor cambiará a true
	std::vector<VECTOR2D> posiciones; // se almacenan las posiciones de control de todas las piezas de color negro
	//un peon negro solo puede ir hacia abajo
	if (casillaValida(pos.x, pos.y - 1, control)) { // se comprueba que no se salga del rango de la matriz
		if (control[pos.x][pos.y - 1] == nullptr) {
			posiciones.push_back({ static_cast<double>(pos.x), static_cast<double>(pos.y - 1) }); // se añade al vector las posiciones donde la torre puede moverse
			//haComidoPieza = false;
		}
	}
	if (casillaValida(pos.x + 1, pos.y - 1, control)) { // se comprueba que no se salga del rango de la matriz
		if (control[pos.x + 1][pos.y - 1] != nullptr && control[pos.x + 1][pos.y - 1]->get_color() == true) { //come hacia abajo derecha una pieza blanca
			posiciones.push_back({ static_cast<double>(pos.x + 1), static_cast<double>(pos.y - 1) }); // se añade al vector las posiciones donde la torre puede moverse
			haComidoPieza = true;
		}
	}
	if (casillaValida(pos.x - 1, pos.y - 1, control)) { // se comprueba que no se salga del rango de la matriz
		if (control[pos.x - 1][pos.y - 1] != nullptr && control[pos.x - 1][pos.y - 1]->get_color() == true) { //come hacia abajo izda una pieza blanca
			posiciones.push_back({ static_cast<double>(pos.x - 1), static_cast<double>(pos.y - 1) }); // se añade al vector las posiciones donde la torre puede moverse
			haComidoPieza = true;
		}
	}
	return posiciones;
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