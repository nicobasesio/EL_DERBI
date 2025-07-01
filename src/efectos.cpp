#include "efectos.h"
#include "ETSIDI.h"
#include "freeglut.h"

void EfectoEspecial::mueve() {
    if (!activo) return;

    tiempoRestante -= 0.033f;
    escala += 0.1f;

    if (tiempoRestante <= 0.0f) {
        activo = false;
    }
}

void EfectoEspecial::dibuja() {
    if (!activo) return;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bonus.png").id);
    glDisable(GL_LIGHTING);
    glColor4f(1, 1, 1, 1.0f);

    float s = escala;
    float x = posicion.x, y = posicion.y;

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(x - s, y - s, 0.2f);
    glTexCoord2f(1, 0); glVertex3f(x + s, y - s, 0.2f);
    glTexCoord2f(1, 1); glVertex3f(x + s, y + s, 0.2f);
    glTexCoord2f(0, 1); glVertex3f(x - s, y + s, 0.2f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}
