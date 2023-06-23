
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
    Uint32 startTime; // The start time of the timer
    Uint32 currentTime;
    TTF_Font* font; // The font for rendering the timer text
    SDL_Renderer* renderer; // The renderer for rendering the timer
    SDL_Surface* screenSurface;
    int seconds;
    int minutes;
    SDL_Color color;
} Timer;

void initializeTimer(Timer* timer, Uint32 startTime, SDL_Surface* screenSurface, SDL_Renderer* renderer);
void renderTimer(Timer* timer);
