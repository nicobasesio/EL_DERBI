#pragma once
#include "VECTOR2D.h"
#include "ETSIDI.h"
class Tablero
{
public:
	VECTOR2D coordenadas{};
	VECTOR2D casilla;
	VECTOR2D posicion_temp;
	

public:
	

	void dibuja_tablero(int c, int f);
	void dibuja_cuadrado_blanco(double i, double j);
	void dibuja_cuadrado_rojo(double i, double j);
	void dibuja_fondo();
	void dibuja_marco(double i, double j);
	

	void set_coordenadas(const VECTOR2D& coord);
	void dibuja_casilla(VECTOR2D posicion_central_click);
	void dibuja_casilla_anterior_tras_movimiento(VECTOR2D posicion_central_click_anterior);



	;
};

