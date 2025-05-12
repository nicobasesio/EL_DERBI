#pragma once
#include <cmath>

struct VECTOR2D
{
	double x{};
	double y{};
	double modulo() const; //modulo del vector
	double argumento() const; //argumento del vector
	VECTOR2D unitario() const; //devuelve un vector unitario
	
	//Los siguientes miembros hace uso de la SOBRECARGA DE OPERADORES
	VECTOR2D operator - (const VECTOR2D&) const; //resta de vectores
	VECTOR2D operator + (const VECTOR2D&) const; //suma de vectores
	double operator *(const VECTOR2D&) const; // producto escalar
	VECTOR2D operator *(double) const; // producto por un escalar
};

inline double VECTOR2D::modulo() const
{
	return sqrt(x * x + y * y);
}

inline double VECTOR2D::argumento() const {
	return atan2(y, x); //atan2 da el valor del argumento teniendo en cuenta el cuadrante, y si la componente en x es nula, indica correctamente el angulo (90º o -90º)
}

inline VECTOR2D VECTOR2D::unitario() const
{
	auto mod = modulo(); //auto simplemente deduce automaticamente el tipo de la variable mod. (no hace falta especificarle que mod es un double, ya lo deduce)
	if (mod > 0.00001) return { x / mod, y / mod };
	return { x,y };
}

inline VECTOR2D VECTOR2D::operator - (const VECTOR2D& v) const
{
	return { x - v.x , y - v.y }; //'x' e 'y' son las coordenadas del primer vector , y 'v.x' y v.y' son las coordenadas del segundo vector.
}
inline  VECTOR2D  VECTOR2D::operator + (const  VECTOR2D& v) const
{
	return { x + v.x , y + v.y };
}
//EJERCICIO : Completar las operaciones de producto escalar de vectores y producto por un escalar
inline double  VECTOR2D::operator *(const  VECTOR2D& v) const
{
	double producto_escalar;
	auto mod1 = modulo(); //modulo primer vector
	auto mod2 = sqrt(v.x * v.x + v.y * v.y); //modulo segundo vector
	auto angulo = argumento() - atan2(v.y, v.x);   //angulo entre los dos vectores

	producto_escalar = mod1 * mod2 * cos(angulo);

	return producto_escalar;
}

inline  VECTOR2D  VECTOR2D::operator *(double d) const
{
	return { d * x, d * y }; //producto por un escalar. Vector por escalar
}

inline  VECTOR2D operator * (double f, const  VECTOR2D& v)
{
	return { v.x * f, v.y * f }; //Esta función permite escribir primero el escalar y después el vector : Escalar por vector
}