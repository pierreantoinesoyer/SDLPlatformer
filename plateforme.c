#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Plateform{
    float posX;
    float posY;
    float sizeX;
    float sizeY;
    struct Plateform *next;
    bool isDisplayed;
}Plateform;

//inserer une plateforme
void insert(Plateform** head, float posX, float posY, float sizeX, float sizeY)
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
    } else {
        Plateform* current = *head;
        while (current->next != NULL) {
            current->isDisplayed = false; // Met à jour le flag isLast de l'élément précédent
            current = current->next;
        }
        current->isDisplayed = false; // Met à jour le flag isLast de l'élément précédent du dernier élément existant
        current->next = newPlateform; // Ajoute le nouvel élément à la fin de la liste
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
