//
// Created by Stefan on 06.03.2021.
//
#include "validators.h"
#include <string.h>

int validateNr(char *nr)
{
    /*
     * returneaza 0 daca numarul de inmatriculare nu e valid
     * sau 1 altfel
     * nr : char (numarul de inmatriculare)
     */
    if(strlen(nr) != 7)
        return 0;
    char d1[10];
    strncpy(d1, nr + 2, 2);
    for(int i = 0; i < 2; i ++)
        if(d1[i] < '0' || d1[i] > '9')
            return 0;

    char d2[10];
    strncpy(d2, nr, 2);
    for(int i = 0; i < 2; i ++)
        if(d2[i] < 'a' || d2[i] > 'z')
            return 0;

    char d3[10];
    strncpy(d3, nr + 4, 2);
    for(int i = 0; i < 2; i ++)
        if(d3[i] < 'a' || d3[i] > 'z')
            return 0;

    return 1;
}

int validateModel(char *model)
{
    /*
     * returneaza 1 daca modelul e valid sau 0 altfel
     * model : char (modelul masinii)
     */
    //extern const char *models[];

    char *models[] = {"dacia", "skoda", "ford", "hyundai",
                     "toyota", "suzuki", "peugeot", "mercedes",
                     "bmw", "audi", "lamborghini", "volkswagen",
                     "tesla", "porsche", "volvo", "honda", "jeep",
                     "fiat", "mazda", "alfa romeo", "lexus", "jaguar",
                     "citroen", "maserati", "ferrari", "chevrolet"};

    for(int i = 0; i < 26; i ++)
    {
        if (strcmp(models[i], model) == 0)
            return 1;
    }
    return 0;
}

int validateCategory(char *category)
{
    /*
     * returneaza 1 daca categoria e valida sau 0 altfel
     * category : char (categoria de masina)
     */

    char* categories[] = {"sedan", "mini", "coupe", "suv",
                         "cabrio", "hatchback", "roadster",
                         "supercar", "van", "crossover"};


    for(int i = 0; i < 9; i ++)
        if(strcmp(category, categories[i]) == 0)
            return 1;

    return 0;
}