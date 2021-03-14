//
// Created by Stefan on 03.03.2021.
//


#ifndef LAB2_4_DOMAIN_H
#define LAB2_4_DOMAIN_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "tests.h"
#include "validators.h"

typedef struct
{
    char *nr;
    char *model;
    char *category;
    int rent;
} Car;

Car* readCar();
Car* CreateCar(char *nr, char* model, char *category);
void destroyCar(Car *car);
Car* CopyCar(Car *c);

#endif //LAB2_4_DOMAIN_H
