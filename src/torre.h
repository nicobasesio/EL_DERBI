#pragma once
#include <vector>
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include "pieza.h"

class Torre : public Pieza
{
private:
	Raton r;
	bool color; // FALSE es rojo. TRUE es blanco
	bool haComidoPieza;
	ETSIDI::SpriteSequence sprite{ "imagenes/torreB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/torreR.png", 1 };


public:

	Torre() {
		sprite.setCenter(+0.75, +0.75);
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75);
		sprite2.setSize(1.5, 1.5);
		color = true; // Blanco predeterminado
	}

	void muevepieza(double, double);
	void set_pos_pieza(const VECTOR2D& pos);
	void dibuja_pieza();
	void set_color_pieza(bool a);
	bool get_color() {
		return color;
	}
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	VECTOR2D get_pos() {
		return posicion_pieza;
	}
	bool pieza_comible(VECTOR2D,std::vector<std::vector<Pieza*>>);
	inline bool es_torre() const override { return true; }
	bool puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) override;
	bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo)override;

};