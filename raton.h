#pragma once
#include "VECTOR2D.h"
class Raton
{
public:
	VECTOR2D casilla{};
	VECTOR2D casilla_anterior{};
	VECTOR2D posicion{}; //tengo que dejarlo en public porque sino no puedo coger la posicion desde principal.cpp
	VECTOR2D posicion_centro_casilla{};


	VECTOR2D elige_casilla(); //En caso de se Vector2D, la funcion devuelve el vector casilla, que va del 1,1 hasta el nfila,mcolumna
	//void marca_casilla_seleccionada(Vector2D);
};

