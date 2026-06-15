#pragma once

#include "raylib.h"
#include <box2d.h>

class Catapulta
{
private:

    float x;
    float y;

    float GetAngulo(float potencia);

public:

    Catapulta(float x, float y);

    void Draw(float potencia);

    Vector2 GetPosicionProyectil(float potencia);
    b2Vec2 GetImpulso(float potencia);
};