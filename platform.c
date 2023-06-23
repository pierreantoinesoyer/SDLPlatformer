#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 750

//Creation de la structure plateform
typedef struct Platform{
    //Position de la plateforme
    int posX;
    int posY;
    //Taille de la plateforme
    int sizeX;
    int sizeY;
    //Une plateforme pointe vers la plateforme suivante
    struct Platform *next;
    bool isDisplayed;
    char file[10];
    SDL_Surface* platformSurface;
}Platform;

//inserer une plateforme
void insert(Platform** head, int posX, int posY, int sizeX, int sizeY, char* file)
{
    // Allocation de memoire pour une nouvelle structure Plateform
    Platform* newPlatform = (Platform*)malloc(sizeof(Platform));

    // Creation de la nouvelle plateforme
    newPlatform->posX = posX;
    newPlatform->posY = posY;
    newPlatform->sizeX = sizeX;
    newPlatform->sizeY = sizeY;
    newPlatform->next = NULL;
    newPlatform->isDisplayed = false;
    strncpy(newPlatform->file, file, sizeof(newPlatform->file) - 1);
    newPlatform->file[sizeof(newPlatform->file) - 1] = '\0';


    char filePath[50];
    sprintf(filePath, "texture/platform/%s", newPlatform->file);
    newPlatform->platformSurface = SDL_LoadBMP(filePath);

    if (!newPlatform->platformSurface)
    {
        printf("erreur image plateforme");
        return;
    }



    if (*head == NULL) {
        *head = newPlatform; // Si la liste est vide, le nouvel élément devient la tête
    }
    else
    {
        Platform* current = *head;
        while (current->next != NULL) {
            current->isDisplayed = false; // Met à jour le flag isDisplayed de l'élément précédent
            current = current->next;
        }
        current->isDisplayed = false; // Met à jour le flag isDisplayed de la plateforme précédente de la dernière plateforme existante
        current->next = newPlatform; // Ajoute la nouvelle plateforme à la fin de la liste
    }
}


// Destruction de la plateform
void destroyPlatform(Platform* platform)
{
    if(platform!= NULL)
    {
        free(platform);
    }
}

// Creation de 5 plateformes
void createPlatform(Platform** platform)
{

    insert(platform,850,650,100,70, "1.bmp");
    insert(platform,600,650,200,70, "2.bmp");
    insert(platform,400,400,300,70, "3.bmp");
    insert(platform,600,200,400,70, "4.bmp");
    insert(platform,0,650,500,70, "5.bmp");

    insert(platform,1850,650,100,70, "1.bmp");
    insert(platform,1600,650,200,70, "2.bmp");
    insert(platform,1400,400,300,70, "3.bmp");
    insert(platform,1600,200,400,70, "4.bmp");
    insert(platform,1000,1650,500,70, "5.bmp");



    /*
    for(int i=0; i<5;i++)
    {
        posX = rand() % 600;
        posY = 100*i;
        sizeX = 500;
        sizeY = 60;
        insert(platform,posX,posY,sizeX,sizeY, "5.bmp");
    }*/
}

//Compte le nombre de plateforme
int count(Platform** platform)
{
    int i = 0;
    if (*platform == NULL) {
        return i;
    } else {
        Platform* current = *platform;
        while(current->next != NULL)
        {
            i++;
            current = current->next;
        }
    return i;
    }
}

// Return une plateforme en fontion d'un index
Platform* returnPlatform(Platform* platform,int index) {
    Platform* current = platform;
    int i = 0;
    while (current != NULL) {
        if(index == i)
        {
            return current;
        }
        i++; //iteration de l'index
        current=current->next; // Plateforme suivante
    }
    exit(0);
}

void renderPlatform(SDL_Renderer* renderer, Platform* platform)
{
    SDL_Rect multi_rect[20];


    int i = 0;
    int current_scroll = 0; //will be implemented later

    while (platform!=NULL)
    {
        if((platform->posX > current_scroll + SCREEN_WIDTH) || (platform->posX + platform->sizeX < current_scroll)){
            platform = platform->next;
            continue;
        }


        SDL_Texture* platformTexture = SDL_CreateTextureFromSurface(renderer, platform->platformSurface);
        multi_rect[i].x = platform->posX;
        multi_rect[i].y = platform->posY;
        multi_rect[i].w = platform->sizeX;
        multi_rect[i].h = platform->sizeY;

        SDL_RenderCopy(renderer, platformTexture, NULL, &multi_rect[i]);
        SDL_DestroyTexture(platformTexture);
        platform = platform->next;
        i++;

    }
    //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    //SDL_RenderFillRects(renderer, multi_rect, 5);


}
