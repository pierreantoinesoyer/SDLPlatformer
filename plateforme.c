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
    // Allocation de memoire pour une nouvelle structure Plateform
    Plateform* newPlateform = (Plateform*)malloc(sizeof(Plateform));

    // Creation de la nouvelle plateforme
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
        current->isDisplayed = false; // Met à jour le flag isDisplayed de la plateforme précédente de la dernière plateforme existante
        current->next = newPlateform; // Ajoute la nouvelle plateforme à la fin de la liste
    }
}


// Destruction de la plateform
void destroyPlateform(Plateform* plateform)
{
    if(plateform!= NULL)
    {
        free(plateform);
    }
}

// Creation de 5 plateformes
void createPlateform(Plateform** plateform)
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

// Return une plateforme en fontion d'un index
Plateform* returnPlateform(Plateform* plateform,int index) {
    Plateform* current = plateform;
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
