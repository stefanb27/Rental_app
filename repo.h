//
// Created by Stefan on 07.03.2021.
//

#ifndef LAB2_4_REPO_H
#define LAB2_4_REPO_H

#include "sort.h"

typedef struct {
    ListCars* list;
} Repository;

Repository *createRepo();
void addCarR(Repository* r, Car* e);
ListCars* showCarsR(Repository* r);
int getCarIndexR(Repository *r, char *numar);
Car* getCarR(Repository  *r, int index);
void updateCarR(Repository* r, int index, Car *newCar);
int getSizeR(Repository* r);
void destroyR(Repository* r);

#endif //LAB2_4_REPO_H
