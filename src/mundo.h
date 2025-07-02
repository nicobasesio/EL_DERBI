#pragma once
#include "VECTOR2D.h"
#include "pieza.h"
#include "torre.h"
#include "tablero.h"
#include "peon.h"
#include "alfil.h"
#include "rey.h"
#include "caballo.h"
#include "reina.h"
#include "freeglut.h"
#include "efectos.h"
#include <vector>
#include <iostream>

class Mundo {
	
	VECTOR2D posicion_central_click; // posición del centro de la casilla clicada
	VECTOR2D posicion_central_click_anterior;
	VECTOR2D casilla_actual;
	VECTOR2D casilla_anterior;
	VECTOR2D coordRatonFin, coordRatonInicial;
	VECTOR2D posInicioPiezaMover;
	VECTOR2D posFinPiezaMover;
	VECTOR2D posicion_anterior;
	VECTOR2D posicion_actual;

	Peon peonB1, peonB2, peonB3, peonB4, peonB5, peonB6, peonB7, peonB8;
	Peon peonR1, peonR2, peonR3, peonR4, peonR5, peonR6, peonR7, peonR8;
	Torre torreB1, torreB2, torreR1, torreR2;
	Alfil alfilB1, alfilB2, alfilR1, alfilR2;
	Caballo caballoB1, caballoB2, caballoR1, caballoR2;
	Rey reyB, reyR;
	Reina reinaB, reinaR;

	Tablero tablero;
	std::vector<std::vector<Pieza*>> control;

	double pos_comidaB_X = 7.0;
	double pos_comidaR_X = -7.0;

	std::vector<Pieza*> comidaB;
	std::vector<Pieza*> comidaR;

	std::vector<VECTOR2D> posiciones_comidas_rojas = {
		{7.0, -2.0}, {6.0, -2.0}, {5.0, -2.0}, {4.0, -2.0},
		{3.0, -2.0}, {2.0, -2.0}, {1.0, -2.0}, {0.0, -2.0}
	};

	std::vector<VECTOR2D> posiciones_comidas_blancas = {
		{-7.0, 17.0}, {-6.0, 17.0}, {-5.0, 17.0}, {-4.0, 17.0},
		{-3.0, 17.0}, {-2.0, 17.0}, {-1.0, 17.0}, {0.0, 17.0}
	};

	bool turno = true; 
	int columnas;
	int filas;
	bool movida = false;

public:
	Mundo();

	
	std::vector<std::vector<Pieza*>>& getControl() { return control; }

	void dibuja();
	void inicializa();
	void inicializa_tab();
	void mueve();
	void actualizar_matriz_control();
	void comidasB();
	void comidasR();
	void crear_matriz_control();
	bool casillaValida(int fila, int columna);
	void aplicar_efecto_especial(VECTOR2D pos);

	EfectoEspecial efectoBalon;
	EfectoEspecial efectoBonus;

	// Getters/setters de posición
	VECTOR2D get_posicion_central_click() const { return posicion_central_click; }
	void set_posicion_central_click(const VECTOR2D& p) { posicion_central_click = p; }
	void set_posicion_central_click_anterior(VECTOR2D& posicion_central);
	void set_casilla_actual(VECTOR2D& casilla_act);
	void set_casilla_anterior(VECTOR2D& casilla_ant);

	// Acceso al tablero
	Tablero& getTablero() { return tablero; }
	const Tablero& getTablero() const { return tablero; }

	inline bool get_turno() { return turno; }

	// Cámara y selección
	double x_ojo{}, y_ojo{}, z_ojo{};
	bool casilla_seleccionada = false;

	std::vector<std::pair<Pieza*, VECTOR2D>> piezas_con_captura();
};

