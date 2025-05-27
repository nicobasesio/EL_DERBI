#include "mundo.h"
#include "pieza.h"
#include "freeglut.h"


// Se crea una matriz con el contenido inicial de cada casilla del tablero. En el momento de mover la ficha, se actualiza la información
   //std::vector<std::vector<Pieza>> control(8, std::vector<Pieza>(8));  // columnas, filas

void Mundo::crear_matriz_control() {
    columnas = 8;
    filas = 8;
    // primera columna
    control[0][0] = &torreB1;
    control[0][1] = &peonB1;
    control[0][2] = nullptr;
    control[0][3] = nullptr;
    control[0][4] = nullptr;
    control[0][5] = nullptr;
    control[0][6] = &peonR1;
    control[0][7] = &torreR1;

    // segunda columna
    control[1][0] = &caballoB1;
    control[1][1] = &peonB2;
    control[1][2] = nullptr;
    control[1][3] = nullptr;
    control[1][4] = nullptr;
    control[1][5] = nullptr;
    control[1][6] = &peonR2;
    control[1][7] = &caballoR1;
    // tercera columna
    control[2][0] = &alfilB1;
    control[2][1] = &peonB3;
    control[2][2] = nullptr;
    control[2][3] = nullptr;
    control[2][4] = nullptr;
    control[2][5] = nullptr;
    control[2][6] = &peonR3;
    control[2][7] = &alfilR1;

    // cuarta columna
    control[3][0] = &reinaB;
    control[3][1] = &peonB4;
    control[3][2] = nullptr;
    control[3][3] = nullptr;
    control[3][4] = nullptr;
    control[3][5] = nullptr;
    control[3][6] = &peonR4;
    control[3][7] = &reinaR;


    // quinta columna
    control[4][0] = &reyB;
    control[4][1] = &peonB5;
    control[4][2] = nullptr;
    control[4][3] = nullptr;
    control[4][4] = nullptr;
    control[4][5] = nullptr;
    control[4][6] = &peonR5;
    control[4][7] = &reyR;

    // sexta columna
    control[5][0] = &alfilB2;
    control[5][1] = &peonB6;
    control[5][2] = nullptr;
    control[5][3] = nullptr;
    control[5][4] = nullptr;
    control[5][5] = nullptr;
    control[5][6] = &peonR6;
    control[5][7] = &alfilR2;

    // septima columna
    control[6][0] = &caballoB2;
    control[6][1] = &peonB7;
    control[6][2] = nullptr;
    control[6][3] = nullptr;
    control[6][4] = nullptr;
    control[6][5] = nullptr;
    control[6][6] = &peonR7;
    control[6][7] = &caballoR2;

    // octaba columna
    control[7][0] = &torreB2;
    control[7][1] = &peonB8;
    control[7][2] = nullptr;
    control[7][3] = nullptr;
    control[7][4] = nullptr;
    control[7][5] = nullptr;
    control[7][6] = &peonR8;
    control[7][7] = &torreR2;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (control[i][j])
                std::cout << "[DEBUG] control[" << i << "][" << j << "] = " << typeid(*control[i][j]).name() << "\n";
            else
                std::cout << "[DEBUG] control[" << i << "][" << j << "] = nullptr\n";
        }
    }

}

Mundo::Mundo() : control(8, std::vector<Pieza*>(8, nullptr)) {}


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
    caballoB1.set_pos_pieza({ -5, 2.5 });
    caballoB2.set_pos_pieza({ 5, 2.5 });
    reyB.set_pos({ 1,2.5 });
    reinaB.set_pos_pieza({ -1,2.5 });

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
    caballoB1.set_color_pieza(true);
    caballoB2.set_color_pieza(true);
    reyB.set_color(true);
    reinaB.set_color_pieza(true);





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
    caballoR1.set_pos_pieza({ -5, 16.5 });
    caballoR2.set_pos_pieza({ 5, 16.5 });
    reyR.set_pos({ 1,16.5 });
    reinaR.set_pos_pieza({-1,16.5 });


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
    caballoR1.set_color_pieza(false);
    caballoR2.set_color_pieza(false);
    reyR.set_color(false);
    reinaR.set_color_pieza(false);


    crear_matriz_control();

}
void Mundo::inicializa_tab() {
    columnas = 8;
    filas = 8;
    // Asegúrate de que las coordenadas estén configuradas correctamente
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

    torreB1.dibuja_pieza();
    torreB2.dibuja_pieza();
    alfilB1.dibuja_pieza();
    alfilB2.dibuja_pieza();
    caballoB1.dibuja_pieza();
    caballoB2.dibuja_pieza();
    reyB.dibuja();
    reinaB.dibuja_pieza();


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
    caballoR1.dibuja_pieza();
    caballoR2.dibuja_pieza();
    reyR.dibuja();
    reinaR.dibuja_pieza();

   
}

