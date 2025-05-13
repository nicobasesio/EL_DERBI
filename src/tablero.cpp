#include "freeglut.h"
#include "tablero.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "raton.h"


void Tablero::dibuja_tablero(int c, int f)
{
	
	
	glDisable(GL_LIGHTING);
	//Bucle que dibuja el tablero cuadrado a cuadrado
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < f; j++)
		{
			// Primeramente hacemos la fila de abajo (cada columna) y después saltamos a la siguiente fila 
			//Va de izquierda a derecha
			if ((i + j) % 2 != 0) //si la suma de fila + columna es imparpar, dibuja blanco, sino, rojo
				dibuja_cuadrado_blanco(i, j); //blanco
			else
				dibuja_cuadrado_rojo(i, j); //rojo
		}
	}

	
	dibuja_marco(c, f);
	glEnable(GL_LIGHTING);
	dibuja_fondo();

	//Llamamos todas las funciones en dibuja tablero
	

	

}


void Tablero::dibuja_cuadrado_blanco(double i, double j)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	//posicion es el centro del cuadrado. Se le suman o restan cosas para ubicar sus vertices
	//vértices del cuadrado. static cast<float> lo que hace es que el valor se convierta a float porque glVertex3f necesita float como argumentos
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i - 1), static_cast<float>(coordenadas.y + 2 * j - 1), -0.0001f);//abajo izq
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i - 1), static_cast<float>(coordenadas.y + 2 * j + 1), -0.0001f);//arriba izq
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i + 1), static_cast<float>(coordenadas.y + 2 * j + 1), -0.0001f);//arriba der
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i + 1), static_cast<float>(coordenadas.y + 2 * j - 1), -0.0001f);//abajo der
	glEnd();


}

void Tablero::dibuja_cuadrado_rojo(double i, double j)
{
	glColor3ub(255, 51, 36);
	glBegin(GL_POLYGON);

	glVertex3f(static_cast<float>(coordenadas.x + 2 * i - 1), static_cast<float>(coordenadas.y + 2 * j - 1), -0.0001f);//abajo izq
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i - 1), static_cast<float>(coordenadas.y + 2 * j + 1), -0.0001f);//arriba izq
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i + 1), static_cast<float>(coordenadas.y + 2 * j + 1), -0.0001f);//arriba der
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i + 1), static_cast<float>(coordenadas.y + 2 * j - 1), -0.0001f);//abajo der
	glEnd();

}

void Tablero::dibuja_marco(double i, double j)
{
	glBegin(GL_POLYGON);
	glColor3ub(255, 51, 51);

	glVertex3f(static_cast<float>(coordenadas.x - 1.5), static_cast<float>(coordenadas.y - 1.5), -0.0001f);//abajo izq
	glVertex3f(static_cast<float>(coordenadas.x - 1.5), static_cast<float>(coordenadas.y + j * 2 - 0.5), -0.0001f);//arriba izq
	glVertex3f(static_cast<float>(coordenadas.x + i * 2 - 0.5), static_cast<float>(coordenadas.y + j * 2 - 0.5), -0.0001f);//arriba der
	glVertex3f(static_cast<float>(coordenadas.x + i * 2 - 0.5), static_cast<float>(coordenadas.y - 1.5), -0.0001f);//abajo der
	glEnd();
}

void Tablero::dibuja_fondo()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Wanda-Metropolitano-Atletico-Madrid.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1); glVertex3f(-14.0f, -3.0f, -0.01f);	// izda abajo
	glTexCoord2d(1, 1); glVertex3f(14.0f, -3.0f, -0.01f);	// dcha abajo
	glTexCoord2d(1, 0); glVertex3f(14.0f, 18.0f, -0.01f);	// dcha arriba
	glTexCoord2d(0, 0); glVertex3f(-14.0f, 18.0f, -0.01f);	// izda arriba

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Tablero::set_coordenadas(const VECTOR2D& coord)
{
	coordenadas = coord;
}



void Tablero::dibuja_casilla(VECTOR2D posicion_central_click)
{
	glColor3ub(0, 200, 0);
	glBegin(GL_POLYGON);

	glVertex3f(static_cast<float>(posicion_central_click.x - 1), static_cast<float>(posicion_central_click.y - 1), 0.0f);//abajo izq
	glVertex3f(static_cast<float>(posicion_central_click.x - 1), static_cast<float>(posicion_central_click.y + 1), 0.0f);//arriba izq
	glVertex3f(static_cast<float>(posicion_central_click.x + 1), static_cast<float>(posicion_central_click.y + 1), 0.0f);//arriba der
	glVertex3f(static_cast<float>(posicion_central_click.x + 1), static_cast<float>(posicion_central_click.y - 1), 0.0f);//abajo der
	glEnd();
}

void Tablero::dibuja_casilla_anterior_tras_movimiento(VECTOR2D posicion_central_click_anterior)
{
	glColor3ub(253, 162, 142);
	glBegin(GL_POLYGON);

	glVertex3f(static_cast<float>(posicion_central_click_anterior.x - 1), static_cast<float>(posicion_central_click_anterior.y - 1), 0.0f);//abajo izq
	glVertex3f(static_cast<float>(posicion_central_click_anterior.x - 1), static_cast<float>(posicion_central_click_anterior.y + 1), 0.0f);//arriba izq
	glVertex3f(static_cast<float>(posicion_central_click_anterior.x + 1), static_cast<float>(posicion_central_click_anterior.y + 1), 0.0f);//arriba der
	glVertex3f(static_cast<float>(posicion_central_click_anterior.x + 1), static_cast<float>(posicion_central_click_anterior.y - 1), 0.0f);//abajo der
	glEnd();
}
