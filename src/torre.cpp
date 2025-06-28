#include "torre.h"


void Torre::set_pos_pieza(const VECTOR2D& pos)
{
	if (r.casilla.x == 0 && r.casilla.y == 0)
		posicion_pieza = pos;
}

void Torre::dibuja_pieza()
{
	glPushMatrix();
	glTranslated(posicion_pieza.x, posicion_pieza.y, 0.001);
	if (color == 0)
		sprite2.draw();			//rojas
	if (color == 1)
		sprite.draw();		// blancas

	glPopMatrix();
	glFlush();
}

void Torre::set_color_pieza(bool a)
{
	if (a == true)
		color = true;
	if (a == false)
		color = false;
}
void Torre::muevepieza(double x, double y)
{
	posicion_pieza.x = x;
	posicion_pieza.y = y;
}


bool Torre::pieza_comible(VECTOR2D casilla_actual, std::vector<std::vector<Pieza*>> control){
	int torre_x = casilla_actual.x - 2;
	int torre_y = casilla_actual.y - 2;
	for (int dx = 0; dx < 3; ++dx) {  //for para darme las 8 casillas al rededor del rey
		for (int dy = 0; dy < 3; ++dy) {
			if (dx == 1 && dy == 1) {
				continue;
			}
			int x = torre_x + dx - 1;
			int y = torre_y + dy - 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 8) {  // mira si esta en el limite del tablero
				if (control[x][y] != nullptr) {
					return true;
				}
			}
		}
	}
}

bool Torre::mover(VECTOR2D destino,std::vector<std::vector<Pieza*>>& control,bool& capturo)
{
    // 1) Cálculo de desplazamiento gráfico
    int dx = static_cast<int>(destino.x - posicion_pieza.x);
    int dy = static_cast<int>(destino.y - posicion_pieza.y);
    int movx = std::abs(dx);
    int movy = std::abs(dy);

    // 2) Conversión a índices de casilla (0–7)
    int ix1 = static_cast<int>((posicion_pieza.x + 8.0f) / 2.0f);
    int iy1 = static_cast<int>((posicion_pieza.y - 1.0f) / 2.0f);
    int ix2 = static_cast<int>((destino.x + 8.0f) / 2.0f);
    int iy2 = static_cast<int>((destino.y - 1.0f) / 2.0f);

    // 3) Fuera de tablero?
    if (ix1 < 0 || ix1 >= 8 || iy1 < 0 || iy1 >= 8 ||
        ix2 < 0 || ix2 >= 8 || iy2 < 0 || iy2 >= 8)
    {
        return false;
    }

    // 4) Solo movimiento en línea recta y no quedarse quieto
    if ((movx == 0 || movy == 0) && !(movx == 0 && movy == 0)) {
        // 5) Comprobar trayectoria libre
        bool libre = true;
        if (movx == 0) {
            // vertical
            int paso = (iy2 > iy1) ? +1 : -1;
            for (int y = iy1 + paso; y != iy2; y += paso) {
                if (control[ix1][y] != nullptr) {
                    libre = false;
                    break;
                }
            }
        }
        else {
            // horizontal
            int paso = (ix2 > ix1) ? +1 : -1;
            for (int x = ix1 + paso; x != ix2; x += paso) {
                if (control[x][iy1] != nullptr) {
                    libre = false;
                    break;
                }
            }
        }

        if (!libre)
            return false;

        // 6) Marcar captura si hay pieza en destino
        if (control[ix2][iy2] != nullptr)
            capturo = true;

        // 7) Ejecutar movimiento gráfico
        muevepieza(destino.x, destino.y);
        return true;
    }

    // 8) No es movimiento válido de torre
    return false;
}


bool Torre::puede_comer_enemigo(VECTOR2D pos, std::vector<std::vector<Pieza*>> control) {
	int x = static_cast<int>(round((pos.x + 7.0f) / 2.0f));
	int y = static_cast<int>(round((pos.y - 2.5f) / 2.0f));

	// Cuatro direcciones: arriba, abajo, izquierda, derecha
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };

	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			Pieza* objetivo = control[nx][ny];
			if (objetivo != nullptr) {
				if (objetivo->get_color() != this->color) return true;
				else break; // bloqueado por aliada
			}
			nx += dx[dir];
			ny += dy[dir];
		}
	}

	return false;
}
