//
// Created by Stefan on 07.03.2021.
//

#ifndef LAB2_4_SERVICE_H
#define LAB2_4_SERVICE_H

#include "repo.h"

typedef struct {
    Repository* r;
    ListCars* undo;
} Service;

Service createService();
void addCarS(Service *s,Car* e);
ListCars *showCarS(Service *s);
int rentCarS(Service* s, char* nr);
void updateCarS(Service * s, int index, Car *newCar);
int getSizeS(Service* s);
Car* getCarS(Service *s, int index);
int returnCarS(Service *s, char *nr);
ListCars* filterModelS(Service* s, char *model);
ListCars* filterCategoryS(Service* s, char *category);

void destroyS(Service *s);

ListCars* SortCars(Service* s, int filter, int reverse);
int cmpModelFwd(Car * c1, Car * c2);
int cmpCategoryFwd(Car * c1, Car * c2);
int cmpModelAft(Car * c1, Car * c2);
int cmpCategoryAft(Car * c1, Car * c2);

#endif //LAB2_4_SERVICE_H
