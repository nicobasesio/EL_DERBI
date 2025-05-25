#include "raton.h"
#include "freeglut.h"
#include <iostream>
#include<mundo.h>

extern Mundo mundo;

VECTOR2D Raton::elige_casilla() {
	// COLUMNAS (x)
	if (posicion.x > -8 && posicion.x < -6) {
		casilla_anterior.x = casilla.x;
		casilla.x = 1.0;
		posicion_centro_casilla.x = -7.0;
	}
	else if (posicion.x > -6 && posicion.x < -4) {
		casilla_anterior.x = casilla.x;
		casilla.x = 2.0;
		posicion_centro_casilla.x = -5.0;
	}
	else if (posicion.x > -4 && posicion.x < -2) {
		casilla_anterior.x = casilla.x;
		casilla.x = 3.0;
		posicion_centro_casilla.x = -3.0;
	}
	else if (posicion.x > -2 && posicion.x < 0) {
		casilla_anterior.x = casilla.x;
		casilla.x = 4.0;
		posicion_centro_casilla.x = -1.0;
	}
	else if (posicion.x > 0 && posicion.x < 2) {
		casilla_anterior.x = casilla.x;
		casilla.x = 5.0;
		posicion_centro_casilla.x = 1.0;
	}
	else if (posicion.x > 2 && posicion.x < 4) {
		casilla_anterior.x = casilla.x;
		casilla.x = 6.0;
		posicion_centro_casilla.x = 3.0;
	}
	else if (posicion.x > 4 && posicion.x < 6) {
		casilla_anterior.x = casilla.x;
		casilla.x = 7.0;
		posicion_centro_casilla.x = 5.0;
	}
	else if (posicion.x > 6 && posicion.x < 8) {
		casilla_anterior.x = casilla.x;
		casilla.x = 8.0;
		posicion_centro_casilla.x = 7.0;
	}




	//filas
	if (posicion.y > 15.5 && posicion.y < 17.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 9.0;
		posicion_centro_casilla.y = 16.5;
	}
	if (posicion.y > 13.5 && posicion.y < 15.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 8.0;
		posicion_centro_casilla.y = 14.5;
	}
	if (posicion.y > 11.5 && posicion.y < 13.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 7.0;
		posicion_centro_casilla.y = 12.5;
	}
	if (posicion.y > 9.5 && posicion.y < 11.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 6.0;
		posicion_centro_casilla.y = 10.5;
	}
	if (posicion.y > 7.5 && posicion.y < 9.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 5.0;
		posicion_centro_casilla.y = 8.5;
	}
	if (posicion.y > 5.5 && posicion.y < 7.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 4.0;
		posicion_centro_casilla.y = 6.5;
	}
	if (posicion.y > 3.5 && posicion.y < 5.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 3.0;
		posicion_centro_casilla.y = 4.5;
	}
	if (posicion.y > 1.5 && posicion.y < 3.5) {
		casilla_anterior.y = casilla.y;
		casilla.y = 2.0;
		posicion_centro_casilla.y = 2.5;
	}
	



	//Se dibuja cuadrado rojo para marcar la casilla seleccionada
	glColor3ub(220, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(static_cast<float>(posicion_centro_casilla.x - 1), static_cast<float>(posicion_centro_casilla.y - 1), 0.0f);//abajo izq
	glVertex3f(static_cast<float>(posicion_centro_casilla.x - 1), static_cast<float>(posicion_centro_casilla.y + 1), 0.0f);//arriba izq
	glVertex3f(static_cast<float>(posicion_centro_casilla.x + 1), static_cast<float>(posicion_centro_casilla.y + 1), 0.0f);//arriba der
	glVertex3f(static_cast<float>(posicion_centro_casilla.x + 1), static_cast<float>(posicion_centro_casilla.y - 1), 0.0f);//abajo der
	glEnd();

	// filas y columnas fuera del tablero
	if (posicion.x >= 8 || posicion.x <= -8) {		// Fuera del tablero
		casilla.x = 0.0;
		casilla.y = 0.0;
		posicion_centro_casilla.x = 0.0;
		posicion_centro_casilla.y = 0.0;
	}

	if (posicion.y >= 17.5 || posicion.y <= 1.5) {	// Fuera del tablero
		casilla.x = 0.0;
		casilla.y = 0.0;
		posicion_centro_casilla.x = 0.0;
		posicion_centro_casilla.y = 0.0;
	}

	return { posicion_centro_casilla };
}
/*  casilla_anterior = casilla;

	// Si está dentro del rango del tablero
	if (posicion.x >= -7.9 && posicion.x <= 7.9 &&
		posicion.y >= -7.9 && posicion.y <= 7.9) {

		casilla.x = round(posicion.x / 2.0) * 2.0;
		casilla.y = round(posicion.y / 2.0) * 2.0;
		posicion_centro_casilla = casilla;
	}
	else {
		casilla = { 0.0, 0.0 };
		posicion_centro_casilla = { 0.0, 0.0 };
	}

	return posicion_centro_casilla;*/