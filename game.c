#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "character.h"
#include "platform.h"

const float GRAVITY = 0.5f;

typedef struct Game{
    Character* character;
    Platform* platform;
}Game;

void initGame(Game* game, Platform* platform,Character* character)
{
    game->character = character;
    game->platform = platform;
    game->character->isJumping = true;
}

void checkCollision(Platform* platform,Character* character, Game* game)
{
    int diffY = character->y + character->sizeHeight + character->speedY - platform->posY;
    if(diffY < character->sizeHeight/2 && diffY > 0)
    {
        int diffLeft = character->x + character->sizeWidth - platform->posX;
        int diffRight = character->x - (platform->posX + platform->sizeX);
        if(diffLeft>0 && diffRight<0)
        {
            character->y=platform->posY-character->sizeHeight;
            character->speedY=0;
            game->character->isJumping=false;
        }
    }

}

void characterGravity(Game* game)
{

    game->character->speedY+=GRAVITY;

    Platform* current = game->platform;
    while(current!=NULL)
    {
        if(current->isDisplayed)
        {
            checkCollision(current, game->character, game);
        }
        current = current->next;
    }
}
