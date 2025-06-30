#include "freeglut.h"
#include "tablero.h"
#include "ETSIDI.h"
#include <stdio.h>
#include "raton.h"

void Tablero::dibuja_tablero(int columnas, int filas) {
	glDisable(GL_LIGHTING);

	// 1) dibuja casillas normales
	for (int c = 0; c < columnas; ++c) {
		for (int f = 0; f < filas; ++f) {
			if ((c + f) & 1) dibuja_cuadrado_blanco(c, f);
			else            dibuja_cuadrado_verde(c, f);
		}
	}

	// 2) dibuja todos los resaltados registrados
	for (auto& pr : casillasResaltadas) {
		int c = pr.first, f = pr.second;
		VECTOR2D centro{
			coordenadas.x + 2.0 * c,
			coordenadas.y + 2.0 * f
		};
		dibuja_casilla_resaltada(centro);
	}

	// 3) marco, fondo, temporizadores...
	dibuja_marco(columnas, filas);
	glEnable(GL_LIGHTING);
	dibuja_fondo();
	dibuja_temporizador();
}

// Borra todos los resaltados
void Tablero::limpiarResaltados() {
	casillasResaltadas.clear();
}

// Registra un resaltado dado por índices (0..7)
void Tablero::agregarResaltado(int col, int fil) {
	// sólo si están en rango
	if (col >= 0 && col < 8 && fil >= 0 && fil < 8)
		casillasResaltadas.emplace_back(col, fil);
}


void Tablero::dibuja_cuadrado_blanco(double i, double j)
{
	glColor3ub(144, 238, 144);
	glBegin(GL_POLYGON);
	//posicion es el centro del cuadrado. Se le suman o restan cosas para ubicar sus vertices
	//vértices del cuadrado. static cast<float> lo que hace es que el valor se convierta a float porque glVertex3f necesita float como argumentos
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i - 1), static_cast<float>(coordenadas.y + 2 * j - 1), -0.0001f);//abajo izq
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i - 1), static_cast<float>(coordenadas.y + 2 * j + 1), -0.0001f);//arriba izq
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i + 1), static_cast<float>(coordenadas.y + 2 * j + 1), -0.0001f);//arriba der
	glVertex3f(static_cast<float>(coordenadas.x + 2 * i + 1), static_cast<float>(coordenadas.y + 2 * j - 1), -0.0001f);//abajo der
	glEnd();


}

void Tablero::dibuja_cuadrado_verde(double i, double j)
{
	glColor3ub(0, 100, 0);
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
	if (posicion_central_click.x == 0.0 && posicion_central_click.y == 0.0)
		return;
	glColor3ub(255, 51, 51);
	glBegin(GL_POLYGON);

	glVertex3f(static_cast<float>(posicion_central_click.x - 1), static_cast<float>(posicion_central_click.y - 1), 0.0f);//abajo izq
	glVertex3f(static_cast<float>(posicion_central_click.x - 1), static_cast<float>(posicion_central_click.y + 1), 0.0f);//arriba izq
	glVertex3f(static_cast<float>(posicion_central_click.x + 1), static_cast<float>(posicion_central_click.y + 1), 0.0f);//arriba der
	glVertex3f(static_cast<float>(posicion_central_click.x + 1), static_cast<float>(posicion_central_click.y - 1), 0.0f);//abajo der
	glEnd();
}

void Tablero::dibuja_casilla_anterior_tras_movimiento(VECTOR2D posicion_central_click_anterior)
{
	glColor3ub(255, 51, 51);
	glBegin(GL_POLYGON);

	glVertex3f(static_cast<float>(posicion_central_click_anterior.x - 1), static_cast<float>(posicion_central_click_anterior.y - 1), 0.0f);//abajo izq
	glVertex3f(static_cast<float>(posicion_central_click_anterior.x - 1), static_cast<float>(posicion_central_click_anterior.y + 1), 0.0f);//arriba izq
	glVertex3f(static_cast<float>(posicion_central_click_anterior.x + 1), static_cast<float>(posicion_central_click_anterior.y + 1), 0.0f);//arriba der
	glVertex3f(static_cast<float>(posicion_central_click_anterior.x + 1), static_cast<float>(posicion_central_click_anterior.y - 1), 0.0f);//abajo der
	glEnd();
}
void Tablero::dibuja_temporizador() {
	// Temporizador superior (jugador rojo)
	glPushMatrix();
	temporizador.setPos(-14.6f, 15.5f);  
	temporizador.draw();
	glPopMatrix();

	// Temporizador inferior (jugador blanco)
	glPushMatrix();
	temporizador2.setPos(-14.6f, -1.5f);  
	glTranslated(0, 0, 0.001);
	temporizador2.draw();
	glPopMatrix();
}

void Tablero::dibuja_casilla_resaltada(const VECTOR2D& centro) {
	glColor3ub(220, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(centro.x - 1, centro.y - 1, 0.0f);
	glVertex3f(centro.x - 1, centro.y + 1, 0.0f);
	glVertex3f(centro.x + 1, centro.y + 1, 0.0f);
	glVertex3f(centro.x + 1, centro.y - 1, 0.0f);
	glEnd();
}