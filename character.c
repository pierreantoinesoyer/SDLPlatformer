#include <stdlib.h>
#include <stdio.h>
#include "character.h"

Character *initCharacter(char* path, int x, int y){
    Character   *ptrCharacter = malloc(sizeof(Character));
    ptrCharacter->path = *path;
    ptrCharacter->x = x;
    ptrCharacter->y = y;
    return ptrCharacter;

}

void DisplayCharacter(Character *Character,SDL_Surface* screenSurface){
    // Chargement image
    SDL_Surface* characterSurface = loadImage(Character->path);

    // Ajout de l'image sur l'écran
    SDL_BlitSurface(characterSurface, NULL, screenSurface, NULL);

    // libération de la surface écran
    SDL_FreeSurface(characterSurface);

}
