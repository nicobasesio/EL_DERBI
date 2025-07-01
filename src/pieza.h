#pragma once
#include "VECTOR2D.h"
#include <iostream>
#include "raton.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include <vector>

class Pieza
{
	Raton r;

protected:
	std::string tipo = "normal";  // "normal" o "balon"

public:
	bool color;	// FALSE es rojo. TRUE es blanco
	bool haComidoPieza;
	VECTOR2D posicion_pieza{}; // común a todas las piezas
	Pieza* pieza_comible = nullptr;

	virtual ~Pieza() {}

	virtual void muevepieza(double x, double y) = 0;
	virtual bool mover(VECTOR2D destino, std::vector<std::vector<Pieza*>>& control, bool& capturo) = 0;

	virtual void set_pos_pieza(const VECTOR2D& pos) {}

	virtual void dibuja() {} // <-- Añadido para evitar errores con override
	virtual void dibuja_pieza() { dibuja(); }

	virtual void set_color_pieza(bool a) { color = a; }

	void setTipo(const std::string& t) { tipo = t; }
	virtual std::string getTipo() const { return tipo; }

	virtual bool get_color() { return color; }
	virtual bool get_haComidoPieza() { return haComidoPieza; }
	virtual VECTOR2D get_pos() { return posicion_pieza; }

	virtual bool piezaAhogada(std::vector<VECTOR2D> posiciones) {
		return posiciones.empty();
	}

	virtual bool casillaValida(int i, int j, std::vector<std::vector<Pieza*>> control) {
		return false;
	}

	virtual std::vector<VECTOR2D> get_movimientos_validos(std::vector<std::vector<Pieza*>> control, VECTOR2D pos, VECTOR2D reyPos) {
		std::vector<VECTOR2D> posiciones;
		return posiciones;
	}

	virtual bool puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
		return false;
	}

	// Métodos de identificación de tipo de pieza
	virtual std::string nombre() const { return "pieza"; }
	virtual bool es_rey() const { return false; }
	virtual bool es_peon() const { return false; }
	virtual bool es_caballo() const { return false; }
	virtual bool es_torre() const { return false; }
	virtual bool es_alfil() const { return false; }
	virtual bool es_reina() const { return false; }
};