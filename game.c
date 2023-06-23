#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "character.h"
#include "platform.h"

const int GRAVITY = 20;

typedef struct Game{
    Character* character;
    Platform* platform;
    bool isJumping;
}Game;

void checkCollision(Platform* platform,Character* character)
{
    int diffY = character->y+character->sizeHeight+character->speedY-plateform->posY;
    if(diffY<0 && diffY>-character->sizeHeight)
    {
        int diffLeft = character->x+ character->sizeWidth - platform->posX;
        int diffRight = character->x - (platform->posX + platform->sizeX);
        if(diffLeft>0||diffRight<0)
        {
            character->y=platform->posY-character->sizeHeight;
            character->speedY=0;
        }
    }

}

void charaterGravity(Game* game)
{
    if(game->isJumping==true)
    {
        game->character.speedY+=GRAVITY;
    }
    Platform* current = Game->platform;
    while(current!=NULL)
    {
        if(current->isDisplayed)
        {
            checkCollision(current,game->character);
        }
        current = current->next;
    }
}
