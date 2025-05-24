#pragma once
#include "pieza.h"
class Caballo : public Pieza
{
<<<<<<< Updated upstream
=======
private:
	Raton r;
	bool color; // false rojo; true negro
	bool haComidoPieza;
	ETSIDI::SpriteSequence sprite{ "imagenes/caballoB.png",1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/caballoR.png",1 };

public:
	caballo() 
	{
		sprite.setCenter
	}
>>>>>>> Stashed changes
};

