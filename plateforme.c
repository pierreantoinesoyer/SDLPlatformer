#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Plateform{
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    struct Plateform *next;
    bool isDisplayed;
}Plateform;

//inserer une plateforme
void insert(Plateform** head, int posX, int posY, int sizeX, int sizeY)
{
    Plateform* newPlateform = (Plateform*)malloc(sizeof(Plateform));

    newPlateform->posX = posX;
    newPlateform->posY = posY;
    newPlateform->sizeX = sizeX;
    newPlateform->sizeY = sizeY;
    newPlateform->next = NULL;
    newPlateform->isDisplayed = false;

    if (*head == NULL) {
        *head = newPlateform; // Si la liste est vide, le nouvel �l�ment devient la t�te
    }
    else
    {
        Plateform* current = *head;
        while (current->next != NULL) {
            current->isDisplayed = false; // Met � jour le flag isLast de l'�l�ment pr�c�dent
            current = current->next;
        }
        current->isDisplayed = false; // Met � jour le flag isLast de l'�l�ment pr�c�dent du dernier �l�ment existant
        current->next = newPlateform; // Ajoute le nouvel �l�ment � la fin de la liste
    }
}


//detruire la structure
void destroyPlateform(Plateform* plateform)
{
    if(plateform!= NULL)
    {
        free(plateform);
    }
}


void createPlateform(Plateform** plateform)
{
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
        insert(plateform,posX,posY,sizeX,sizeY);
    }
}

int count(Plateform** plateform)
{
    int i = 0;
    if (*plateform == NULL) {
        return i;
    } else {
        Plateform* current = *plateform;
        while(current->next != NULL)
        {
            i++;
            current = current->next;
        }
    return i;
    }
}

Plateform* returnPlatform(Plateform* plateform,int index) {
    Plateform* current = plateform;
    int i = 0;
    while (current != NULL) {
        if(index == i)
        {
            return current;
        }
        i++;
        current=current->next;
    }
    exit(0);
}
