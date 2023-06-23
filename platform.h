#ifndef PLATEFORM
#define PLATEFORM
typedef struct Platform{
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    struct Platform *next;
    bool isDisplayed;
    char file[10];
    SDL_Surface* platformSurface;
}Platform;
void insert(Platform** head, int posX, int posY, int sizeX, int sizeY, char* file);
void destroyPlatform(Platform* platform);
void createPlatform(Platform** platform);
Platform* returnPlateform(Platform* platform,int index);

#endif
