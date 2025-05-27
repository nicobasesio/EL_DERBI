#pragma once
#include "pieza.h"
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include <vector>

class Peon : public Pieza //Peon hereda de Pieza
{
	Raton r; 
	bool color; // FALSE es Rojo. TRUE es blanco
	ETSIDI::SpriteSequence sprite{ "imagenes/peonB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/peonR.png", 1 };
	bool haComidoPieza;
public:

	Peon()
	{
		sprite.setCenter(+0.75, +0.75); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), está descolocada
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), está descolocada
		sprite2.setSize(1.5, 1.5);
		color = TRUE; //Blanco predeterminado
	}
	
	void mueve(double, double);
	void set_pos_pieza(const VECTOR2D& pos); // Se introduce la dirección en la que hay un peon
	void dibuja_pieza();
	void set_color_pieza(bool a);
	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>>);
	bool get_color() {
		return color;
	}
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	VECTOR2D get_pos() {
		return posicion_pieza;
	}

	
	
	//bool piezaAhogada(std::vector<VECTOR2D> posiciones);
	//std::vector<VECTOR2D> get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos);
	//bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no

};


