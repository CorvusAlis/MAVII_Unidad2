#pragma once

#include "raylib.h"
#include <box2d.h>

using namespace std;

class Proyectil
{
private:

    b2Body* body;
    float radio;
    Color color;
    b2Vec2 impulso;

public:

    Proyectil(
        b2World& world,
        float x,
        float y,
        float radio,
        Color color
    );

    void Update();
    void Draw();

    void ApplyImpulse(float x, float y);

    b2Body* GetBody();
};