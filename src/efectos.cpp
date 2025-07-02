#include "efectos.h"
#include "ETSIDI.h"
#include <freeglut.h>
#include <cmath>

void EfectoEspecial::mueve() {
    if (!activo) return;

    tiempoRestante -= 0.033f;
    if (tiempoRestante <= 0.0f) {
        activo = false;
        particulas.clear();
        return;
    }

    if (tipo == "balon") {
        float t = 2.0f - tiempoRestante;
        float radio = 9.0f;
        float cx = destino.x;
        float cy = destino.y;
        float omega = 2.0f;

        posicion.x = cx + cos(t * omega) * radio;
        posicion.y = cy + sin(t * omega) * radio;

        rotacion += 15.0f;
        if (rotacion >= 360.0f) rotacion -= 360.0f;

    }

    else if (tipo == "bonus") {
        float t = tiempoTotal - tiempoRestante;
        escala = 1.0f + 4.0f * (t / tiempoTotal);  // animación de escala

        if (tiempoRestante <= 0.1f && !explosionHecha) {
            explosionHecha = true;
            particulas.clear();
            for (int i = 0; i < 50; ++i) {
                Particula p;
                p.pos = posicion;  // ya es el centro
                float ang = (float)i / 50.0f * 2.0f * 3.14159f;
                float vel = 2.5f + static_cast<float>(rand()) / RAND_MAX * 1.5f;
                p.vel = { cos(ang) * vel, sin(ang) * vel };
                p.vida = 1.0f;
                particulas.push_back(p);
            }
        }

        for (auto& p : particulas) {
            p.pos.x += p.vel.x * 0.033f;
            p.pos.y += p.vel.y * 0.033f;
            p.vida -= 0.05f;
        }
    }
}

void EfectoEspecial::dibuja() {
    if (!activo) return;

    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0.15f);
    glScalef(escala, escala, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    if (tipo == "balon") {
        GLuint textura = ETSIDI::getTexture("imagenes/balon.png").id;
        if (textura > 0) glBindTexture(GL_TEXTURE_2D, textura);

        glColor4f(1, 1, 1, 0.3f);
        glBegin(GL_QUADS);
        glVertex3f(-1.2f, -1.2f, -0.01f);
        glVertex3f(1.2f, -1.2f, -0.01f);
        glVertex3f(1.2f, 1.2f, -0.01f);
        glVertex3f(-1.2f, 1.2f, -0.01f);
        glEnd();

        glRotatef(rotacion, 0, 0, 1);
        glColor4f(1, 1, 1, 1);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex3f(-1, -1, 0);
        glTexCoord2d(1, 1); glVertex3f(1, -1, 0);
        glTexCoord2d(1, 0); glVertex3f(1, 1, 0);
        glTexCoord2d(0, 0); glVertex3f(-1, 1, 0);
        glEnd();
    }

    else if (tipo == "bonus") {
        GLuint textura = ETSIDI::getTexture("imagenes/bonus.png").id;
        if (textura > 0) glBindTexture(GL_TEXTURE_2D, textura);

        float alpha = fabs(sin(tiempoRestante * 5.0f));
        glColor4f(1, 1, 1, alpha);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex3f(-1, -1, 0);
        glTexCoord2d(1, 1); glVertex3f(1, -1, 0);
        glTexCoord2d(1, 0); glVertex3f(1, 1, 0);
        glTexCoord2d(0, 0); glVertex3f(-1, 1, 0);
        glEnd();

        // Partículas de explosión
        for (auto& p : particulas) {
            if (p.vida <= 0.0f) continue;
            glColor4f(1.0f, 1.0f, 0.0f, p.vida);  
            glPushMatrix();
            glTranslatef(p.pos.x, p.pos.y, 0.2f);
            glScalef(0.2f, 0.2f, 1.0f);
            glBegin(GL_QUADS);
            glVertex3f(-1, -1, 0);
            glVertex3f(1, -1, 0);
            glVertex3f(1, 1, 0);
            glVertex3f(-1, 1, 0);
            glEnd();
            glPopMatrix();
        }
    }

    glColor4f(1, 1, 1, 1);
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
