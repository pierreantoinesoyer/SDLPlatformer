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
    bool isJumping;
}Game;

void initGame(Game* game, Platform* platform,Character* character)
{
    game->character = character;
    game->platform = platform;
    game->isJumping = true;
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
            printf("platform detected : %d, %d", platform->posX, platform->sizeX);
            character->y=platform->posY-character->sizeHeight;
            character->speedY=0;
            game->isJumping=false;
        }
    }

}

void characterGravity(Game* game)
{
    if(game->isJumping==true)
    {
        game->character->speedY+=GRAVITY;
        printf("%f",game->character->speedY);
    }
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
