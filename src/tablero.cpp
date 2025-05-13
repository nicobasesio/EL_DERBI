#include "freeglut.h"
#include "tablero.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "raton.h"

void Tablero::dibuja_tablero(int c, int f)
{

	//tablero en si. Bucle que dibuja cuadrado a cuadrado
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < f; j++)
		{
			//primero hacer toda la primera fila (la de abajo) con cada columna, luego la segunda fila, etc
			//el primer cuadrado es el de abajo a la izquierda
			if ((i + j) % 2 != 0) //si la suma de fila + columna es imparpar, dibuja blanco, sino, azul
				dibuja_cuadrado_blanco(i, j); //blanco
			else
				dibuja_cuadrado_azul(i, j); //azul
		}
	}

	//dibuja marco
	dibuja_marco(c, f);


	//dibuja un fondo
	dibuja_fondo();

	//dibuja temporizador
	dibuja_temporizador();


}

//TODAS LAS FUNCIONES SIGUIENTES SON LLAMADAS EN dibuja_tablero

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

void Tablero::dibuja_cuadrado_azul(double i, double j)
{
	glColor3ub(0, 102, 0);
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
	glColor3ub(0, 51, 0);

	glVertex3f(static_cast<float>(coordenadas.x - 1.5), static_cast<float>(coordenadas.y - 1.5), -0.0001f);//abajo izq
	glVertex3f(static_cast<float>(coordenadas.x - 1.5), static_cast<float>(coordenadas.y + j * 2 - 0.5), -0.0001f);//arriba izq
	glVertex3f(static_cast<float>(coordenadas.x + i * 2 - 0.5), static_cast<float>(coordenadas.y + j * 2 - 0.5), -0.0001f);//arriba der
	glVertex3f(static_cast<float>(coordenadas.x + i * 2 - 0.5), static_cast<float>(coordenadas.y - 1.5), -0.0001f);//abajo der
	glEnd();
}

void Tablero::dibuja_fondo()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,
		ETSIDI::getTexture("imagenes/fondo_madera2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2d(-14, -3);	// izda abajo
	glTexCoord2d(1, 1); glVertex2d(14, -3);	// dcha abajo
	glTexCoord2d(1, 0); glVertex2d(14, 18);	// dcha arriba
	glTexCoord2d(0, 0); glVertex2d(-14, 18);// izda arriba
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
	glColor3ub(220, 0, 0);
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
void Tablero::dibuja_temporizador() {

	glPushMatrix();
	temporizador.setPos(-11.4, 10);
	temporizador2.setPos(-11.4, 2);
	glTranslated(posicion_temp.x, posicion_temp.y, 0.001);
	temporizador2.draw();
	temporizador.draw();
	glPopMatrix();
	glFlush();
}

void Tablero::dibuja_pizarras(double altura_arriba, double altura_abajo) {
	glPushMatrix();
	pizarra.setPos(5.4, 4.5);
	pizarra2.setPos(-7.5, altura_arriba);
	pizarra3.setPos(-7.5, altura_abajo);
	pizarra4.setPos(-13, 4.5);
	glTranslated(posicion_temp.x, posicion_temp.y, 0.0001);
	pizarra2.draw();
	pizarra.draw();
	pizarra3.draw();
	pizarra4.draw();
	glPopMatrix();
	glFlush();
}