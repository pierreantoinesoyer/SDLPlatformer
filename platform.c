#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
}Platform;

//inserer une plateforme
void insert(Platform** head, int posX, int posY, int sizeX, int sizeY)
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
    //initatilisation
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    for(int i=0; i<5;i++)
    {
        posX = rand() % 600;
        posY = 100*i;
        sizeX = 400;
        sizeY = 50;
        insert(platform,posX,posY,sizeX,sizeY);
    }
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
    SDL_Rect multi_rect[5];

    for (int i = 0; i < 5; i++)
    {
        multi_rect[i].x = returnPlatform(platform,i)->posX;
        multi_rect[i].y = returnPlatform(platform,i)->posY;
        multi_rect[i].w = returnPlatform(platform,i)->sizeX;
        multi_rect[i].h = returnPlatform(platform,i)->sizeY;
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRects(renderer, multi_rect, 5);


}
