/*#pragma once
#include "VECTOR2D.h"

class Efectos {
public:
    bool activo = false;
    float escala = 1.0f;
    float tiempoRestante = 2.0f;
    VECTOR2D posicion;
};

// Variables globales
extern Efectos efectoEspecial;

// Declaración de función
void aplicar_efecto_especial(VECTOR2D pos);

// (Opcional) para el destello antiguo, si aún lo quieres
extern bool efecto_activo;
extern unsigned int tiempo_efecto;
*/
#pragma once
#include "VECTOR2D.h"

class EfectoEspecial {
public:
    bool activo = false;
    float escala = 1.0f;
    float tiempoRestante = 0.0f;
    VECTOR2D posicion;

    void mueve();
    void dibuja();
};
