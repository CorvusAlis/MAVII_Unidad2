#pragma once

#include "raylib.h"
#include <box2d.h>
#include <vector>

#include "Proyectil.h"

class GameManager
{
private:

    Texture2D background;

    b2World* world;

    b2Body* groundBody;

    vector<Proyectil*> proyectiles;


public:

    GameManager();
    ~GameManager();

    void Update();
    void Draw();

    void CreateGround();
};