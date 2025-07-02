#pragma once
#include "VECTOR2D.h"
#include <string>
#include <vector>

class EfectoEspecial {
public:
    bool activo = false; 
    float tiempoRestante = 0.0f; 
    float tiempoTotal = 2.0f;  
    float escala = 1.0f;  
    float rotacion = 0.0f; 
    std::string tipo;                // "balon" o "bonus"

    VECTOR2D posicion;  
    VECTOR2D destino;  

    struct Particula {
        VECTOR2D pos;               
        VECTOR2D vel;               
        float vida = 1.0f;          
    };

    std::vector<Particula> particulas; 
    bool explosionHecha = false;        

    void mueve();    
    void dibuja();   
};
