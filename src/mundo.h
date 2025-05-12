#pragma once
#include "VECTOR2D.h"
#include "tablero.h"
#include "raton.h"
#include <vector>

class Mundo
{
	VECTOR2D posicion_central_click; //es la posicion del centro de la casilla a la que se hace click
	VECTOR2D posicion_central_click_anterior;
	VECTOR2D casilla_actual;
	VECTOR2D casilla_anterior;
	VECTOR2D coordRatonFin, coordRatonInicial;

public:
	void dibuja();
	void inicializa();
	void inicializa_demi();
	double x_ojo{}, y_ojo{}, z_ojo{};
	int columnas;
	int filas;
public:
	void set_posicion_central_click(VECTOR2D& posicion_central_click);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_posicion_central_click_anterior(VECTOR2D& posicion_central);
	void set_casilla_actual(VECTOR2D& casilla_act);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_casilla_anterior(VECTOR2D& casilla_ant);
};

