#pragma once

#include "raylib.h"
#include <box2d.h>
#include <vector>

#include "Proyectil.h"

class GameManager
{
private:

    //para simular el proyectil en espera a ser lanzado
    float spawnX;
    float spawnY;
    float spawnRadius;
    Color spawnColor;

    Texture2D background;

    b2World* world;
    b2Body* groundBody;

    vector<Proyectil*> proyectiles;
    float impulsoActual;


public:

    GameManager();
    ~GameManager();

    void Update();
    void Draw();

    void CreateGround();
};