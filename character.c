#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "character.h"

Character *initCharacter(int x, int y){
    Character   *ptrCharacter = malloc(sizeof(Character));
    ptrCharacter->path = "./texture/character/still.bmp";
    ptrCharacter->x = x;
    ptrCharacter->y = y;
    return ptrCharacter;

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
