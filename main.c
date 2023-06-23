#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "background.h"
#include "hud.h"
#include "platform.h"
#include "character.h"
#include "game.h"

//Screen dimension constants
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 750

int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    Uint32 startTime = SDL_GetTicks(); //On récupère le temps de départ


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

        Platform* platform = NULL;
        createPlatform(&platform);

        Character* character = createCharacter(renderer);
        Game* game = malloc(sizeof(Game));
        initGame(game, platform, character);

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
            bool quit = false;
            Uint32 frameTime = SDL_GetTicks();
            int speed = 60;

            while( quit == false )
            {

                SDL_Event event;
                controlCharacter(character,&event, &quit,&speed);


                characterGravity(game);


                renderBackground(renderer, background);
                renderPlatform(renderer, platform);
                renderCharacter(renderer, character);
                renderTimer(timer);

                SDL_RenderPresent(renderer);


                Uint32 endFrame = SDL_GetTicks();
                int32_t delay = (16 - (SDL_GetTicks() - frameTime)); //entier signé nécessaire

                if(delay<1)
                {
                    delay = 1;
                }

                SDL_Delay(delay);
                frameTime = SDL_GetTicks();


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
