#include <stdio.h>
#include <SDL2/SDL.h>
#include "background.h"

// Chargement de la texture d'arrière plan
SDL_Surface* loadImage(const char* filePath)
{
    SDL_Surface* loadedSurface = SDL_LoadBMP(filePath);
    return loadedSurface;
}


//rendu de l'arrière plan
void renderBackground(SDL_Surface* screenSurface)
{

    // Chargement image
    SDL_Surface* backgroundSurface = loadImage("texture/background/back.bmp");

    // Ajout de l'image sur l'écran
    SDL_BlitSurface(backgroundSurface, NULL, screenSurface, NULL);

    // libération de la surface écran
    SDL_FreeSurface(backgroundSurface);
}
