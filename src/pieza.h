#pragma once
#include "VECTOR2D.h"
#include "raton.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include <vector>
class Pieza
{
	Raton r;


public:
	bool color;	// FALSE es rojo. TRUE es blanco
	bool haComidoPieza;

	VECTOR2D posicion_pieza{}; // comun a todas las piezas
	virtual ~Pieza() {}
	virtual void muevepieza(double x, double y) {}
	virtual void set_pos_pieza(const VECTOR2D& pos) {} // Se introduce la dirección en la que hay una pieza
	virtual void dibuja_pieza() {}
	virtual void set_color_pieza(bool a) {
		if (a == true)
			color = true;
		if (a == false)
			color = false;
	}
	virtual bool get_color() {
		return color;
	}
	virtual bool get_haComidoPieza() {
		return haComidoPieza;
	}
	virtual VECTOR2D get_pos() {
		return posicion_pieza;
	}

	virtual bool piezaAhogada(std::vector<VECTOR2D> posiciones)
	{
		if (posiciones.size() == 0)
			return true;
		else
			return false;
	}

	virtual bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {   // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no
		return false;
	}

	virtual std::vector<VECTOR2D> get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos) { // 
		std::vector<VECTOR2D> posiciones; // se almacenan las posiciones de control de todas las piezas de color negro


		return posiciones;
	}
};

