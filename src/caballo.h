#pragma once
#include "pieza.h"
#include "VECTOR2D.h"
#include "raton.h"
#include "ETSIDI.h"
#include <vector>

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
		sprite.setCenter(+0.75, +0.75);
		sprite.setSize(1.5, 1.5);
		sprite2.setCenter(+0.75, +0.75);
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

	bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control);  // Para que no se salga del tamaño de la matriz control 

	bool pieza_comible(VECTOR2D, std::vector<std::vector<Pieza*>>);

	bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo);


	bool get_haComidoPieza()
	{
		return haComidoPieza;
	}
	bool puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) override;
	inline bool es_caballo() const override { return true; }

};

