#pragma once
#include "VECTOR2D.h"
#include "tablero.h"
#include "raton.h"
#include "peon.h"
#include <vector>

class Mundo
{
	Tablero tablero;
	VECTOR2D posicion_central_click; //es la posicion del centro de la casilla a la que se hace click
	VECTOR2D posicion_central_click_anterior;
	VECTOR2D casilla_actual;
	VECTOR2D casilla_anterior;
	VECTOR2D coordRatonFin, coordRatonInicial;
	Peon peonB1, peonB2, peonB3, peonB4, peonB5, peonB6, peonB7, peonB8;
	Peon peonR1, peonR2, peonR3, peonR4, peonR5, peonR6, peonR7, peonR8;

public:
	void dibuja();
	void inicializa();
	void inicializa_tab();
public:
	void set_posicion_central_click(VECTOR2D& posicion_central_click);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_posicion_central_click_anterior(VECTOR2D& posicion_central);
	void set_casilla_actual(VECTOR2D& casilla_act);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_casilla_anterior(VECTOR2D& casilla_ant);
	double x_ojo{}, y_ojo{}, z_ojo{};
	int columnas;
	int filas;
	bool casilla_seleccionada = false; //será true cuando se haya movido una pieza

	//las siguientes variables son para el tema de las piezas comidas
	int material_rojo = 0; //contador de puntos de piezas comidas
	int material_blanco = 0;
	int dif_material_int;

	int b = 0;      // Se lleva el conteo del numero de piezas blancas comidas
	int r = 0;      // Se lleva el conteo del numero de piezas negras comidas

};

