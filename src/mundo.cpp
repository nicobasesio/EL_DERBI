#include "mundo.h"
#include "pieza.h"
#include "freeglut.h"
#include <cmath> 


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

Mundo::Mundo() : control(8, std::vector<Pieza*>(8, nullptr))  {}


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
    for (auto* pieza : comidaB)
        pieza->dibuja_pieza();
    for (auto* pieza : comidaR)
        pieza->dibuja_pieza();

}

bool Mundo::casillaValida(int i, int j) {   // Para que no se salga del tamaño de la matriz control 
    return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}

void Mundo::mueve()

{
    auto capturables = piezas_con_captura();
    Pieza* pieza = control[casilla_anterior.x - 1][casilla_anterior.y - 1];

    if (!capturables.empty()) {

        Pieza* pieza_seleccionada = control[casilla_anterior.x - 1][casilla_anterior.y - 1];
        VECTOR2D origen = posicion_central_click_anterior;

        // Verificamos si la pieza seleccionada está entre las obligadas a capturar
        bool es_pieza_capturable = false;
        for (const auto& par : capturables) {
            if (par.first == pieza_seleccionada) {
                es_pieza_capturable = true;
                break;
            }
        }

        if (!es_pieza_capturable) {
            std::cout << "[REGLA] Debes mover una de las piezas obligadas a capturar.\n";
            return;
        }

        // Ahora usamos la pieza seleccionada normalmente
        pieza = pieza_seleccionada;

        std::vector<VECTOR2D> destinos;

        // Si es REY movimiento automático al destino clicado
        if (pieza->es_rey()) {
            std::cout << "[AUTO] Captura unica con rey.\n";
            Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
            if (comida) {
                if (comida->get_color())
                    comidasB();
                else
                    comidasR();
            }
            pieza->muevepieza(posicion_central_click.x, posicion_central_click.y);
            actualizar_matriz_control();
            turno = !turno;
            return;
        }

        // Si es PEÓN lo mismo: captura directa
        if (pieza->es_peon()) {
            std::cout << "[AUTO] Captura unica con peon.\n";
            Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
            if (comida) {
                if (comida->get_color())
                    comidasB();
                else
                    comidasR();
            }
            pieza->muevepieza(posicion_central_click.x, posicion_central_click.y);
            actualizar_matriz_control();
            turno = !turno;
            return;
        }

        // Si es caballo

        if (pieza->es_caballo()) {
            std::cout << "[AUTO] Captura unica con caballo.\n";
            Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
            if (comida) {
                if (comida->get_color())
                    comidasB();
                else
                    comidasR();
            }
            pieza->muevepieza(posicion_central_click.x, posicion_central_click.y);
            actualizar_matriz_control();
            turno = !turno;
            return;
        }

        if (pieza->es_torre()) {
            std::cout << "[AUTO] Captura unica con torre.\n";

            int x = static_cast<int>(round((pieza->posicion_pieza.x + 7.0f) / 2.0f));
            int y = static_cast<int>(round((pieza->posicion_pieza.y - 2.5f) / 2.0f));

            int dx[] = { 0, 0, -1, 1 };
            int dy[] = { -1, 1, 0, 0 };


            std::vector<VECTOR2D> posibles_destinos;

            for (int dir = 0; dir < 4; ++dir) { // evalua todas las direcciones horizontales y verticales
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) { // mientras que no se salga del tablero continua
                    Pieza* objetivo = control[nx][ny];
                    if (objetivo != nullptr) {
                        if (objetivo->get_color() != pieza->get_color()) {
                            float x_mundo = nx * 2.0f - 7.0f;
                            float y_mundo = ny * 2.0f + 2.5f;
                            VECTOR2D destino;
                            destino.x = x_mundo;
                            destino.y = y_mundo;
                            posibles_destinos.push_back(destino);

                        }
                        break;
                    }
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }

            // el clic está en uno de esos destinos válidos
            for (const auto& destino : posibles_destinos) {
                if (std::abs(destino.x - posicion_central_click.x) < 0.1 &&
                    std::abs(destino.y - posicion_central_click.y) < 0.1) {

                    Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
                    if (comida) {
                        if (comida->get_color())
                            comidasB();
                        else
                            comidasR();
                    }

                    pieza->muevepieza(posicion_central_click.x, posicion_central_click.y);
                    actualizar_matriz_control();
                    turno = !turno;
                    return;
                }
            }

            std::cout << "[REGLA] Movimiento no valido para la torre.\n";
            return;
        }

        if (pieza->es_alfil()) {
            std::cout << "[AUTO] Captura unica con alfil.\n";

            int x = static_cast<int>(round((pieza->posicion_pieza.x + 7.0f) / 2.0f));
            int y = static_cast<int>(round((pieza->posicion_pieza.y - 2.5f) / 2.0f));

            int dx[] = { -1, -1, 1, 1 };
            int dy[] = { -1, 1, -1, 1 };

            std::vector<VECTOR2D> posibles_destinos;

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    Pieza* objetivo = control[nx][ny];
                    if (objetivo != nullptr) {
                        if (objetivo->get_color() != pieza->get_color()) {
                            float x_mundo = nx * 2.0f - 7.0f;
                            float y_mundo = ny * 2.0f + 2.5f;
                            VECTOR2D destino;
                            destino.x = x_mundo;
                            destino.y = y_mundo;
                            posibles_destinos.push_back(destino);
                        }
                        break;
                    }
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }

            for (const auto& destino : posibles_destinos) {
                if (std::abs(destino.x - posicion_central_click.x) < 0.1 &&
                    std::abs(destino.y - posicion_central_click.y) < 0.1) {

                    Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
                    if (comida) {
                        if (comida->get_color())
                            comidasB();
                        else
                            comidasR();
                    }

                    pieza->muevepieza(posicion_central_click.x, posicion_central_click.y);
                    actualizar_matriz_control();
                    turno = !turno;
                    return;
                }
            }

            std::cout << "[REGLA] Movimiento no valido para el alfil.\n";
            return;
        }


        if (pieza->es_reina()) {
            std::cout << "[AUTO] Captura unica con reina.\n";

            int x = static_cast<int>(round((pieza->posicion_pieza.x + 7.0f) / 2.0f));
            int y = static_cast<int>(round((pieza->posicion_pieza.y - 2.5f) / 2.0f));

            int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
            int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

            std::vector<VECTOR2D> posibles_destinos;

            for (int dir = 0; dir < 8; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    Pieza* objetivo = control[nx][ny];
                    if (objetivo != nullptr) {
                        if (objetivo->get_color() != pieza->get_color()) {
                            float x_mundo = nx * 2.0f - 7.0f;
                            float y_mundo = ny * 2.0f + 2.5f;
                            VECTOR2D destino;
                            destino.x = x_mundo;
                            destino.y = y_mundo;
                            posibles_destinos.push_back(destino);
                        }
                        break;
                    }
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }

            for (const auto& destino : posibles_destinos) {
                if (std::abs(destino.x - posicion_central_click.x) < 0.1 &&
                    std::abs(destino.y - posicion_central_click.y) < 0.1) {

                    Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
                    if (comida) {
                        if (comida->get_color())
                            comidasB();
                        else
                            comidasR();
                    }

                    pieza->muevepieza(posicion_central_click.x, posicion_central_click.y);
                    actualizar_matriz_control();
                    turno = !turno;
                    return;
                }
            }

            std::cout << "[REGLA] Movimiento no valido para la reina.\n";
            return;
        }

    }

    else
    {
        if (pieza->es_rey()) {
            Rey* rey = dynamic_cast<Rey*>(pieza);
            bool capturo = false;
            if (rey && rey->mover(posicion_central_click, control, capturo)) {
                if (capturo)
                    pieza->get_color() ? comidasB() : comidasR(); // si get color true entonces comidasB si no comidas R
                actualizar_matriz_control();
                turno = !turno;
                movida = true;
            }
            else {
                std::cout << "[REGLA] Movimiento no valido para el rey.\n";
            }
            return;
        }

        if (pieza->es_alfil()) {
            Alfil* alfil = dynamic_cast<Alfil*>(pieza);
            bool capturo = false;
            if (alfil && alfil->mover(posicion_central_click, control, capturo)) {
                if (capturo)
                    pieza->get_color() ? comidasB() : comidasR();
                actualizar_matriz_control();
                turno = !turno;
                movida = true;
            }
            else {
                std::cout << "[REGLA] Movimiento no valido para el alfil.\n";
            }
            return;
        }

        if (pieza->es_peon()) {
            Peon* peon = dynamic_cast<Peon*>(pieza);
            bool capturo = false;
            if (peon && peon->mover(posicion_central_click, control, capturo)) {
                if (capturo)
                    pieza->get_color() ? comidasB() : comidasR();
                actualizar_matriz_control();
                turno = !turno;
                movida = true;
            }
            else {
                std::cout << "[REGLA] Movimiento no valido para el peon.\n";
            }
            return;
        }

        if (pieza->es_torre()) {
            Torre* torre = dynamic_cast<Torre*>(pieza);
            bool capturo = false;
            if (torre && torre->mover(posicion_central_click, control, capturo)) {
                if (capturo)
                    pieza->get_color() ? comidasB() : comidasR();
                actualizar_matriz_control();
                turno = !turno;
                movida = true;
            }
            else {
                std::cout << "[REGLA] Movimiento no valido para la torre.\n";
            }
            return;
        }

        if (pieza->es_reina()) {
            Reina* reina = dynamic_cast<Reina*>(pieza);
            bool capturo = false;
            if (reina && reina->mover(posicion_central_click, control, capturo)) {
                if (capturo)
                    pieza->get_color() ? comidasB() : comidasR();
                actualizar_matriz_control();
                turno = !turno;
                movida = true;
            }
            else {
                std::cout << "[REGLA] Movimiento no valido para la reina.\n";
            }
            return;
        }

        if (pieza->es_caballo()) {
            Caballo* caballo = dynamic_cast<Caballo*>(pieza);
            bool capturo = false;
            if (caballo && caballo->mover(posicion_central_click, control, capturo)) {
                if (capturo)
                    pieza->get_color() ? comidasB() : comidasR();
                actualizar_matriz_control();
                turno = !turno;
                movida = true;
            }
            else {
                std::cout << "[REGLA] Movimiento no valido para el caballo.\n";
            }
            return;
        }


    }

}



