#include "Proyectil.h"
#include "Constantes.h"

Proyectil::Proyectil(
    b2World& world,
    float x,
    float y,
    float radio,
    Color color
)
{
    this->radio = radio;
    this->color = color;

    //body

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(
        x / SCALE,
        y / SCALE
    );

    body = world.CreateBody(&bodyDef);

    //shape
    b2CircleShape circleShape;
    circleShape.m_radius = radio / SCALE;

    //fixture
    b2FixtureDef fixtureDef;

    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f;

    body->CreateFixture(&fixtureDef);
}

void Proyectil::Update()
{
}

void Proyectil::Draw()
{
    b2Vec2 pos = body->GetPosition();

    DrawCircle(
        (int)(pos.x * SCALE),
        (int)(pos.y * SCALE),
        radio,
        color
    );
}

void Proyectil::ApplyImpulse(float x,float y)
{
    body->ApplyLinearImpulseToCenter(
        b2Vec2(x, y),
        true
    );
}

b2Body* Proyectil::GetBody()
{
    return body;
}