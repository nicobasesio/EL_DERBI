#pragma once
#include <vector>
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include "pieza.h"

class Alfil :public Pieza {
private:
	Raton r;
	bool color; // FALSE es rojo. TRUE es blanco
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
	VECTOR2D get_pos() {
		return posicion_pieza;
	}
	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>>);

	bool get_haComidoPieza() {
		return haComidoPieza;
	}


	bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  // Para que no se salga del tama�o de la matriz control 
	bool rutaDiagonalLibre(int x1, int y1, int x2, int y2, const std::vector<std::vector<Pieza*>>& control);
	inline bool es_alfil() const override { return true; }

	bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo);
	bool puede_comer_enemigo(const VECTOR2D& origen, const VECTOR2D& destino, const std::vector<std::vector<Pieza*>>& control) override;

};