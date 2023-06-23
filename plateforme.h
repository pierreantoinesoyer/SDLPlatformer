#ifndef PLATEFORM
#define PLATEFORM
typedef struct Plateform{
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    struct Plateform *next;
    bool isDisplayed;
}Plateform;
void insert(Plateform** head, int posX, int posY, int sizeX, int sizeY);
void destroyPlateform(Plateform* plateform);
void createPlateform(Plateform** plateform);
Plateform* returnPlateform(Plateform* plateform,int index);

#endif
