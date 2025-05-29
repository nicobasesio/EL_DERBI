#include "reina.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "mundo.h" 
#include "pieza.h"

void Reina::muevepieza(double x, double y)
{
	posicion_pieza.x = x;
	posicion_pieza.y = y;
}

bool Reina::piezaAhogada(std::vector<VECTOR2D> posiciones)
{
	if (posiciones.size() == 0)
		return true;
	else
		return false;
}


bool Reina::casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {   // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
	if (i >= 0 && i < control.size() && j >= 0 && j < control[0].size())
		return true;
	else
		return false;

}


std::vector<VECTOR2D> Reina::get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos) { // pos es la casilla que ocupa la torre en nuestra matriz de control
	haComidoPieza = false; // por defecto no come pieza. En caso de que tenga la posibilidad de hacerlo, si valor cambiará a true
	std::vector<VECTOR2D> posiciones; // se almacenan las posiciones de control de todas las piezas de color negro
	//FILAS REINA (horizontal)
	for (int i = 1; i < control.size(); i++) { //HORIZONTAL derecha DE LA TORRE
		if (casillaValida(pos.x + i, pos.y, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x + i][pos.y] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x + i][pos.y] != nullptr && control[pos.x + i][pos.y]->get_color() == true) { //se comprueba que es viable la captura de la pieza
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x + i][pos.y] != nullptr && control[pos.x + i][pos.y]->get_color() == false) { // se detecta pieza negra
				//haComidoPieza = false;
				break;
			}
		}
	}
	for (int i = 1; i < control.size(); i++) { 		//HORIZONTAL izquierda DE LA TORRE
		if (casillaValida(pos.x - i, pos.y, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x - i][pos.y] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x - i][pos.y] != nullptr && control[pos.x - i][pos.y]->get_color() == true) {
				posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x - i][pos.y] != nullptr && control[pos.x - i][pos.y]->get_color() == false) { // se detecta pieza negra
				//haComidoPieza = false; 
				break;
			}
		}
	}
	//COLUMNAS REINA (vertical)
	for (int i = 1; i < control[0].size(); i++) { // tamaño de la vertical 
		if (casillaValida(pos.x, pos.y + i, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x][pos.y + i] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x), static_cast<double>(pos.y + i) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x][pos.y + i] != nullptr && control[pos.x][pos.y + i]->get_color() == true) {
				posiciones.push_back({ static_cast<double>(pos.x), static_cast<double>(pos.y + i) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x][pos.y + i] != nullptr && control[pos.x][pos.y + i]->get_color() == false) { // se detecta pieza roja
				//haComidoPieza = false; 
				break;
			}
		}
	}
	for (int i = 1; i < control[0].size(); i++) { //VERTICAL abajo DE LA TORRE
		if (casillaValida(pos.x, pos.y - i, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x][pos.y - i] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x), static_cast<double>(pos.y - i) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x][pos.y - i] != nullptr && control[pos.x][pos.y - i]->get_color() == true) {
				posiciones.push_back({ static_cast<double>(pos.x), static_cast<double>(pos.y - i) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x][pos.y - i] != nullptr && control[pos.x][pos.y - i]->get_color() == false) { // se detecta pieza roja
				//haComidoPieza = false;
				break;
			}
		}
	}
	//1ª y 3ª DIAGONAL REINA (arriba derecha. Abajo izda)
	for (int i = 1; i < control.size(); i++) { //1ª diagonal
		if (casillaValida(pos.x + i, pos.y + i, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x + i][pos.y + i] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y + i) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x + i][pos.y + i] != nullptr && control[pos.x + i][pos.y + i]->get_color() == true) { //se comprueba que es viable la captura de la pieza
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y + i) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x + i][pos.y + i] != nullptr && control[pos.x + i][pos.y + i]->get_color() == false) { // se detecta pieza roja
				//haComidoPieza = false;
				break;
			}
		}
	}
	for (int i = 1; i < control.size(); i++) { 		//3ª diagonal
		if (casillaValida(pos.x - i, pos.y - i, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x - i][pos.y - i] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y - i) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x - i][pos.y - i] != nullptr && control[pos.x - i][pos.y - i]->get_color() == true) {
				posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y - i) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x - i][pos.y - i] != nullptr && control[pos.x - i][pos.y - i]->get_color() == false) { // se detecta pieza roja
				//haComidoPieza = false;
				break;
			}
		}
	}
	//2ª y 4ª DIAGONAL REINA (arriba izqda. Abajo drcha)
	for (int i = 1; i < control.size(); i++) { //2ª diagonal
		if (casillaValida(pos.x - i, pos.y + i, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x - i][pos.y + i] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y + i) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x - i][pos.y + i] != nullptr && control[pos.x - i][pos.y + i]->get_color() == true) { //se comprueba que es viable la captura de la pieza
				posiciones.push_back({ static_cast<double>(pos.x - i), static_cast<double>(pos.y + i) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x - i][pos.y + i] != nullptr && control[pos.x - i][pos.y + i]->get_color() == false) { // se detecta pieza negra
				//haComidoPieza = false;
				break;
			}
		}
	}
	for (int i = 1; i < control.size(); i++) { 		//4ª diagonal
		if (casillaValida(pos.x + i, pos.y - i, control)) { // se comprueba que no se salga del rango de la matriz
			if (control[pos.x + i][pos.y - i] == nullptr) { // se recorre la fila de la torre en horizontal (y = cte)
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y - i) }); // se añade al vector las posiciones donde la torre puede moverse
				//haComidoPieza = false;
			}
			else if (control[pos.x + i][pos.y - i] != nullptr && control[pos.x + i][pos.y - i]->get_color() == true) {
				posiciones.push_back({ static_cast<double>(pos.x + i), static_cast<double>(pos.y - i) }); // se añade al vector las posiciones donde la torre puede moverse
				haComidoPieza = true;
				break;
			}
			else if (control[pos.x + i][pos.y - i] != nullptr && control[pos.x + i][pos.y - i]->get_color() == false) { // se detecta pieza roja
				//haComidoPieza = false;
				break;
			}
		}
	}
	return posiciones;
}

void Reina::set_pos_pieza(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;
}

void Reina::dibuja_pieza()
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

void Reina::set_color_pieza(bool a)
{
	if (a == true)
		color = true;
	if (a == false)
		color = false;
}

bool Reina::caminoLibre(VECTOR2D origen, VECTOR2D destino, const std::vector<std::vector<Pieza*>>& control) {
	int dx = destino.x - origen.x;
	int dy = destino.y - origen.y;

	int paso_x = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
	int paso_y = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

	int x = origen.x + paso_x;
	int y = origen.y + paso_y;

	while (x != destino.x || y != destino.y) {
		if (!casillaValida(x, y, control)) return false;
		if (control[x][y] != nullptr) return false;
		x += paso_x;
		y += paso_y;
	}

	return true;
}


bool Reina::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control) {
	int reina_x = casilla_actual.x - 2;
	int reina_y = casilla_actual.y - 2;
	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas al rededor del rey
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = reina_x + dx - 1;
			int y = reina_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {
					//std::cout << "Hay pieza comible para el rey en control[" << x << "," << y << "]\n";
					return true;
				}
			}
		}
	}
}