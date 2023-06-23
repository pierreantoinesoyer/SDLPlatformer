#include <SDL2/SDL.h>

typedef struct Background
{
    SDL_Texture* texture;
    SDL_Rect destinationRect;
} Background;

Background* createBackground(SDL_Renderer* renderer);
void renderBackground(SDL_Renderer* renderer, Background* background);

