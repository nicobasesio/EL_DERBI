#include "pieza.h"
#include "torre.h"
#include "tablero.h"
#include "peon.h"
#include "alfil.h"
#include <vector>
#include <iostream>
#include "rey.h"
#include "caballo.h"
#include "reina.h"

class Mundo
{
	//Tablero tablero;
	VECTOR2D posicion_central_click; //es la posicion del centro de la casilla a la que se hace click
	VECTOR2D posicion_central_click_anterior;
	VECTOR2D casilla_actual;
	VECTOR2D casilla_anterior;
	VECTOR2D coordRatonFin, coordRatonInicial;
	VECTOR2D posInicioPiezaMover;    //Mediante el azar se elegir� una pieza del vector piezasNegras. Posicion inicial de la pieza que se movera
	VECTOR2D posFinPiezaMover;       //Mediante el azar se elegir� una pieza del vector posiciones. Posicion final donde la pieza se movera
	VECTOR2D posicion_anterior;
	VECTOR2D posicion_actual;
	Peon peonB1, peonB2, peonB3, peonB4, peonB5, peonB6, peonB7, peonB8;
	Peon peonR1, peonR2, peonR3, peonR4, peonR5, peonR6, peonR7, peonR8;
	Torre torreB1;
	Torre torreB2;
	Torre torreR1;
	Torre torreR2;
	Alfil alfilB1, alfilB2;
	Alfil alfilR1, alfilR2;
	Caballo caballoB1, caballoB2;
	Caballo caballoR1, caballoR2;
	Rey reyB, reyR;
	Reina reinaB, reinaR;
	Tablero tablero;
	std::vector<std::vector<Pieza*>> control;

	double pos_comidaB_X = 7.0;
	double pos_comidaR_X = -7.0;


	std::vector<Pieza*> comidaB;//es un vector que contienen punteros a objetos de tipo Pieza
	std::vector<Pieza*> comidaR;//es un vector que contienen punteros a objetos de tipo Pieza

	std::vector<VECTOR2D> posiciones_comidas_rojas = {
		{7.0, -2.0}, {6.0, -2.0}, {5.0, -2.0}, {4.0, -2.0}, {3.0, -2.0}, {2.0, -2.0}, {1.0, -2.0}, {0.0, -2.0}
	};

	std::vector<VECTOR2D> posiciones_comidas_blancas = {
		{-7.0, 17.0}, {-6.0, 17.0}, {-5.0, 17.0}, {-4.0, 17.0}, {-3.0, 17.0}, {-2.0, 17.0}, {-1.0, 17.0}, {0.0, 17.0}
	};

	bool turno = true; //true: turno de blancos, false: turno de rojas
	int columnas;
	int filas;
	

	bool movida = false; //ser� true cuando se haya movido una pieza

	
public:
	Mundo();
	
	std::vector<std::vector<Pieza*>>& getControl() { return control; }

	void dibuja();
	void inicializa();
	void inicializa_tab();
	void mueve();
	void set_posicion_central_click(VECTOR2D& posicion_central_click);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_posicion_central_click_anterior(VECTOR2D& posicion_central);
	void set_casilla_actual(VECTOR2D& casilla_act);	// De esta manera no es necesario introducir como entrada este valor para los metodos "mueve_pieza()" y "dibuja()"
	void set_casilla_anterior(VECTOR2D& casilla_ant);
	bool casillaValida(int fila, int columna);
	void crear_matriz_control();

	void actualizar_matriz_control();
	void comidasB();
	void comidasR();
    // Getters para exponer el tablero
    Tablero& getTablero() {
        return tablero;
    }
    const Tablero& getTablero() const {
        return tablero;
    }
	inline bool get_turno() { return turno; }

	double x_ojo{}, y_ojo{}, z_ojo{};
	bool casilla_seleccionada = false; //ser� true cuando se haya movido una pieza
	
	std::vector<std::pair<Pieza*, VECTOR2D>> piezas_con_captura();
	
	
};



