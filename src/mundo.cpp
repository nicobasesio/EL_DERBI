#include "mundo.h"
#include "pieza.h"
#include "freeglut.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>




// Se crea una matriz con el contenido inicial de cada casilla del tablero. En el momento de mover la ficha, se actualiza la información
   //std::vector<std::vector<Pieza>> control(8, std::vector<Pieza>(8));  // columnas, filas
std::vector<std::vector<Pieza*>> control(8, std::vector<Pieza*>(8, nullptr)); //es un vector de vectores que contienen punteros a objetos de tipo Pieza MATRIZ PARA TABLERO SILVERMAN

void Mundo::crear_matriz_control() {
    columnas = 8;
    filas = 8;
    // primera columna
    control[0][1] = &peonB1;
    control[0][2] = nullptr;
    control[0][3] = &peonR1;

    // segunda columna
    control[1][1] = &peonB2;
    control[1][2] = nullptr;
    control[1][3] = &peonR2;

    // tercera columna
    control[2][1] = &peonB3;
    control[2][2] = nullptr;
    control[2][3] = &peonR3;

    // cuarta columna
    control[3][1] = &peonB4;
    control[3][2] = nullptr;
    control[3][3] = &peonR4;

    // quinta columna
    control[4][1] = &peonB5;
    control[4][2] = nullptr;
    control[4][3] = &peonR5;

    // sexta columna
    control[5][1] = &peonB6;
    control[5][2] = nullptr;
    control[5][3] = &peonR6;

    // septima columna
    control[6][1] = &peonB7;
    control[6][2] = nullptr;
    control[6][3] = &peonR7;

    // octaba columna
    control[7][1] = &peonB8;
    control[7][2] = nullptr;
    control[7][3] = &peonR8;

}


void Mundo::set_posicion_central_click(VECTOR2D& posicion_central) {
    posicion_central_click = posicion_central;
    // Aquí no detectamos clics en el menú si no estamos en el estado de menú principal
}

void Mundo::set_posicion_central_click_anterior(VECTOR2D& posicion_central)
{
    posicion_central_click_anterior = posicion_central; //centro de la casilla a la que se hace click

}
void Mundo::set_casilla_actual(VECTOR2D& casilla_act)
{
    casilla_actual = casilla_act;
}
void Mundo::set_casilla_anterior(VECTOR2D& casilla_ant)
{
    casilla_anterior = casilla_ant;
}
void Mundo::inicializa() {
    x_ojo = 0.0;
    y_ojo = 7.5;
    z_ojo = 30.0;
    inicializa_tab();

    //Piezas blancas
    peonB1.set_pos_pieza({ -7,4.5 });
    peonB2.set_pos_pieza({ -5,4.5 });
    peonB3.set_pos_pieza({ -3,4.5 });
    peonB4.set_pos_pieza({ -1,4.5 });
    peonB5.set_pos_pieza({ 1,4.5 });
    peonB6.set_pos_pieza({ 3,4.5 });
    peonB7.set_pos_pieza({ 5,4.5 });
    peonB8.set_pos_pieza({ 7,4.5 });
    torreB1.set_pos_pieza({ -7, 2.5 });
    torreB2.set_pos_pieza({ 7, 2.5 });
    alfilB1.set_pos_pieza({ -3, 2.5 });
    alfilB2.set_pos_pieza({ 3, 2.5 });

    peonB1.set_color_pieza(true); //Cambios
    peonB2.set_color_pieza(true);
    peonB3.set_color_pieza(true);
    peonB4.set_color_pieza(true);
    peonB5.set_color_pieza(true);
    peonB6.set_color_pieza(true);
    peonB7.set_color_pieza(true);
    peonB8.set_color_pieza(true);
    torreB1.set_color_pieza(true);
    torreB2.set_color_pieza(true);
    alfilB1.set_color_pieza(true);
    alfilB2.set_color_pieza(true);


    //Piezas rojas
    peonR1.set_pos_pieza({ -7,14.5 });
    peonR2.set_pos_pieza({ -5,14.5 });
    peonR3.set_pos_pieza({ -3,14.5 });
    peonR4.set_pos_pieza({ -1,14.5 });
    peonR5.set_pos_pieza({ 1,14.5 });
    peonR6.set_pos_pieza({ 3,14.5 });
    peonR7.set_pos_pieza({ 5,14.5 });
    peonR8.set_pos_pieza({ 7,14.5 });
    torreR1.set_pos_pieza({ -7, 16.5 });
    torreR2.set_pos_pieza({ 7, 16.5 });
    alfilR1.set_pos_pieza({ -3, 16.5 });
    alfilR2.set_pos_pieza({ 3, 16.5 });

    peonR1.set_color_pieza(false); //Cambios
    peonR2.set_color_pieza(false);
    peonR3.set_color_pieza(false);
    peonR4.set_color_pieza(false);
    peonR5.set_color_pieza(false);
    peonR6.set_color_pieza(false);
    peonR7.set_color_pieza(false);
    peonR8.set_color_pieza(false);
    torreR1.set_color_pieza(false);
    torreR2.set_color_pieza(false);
    alfilR1.set_color_pieza(false);
    alfilR2.set_color_pieza(false);

}
void Mundo::inicializa_tab() {
    columnas = 8;
    filas = 8;
    // Asegúrate de que las coordenadas estén configuradas correctamente
    tablero.set_coordenadas({ -columnas + 1.0, ((21.0 - 2.0 * filas) / 2.0) - 3.0 + 3.0 });
}

