#include "raylib.h"
#include "Constantes.h"

//escala para convertir pixeles/metros
//metros a píxeles : *SCALE
//píxeles a metros : / SCALE
const float SCALE = 30.0f;

const int SCREENWIDTH = 1000;
const int SCREENHEIGHT = 600;


//para render de proyectiles
const float PROYECTIL_SPAWN_X = 100.0f;
const float PROYECTIL_SPAWN_Y = 450.0f;
const float PROYECTIL_RADIO = 20.0f;
const Color PROYECTIL_COLOR = DARKGRAY;

//parametros del impulso
const float IMPULSO_X = 8.0f;
const float IMPULSO_Y = -6.0f;

const float IMPULSO_MIN = 2.0f;
const float IMPULSO_MAX = 50.0f;
const float IMPULSO_STEP = 1.0f;

const bool DEBUG_MODE = false;