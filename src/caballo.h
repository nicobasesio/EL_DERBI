#pragma once
#include "pieza.h"
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
		sprite.setCenter(+0.75,0.75);
	}
};