void Mundo::imprimirmatriz() {
    for (int i = 0; i < control.size(); ++i) {
        for (int j = 0; j < control[i].size(); ++j) {
            if (control[i][j] == nullptr)
                std::cout << "  [   ]" << std::endl;
            else if (control[i][j] == &peonB1)
                std::cout << "[ peonB1 ]" << std::endl;
            else if (control[i][j] == &peonB2)
                std::cout << "[ peonB2 ]" << std::endl;
            else if (control[i][j] == &peonB3)
                std::cout << "[ peonB3 ]" << std::endl;
            else if (control[i][j] == &peonB4)
                std::cout << "[ peonB4 ]" << std::endl;
            else if (control[i][j] == &peonB5)
                std::cout << "[ peonB5 ]" << std::endl;
            else if (control[i][j] == &peonB6)
                std::cout << "[peonB6 ]" << std::endl;
            else if (control[i][j] == &peonB7)
                std::cout << "[peonB7 ]" << std::endl;
            else if (control[i][j] == &peonB8)
                std::cout << "[peonB8 ]" << std::endl;

        }
    }
    std::cout << "\n\n" << std::endl;
}

void Mundo::dibuja() {
    tablero.dibuja_tablero(columnas, filas);
    if (casilla_seleccionada)
        tablero.dibuja_casilla(posicion_central_click);
    
    //Blancas
    peonB1.dibuja_pieza();
    peonB2.dibuja_pieza();
    peonB3.dibuja_pieza();
    peonB4.dibuja_pieza();
    peonB5.dibuja_pieza();
    peonB6.dibuja_pieza();
    peonB7.dibuja_pieza();
    peonB8.dibuja_pieza();
    torreB1.dibuja_pieza();
    torreB2.dibuja_pieza();
    alfilB1.dibuja_pieza();
    alfilB2.dibuja_pieza();

    //Rojas
    peonR1.dibuja_pieza();
    peonR2.dibuja_pieza();
    peonR3.dibuja_pieza();
    peonR4.dibuja_pieza();
    peonR5.dibuja_pieza();
    peonR6.dibuja_pieza();
    peonR7.dibuja_pieza();
    peonR8.dibuja_pieza();
    torreR1.dibuja_pieza();
    torreR2.dibuja_pieza();
    alfilR1.dibuja_pieza();
    alfilR2.dibuja_pieza();
}


void Mundo::mueve_piezas() {
    movida = false;
    //Vector2D pos_fuera_tablero = { 20.0, 20.0 };
    if (posicion_central_click.x != 0 && posicion_central_click.y != 0) {

        // movimiento peonB1 
        if (peonB1.posicion_pieza.x == posicion_central_click_anterior.x && peonB1.posicion_pieza.y == posicion_central_click_anterior.y && turno == true)
        {
            
        }
    }

}



