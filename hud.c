#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "hud.h"

void initializeTimer(Timer* timer, Uint32 startTime, SDL_Surface* screenSurface, SDL_Renderer* renderer)
{

    timer->startTime = startTime;
    timer->currentTime = SDL_GetTicks();
    timer->font = TTF_OpenFont("texture/font/MouldyCheeseRegular-WyMWG.ttf", 60); //ouverture du fichier de police
    if (timer->font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }
    timer->renderer = renderer;
    timer->screenSurface = screenSurface;
    timer->seconds = 0;
    timer -> minutes = 0;
    timer->color.r =255;
    timer->color.g =255;
    timer->color.b =255;
    timer->color.a =255;
}



void renderTimer(Timer* timer)
{
    timer->currentTime = SDL_GetTicks(); //On récupère le temps em ms

    Uint32 elapsedMinutes = ((timer->currentTime - timer->startTime) / 1000) / 60; //temps écoulé en m et s
    Uint32 elapsedSeconds = ((timer->currentTime - timer->startTime) / 1000) % 60;

    if(1 || elapsedSeconds!=timer->seconds)
    {
        char textTimer[6];
        sprintf(textTimer, "%d:%02d", elapsedMinutes, elapsedSeconds);  // Conversion en string


        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(timer->font, textTimer, timer->color);
        if (surfaceMessage == NULL) {
            printf("Failed to create surface for text! SDL Error: %s\n", SDL_GetError());
            TTF_CloseFont(timer->font);
            return;
        }


        SDL_Texture* Message = SDL_CreateTextureFromSurface(timer->renderer, surfaceMessage);
        if (Message == NULL) {
            printf("Failed to create texture from surface! SDL Error: %s\n", SDL_GetError());
            SDL_FreeSurface(surfaceMessage);
            TTF_CloseFont(timer->font);
            return;
        }

        SDL_Rect Message_rect; //create a rect
        Message_rect.x = 10;  //controls the rect's x coordinate
        Message_rect.y = 10; // controls the rect's y coordinate
        Message_rect.w = surfaceMessage->w + 10; // controls the width of the rect
        Message_rect.h = surfaceMessage->h + 10; // controls the height of the rect

        timer->seconds = elapsedSeconds; //réattribution des valeurs
        timer->minutes = elapsedMinutes;

        SDL_RenderCopy(timer->renderer, Message, NULL, &Message_rect); //enregistrement dans le rendu

        // Free resources
        SDL_DestroyTexture(Message); //libération mémoire
        SDL_FreeSurface(surfaceMessage);
    }
}
