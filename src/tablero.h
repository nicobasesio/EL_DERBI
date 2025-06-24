#pragma once
#include "VECTOR2D.h"
#include "ETSIDI.h"
class Tablero
{
public:
	VECTOR2D coordenadas{};
	VECTOR2D casilla;
	VECTOR2D posicion_temp;
	ETSIDI::SpriteSequence temporizador{ "imagenes/temporizador.png", 1 };
	ETSIDI::SpriteSequence temporizador2{ "imagenes/temporizador.png", 1 };

public:
	
	Tablero() {
		temporizador.setCenter(0, 0);
		temporizador.setSize(6, 3);
		temporizador2.setCenter(0, 0);
		temporizador2.setSize(6, 3);
	}

	void dibuja_tablero(int c, int f);
	void dibuja_cuadrado_blanco(double i, double j);
	void dibuja_cuadrado_verde(double i, double j);
	void dibuja_fondo();
	void dibuja_marco(double i, double j);
	void dibuja_temporizador();

	void set_coordenadas(const VECTOR2D& coord);
	void dibuja_casilla(VECTOR2D posicion_central_click);
	void dibuja_casilla_anterior_tras_movimiento(VECTOR2D posicion_central_click_anterior);



	
};

