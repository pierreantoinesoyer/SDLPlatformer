#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "character.h"

Character *createCharacter(SDL_Renderer *rend){
    Character  *ptrCharacter = malloc(sizeof(Character));
    ptrCharacter->path = "./texture/character/still.bmp";
    ptrCharacter->x = 100;
    ptrCharacter->y = 100;
    ptrCharacter->sizeWidth = 100;
    ptrCharacter->sizeHeight = 100;
    ptrCharacter->speedX = 0;
    ptrCharacter->speedY = 0;

    SDL_Surface* characterSurface = NULL;
    characterSurface = SDL_LoadBMP("./texture/character/still.bmp");
    if(characterSurface == NULL){
        printf("chararcter surface is NULL");
        exit(7);
    }
    else{
        ptrCharacter->texture = SDL_CreateTextureFromSurface(rend, characterSurface);
        SDL_FreeSurface(characterSurface);
    }
    SDL_Rect dest;
    SDL_QueryTexture(ptrCharacter->texture, NULL, NULL, &dest.w, &dest.h);
    dest.w = ptrCharacter->sizeWidth;
    dest.h = ptrCharacter->sizeHeight;
    // sets initial x-position of object
    dest.x = ptrCharacter->x;
    // sets initial y-position of object
    dest.y = ptrCharacter->y;
    ptrCharacter->rect = dest;




    return ptrCharacter;

}

void renderCharacter(SDL_Renderer* renderer, Character* character)
{
    if (character == NULL)
    {
        exit(8);
    }
    updateCharacterPosition(character);
    SDL_RenderCopy(renderer, character->texture, NULL, &character->rect);
}


void printCharacter(Character *perso){
    printf("image du character %s\n pos x: %d\tpos y: %d\n",perso->path,perso->x,perso->y);


}

void DisplayCharacter(Character *Character,SDL_Surface* screenSurface){
    // Chargement image
    SDL_Surface* characterSurface = SDL_LoadBMP(Character->path);

    // Ajout de l'image sur l'écran
    SDL_BlitSurface(characterSurface, NULL, screenSurface, NULL);

    // libération de la surface écran
    SDL_FreeSurface(characterSurface);

}

void updateCharacterPosition(Character* character)
{
    character->x = character->x + character->speedX;
    character->y = character->y + character->speedY;

    SDL_Rect dest;
    SDL_QueryTexture(character->texture, NULL, NULL, &dest.w, &dest.h);
    dest.w = character->sizeWidth;
    dest.h = character->sizeHeight;
    // sets initial x-position of object
    dest.x = character->x;
    // sets initial y-position of object
    dest.y = character->y;
    character->rect = dest;

}
