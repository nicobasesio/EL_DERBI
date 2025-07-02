#include "mundo.h"
#include "pieza.h"
#include "freeglut.h"
#include <cmath> 
#include "efectos.h"

// Se crea una matriz con el contenido inicial de cada casilla del tablero. En el momento de mover la ficha, se actualiza la información
   //std::vector<std::vector<Pieza>> control(8, std::vector<Pieza>(8));  // columnas, filas

float anguloAnimacion = 0.0f;
extern EfectoEspecial efectoEspecial;


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
    
    //Para mejorar la nítidez de las piezas
    auto tB = ETSIDI::getTexture("imagenes/caballoB.png");
    glBindTexture(GL_TEXTURE_2D, tB.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    auto tR = ETSIDI::getTexture("imagenes/caballoR.png");
    glBindTexture(GL_TEXTURE_2D, tR.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    auto tTB = ETSIDI::getTexture("imagenes/torreB.png");
    glBindTexture(GL_TEXTURE_2D, tTB.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tTR = ETSIDI::getTexture("imagenes/torreR.png");
    glBindTexture(GL_TEXTURE_2D, tTR.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tAB = ETSIDI::getTexture("imagenes/alfilB.png");
    glBindTexture(GL_TEXTURE_2D, tAB.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tAR = ETSIDI::getTexture("imagenes/alfilR.png");
    glBindTexture(GL_TEXTURE_2D, tAR.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tPB = ETSIDI::getTexture("imagenes/peonB.png");
    glBindTexture(GL_TEXTURE_2D, tPB.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tPR = ETSIDI::getTexture("imagenes/peonR.png");
    glBindTexture(GL_TEXTURE_2D, tPR.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tQB = ETSIDI::getTexture("imagenes/reinaB.png");
    glBindTexture(GL_TEXTURE_2D, tQB.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tQR = ETSIDI::getTexture("imagenes/reinaR.png");
    glBindTexture(GL_TEXTURE_2D, tQR.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tKB = ETSIDI::getTexture("imagenes/reyB.png");
    glBindTexture(GL_TEXTURE_2D, tKB.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    auto tKR = ETSIDI::getTexture("imagenes/reyR.png");
    glBindTexture(GL_TEXTURE_2D, tKR.id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
void Mundo::inicializa_tab() {
    columnas = 8;
    filas = 8;
    tablero.set_coordenadas({ -columnas + 1.0, ((21.0 - 2.0 * filas) / 2.0) - 3.0 + 3.0 });
}

void dibujar_con_balanceo(Pieza& pieza, float angulo) {
    VECTOR2D pos = pieza.get_pos();

    glPushMatrix();
    glTranslatef(pos.x, pos.y, 0.0f); // Mueve al centro de la pieza
    float rot = sin(angulo * 3.1416f / 180.0f) * 20.0f; // Oscilación grados
    glRotatef(rot, 0.0f, 0.0f, 1.0f); // Rota en Z
    glTranslatef(-pos.x, -pos.y, 0.0f); // Regresa a origen

    pieza.dibuja_pieza();

    glPopMatrix();
}



void Mundo::dibuja() {
    anguloAnimacion += 10.0f;
    if (anguloAnimacion > 360.0f)
        anguloAnimacion -= 360.0f;

    tablero.dibuja_tablero(columnas, filas);
    if (casilla_seleccionada)
        tablero.dibuja_casilla(posicion_central_click);

    // Mostrar ambos efectos a la vez
    if (efectoBalon.activo) {
        efectoBalon.mueve();
        efectoBalon.dibuja();
    }
    if (efectoBonus.activo) {
        efectoBonus.mueve();
        efectoBonus.dibuja();
    }

    // Blancas
    dibujar_con_balanceo(peonB1, anguloAnimacion);
    dibujar_con_balanceo(peonB2, anguloAnimacion);
    dibujar_con_balanceo(peonB3, anguloAnimacion);
    dibujar_con_balanceo(peonB4, anguloAnimacion);
    dibujar_con_balanceo(peonB5, anguloAnimacion);
    dibujar_con_balanceo(peonB6, anguloAnimacion);
    dibujar_con_balanceo(peonB7, anguloAnimacion);
    dibujar_con_balanceo(peonB8, anguloAnimacion);

    dibujar_con_balanceo(torreB1, anguloAnimacion);
    dibujar_con_balanceo(torreB2, anguloAnimacion);
    dibujar_con_balanceo(alfilB1, anguloAnimacion);
    dibujar_con_balanceo(alfilB2, anguloAnimacion);
    dibujar_con_balanceo(caballoB1, anguloAnimacion);
    dibujar_con_balanceo(caballoB2, anguloAnimacion);
    dibujar_con_balanceo(reyB, anguloAnimacion);
    dibujar_con_balanceo(reinaB, anguloAnimacion);

    // Rojas
    dibujar_con_balanceo(peonR1, anguloAnimacion);
    dibujar_con_balanceo(peonR2, anguloAnimacion);
    dibujar_con_balanceo(peonR3, anguloAnimacion);
    dibujar_con_balanceo(peonR4, anguloAnimacion);
    dibujar_con_balanceo(peonR5, anguloAnimacion);
    dibujar_con_balanceo(peonR6, anguloAnimacion);
    dibujar_con_balanceo(peonR7, anguloAnimacion);
    dibujar_con_balanceo(peonR8, anguloAnimacion);

    dibujar_con_balanceo(torreR1, anguloAnimacion);
    dibujar_con_balanceo(torreR2, anguloAnimacion);
    dibujar_con_balanceo(alfilR1, anguloAnimacion);
    dibujar_con_balanceo(alfilR2, anguloAnimacion);
    dibujar_con_balanceo(caballoR1, anguloAnimacion);
    dibujar_con_balanceo(caballoR2, anguloAnimacion);
    dibujar_con_balanceo(reyR, anguloAnimacion);
    dibujar_con_balanceo(reinaR, anguloAnimacion);

    for (auto* pieza : comidaB)
        pieza->dibuja();

    for (auto* pieza : comidaR)
        pieza->dibuja();
}




bool Mundo::casillaValida(int i, int j) {   // Para que no se salga del tamaño de la matriz control 
    return i >= 0 && i < control.size() && j >= 0 && j < control[i].size();
}


void Mundo::comidasB() {
    std::cout << "Pieza comida" << std::endl;

    Pieza* pieza_comida = control[casilla_actual.x - 1][casilla_actual.y - 1];

    if (pieza_comida != nullptr) {
        comidaB.push_back(pieza_comida);
        comidaB.back()->muevepieza(pos_comidaB_X, -4);
        pos_comidaB_X -= 1.0;
        control[casilla_actual.x - 1][casilla_actual.y - 1] = nullptr;
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
        control[casilla_actual.x - 1][casilla_actual.y - 1] = nullptr;
    }
    else {
        std::cerr << "[ERROR] pieza comida era nullptr" << std::endl;
    }
}

void Mundo::aplicar_efecto_especial(VECTOR2D pos) {
    // Balón animado
    efectoBalon.activo = true;
    efectoBalon.tipo = "balon";
    efectoBalon.tiempoRestante = 2.0f;
    efectoBalon.destino = pos;
    efectoBalon.rotacion = 0.0f;

    // BONUS centrado en la pantalla
    efectoBonus.activo = true;
    efectoBonus.tipo = "bonus";
    efectoBonus.tiempoRestante = 2.0f;
    efectoBonus.tiempoTotal = 2.0f;
    efectoBonus.escala = 1.0f;
    efectoBonus.posicion = { 0.0f, 0.0f }; 
    efectoBonus.explosionHecha = false;

    ETSIDI::play("sonido/bonus.mp3");
}


extern std::string imagen_arbitro;
extern unsigned int tiempo_cambio_arbitro;


void Mundo::mueve() {
    auto capturables = piezas_con_captura();
    Pieza* pieza = control[casilla_anterior.x - 1][casilla_anterior.y - 1];

    if (!capturables.empty()) {
        Pieza* pieza_seleccionada = control[casilla_anterior.x - 1][casilla_anterior.y - 1];
        bool es_pieza_capturable = false;
        for (const auto& par : capturables) {
            if (par.first == pieza_seleccionada) {
                es_pieza_capturable = true;
                break;
            }
        }
        if (!es_pieza_capturable) {
            std::cout << "[REGLA] Debes mover una de las piezas obligadas a capturar.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
            return;
        }
        pieza = pieza_seleccionada;
    }

    if (!pieza) 
    {
        imagen_arbitro = "imagenes/arbitroamarillo.png";
        tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
        ETSIDI::play("sonido/pitido.mp3");
    }

    bool capturo = false;

    if (pieza->es_rey()) {
        Rey* rey = dynamic_cast<Rey*>(pieza);
        if (rey && rey->mover(posicion_central_click, control, capturo)) {
            Pieza* comida = control[casilla_actual.x - 1][casilla_actual.y - 1];
            if (capturo) {
                if (pieza->get_color()) comidasB(); else comidasR();

                // Efecto solo si el rey come una pieza enemiga
                if (comida && comida->get_color() != pieza->get_color()) {
                    aplicar_efecto_especial(posicion_central_click);
                }
            }
            actualizar_matriz_control();
            turno = !turno;
            movida = true;
        }
        else {
            std::cout << "[REGLA] Movimiento no valido para el rey.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
        }
        return;
    }

    if (pieza->es_peon()) {
        Peon* p = dynamic_cast<Peon*>(pieza);
        if (p && p->mover(posicion_central_click, control, capturo)) {
            if (capturo) pieza->get_color() ? comidasB() : comidasR();
            actualizar_matriz_control();
            turno = !turno;
        }
        else {
            std::cout << "[REGLA] Movimiento no valido para el peon.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
        }
        return;
    }

    if (pieza->es_torre()) {
        Torre* t = dynamic_cast<Torre*>(pieza);
        if (t && t->mover(posicion_central_click, control, capturo)) {
            if (capturo) pieza->get_color() ? comidasB() : comidasR();
            actualizar_matriz_control();
            turno = !turno;
        }
        else {
            std::cout << "[REGLA] Movimiento no valido para la torre.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
        }
        return;
    }

    if (pieza->es_alfil()) {
        Alfil* a = dynamic_cast<Alfil*>(pieza);
        if (a && a->mover(posicion_central_click, control, capturo)) {
            if (capturo) pieza->get_color() ? comidasB() : comidasR();
            actualizar_matriz_control();
            turno = !turno;
        }
        else {
            std::cout << "[REGLA] Movimiento no valido para el alfil.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
        }
        return;
    }

    if (pieza->es_reina()) {
        Reina* r = dynamic_cast<Reina*>(pieza);
        if (r && r->mover(posicion_central_click, control, capturo)) {
            if (capturo) pieza->get_color() ? comidasB() : comidasR();
            actualizar_matriz_control();
            turno = !turno;
        }
        else {
            std::cout << "[REGLA] Movimiento no valido para la reina.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
        }
        return;
    }

    if (pieza->es_caballo()) {
        Caballo* c = dynamic_cast<Caballo*>(pieza);
        if (c && c->mover(posicion_central_click, control, capturo)) {
            if (capturo) pieza->get_color() ? comidasB() : comidasR();
            actualizar_matriz_control();
            turno = !turno;
        }
        else {
            std::cout << "[REGLA] Movimiento no valido para el caballo.\n";
            imagen_arbitro = "imagenes/arbitroamarillo.png";
            tiempo_cambio_arbitro = glutGet(GLUT_ELAPSED_TIME);
            ETSIDI::play("sonido/pitido.mp3");
        }
        return;
    }

}



void Mundo::actualizar_matriz_control()
{
    control[casilla_actual.x - 1][casilla_actual.y - 1] = control[casilla_anterior.x - 1][casilla_anterior.y - 1];//actualizan la matriz control en cada movimiento
    control[casilla_anterior.x - 1][casilla_anterior.y - 1] = nullptr;
}

std::vector<std::pair<Pieza*, VECTOR2D>> Mundo::piezas_con_captura() {
    std::vector<std::pair<Pieza*, VECTOR2D>> lista;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Pieza* origen = control[i][j];
            if (!origen || origen->get_color() != turno)
                continue;

            VECTOR2D pos_origen = origen->posicion_pieza;

            // ——— Comprobación de mapeo para el origen ———
            {
                int test_i = static_cast<int>(std::round((pos_origen.x + 7.0f) / 2.0f));
                int test_j = static_cast<int>(std::round((pos_origen.y - 2.5f) / 2.0f));
                if (test_i != i || test_j != j) {
                    std::cout << "[MAPPING-ERROR] origen índice esperado ("
                        << i << "," << j << ") vs mapeado ("
                        << test_i << "," << test_j << ")\n";
                }
            }

            // Recorremos cada casilla destino
            for (int x = 0; x < 8; ++x) {
                for (int y = 0; y < 8; ++y) {
                    Pieza* destinoPieza = control[x][y];

                    // —— Paso 2: filtro por pieza enemiga —— 
                    if (!destinoPieza || destinoPieza->get_color() == turno)
                        continue;

                    // **DECLARA AQUÍ** el VECTOR2D destino
                    VECTOR2D pos_destino{
                        static_cast<double>(x),
                        static_cast<double>(y)
                    };

                    // ——— Comprobación de mapeo para el destino ———
                    {
                        int test_x = static_cast<int>(std::round(pos_destino.x));
                        int test_y = static_cast<int>(std::round(pos_destino.y));
                        if (test_x != x || test_y != y) {
                            std::cout << "[MAPPING-ERROR] destino índice esperado ("
                                << x << "," << y << ") vs mapeado ("
                                << test_x << "," << test_y << ")\n";
                        }
                    }

                    // DEBUG: imprimo antes de añadir al vector
                    if (origen->puede_comer_enemigo(pos_origen,
                        pos_destino,
                        control)) {
                        std::cout << "[DEBUG] Origen=("
                            << i << "," << j
                            << ") Destino=("
                            << x << "," << y
                            << ")\n";

                        lista.emplace_back(origen, pos_origen);
                        lista.emplace_back(destinoPieza, pos_destino);
                    }
                }
            }
        }
    }

    return lista;
}
