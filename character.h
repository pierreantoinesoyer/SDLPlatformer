#include <SDL2/SDL.h>


typedef struct Character{
    char* path;
    int x;
    int y;

}Character;


Character *initCharacter(int x, int y);
void printCharacter(Character *perso);
void DisplayCharacter(Character *Character,SDL_Surface* screenSurface);

