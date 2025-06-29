#pragma once
#include "VECTOR2D.h"
#include "vector"
#include "raton.h"
#include "ETSIDI.h"
#include "pieza.h"

class Reina :public Pieza	
{
	Raton r;
	bool color;
	bool haComidoPieza;
	ETSIDI::SpriteSequence sprite{ "imagenes/reinaB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/reinaR.png", 1 };
public:

	Reina() {
		sprite.setCenter(+0.75, +0.75); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), está descolocada
		sprite.setSize(1.5, 1.5);
		//sprite.setPos(0,0);
		sprite2.setCenter(+0.75, +0.75); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), está descolocada
		sprite2.setSize(1.5, 1.5);
		color = TRUE; //Blanco predeterminado

	}
	void muevepieza(double, double);
	void set_pos_pieza(const VECTOR2D& pos);	// Se introduce la dirección en la que hay una reina
	void dibuja_pieza();
	void set_color_pieza(bool a);
	bool caminoLibre(VECTOR2D origen, VECTOR2D destino, const std::vector<std::vector<Pieza*>>& control);

	bool get_color() {
		return color;
	}
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	VECTOR2D get_pos() {
		return posicion_pieza;
	}
	
	bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  
	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>>);
	inline bool es_reina() const override { return true; }
	bool puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) override;
	bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo);
};