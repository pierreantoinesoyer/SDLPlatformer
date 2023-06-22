#include <SDL2/SDL.h>


typedef struct Character{
    char* path;
    int x;
    int y;

}Character;


Character *initCharacter(char* path, int x, int y);
void DisplayCharacter(Character *Character,SDL_Surface* screenSurface);

