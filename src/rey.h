#pragma once
#include <vector>
#include <iostream>
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include "pieza.h"

class Rey : public Pieza 
{
	Raton r;

	ETSIDI::SpriteSequence sprite{ "imagenes/reyB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/reyR.png", 1 };

	std::string tipo = "normal";

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
	void setTipo(const std::string& t);  // nuevo método

	bool get_color() {
		return color;
	}

	void dibuja_pieza() override;
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	VECTOR2D get_pos() {
		return posicion_pieza;
	}
	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>>);

	bool puede_comer_enemigo(const VECTOR2D& origen, const VECTOR2D& destino, const std::vector<std::vector<Pieza*>>& control) override;
	inline bool es_rey() const override { return true; }
	bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo);
};
