//
// Created by Stefan on 07.03.2021.
//
#include "repo.h"

Repository *createRepo()
{
    /*
     * creeaza un repository pe care il aloca in memorie
     */
    Repository *r = malloc(sizeof(Repository));
    r->list = CreateList();
    return r;
}

void addCarR(Repository* r, Car* e)
{
    /*
     * adauga o masina in lista
     * r : Repository
     * e : Car
     */
    addCar(r->list, e);
}

ListCars* showCarsR(Repository* r)
{
    /*
     * returneaza lista de masini de tip ListCars
     * r : Repository
     */
     return showCars(r->list);
}
int getCarIndexR(Repository *r, char *numar)
{
    /*
     * returneaza indexul unei masini
     * r : Repository
     * numar : char (numarul de inmatriculare al masinii)
     */
    return getCarIndex(r->list, numar);
}

int getSizeR(Repository* r)
{
    return getSize(r->list);
}
Car* getCarR(Repository  *r, int index)
{
    /*
     * returneaza masina (Car) care se afla pe pozitia = index in lista
     * index : int
     */
    return getCar(r->list, index);
}

void updateCarR(Repository* r, int index, Car *newCar)
{
    /*
     * face update la o masina din lista
     * r : Repository
     * index : int
     * newCar : Car
     */
    updateCar(r->list, index, newCar);
}

void destroyR(Repository* r)
{
    destroyCars(r->list);
    free(r);
}

