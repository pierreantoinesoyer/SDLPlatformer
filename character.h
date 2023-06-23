#include <SDL2/SDL.h>


typedef struct Character{
    char* path;
    int x;
    int y;
    SDL_Texture* texture;
    SDL_Rect rect;
    int sizeHeight ;
    int sizeWidth ;
    float speedX;
    float speedY;
    bool isJumping;

}Character;


Character *createCharacter(SDL_Renderer * rend);
void printCharacter(Character *perso);
void renderCharacter(SDL_Renderer* renderer, Character* character);
void controlCharacter(Character *ptrCharacter,SDL_Event *ptrEvent, bool *quit,int *speed);
void DisplayCharacter(Character *Character,SDL_Surface* screenSurface);

