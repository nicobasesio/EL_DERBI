#pragma once
#include "pieza.h"
#include <vector>
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"

class Caballo : public Pieza
{

private:
	Raton r;
	bool color; // false rojo; true negro
	bool haComidoPieza;
	ETSIDI::SpriteSequence sprite{ "imagenes/caballoB.png",1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/caballoR.png",1 };

public:
	Caballo() 
	{
		sprite.setCenter(+1.5, +1.5);
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+1.5, +1.5);
		sprite2.setSize(1.5, 1.5);
		color = true;
	}

	void muevepieza(double, double);
	void set_pos_pieza(const VECTOR2D& pos);
	void dibuja_pieza();
	void set_color_pieza(bool a);
	bool get_color()
	{
		return color;
	}
	VECTOR2D get_pos()
	{
		return posicion_pieza;
	}
};

