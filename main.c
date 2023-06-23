#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "background.h"
#include "hud.h"
#include "platform.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 750;

int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    Uint32 startTime = SDL_GetTicks(); //On r�cup�re le temps de d�part


    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        if (TTF_Init() < 0) {
            printf("SDL_ttf could not initialize! SDL_ttf Error");
            // Handle initialization error
        }
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        Timer* timer = malloc(sizeof(Timer));
        initializeTimer(timer, startTime, screenSurface, renderer);

        Background* background = createBackground(renderer);

        Plateform* platform = NULL;
        createPlateform(&platform);

        SDL_RenderPresent(renderer);

        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            // Update the surface
            SDL_UpdateWindowSurface(window);

            //Hack to get window to stay up
            SDL_Event e;
            bool quit = false;
            Uint32 frameTime = SDL_GetTicks();

            while( quit == false )
            {


                renderBackground(renderer, background);
                renderPlatform(renderer, platform);
                renderTimer(timer);

                SDL_RenderPresent(renderer);


                Uint32 endFrame = SDL_GetTicks();
                int32_t delay = (16 - (SDL_GetTicks() - frameTime)); //entier sign� n�cessaire

                if(delay<1)
                {
                    delay = 1;
                }

                SDL_Delay(delay);
                frameTime = SDL_GetTicks();

                while( SDL_PollEvent( &e ) )
                {
                    if( e.type == SDL_QUIT )
                    quit = true;
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
