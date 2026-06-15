#include "Catapulta.h"
#include <cmath>

Catapulta::Catapulta(
    float x,
    float y
)
{
    this->x = x;
    this->y = y;
}

void Catapulta::Draw(float potencia)
{
    //base
    DrawRectangle(
        x - 20,
        y,
        40,
        40,
        DARKBROWN
    );

    //angulo del brazo
    float angulo = GetAngulo(potencia);

    Rectangle brazo =
    {
        x,
        y,
        70,
        8
    };

    DrawRectanglePro(
        brazo,
        { 0, 4 },
        angulo - 90,
        BROWN
    );
}

Vector2 Catapulta::GetPosicionProyectil(float potencia)
{
    float angulo = GetAngulo(potencia);
    float rad = (angulo - 90) * DEG2RAD;

    Vector2 posicion;

    posicion.x = x + cosf(rad) * 65;
    posicion.y = y + sinf(rad) * 65;

    return posicion;
}

float Catapulta::GetAngulo(float potencia)
{
    return -30.0f - (potencia * 0.5f);
}

b2Vec2 Catapulta::GetImpulso(float potencia)
{
    float angulo = GetAngulo(potencia);

    float rad = angulo * DEG2RAD;

    b2Vec2 impulso;

    impulso.x = cosf(rad) * potencia;
    impulso.y = sinf(rad) * potencia;

    return impulso;
}