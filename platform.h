#ifndef PLATEFORM
#define PLATEFORM
typedef struct Platform{
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    struct Platform *next;
    bool isDisplayed;
}Platform;
void insert(Platform** head, int posX, int posY, int sizeX, int sizeY);
void destroyPlatform(Platform* platform);
void createPlatform(Platform** platform);
Platform* returnPlateform(Platform* platform,int index);

#endif
