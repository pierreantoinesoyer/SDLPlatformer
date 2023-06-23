#include <SDL2/SDL.h>

typedef struct Game{
    Character* character;
    Platform* platform;
    bool isJumping;
}Game;

void initGame(Game* game, Platform* platform,Character* character);

void checkCollision(Platform* platform,Character* character, Game* game);

void characterGravity(Game* game);
