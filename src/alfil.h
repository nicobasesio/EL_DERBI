#pragma once
#include <vector>
#include "vector2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include "pieza.h"
class Alfil : public Pieza
{
private:
	Raton r;
	bool color; // FALSE es negro. TRUE es blanco
	bool haComidoPieza;
	ETSIDI::SpriteSequence sprite{ "imagenes/alfilB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/alfilR.png", 1 };
public:
	Alfil() {
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
	bool piezaAhogada(std::vector<VECTOR2D> posiciones);
	std::vector<VECTOR2D> get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos);
	bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  // Para que no se salga del tamaño de la matriz control al comprobar si es jaque o no


};