bool Mundo::casillaValida(int i, int j) {   // Para que no se salga del tama�o de la matriz control al comprobar si es jaque o no
    return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

void Mundo::mueve()
{


    //movimiento reyB
    if (posicion_central_click_anterior.x == reyB.posicion_pieza.x && posicion_central_click_anterior.y == reyB.posicion_pieza.y && turno == true) //si seleccionas el rey blanco y es su turno, entonces:
    {

        int movx = std::abs(reyB.posicion_pieza.x - posicion_central_click.x); // distancia entre la posicion del rey y la del click del movimiento
        int movy = std::abs(reyB.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;


        if (movx <= 2 && movy <= 2 && !(movx == 0 && movy == 0)) // si el movimiento es de una casilla
        {


            if (!casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true)) { // Si la casilla no esta en jaque 
                if (reyB.pieza_comible(casilla_actual, control) == true) { // si se va a comer una pieza roja
                    if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                    {
                       
                        comidasR();
                    }
                    else
                    {
                        
                        comidasB();
                    }


                }
                std::cout << "[DEBUG] Moviendo reyB a: " << std::endl;
                reyB.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = false;
                std::cout << "Turno de Rojas\n" << std::endl;
            }
            else if (casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true))
                std::cout << "\nEl rey blanco NO se puede mover a una casilla atacada\n" << std::endl;
        }

    }


    //movimiento reyR
    if (posicion_central_click_anterior.x == reyR.posicion_pieza.x && posicion_central_click_anterior.y == reyR.posicion_pieza.y && turno == false) //si seleccionas el rey blanco y es su turno, entonces:
    {

        int movx = std::abs(reyR.posicion_pieza.x - posicion_central_click.x); // distancia entre la posicion del rey y la del click del movimiento
        int movy = std::abs(reyR.posicion_pieza.y - posicion_central_click.y);


        if (movx <= 2 && movy <= 2 && !(movx == 0 && movy == 0)) // si el movimiento es de una casilla
        {


            if (!casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true)) { // Si la casilla no esta en jaque 
                if (reyR.pieza_comible(casilla_actual, control) == true) { // si se va a comer una pieza roja
                    if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                    {
                        
                        comidasR();
                    }
                    else
                    {
                        
                        comidasB();
                    }


                }

                std::cout << "[DEBUG] Moviendo reyR a: " << std::endl;
                reyR.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = true;
                std::cout << "Turno de negras\n" << std::endl;
            }
            else if (casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true))
                std::cout << "\nEl rey blanco NO se puede mover a una casilla atacada\n" << std::endl;

        }

    }
    //movimiento peonB1
   
    if (posicion_central_click_anterior.x == peonB1.posicion_pieza.x && posicion_central_click_anterior.y == peonB1.posicion_pieza.y && turno == true) //si seleccionas el peon blanco y es su turno, entonces:
    {

        int movx = std::abs(peonB1.posicion_pieza.x - posicion_central_click.x); // distancia entre la posicion del peon y la del click del movimiento
        int movy = std::abs(peonB1.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;


        if (movx <= 0 && movy <= 4 && !(movx == 0 && movy == 0)) // si el movimiento es de una casilla
        {


            if (!casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true)) { // Si la casilla no esta en jaque 
                if (peonB1.pieza_comible(casilla_actual, control) == true) { // si se va a comer una pieza roja
                    if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                    {
                        comidasR();
                    }
                    else
                    {
                        comidasB();
                    }


                }
                std::cout << "[DEBUG] Moviendo peonB1 a: " << std::endl;
                peonB1.mueve(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = false;
                std::cout << "Turno de Rojas\n" << std::endl;
            }
            else if (casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true))
                std::cout << "\nEl peon blanco NO se puede mover a una casilla atacada\n" << std::endl;
        }
        else if  (movx <= 0 && movy <= 2 && !(movx == 0 && movy == 0)) // si el movimiento es de dps casillas
       
        {

            if (!casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true)) { // Si la casilla no esta en jaque 
                if (peonB1.pieza_comible(casilla_actual, control) == true) { // si se va a comer una pieza roja
                    if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                    {
                        comidasR();
                    }
                    else
                    {
                        comidasB();
                    }


                }
                std::cout << "[DEBUG] Moviendo peonB1 a: " << std::endl;
                peonB1.mueve(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = false;
                std::cout << "Turno de Rojas\n" << std::endl;
            }
            else if (casilla_Jaque({ casilla_anterior.x - 1, casilla_anterior.y - 1 }, { casilla_actual.x - 1, casilla_actual.y - 1 }, true))
                std::cout << "\nEl peon blanco NO se puede mover a una casilla atacada\n" << std::endl;
        }

    }
   
    



    //movimiento caballo blanco1 
    if (posicion_central_click_anterior.x == caballoB1.posicion_pieza.x && posicion_central_click_anterior.y == caballoB1.posicion_pieza.y && turno == true)
    {
        int movx = std::abs(caballoB1.posicion_pieza.x - posicion_central_click.x);
        int movy = std::abs(caballoB1.posicion_pieza.y - posicion_central_click.x);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;

        //condicion del movimiento del caballo (movimiento en L)
        bool movimiento_valido = (movx == 2 && movy == 1) || (movx == 1 && movy == 2);

        if (movimiento_valido)
        {
            if (caballoB1.pieza_comible(casilla_actual, control) == true)
            {
                if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                {
                    comidasR();
                }
                else
                {
                    comidasB();
                }
            }
            std::cout << "[DEBUG] Moviendo caballoB1 a: " << posicion_central_click.x << ", " << posicion_central_click.y << std::endl;

            caballoB1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            movida = true;
            turno = false;
            std::cout << "Turno de Rojas\n" << std::endl;
        }
        else
        {
            std::cout << "\n Movimiento invalido para el caballo\n" << std::endl;
        }
    }


    //movimiento caballo blanco2
    if (posicion_central_click_anterior.x == caballoB2.posicion_pieza.x && posicion_central_click_anterior.y == caballoB2.posicion_pieza.y && turno == true)
    {
        int movx = std::abs(caballoB2.posicion_pieza.x - posicion_central_click.x);
        int movy = std::abs(caballoB2.posicion_pieza.y - posicion_central_click.x);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;

        //condicion del movimiento del caballo (movimiento en L)
        bool movimiento_valido = (movx == 2 && movy == 1) || (movx == 1 && movy == 2);

        if (movimiento_valido)
        {
            if (caballoB2.pieza_comible(casilla_actual, control) == true)
            {
                if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                {
                    comidasR();
                }
                else
                {
                    comidasB();
                }
            }
            std::cout << "[DEBUG] Moviendo caballoB2 a: " << posicion_central_click.x << ", " << posicion_central_click.y << std::endl;

            caballoB2.muevepieza(posicion_central_click.x, posicion_central_click.y);
            movida = true;
            turno = false;
            std::cout << "Turno de Rojas\n" << std::endl;
        }
        else
        {
            std::cout << "\n Movimiento invalido para el caballo\n" << std::endl;
        }
    }

}

