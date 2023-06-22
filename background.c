#include <stdio.h>
#include <SDL2/SDL.h>
#include "background.h"

// Chargement de la texture d'arri�re plan
SDL_Surface* loadImage(const char* filePath)
{
    SDL_Surface* loadedSurface = SDL_LoadBMP(filePath);
    return loadedSurface;
}


//rendu de l'arri�re plan
void renderBackground(SDL_Surface* screenSurface)
{

    // Chargement image
    SDL_Surface* backgroundSurface = loadImage("texture/background/back.bmp");

    // Ajout de l'image sur l'�cran
    SDL_BlitSurface(backgroundSurface, NULL, screenSurface, NULL);

    // lib�ration de la surface �cran
    SDL_FreeSurface(backgroundSurface);
}
