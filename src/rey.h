#pragma once
#include <vector>
#include <iostream>
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include "pieza.h"

class Rey :public Pieza // Rey hereda de Pieza
{
	Raton r;
	
	ETSIDI::SpriteSequence sprite{ "imagenes/reyB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/reyR.png", 1 };
public:

	Rey() {
		sprite.setCenter(+0.75, +0.75); 
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75); 
		sprite2.setSize(1.5, 1.5);
		color = TRUE; 

	}
	void muevepieza(double, double);
	void set_pos(const VECTOR2D& pos);	
	void dibuja();
	void set_color(bool a);
	bool get_color() {
		return color;
	}
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	VECTOR2D get_pos() {
		return posicion_pieza;
	}
	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>> );
	//bool piezaAtrapada(std::vector<VECTOR2D> posiciones);
	//std::vector<VECTOR2D> get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos);
	//bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control); 
	bool puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) override;
	inline bool es_rey() const override { return true; }
	std::string nombre() const override { return "rey_rojo"; }  // o "rey_blanco" si es reyB

		


};

