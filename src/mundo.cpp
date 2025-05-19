#include "mundo.h"
void Mundo::set_posicion_central_click(VECTOR2D& posicion_central) {
    posicion_central_click = posicion_central;
    // Aqu� no detectamos clics en el men� si no estamos en el estado de men� principal
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
}
void Mundo::inicializa_tab() {
    columnas = 8;
    filas = 8;
    // Aseg�rate de que las coordenadas est�n configuradas correctamente
    tablero.set_coordenadas({ -columnas + 1.0, ((21.0 - 2.0 * filas) / 2.0) - 3.0 + 3.0 });
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

    //Rojas
    peonR1.dibuja_pieza();
    peonR2.dibuja_pieza();
    peonR3.dibuja_pieza();
    peonR4.dibuja_pieza();
    peonR5.dibuja_pieza();
    peonR6.dibuja_pieza();
    peonR7.dibuja_pieza();
    peonR8.dibuja_pieza();
}
