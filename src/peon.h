#pragma once
#include "pieza.h"
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include <vector>

class Peon : public Pieza //Peon hereda de Pieza
{
	Raton r; 
	bool color; // FALSE es Rojo. TRUE es blanco
	ETSIDI::SpriteSequence sprite{ "imagenes/peonB.png", 1 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/peonR.png", 1 };
	bool haComidoPieza;
public:

	Peon()
	{
		sprite.setCenter(+0.75, +0.75); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), est� descolocada
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75); //puesto a mano. las 'x' positivas van hacia la izquierda y las 'y' positivas van hacia abajo. en el (0,0), est� descolocada
		sprite2.setSize(1.5, 1.5);
		color = TRUE; //Blanco predeterminado
	}
	
	void muevepieza(double, double);
	void set_pos_pieza(const VECTOR2D& pos); // Se introduce la direcci�n en la que hay un peon
	void dibuja_pieza();
	void set_color_pieza(bool a);
	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>>);
	bool get_color() {
		return color;
	}
	bool get_haComidoPieza() {
		return haComidoPieza;
	}
	VECTOR2D get_pos() {
		return posicion_pieza;
	}
	
	inline bool es_peon() const override { return true; }
	bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  // Para que no se salga del tama�o de la matriz control 
	
	bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo);
	bool puede_comer_enemigo(const VECTOR2D& origen,const VECTOR2D& destino,const std::vector<std::vector<Pieza*>>& control) override;
};




