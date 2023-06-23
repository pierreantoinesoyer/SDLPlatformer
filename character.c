#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "character.h"

Character *createCharacter(SDL_Renderer *rend){
    Character  *ptrCharacter = malloc(sizeof(Character));
    ptrCharacter->path = "./texture/character/still.bmp";
    ptrCharacter->x = 1000;
    ptrCharacter->y = 1000;
    ptrCharacter->sizeWidth = 40;
    ptrCharacter->sizeHeight = 40;

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
    dest.x = (ptrCharacter->x - dest.w) / 2;
    // sets initial y-position of object
    dest.y = (ptrCharacter->y - dest.h) / 2;
    ptrCharacter->rect = dest;




    return ptrCharacter;

}

void renderCharacter(SDL_Renderer* renderer, Character* character)
{
    if (character == NULL)
    {
        exit(8);
    }
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
