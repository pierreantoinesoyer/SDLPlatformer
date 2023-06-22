#include <stdio.h>
#include <SDL2/SDL.h>
#include "background.h"

Background* createBackground(SDL_Renderer* renderer)
{
    Background* background = malloc(sizeof(Background)); //allocation mémoire

    SDL_Surface* loadedSurface = SDL_LoadBMP("texture/background/back.bmp");  //chargement BMP
    if (loadedSurface == NULL)
    {
        printf("Failed to load background image! SDL_Error: %s\n", SDL_GetError());
        free(background);
        return NULL;
    }

    background->texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);  //création texture
    SDL_FreeSurface(loadedSurface); //libération mémoire

    if (background->texture == NULL)
    {
        printf("Failed to create background texture! SDL_Error: %s\n", SDL_GetError());
        free(background);
        return NULL;
    }
    SDL_Rect destinationRect;

    destinationRect.w = loadedSurface->w;   //chargement des valeurs dans le background
    destinationRect.h = loadedSurface->h;;

    background->destinationRect.x = 0;
    background->destinationRect.y = 0;

    background->destinationRect = destinationRect;

    return background;
}

void renderBackground(SDL_Renderer* renderer, Background* background)
{
    if (background == NULL)
    {
        return;
    }
    SDL_RenderCopy(renderer, background->texture, NULL, &background->destinationRect);
}
