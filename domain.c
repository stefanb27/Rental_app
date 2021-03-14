//
// Created by Stefan on 03.03.2021.
//
//
// Created by Stefan on 03.03.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domain.h"
/*
typedef struct
{
    char *nr;
    char *model;
    char *category;
} Car;
*/

//Car* CreateCar(char *nr, char* model, char *category);

//Car* CreateCar(char *nr, char* model, char *category);

/*
Car* readCar()
{
    char Nr[11], Model[11], Category[11];
    while(1) {
        printf("Dati numarul de inmatriculare: ");
        scanf("%s", Nr);
        if(validateNr(Nr) == 0)
        {
            printf("Numarul de inmatriculare trebuie "
                   "sa fie de foma 'llcclll'");
            printf("\n");
        }
        if(validateNr(Nr) == 1)
            break;
    }
    while(1) {
        printf("Dati modelul: ");
        scanf("%s", Model);
        if(validateModel(Model) == 0) {
            printf("Modelul de masina este invalid!\n");
            printf("Modele posibile: ");
            printf("{dacia, skoda, ford, hyundai, toyota, suzuki, peugeot, mercedes, bmw, audi, lamborghini, volkswagen, tesla, porsche, volvo, honda, jeep, fiat, mazda, alfa romeo, lexus, jaguar, citroen, maserati, ferrari, chevrolet}");
            printf("\n");
        }
        if(validateModel(Model) == 1)
            break;
    }
    while(1)
    {
        printf("Dati cateogoria: ");
        scanf("%s", Category);
        if(validateCategory(Category) == 0)
        {
            printf("Categoria de masina este invalida!\n");
            printf("Categorii posibile: ");
            printf("{sedan, mini, coupe, suv,cabrio, hatchback, roadster,supercar, van, crossover}");
            printf("\n");
        }
        if(validateCategory(Category) == 1)
            break;
    }

    Car *c = CreateCar(Nr, Model, Category);
    //printf("%s %s %s",c->nr, c->category,c->model);
    return c;
}
*/

Car* CreateCar(char *nr, char* model, char *category)
{
    /*
     * creeaza o masina
     * nr : char
     * model : char
     * category : char
     */
    Car* c = malloc(sizeof(Car));
    c->nr = malloc(sizeof(char) * (strlen(nr) + 1));
    strcpy(c->nr, nr);// nr);
    c->model = malloc(sizeof(char) * (strlen(model) + 1));
    strcpy(c->model, model);
    c->category = malloc(sizeof(char) * (strlen(category) + 1));
    strcpy(c->category, category);
    //c->rent = malloc(sizeof(int));
    c->rent = 0;
    return c;
}

void destroyCar(Car *car)
{
    free(car->nr);
    free(car->model);
    free(car->category);
    //free(car);
}

Car* CopyCar(Car* c)
{
    return CreateCar(c->nr, c->model, c->category);
}




