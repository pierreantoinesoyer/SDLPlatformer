/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "plateforme.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            //Update the surface
            SDL_UpdateWindowSurface(window);

            // Setup renderer
            SDL_Renderer* renderer = NULL;
            renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

            // Clear window
            SDL_RenderClear( renderer );

            // initialization tab of SDL_Rect
            SDL_Rect multi_rect[5];

            // Create Plateform
            Plateform* plateform = NULL;
            createPlateform(&plateform);
            // Add value for each rectangle
            for (int i = 0; i < 5; i++)
            {
                multi_rect[i].x = returnPlateform(plateform,i)->posX;
                multi_rect[i].y = returnPlateform(plateform,i)->posY;
                multi_rect[i].w = returnPlateform(plateform,i)->sizeX;
                multi_rect[i].h = returnPlateform(plateform,i)->sizeY;
            }
            // Fill green color to the rectangle
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRects(renderer, multi_rect, 5);

            SDL_RenderPresent(renderer);

            //Destroy Plateform
            destroyPlateform(plateform);

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
        }
    }

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
