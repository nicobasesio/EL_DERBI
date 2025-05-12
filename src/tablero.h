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
	ETSIDI::SpriteSequence pizarra{ "imagenes/pizarra.png", 1 };
	ETSIDI::SpriteSequence pizarra2{ "imagenes/pizarra_larga.png", 1 };
	ETSIDI::SpriteSequence pizarra3{ "imagenes/pizarra_larga.png", 1 };
	ETSIDI::SpriteSequence pizarra4{ "imagenes/pizarra.png",1 };

public:
	Tablero() {
		temporizador.setCenter(0, 0);
		temporizador.setSize(6, 3);
		temporizador2.setCenter(0, 0); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), está descolocada
		temporizador2.setSize(6, 3);

		pizarra.setCenter(0, 2);
		pizarra.setSize(8, 10);
		pizarra2.setCenter(0, 0);
		pizarra2.setSize(15, 2);
		pizarra3.setCenter(0, 0);
		pizarra3.setSize(15, 2);
		pizarra4.setCenter(0, 0);
		pizarra4.setSize(8, 6);
	}

	void dibuja_tablero(int c, int f);
	void dibuja_cuadrado_blanco(double i, double j);
	void dibuja_cuadrado_azul(double i, double j);
	void dibuja_fondo();
	void dibuja_marco(double i, double j);
	void dibuja_temporizador();
	void dibuja_pizarras(double altura_arriba, double altura_abajo);

	void set_coordenadas(const VECTOR2D& coord);
	void dibuja_casilla(VECTOR2D posicion_central_click);
	void dibuja_casilla_anterior_tras_movimiento(VECTOR2D posicion_central_click_anterior);



	;
};

