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
    reinaR.set_pos_pieza({ -1,16.5 });


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
    if (posicion_central_click_anterior.x == reyB.posicion_pieza.x && posicion_central_click_anterior.y == reyB.posicion_pieza.y && turno==true) //si seleccionas el rey blanco y es su turno, entonces:
    {

        int movx = std::abs(reyB.posicion_pieza.x - posicion_central_click.x); // distancia entre la posicion del rey y la del click del movimiento
        int movy = std::abs(reyB.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;


        if (movx <= 2 && movy <= 2 && !(movx == 0 && movy == 0)) // si el movimiento es de una casilla
        {
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

    }

        
            
    
    
     

    //movimiento reyR
    if (posicion_central_click_anterior.x == reyR.posicion_pieza.x && posicion_central_click_anterior.y == reyR.posicion_pieza.y && turno == false) //si seleccionas el rey blanco y es su turno, entonces:
    {

        int movx = std::abs(reyR.posicion_pieza.x - posicion_central_click.x); // distancia entre la posicion del rey y la del click del movimiento
        int movy = std::abs(reyR.posicion_pieza.y - posicion_central_click.y);


        if (movx <= 2 && movy <= 2 && !(movx == 0 && movy == 0)) // si el movimiento es de una casilla
        { 
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

    }

    

    // movimiento torreB1
    if (posicion_central_click_anterior.x == torreB1.posicion_pieza.x &&
        posicion_central_click_anterior.y == torreB1.posicion_pieza.y &&
        turno == true)
    {
        std::cout << "[DEBUG] torreB1 seleccionada\n";

        int dx = static_cast<int>(posicion_central_click.x - torreB1.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - torreB1.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);

        // Conversión de coordenadas del mundo (-7, ..., 7 y 2.5, ..., 16.5) a índices 0-7
        int ix1 = static_cast<int>((torreB1.posicion_pieza.x + 8.0) / 2.0);
        int iy1 = static_cast<int>((torreB1.posicion_pieza.y - 1.0) / 2.0);
        int ix2 = static_cast<int>((posicion_central_click.x + 8.0) / 2.0);
        int iy2 = static_cast<int>((posicion_central_click.y - 1.0) / 2.0);

        // Validación de rango antes de usar
        if (ix1 < 0 || ix1 > 7 || iy1 < 0 || iy1 > 7 ||
            ix2 < 0 || ix2 > 7 || iy2 < 0 || iy2 > 7)
        {
            std::cout << "[ERROR] Movimiento fuera del tablero (índices inválidos)\n";
            return;
        }

        if ((movx == 0 || movy == 0) && !(movx == 0 && movy == 0)) {
            std::cout << "[DEBUG] Movimiento válido en línea recta\n";
            bool trayectoria_libre = true;

            if (movx == 0) {
                int paso = (iy2 > iy1) ? 1 : -1;
                for (int y = iy1 + paso; y != iy2; y += paso) {
                    if (control[ix1][y] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << ix1 << ", " << y << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }
            else {
                int paso = (ix2 > ix1) ? 1 : -1;
                for (int x = ix1 + paso; x != ix2; x += paso) {
                    if (control[x][iy1] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << x << ", " << iy1 << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }

            if (trayectoria_libre) {
                std::cout << "[DEBUG] Trayectoria libre, moviendo\n";

                if (control[ix2][iy2] != nullptr) {
                    if (control[ix2][iy2]->get_color() == false)
                        comidasR();
                    else
                        comidasB();
                }

                torreB1.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = false;
                std::cout << "Turno de Rojas\n";
            }
            else {
                std::cout << "[INFO] Movimiento bloqueado por otra pieza\n";
            }
        }
        else {
            std::cout << "[INFO] Movimiento inválido: no es línea recta\n";
        }
    }
    // movimiento torreB2
    if (posicion_central_click_anterior.x == torreB2.posicion_pieza.x &&
        posicion_central_click_anterior.y == torreB2.posicion_pieza.y &&
        turno == true)
    {
        std::cout << "[DEBUG] torreB2 seleccionada\n";

        int dx = static_cast<int>(posicion_central_click.x - torreB2.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - torreB2.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);

        int ix1 = static_cast<int>((torreB2.posicion_pieza.x + 8.0) / 2.0);
        int iy1 = static_cast<int>((torreB2.posicion_pieza.y - 1.0) / 2.0);
        int ix2 = static_cast<int>((posicion_central_click.x + 8.0) / 2.0);
        int iy2 = static_cast<int>((posicion_central_click.y - 1.0) / 2.0);

        if (ix1 < 0 || ix1 > 7 || iy1 < 0 || iy1 > 7 ||
            ix2 < 0 || ix2 > 7 || iy2 < 0 || iy2 > 7)
        {
            std::cout << "[ERROR] Movimiento fuera del tablero (índices inválidos)\n";
            return;
        }

        if ((movx == 0 || movy == 0) && !(movx == 0 && movy == 0)) {
            std::cout << "[DEBUG] Movimiento válido en línea recta\n";
            bool trayectoria_libre = true;

            if (movx == 0) {
                int paso = (iy2 > iy1) ? 1 : -1;
                for (int y = iy1 + paso; y != iy2; y += paso) {
                    if (control[ix1][y] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << ix1 << ", " << y << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }
            else {
                int paso = (ix2 > ix1) ? 1 : -1;
                for (int x = ix1 + paso; x != ix2; x += paso) {
                    if (control[x][iy1] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << x << ", " << iy1 << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }

            if (trayectoria_libre) {
                std::cout << "[DEBUG] Trayectoria libre, moviendo\n";

                if (control[ix2][iy2] != nullptr) {
                    if (control[ix2][iy2]->get_color() == false)
                        comidasR();
                    else
                        comidasB();
                }

                torreB2.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = false;
                std::cout << "Turno de Rojas\n";
            }
            else {
                std::cout << "[INFO] Movimiento bloqueado por otra pieza\n";
            }
        }
        else {
            std::cout << "[INFO] Movimiento inválido: no es línea recta\n";
        }
    }
    // movimiento torreR1
    if (posicion_central_click_anterior.x == torreR1.posicion_pieza.x &&
        posicion_central_click_anterior.y == torreR1.posicion_pieza.y &&
        turno == false)
    {
        std::cout << "[DEBUG] torreR1 seleccionada\n";

        int dx = static_cast<int>(posicion_central_click.x - torreR1.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - torreR1.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);

        int ix1 = static_cast<int>((torreR1.posicion_pieza.x + 8.0) / 2.0);
        int iy1 = static_cast<int>((torreR1.posicion_pieza.y - 1.0) / 2.0);
        int ix2 = static_cast<int>((posicion_central_click.x + 8.0) / 2.0);
        int iy2 = static_cast<int>((posicion_central_click.y - 1.0) / 2.0);

        if (ix1 < 0 || ix1 > 7 || iy1 < 0 || iy1 > 7 ||
            ix2 < 0 || ix2 > 7 || iy2 < 0 || iy2 > 7)
        {
            std::cout << "[ERROR] Movimiento fuera del tablero (índices inválidos)\n";
            return;
        }

        if ((movx == 0 || movy == 0) && !(movx == 0 && movy == 0)) {
            std::cout << "[DEBUG] Movimiento válido en línea recta\n";
            bool trayectoria_libre = true;

            if (movx == 0) {
                int paso = (iy2 > iy1) ? 1 : -1;
                for (int y = iy1 + paso; y != iy2; y += paso) {
                    if (control[ix1][y] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << ix1 << ", " << y << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }
            else {
                int paso = (ix2 > ix1) ? 1 : -1;
                for (int x = ix1 + paso; x != ix2; x += paso) {
                    if (control[x][iy1] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << x << ", " << iy1 << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }

            if (trayectoria_libre) {
                std::cout << "[DEBUG] Trayectoria libre, moviendo\n";

                if (control[ix2][iy2] != nullptr) {
                    if (control[ix2][iy2]->get_color() == true)
                        comidasB();
                    else
                        comidasR();
                }

                torreR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = true;
                std::cout << "Turno de Blancas\n";
            }
            else {
                std::cout << "[INFO] Movimiento bloqueado por otra pieza\n";
            }
        }
        else {
            std::cout << "[INFO] Movimiento inválido: no es línea recta\n";
        }
    }
    // movimiento torreR2
    if (posicion_central_click_anterior.x == torreR2.posicion_pieza.x &&
        posicion_central_click_anterior.y == torreR2.posicion_pieza.y &&
        turno == false)
    {
        std::cout << "[DEBUG] torreR2 seleccionada\n";

        int dx = static_cast<int>(posicion_central_click.x - torreR2.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - torreR2.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);

        int ix1 = static_cast<int>((torreR2.posicion_pieza.x + 8.0) / 2.0);
        int iy1 = static_cast<int>((torreR2.posicion_pieza.y - 1.0) / 2.0);
        int ix2 = static_cast<int>((posicion_central_click.x + 8.0) / 2.0);
        int iy2 = static_cast<int>((posicion_central_click.y - 1.0) / 2.0);

        if (ix1 < 0 || ix1 > 7 || iy1 < 0 || iy1 > 7 ||
            ix2 < 0 || ix2 > 7 || iy2 < 0 || iy2 > 7)
        {
            std::cout << "[ERROR] Movimiento fuera del tablero (índices inválidos)\n";
            return;
        }

        if ((movx == 0 || movy == 0) && !(movx == 0 && movy == 0)) {
            std::cout << "[DEBUG] Movimiento válido en línea recta\n";
            bool trayectoria_libre = true;

            if (movx == 0) {
                int paso = (iy2 > iy1) ? 1 : -1;
                for (int y = iy1 + paso; y != iy2; y += paso) {
                    if (control[ix1][y] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << ix1 << ", " << y << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }
            else {
                int paso = (ix2 > ix1) ? 1 : -1;
                for (int x = ix1 + paso; x != ix2; x += paso) {
                    if (control[x][iy1] != nullptr) {
                        std::cout << "[DEBUG] Obstrucción en (" << x << ", " << iy1 << ")\n";
                        trayectoria_libre = false;
                        break;
                    }
                }
            }

            if (trayectoria_libre) {
                std::cout << "[DEBUG] Trayectoria libre, moviendo\n";

                if (control[ix2][iy2] != nullptr) {
                    if (control[ix2][iy2]->get_color() == true)
                        comidasB();
                    else
                        comidasR();
                }

                torreR2.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = true;
                std::cout << "Turno de Blancas\n";
            }
            else {
                std::cout << "[INFO] Movimiento bloqueado por otra pieza\n";
            }
        }
        else {
            std::cout << "[INFO] Movimiento inválido: no es línea recta\n";
        }

    }

    
    //movimiento peonB1
    if (posicion_central_click_anterior.x == peonB1.posicion_pieza.x && posicion_central_click_anterior.y == peonB1.posicion_pieza.y&& turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB1.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB1.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB1.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB1.muevepieza(posicion_central_click.x,posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB1.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

   
    // movimiento peonB2
    if (posicion_central_click_anterior.x == peonB2.posicion_pieza.x && posicion_central_click_anterior.y == peonB2.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB2.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB2.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB2.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB2.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB2.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonB3
    if (posicion_central_click_anterior.x == peonB3.posicion_pieza.x && posicion_central_click_anterior.y == peonB3.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB3.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB3.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB3.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB3.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB3.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonB4
    if (posicion_central_click_anterior.x == peonB4.posicion_pieza.x && posicion_central_click_anterior.y == peonB4.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB4.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB4.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB4.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB4.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB4.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonB5
    if (posicion_central_click_anterior.x == peonB5.posicion_pieza.x && posicion_central_click_anterior.y == peonB5.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB5.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB5.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB5.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB5.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB5.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonB6
    if (posicion_central_click_anterior.x == peonB6.posicion_pieza.x && posicion_central_click_anterior.y == peonB6.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB6.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB6.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB1.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB6.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB6.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonB7
    if (posicion_central_click_anterior.x == peonB7.posicion_pieza.x && posicion_central_click_anterior.y == peonB7.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB7.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB7.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB7.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB7.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB7.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonB8
    if (posicion_central_click_anterior.x == peonB8.posicion_pieza.x && posicion_central_click_anterior.y == peonB8.posicion_pieza.y && turno == true)  // peón blanco seleccionado y es turno de blancas
    {
        // 1) desplazamientos en unidades de casilla
        int dx = static_cast<int>(posicion_central_click.x - peonB8.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonB8.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

        // 2) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 3) validar dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 4a) avance simple: misma columna, un paso adelante
        bool avance_simple = (dx == 0 && dy == 2);

        // 4b) doble avance: fila inicial (srcY == 2), dos pasos, y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == 4 && srcY == 2) {
            int iy_inter = iy - 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr
                && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 4c) captura diagonal: solo hacia adelante (dy == 2)
        //    y un paso a la derecha (dx ==  2) o izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == 2) {
            if (peonB8.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 5) ejecutar jugada
        if (avance_simple || avance_doble) {
            peonB8.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                // registrar la captura
                if (target->get_color() == false)
                    comidasR();
                else
                    comidasB();
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

            peonB8.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else {
            std::cout << "Movimiento inválido: el peón solo puede avanzar hacia delante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        actualizar_matriz_control();
        movida = true;
        turno = false;  // turno de las rojas
        std::cout << "Turno de Rojas\n";
    }

     //movimiento peonR1
    if (posicion_central_click_anterior.x == peonR1.posicion_pieza.x && posicion_central_click_anterior.y == peonR1.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR1.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR1.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR1.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }



     //movimiento peonR2
    if (posicion_central_click_anterior.x == peonR2.posicion_pieza.x && posicion_central_click_anterior.y == peonR2.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR2.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR2.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR2.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR2.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     //movimiento peonR3
    if (posicion_central_click_anterior.x == peonR3.posicion_pieza.x && posicion_central_click_anterior.y == peonR3.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR3.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR3.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR3.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR3.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     //movimiento peonR4
    if (posicion_central_click_anterior.x == peonR4.posicion_pieza.x && posicion_central_click_anterior.y == peonR4.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR4.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR4.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR4.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR4.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     //movimiento peonR5
    if (posicion_central_click_anterior.x == peonR5.posicion_pieza.x && posicion_central_click_anterior.y == peonR5.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR5.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR5.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR5.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR5.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     //movimiento peonR6
    if (posicion_central_click_anterior.x == peonR6.posicion_pieza.x && posicion_central_click_anterior.y == peonR6.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR6.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR6.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR6.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR6.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     //movimiento peonR7
    if (posicion_central_click_anterior.x == peonR7.posicion_pieza.x && posicion_central_click_anterior.y == peonR7.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR7.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR7.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR7.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR7.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     //movimiento peonR8
    if (posicion_central_click_anterior.x == peonR8.posicion_pieza.x && posicion_central_click_anterior.y == peonR8.posicion_pieza.y && turno == false)  // peón rojo seleccionado y es turno de las rojas
    {
        // 1) filtro de clic dentro del tablero (1..8)
        if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
            casilla_actual.y < 1 || casilla_actual.y > 8) {
            return;
        }

        // 2) cálculo de desplazamiento en “casillas” (dx, dy)
        int dx = static_cast<int>(posicion_central_click.x - peonR8.posicion_pieza.x);
        int dy = static_cast<int>(posicion_central_click.y - peonR8.posicion_pieza.y);
        int movx = std::abs(dx);
        int movy = std::abs(dy);
        std::cout << "[DEBUG] movx=" << movx << ", movy=" << movy << std::endl;

        // 3) índices destino en la matriz (0..7)
        int ix = casilla_actual.x - 1;
        int iy = casilla_actual.y - 1;
        int srcY = casilla_anterior.y;  // fila origen 0..7

        // 4) validar que destino esté dentro del tablero
        if (!casillaValida(ix, iy)) {
            std::cout << "Movimiento inválido: fuera del tablero\n";
            return;
        }

        // 5a) avance simple: misma columna, un paso “adelante” (dy == –2)
        bool avance_simple = (dx == 0 && dy == -2);

        // 5b) doble avance: fila inicial (srcY == 7), dos pasos (dy == –4) y casillas libres
        bool avance_doble = false;
        if (dx == 0 && dy == -4 && srcY == 7) {
            int iy_inter = iy + 1;
            if (casillaValida(ix, iy_inter)
                && control[ix][iy_inter] == nullptr && control[ix][iy] == nullptr)
            {
                avance_doble = true;
            }
        }

        // 5c) captura diagonal: sólo hacia “adelante” (dy == –2)
        //     y un paso a la derecha  (dx ==  2)
        //     o un paso a la izquierda (dx == -2)
        bool captura_diagonal = false;
        if ((dx == 2 || dx == -2) && dy == -2) {
            if (peonR8.pieza_comible(casilla_actual, control)) {
                captura_diagonal = true;
            }
        }

        // 6) ejecutar la jugada válida
        if (avance_simple || avance_doble) {
            peonR8.muevepieza(posicion_central_click.x, posicion_central_click.y);
        }
        else if (captura_diagonal) {
            Pieza* target = control[ix][iy];
            if (target != nullptr) {
                if (target->get_color() == false)
                    comidasR();  // captura pieza blanca
                else
                    comidasB();  // caso excepcional
                peonR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            }
            else {
                std::cout << "Movimiento inválido: no hay pieza para capturar\n";
                return;
            }

        }
        else {
            std::cout << "Movimiento inválido: el peón sólo puede avanzar hacia adelante\n"
                << "o capturar en diagonal adelante (derecha o izquierda)\n";
            return;
        }

        // 7) actualizar tablero y cambiar turno
        actualizar_matriz_control();
        movida = true;
        turno = true;   // ahora juegan las blancas
        std::cout << "Turno de Blancas\n";
    }

     
     // movimiento alfilB1
     if (posicion_central_click_anterior.x == alfilB1.posicion_pieza.x && posicion_central_click_anterior.y == alfilB1.posicion_pieza.y && turno == true)  // turno de blancas
     {
         // filtro de clic dentro del tablero
         if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
             casilla_actual.y < 1 || casilla_actual.y > 8) {
             return;
         }

         // 1) cálculo de desplazamiento
         int dx = static_cast<int>(posicion_central_click.x - alfilB1.posicion_pieza.x);
         int dy = static_cast<int>(posicion_central_click.y - alfilB1.posicion_pieza.y);
         int movx = std::abs(dx);
         int movy = std::abs(dy);
         std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

         // 2) índices destino (0..7)
         int ix = casilla_actual.x - 1;
         int iy = casilla_actual.y - 1;

         // 3) comprobación de tablero
         if (!casillaValida(ix, iy)) {
             std::cout << "Movimiento inválido: fuera del tablero\n";
             return;
         }

         // 4) sólo diagonal estricta (cualquier dirección)
         bool es_diagonal = (movx == movy && movx > 0);

         // 5) ejecutar movimiento o captura sin validar ruta
         if (es_diagonal) {
             Pieza* destino = control[ix][iy];
             if (destino == nullptr) {
                 // casilla vacía
                 alfilB1.muevepieza(posicion_central_click.x,
                     posicion_central_click.y);
             }
             else if (alfilB1.pieza_comible(casilla_actual, control)) {
                 // captura enemiga
                 if (destino->get_color() == false)
                     comidasR();  // comes pieza roja
                 else
                     comidasB();  // caso excepcional
                 alfilB1.muevepieza(posicion_central_click.x,
                     posicion_central_click.y);
             }
             else {
                 std::cout << "Movimiento inválido: no puedes capturar tu propia pieza\n";
                 return;
             }
         }
         else {
             std::cout << "Movimiento inválido: el alfil se mueve solo en diagonal\n";
             return;
         }

         // 6) actualizar y cambiar turno
         actualizar_matriz_control();
         movida = true;
         turno = false;  // turno de rojas
         std::cout << "Turno de Rojas\n";
     }


     // movimiento alfilB2
     if (posicion_central_click_anterior.x == alfilB2.posicion_pieza.x && posicion_central_click_anterior.y == alfilB2.posicion_pieza.y && turno == true)  // turno de blancas
     {
         // filtro de clic dentro del tablero
         if (casilla_actual.x < 1 || casilla_actual.x > 8 ||
             casilla_actual.y < 1 || casilla_actual.y > 8) {
             return;
         }

         // 1) cálculo de desplazamiento
         int dx = static_cast<int>(posicion_central_click.x - alfilB2.posicion_pieza.x);
         int dy = static_cast<int>(posicion_central_click.y - alfilB2.posicion_pieza.y);
         int movx = std::abs(dx);
         int movy = std::abs(dy);
         std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

         // 2) índices destino (0..7)
         int ix = casilla_actual.x - 1;
         int iy = casilla_actual.y - 1;

         // 3) comprobación de tablero
         if (!casillaValida(ix, iy)) {
             std::cout << "Movimiento inválido: fuera del tablero\n";
             return;
         }

         // 4) sólo diagonal estricta (cualquier dirección)
         bool es_diagonal = (movx == movy && movx > 0);

         // 5) ejecutar movimiento o captura sin validar ruta
         if (es_diagonal) {
             Pieza* destino = control[ix][iy];
             if (destino == nullptr) {
                 // casilla vacía
                 alfilB2.muevepieza(posicion_central_click.x, posicion_central_click.y);
             }
             else if (alfilB2.pieza_comible(casilla_actual, control)) {
                 // captura enemiga
                 if (destino->get_color() == false)
                     comidasR();  // comes pieza roja
                 else
                     comidasB();  // caso excepcional
                 alfilB2.muevepieza(posicion_central_click.x, posicion_central_click.y);
             }
             else {
                 std::cout << "Movimiento inválido: no puedes capturar tu propia pieza\n";
                 return;
             }
         }
         else {
             std::cout << "Movimiento inválido: el alfil se mueve solo en diagonal\n";
             return;
         }

         // 6) actualizar y cambiar turno
         actualizar_matriz_control();
         movida = true;
         turno = false;  // turno de rojas
         std::cout << "Turno de Rojas\n";
     }
     
     // movimiento alfilR1 
     if (posicion_central_click_anterior.x == alfilR1.posicion_pieza.x && posicion_central_click_anterior.y == alfilR1.posicion_pieza.y && turno == false)  // alfil rojo seleccionado y es turno de las rojas
     {
         // filtro de clic dentro del tablero
         if (casilla_actual.x < 1 || casilla_actual.x > 8 ||casilla_actual.y < 1 || casilla_actual.y > 8) {
             return;
         }

         // 1) cálculo de desplazamiento
         int dx = static_cast<int>(posicion_central_click.x - alfilR1.posicion_pieza.x);
         int dy = static_cast<int>(posicion_central_click.y - alfilR1.posicion_pieza.y);
         int movx = std::abs(dx);
         int movy = std::abs(dy);
         std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

         // 2) índices destino (0..7)
         int ix = casilla_actual.x - 1;
         int iy = casilla_actual.y - 1;

         // 3) comprobación de tablero
         if (!casillaValida(ix, iy)) {
             std::cout << "Movimiento inválido: fuera del tablero\n";
             return;
         }

         // 4) sólo diagonal estricta (cualquier dirección)
         bool es_diagonal = (movx == movy && movx > 0);

         // 5) ejecutar movimiento o captura sin validar ruta
         if (es_diagonal) {
             Pieza* destino = control[ix][iy];
             if (destino == nullptr) {
                 // casilla vacía
                 alfilR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
             }
             else if (alfilR1.pieza_comible(casilla_actual, control)) {
                 // captura enemiga
                 if (destino->get_color() == true)
                     comidasB();  // comes pieza blanca
                 else
                     comidasR();  // caso excepcional
                 alfilR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
             }
             else {
                 std::cout << "Movimiento inválido: no puedes capturar tu propia pieza\n";
                 return;
             }
         }
         else {
             std::cout << "Movimiento inválido: el alfil se mueve solo en diagonal\n";
             return;
         }

         // 6) actualizar y cambiar turno
         actualizar_matriz_control();
         movida = true;
         turno = true;   // ahora juegan las blancas
         std::cout << "Turno de Blancas\n";
     }

     // movimiento alfilR1 
     if (posicion_central_click_anterior.x == alfilR2.posicion_pieza.x && posicion_central_click_anterior.y == alfilR2.posicion_pieza.y && turno == false)  // alfil rojo seleccionado y es turno de las rojas
     {
         // filtro de clic dentro del tablero
         if (casilla_actual.x < 1 || casilla_actual.x > 8 || casilla_actual.y < 1 || casilla_actual.y > 8) {
             return;
         }

         // 1) cálculo de desplazamiento
         int dx = static_cast<int>(posicion_central_click.x - alfilR2.posicion_pieza.x);
         int dy = static_cast<int>(posicion_central_click.y - alfilR2.posicion_pieza.y);
         int movx = std::abs(dx);
         int movy = std::abs(dy);
         std::cout << "[DEBUG] movx: " << movx << ", movy: " << movy << std::endl;

         // 2) índices destino (0..7)
         int ix = casilla_actual.x - 1;
         int iy = casilla_actual.y - 1;

         // 3) comprobación de tablero
         if (!casillaValida(ix, iy)) {
             std::cout << "Movimiento inválido: fuera del tablero\n";
             return;
         }

         // 4) sólo diagonal estricta (cualquier dirección)
         bool es_diagonal = (movx == movy && movx > 0);

         // 5) ejecutar movimiento o captura sin validar ruta
         if (es_diagonal) {
             Pieza* destino = control[ix][iy];
             if (destino == nullptr) {
                 // casilla vacía
                 alfilR2.muevepieza(posicion_central_click.x, posicion_central_click.y);
             }
             else if (alfilR2.pieza_comible(casilla_actual, control)) {
                 // captura enemiga
                 if (destino->get_color() == true)
                     comidasB();  // comes pieza blanca
                 else
                     comidasR();  // caso excepcional
                 alfilR2.muevepieza(posicion_central_click.x, posicion_central_click.y);
             }
             else {
                 std::cout << "Movimiento inválido: no puedes capturar tu propia pieza\n";
                 return;
             }
         }
         else {
             std::cout << "Movimiento inválido: el alfil se mueve solo en diagonal\n";
             return;
         }

         // 6) actualizar y cambiar turno
         actualizar_matriz_control();
         movida = true;
         turno = true;   // ahora juegan las blancas
         std::cout << "Turno de Blancas\n";
     }

    //movimiento caballo blanco1 
    if (posicion_central_click_anterior.x == caballoB1.posicion_pieza.x && posicion_central_click_anterior.y == caballoB1.posicion_pieza.y && turno == true)
    {
        int movx = std::abs(caballoB1.posicion_pieza.x - posicion_central_click.x);
        int movy = std::abs(caballoB1.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;

        if ((movx == 4 && movy == 2) || (movx == 2 && movy == 4))
        {
            if (caballoB1.pieza_comible(casilla_actual, control) == true)
            {
                std::cout << "[DEBUG] pieza comible " << std::endl;
                if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr && control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                {
                    comidasR();
                    std::cout << "[DEBUG] comida roja " << std::endl;
                }
                else
                {
                    comidasB();
                    std::cout << "[DEBUG] comida blanca " << std::endl;
                }
            }
            std::cout << "[DEBUG] Moviendo caballoB1 a: " << posicion_central_click.x << ", " << posicion_central_click.y << std::endl;

            caballoB1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            actualizar_matriz_control();
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
        int movy = std::abs(caballoB2.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;

       

        if ((movx == 2 && movy == 4) || (movx == 4 && movy == 2))
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
            actualizar_matriz_control();
            movida = true;
            turno = false;
            std::cout << "Turno de Rojas\n" << std::endl;
        }
        else
        {
            std::cout << "\n Movimiento invalido para el caballo\n" << std::endl;
        }
    }

    //movimiento de caballoR1
    if (posicion_central_click_anterior.x == caballoR1.posicion_pieza.x && posicion_central_click_anterior.y == caballoR1.posicion_pieza.y && turno == false)
    {
        int movx = std::abs(caballoR1.posicion_pieza.x - posicion_central_click.x);
        int movy = std::abs(caballoR1.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;

        if ((movx == 2 && movy == 4) || (movx == 4 && movy == 2))
        {
            if (caballoR1.pieza_comible(casilla_actual, control) == true)
            {
                if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr &&
                    control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == true)
                {
                    comidasB();
                }
                else
                {
                    comidasR();
                }
            }

            std::cout << "[DEBUG] Moviendo caballoR1 a: " << posicion_central_click.x << ", " << posicion_central_click.y << std::endl;

            caballoR1.muevepieza(posicion_central_click.x, posicion_central_click.y);
            actualizar_matriz_control();
            movida = true;
            turno = true;
            std::cout << "Turno de Blancas\n" << std::endl;
        }
        else
        {
            std::cout << "\n Movimiento invalido para el caballo\n" << std::endl;
        }
    }

    //movimiento de caballoR2

    if (posicion_central_click_anterior.x == caballoR2.posicion_pieza.x &&
        posicion_central_click_anterior.y == caballoR2.posicion_pieza.y &&
        turno == false)
    {
        int movx = std::abs(caballoR2.posicion_pieza.x - posicion_central_click.x);
        int movy = std::abs(caballoR2.posicion_pieza.y - posicion_central_click.y);
        std::cout << "[DEBUG] movx: " << movx << std::endl;
        std::cout << "[DEBUG] movy: " << movy << std::endl;

        if ((movx == 2 && movy == 4) || (movx == 4 && movy == 2))
        {
            if (caballoR2.pieza_comible(casilla_actual, control) == true)
            {
                if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr &&control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == true)
                {
                    std::cout << "caballo comiendo blanco"<<std::endl;
                    comidasB();
                }
                else
                {
                    std::cout << "caballo comiendo" << std::endl;
                    comidasR();
                }
            }

            std::cout << "[DEBUG] Moviendo caballoR2 a: " << posicion_central_click.x << ", " << posicion_central_click.y << std::endl;

            caballoR2.muevepieza(posicion_central_click.x, posicion_central_click.y);
            actualizar_matriz_control();
            movida = true;
            turno = true;
            std::cout << "Turno de Blancas\n" << std::endl;
        }
        else
        {
            std::cout << "\n Movimiento invalido para el caballo\n" << std::endl;
        }
    }


    // Movimiento reinaB
    if (posicion_central_click_anterior.x == reinaB.posicion_pieza.x &&
        posicion_central_click_anterior.y == reinaB.posicion_pieza.y && turno == true)
    {
        int dx = posicion_central_click.x - reinaB.posicion_pieza.x;
        int dy = posicion_central_click.y - reinaB.posicion_pieza.y;

        int abs_dx = std::abs(dx);
        int abs_dy = std::abs(dy);

        bool movimiento_valido = (dx == 0 || dy == 0 || abs_dx == abs_dy);

        if (movimiento_valido)
        {
            
            
                if (reinaB.pieza_comible(casilla_actual, control))
                {
                    if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr &&
                        control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == false)
                    {
                        comidasR();
                    }
                    else
                    {
                        comidasB();
                    }
                }

                reinaB.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = false;
                std::cout << "Turno de rojas\n";
        }
    }

    // Movimiento reinaR
    if (posicion_central_click_anterior.x == reinaR.posicion_pieza.x &&
        posicion_central_click_anterior.y == reinaR.posicion_pieza.y && turno == false)
    {
        int dx = posicion_central_click.x - reinaR.posicion_pieza.x;
        int dy = posicion_central_click.y - reinaR.posicion_pieza.y;

        int abs_dx = std::abs(dx);
        int abs_dy = std::abs(dy);

        bool movimiento_valido = (dx == 0 || dy == 0 || abs_dx == abs_dy);

        if (movimiento_valido)
        {
                if (reinaR.pieza_comible(casilla_actual, control))
                {
                    if (control[casilla_actual.x - 1][casilla_actual.y - 1] != nullptr &&
                        control[casilla_actual.x - 1][casilla_actual.y - 1]->get_color() == true)
                    {
                        comidasB();
                    }
                    else
                    {
                        comidasR();
                    }
                }

                reinaR.muevepieza(posicion_central_click.x, posicion_central_click.y);
                actualizar_matriz_control();
                movida = true;
                turno = true;
                std::cout << "Turno de rojas\n";
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

    // Obtener puntero a la pieza comida
    Pieza* pieza_comida = control[casilla_actual.x - 1][casilla_actual.y - 1];

    // Verificar que no sea nullptr antes de hacer push y moverla
    if (pieza_comida != nullptr) {
        comidaR.push_back(pieza_comida);
        comidaR.back()->muevepieza(pos_comidaB_X, -2); // Mover fuera del tablero
        pos_comidaR_X += 2.0;
    }
    else {
        std::cerr << "[ERROR] pieza_comida era nullptr" << std::endl;
    }

}



void Mundo::actualizar_matriz_control()
{
    control[casilla_actual.x - 1][casilla_actual.y - 1] = control[casilla_anterior.x - 1][casilla_anterior.y - 1];//actualizan la matriz control en cada movimiento
    control[casilla_anterior.x - 1][casilla_anterior.y - 1] = {};
}




