#include "GameManager.h"
#include "Constantes.h"
#include "Proyectil.h"

using namespace std;

GameManager::GameManager()
{
    background = LoadTexture("assets/fondo_cm.png");

    world = new b2World(
        b2Vec2(0.0f, 9.8f)  //gravedad del mundo
    );

    CreateGround();
}

void GameManager::Update()
{
    world->Step(1.0f / 60.0f, 8, 3);

    if (IsKeyPressed(KEY_SPACE))
    {
        Proyectil* nuevo = new Proyectil(
            *world,
            100,
            450,
            20,
            RED
        );

        nuevo->ApplyImpulse(8.0f,-6.0f);   //aplico impulso contra la gravedad con componente Y negativo

        proyectiles.push_back(nuevo);
    }
}

void GameManager::Draw()
{
    BeginDrawing();

    #pragma region fondo
    ClearBackground(RAYWHITE);

    Rectangle source = {
        0,
        0,
        (float)background.width,
        (float)background.height
    };

    Rectangle dest = {
        0,
        0,
        1000,
        600
    };

    DrawTexturePro(
        background,
        source,
        dest,
        { 0,0 },
        0.0f,
        WHITE
    );
#pragma endregion

    for (auto proyectil : proyectiles)
    {
        proyectil->Draw();
    }

    EndDrawing();
}

GameManager::~GameManager()
{
    delete world;

    UnloadTexture(background);
}

void GameManager::CreateGround() {
    //suelo estático - marca el espacio con el que los elementos interactuan != del suelo visual
    b2BodyDef groundDef;
    groundDef.type = b2_staticBody;
    groundDef.position.Set(
        (SCREENWIDTH / 2.0f) / SCALE,
        (SCREENHEIGHT - 70.0f) / SCALE
    );

    b2PolygonShape groundShape;
    groundShape.SetAsBox(
        (SCREENWIDTH / 2.0f) / SCALE,
        20.0f / SCALE
    );

    groundBody = world->CreateBody(&groundDef);
    groundBody->CreateFixture(&groundShape, 0.0f);
}