//
// Created by Stefan on 03.03.2021.
//
#include "service.h"
#include <string.h>
Service createService()
{
    /*
     * creeaza Service
     */
    Service s;
    s.r = createRepo();
    return s;
}
void addCarS(Service *s,Car* e)
{
    /*
     * adauga masina in lista
     * s : Service
     * e : Car
     */
     addCarR(s->r, e);
}
ListCars* showCarS(Service *s)
{
    /*
     * afiseaza
     */
    /*
    ListCars *l = showCarsR(s->r);
    for(int i = 0; i < l->nrElements; i ++) {
        Car* c = getCar(l, i);
        printf("%s %s %s \n", c->nr, c->model, c->category);
    }
     */
    return showCarsR(s->r);
    //showCars()
}

void updateCarS(Service* s, int index, Car *newCar)
{
    /*
     * updateaza o masina din lista
     * s : Service
     * index : i
     * newCar : Car
     */
    updateCarR(s->r, index, newCar);
}

int getSizeS(Service* s)
{
    return getSizeR(s->r);
}

Car* getCarS(Service *s, int index)
{
    return getCarR(s->r, index);
}

int rentCarS(Service* s, char* nr)
{
    /*
     * returneaza 1 daca masina data ca parametru poate
     * fi inchiriat sau 0 altfel
     * nr : char (numarul de inmatriculare )
     */
    int i = getCarIndexR(s->r, nr);
    if(i == -1)
        return 0;
    Car *c = getCarR(s->r, i);
    if(c->rent != 0)
        return -1;

    if(c->rent == 0)
    {
        c->rent = 1;
        return 1;
    }

}

int returnCarS(Service *s, char *nr)
{
    int i = getCarIndexR(s->r, nr);
    if(i == -1)
        return 0;
    Car *c = getCarR(s->r, i);
    if(c->rent == 1)
    {
        c->rent = 0;
        return 1;
    }

    if(c->rent == 0)
        return -1;

}

ListCars* filterModelS(Service* s, char *model)
{
    ListCars *l = CreateList();
    for(int i = 0; i < getSizeS(s); i ++)
    {
        Car *c = getCarS(s, i);
        if(strcmp(c->model, model) == 0)
        {
            addCar(l, c);
        }
    }
    return l;
}

ListCars* filterCategoryS(Service* s, char *category)
{
    ListCars *l = CreateList();
    for(int i = 0; i < getSizeS(s); i ++)
    {
        Car *c = getCarS(s, i);
        if(strcmp(c->category, category) == 0)
        {
            addCar(l, c);
        }
    }
    return l;
}

ListCars* SortCars(Service* s, int filter, int reverse)
{
    ListCars* rez = showCarS(s);
    //faci cu reversul
    if(reverse == 1)
    {
        if(filter == 1)
            sort(rez, cmpModelFwd);
        else
            sort(rez, cmpCategoryFwd);
    }
    else
    {
        if(filter == 1)
            sort(rez, cmpModelAft);
        else
            sort(rez, cmpCategoryAft);
    }
    return rez;
}

int cmpModelFwd(Car * c1, Car * c2) {
    int i = strcmp(c1->model, c2->model);
    return i * (-1);
}

int cmpCategoryFwd(Car * c1, Car * c2) {
    int i = strcmp(c1->category, c2->category);
    return i * (-1);
}

int cmpModelAft(Car * c1, Car * c2) {
    return strcmp(c1->model, c2->model);
}

int cmpCategoryAft(Car * c1, Car * c2) {
    return strcmp(c1->category, c2->category);
}

void destroyS(Service *s)
{
    destroyR(s->r);
}