//
// Created by Stefan on 03.03.2021.
//

#ifndef LAB2_4_VCT_H
#define LAB2_4_VCT_H

#include "domain.h"

typedef void(*DestroyFunction) (void*);

typedef struct
{
    void **l;
    int nrElements;
    int maxElements;
    //DestroyFunction df;
} ListCars;

ListCars* CreateList();
void Realloc(ListCars* pCars);
void addCar(ListCars* pCars, Car *car);
Car* getCar(ListCars* pCars, int index);
ListCars* showCars(ListCars* pCars);
int getCarIndex(ListCars *pCars, char *numar);
void updateCar(ListCars* pCars, int index, Car *newCar);
int getSize(ListCars* pCars);
void destroyCars(ListCars* pCars);

#endif //LAB2_4_VCT_H