void Mundo::comidasB() {
    std::cout << "Pieza comida" << std::endl;

    Pieza* pieza_comida = control[casilla_actual.x - 1][casilla_actual.y - 1];

    if (pieza_comida != nullptr) {
        comidaB.push_back(pieza_comida);
        comidaB.back()->muevepieza(pos_comidaB_X, -4);
        pos_comidaB_X -= 1.0;
    }
    else {
        std::cerr << "[ERROR] pieza comida era nullptr" << std::endl;
    }
}



void Mundo::comidasR() {
    std::cout << "Pieza comida" << std::endl;

    Pieza* pieza_comida = control[casilla_actual.x - 1][casilla_actual.y - 1];

    if (pieza_comida != nullptr) {
        comidaR.push_back(pieza_comida);
        comidaR.back()->muevepieza(pos_comidaR_X, -2);
        pos_comidaR_X += 1.0;
    }
    else {
        std::cerr << "[ERROR] pieza comida era nullptr" << std::endl;
    }
}

void Mundo::actualizar_matriz_control()
{
    control[casilla_actual.x - 1][casilla_actual.y - 1] = control[casilla_anterior.x - 1][casilla_anterior.y - 1];//actualizan la matriz control en cada movimiento
    control[casilla_anterior.x - 1][casilla_anterior.y - 1] = nullptr;
}



std::vector<std::pair<Pieza*, VECTOR2D>> Mundo::piezas_con_captura() { // el pair es para empaquetar dos valores
    std::vector<std::pair<Pieza*, VECTOR2D>> lista;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Pieza* p = control[i][j];
            if (p != nullptr && p->get_color() == turno) { // si hay pieza y la pizea que hay es del color adecuado
                VECTOR2D pos = p->posicion_pieza;  // posicion de la pieza
                if (p->puede_comer_enemigo(pos, control)) {  //funcion interna de cada pieza para ver si hay un enemigo comible, si lo hay devuelve true, se pasa control para saber las posiciones de las piezas en el tablero
                    std::cout << "[INFO] Pieza en coordenadas físicas (" << pos.x << "," << pos.y << ") puede capturar\n";
                    lista.push_back(std::make_pair(p, pos)); //aumentamos el vector
                }
            }
        }
    }
    return lista;
}
