#include "Raylib.h"
#include "GameManager.h"
#include "Constantes.h"
#include "Proyectil.h"

using namespace std;

GameManager::GameManager()
{
    background = LoadTexture("assets/fondo_cm.png");

    world = new b2World(b2Vec2(0.0f, 9.8f));

    CreateGround();

    impulsoActual = 8.0f;
}

void GameManager::Update()
{
    //control de impulso - primero ajusto el impuslo del proyectil
    if (IsKeyPressed(KEY_RIGHT))
    {
        impulsoActual += IMPULSO_STEP;
    }

    if (IsKeyPressed(KEY_LEFT))
    {
        impulsoActual -= IMPULSO_STEP;
    }

    if (impulsoActual > IMPULSO_MAX) impulsoActual = IMPULSO_MAX;
    if (impulsoActual < IMPULSO_MIN) impulsoActual = IMPULSO_MIN;

    //lanzamiento del proyectil con el impulso ajustado
    if (IsKeyPressed(KEY_SPACE))
    {
        Proyectil* nuevo = new Proyectil(
            *world,
            PROYECTIL_SPAWN_X,
            PROYECTIL_SPAWN_Y,
            PROYECTIL_RADIO,
            PROYECTIL_COLOR
        );

        nuevo->ApplyImpulse(impulsoActual,IMPULSO_Y);   //aplico impulso contra la gravedad con componente Y negativo

        proyectiles.push_back(nuevo);
    }

    //update general del mundo
    world->Step(1.0f / 60.0f, 8, 3);
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

    //render el proyectil en espera
    DrawCircle(
        PROYECTIL_SPAWN_X,
        PROYECTIL_SPAWN_Y,
        PROYECTIL_RADIO,
        PROYECTIL_COLOR
    );

    for (auto proyectil : proyectiles)
    {
        proyectil->Draw();
    }

    DrawText(
        TextFormat("Potencia: %.0f", impulsoActual),
        20,
        20,
        20,
        BLACK
    );

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