void Mundo::comidasB() {
    std::cout << "Pieza comida" << std::endl;

    // Obtener puntero a la pieza comida
    Pieza* pieza_comida = control[casilla_actual.x - 1][casilla_actual.y - 1];

    // Verificar que no sea nullptr antes de hacer push y moverla
    if (pieza_comida != nullptr) {
        comidaB.push_back(pieza_comida);
        comidaB.back()->muevepieza(pos_comidaB_X, -2); // Mover fuera del tablero
        pos_comidaB_X -= 2.0;
    }
    else {
        std::cerr << "[ERROR] pieza_comida era nullptr" << std::endl;
    }
}


void Mundo::comidasR() { //se añaden las piezas blancas comidas al vector comidaB y se ejecuta el movimiento de la pieza comida a la posicion deseada

    std::cout << "Pieza comida" << std::endl;

    // Añadir la pieza comida al vector
    comidaR.push_back(control[casilla_actual.x - 1][casilla_actual.y - 1]);

    // Mover la pieza a la "zona de piezas comidas"
    comidaR.back()->muevepieza(pos_comidaR_X, -2);  // Y fijo en -2

    // Desplazar la X para la siguiente pieza
    pos_comidaR_X += 2.0;

}



void Mundo::actualizar_matriz_control()
{
    control[casilla_actual.x - 1][casilla_actual.y - 1] = control[casilla_anterior.x - 1][casilla_anterior.y - 1];//actualizan la matriz control en cada movimiento
    control[casilla_anterior.x - 1][casilla_anterior.y - 1] = {};
}

bool Mundo::casilla_Jaque(VECTOR2D from, VECTOR2D to, bool colorRey) { // esta funcion unicamente comprueba si el rey amenazado puede moverse a otra casilla (Vector2D to) sin que siga amenazado
    // Realiza el movimiento temporalmente
    //auto piezaOriginal = control[to.x][to.y]; // guarda el tipo de pieza que hay en la casilla a la que se quiere ir (puede ser casilla en blanco) para luego revertir el cambio
    //control[to.x][to.y] = control[from.x][from.y];
    //control[from.x][from.y] = nullptr;


   // bool enJaque = estaEnJaque(colorRey);


    // Revertir el movimiento
    //control[from.x][from.y] = control[to.x][to.y];
    //control[to.x][to.y] = piezaOriginal;

    return false; //enJaque; // si tras realizar el movimiento con el rey a dicha casilla sigue en jaque, entonces la salida de la funcion ser� false. La matriz de control no sufre cambios
    // esta funcion se llama en la funci�n de estaEnJaqueMate()
}



