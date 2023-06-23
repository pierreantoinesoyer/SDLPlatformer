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

    //The surface contained by the window
    //SDL_Surface* screenSurface = NULL;

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
//            //Get window surface
//            //screenSurface = SDL_GetWindowSurface(window);

            //Fill the surface white
            ///SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            //Update the surface
            SDL_UpdateWindowSurface(window);

            // Setup renderer
            SDL_Renderer* renderer = NULL;
            renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

            // Clear window
            SDL_RenderClear( renderer );
            SDL_Rect multi_rect[5];
            Plateform* plateform = NULL;
            createPlateform(&plateform);
            for (int i = 0; i < 5; i++)
            {
                multi_rect[i].x = returnPlatform(plateform,i)->posX;
                multi_rect[i].y = returnPlatform(plateform,i)->posY;
                multi_rect[i].w = returnPlatform(plateform,i)->sizeX;
                multi_rect[i].h = returnPlatform(plateform,i)->sizeY;
            }
//            for(int i=0; i<5;i++)
//            {
//                multi_rect[i].x = rand() % 600;
//                multi_rect[i].y = 100*i;
//                multi_rect[i].w = 300;
//                multi_rect[i].h = 30;
//            }
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRects(renderer, multi_rect, 5);

            SDL_RenderPresent(renderer);

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
