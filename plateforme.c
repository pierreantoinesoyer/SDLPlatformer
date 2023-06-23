#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Creation de la structure plateform
typedef struct Plateform{
    //Position de la plateforme
    int posX;
    int posY;
    //Taille de la plateforme
    int sizeX;
    int sizeY;
    //Une plateforme pointe vers la plateforme suivante
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
        *head = newPlateform; // Si la liste est vide, le nouvel élément devient la tête
    }
    else
    {
        Plateform* current = *head;
        while (current->next != NULL) {
            current->isDisplayed = false; // Met à jour le flag isDisplayed de l'élément précédent
            current = current->next;
        }
        current->isDisplayed = false; // Met à jour le flag isDisplayed de l'élément précédent du dernier élément existant
        current->next = newPlateform; // Ajoute le nouvel élément à la fin de la liste
    }
}


//detruire la plateform
void destroyPlateform(Plateform* plateform)
{
    if(plateform!= NULL)
    {
        free(plateform);
    }
}

//creation de 5 plateforme
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

//Compte le nombre de plateforme
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

//return la une plateforme en fontion d'un index
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
