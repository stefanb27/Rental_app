//
// Created by Stefan on 03.03.2021.
//
//#include "domain.h"
//#include "vct.h"
//#include "domain.h"
#include "vct.h"
#include <stdio.h>
#include <stdlib.h>

ListCars* CreateList()
{
    /*
     * creeaza o lista si o aloca dinamic in memorie
     */
    ListCars* list = malloc(sizeof(ListCars));
    list->nrElements = 0;
    list->maxElements = 2;
    list->l = malloc(list->maxElements * sizeof(void*));
    //list->df = DF;
    return list;
}

void Realloc(ListCars* pCars)
{
    /*
     * realoca lista dinamic cand se doreste sa se mareasca
     * numarul de elemente
     * pCars : ListCars
     */
    if(pCars->nrElements < pCars->maxElements) return;
    void** newList = malloc(2 * (pCars->maxElements) * sizeof (void*));
    for(int i = 0; i < pCars->nrElements; i ++)
    {
        newList[i] = pCars->l[i];
    }
    free(pCars->l);
    pCars->l = newList;
    pCars->maxElements *= 2;
}

void addCar(ListCars* pCars, Car *car)
{
    /*
     * adauga o masina in lista
     * pCars : ListCars
     * car : Car
     */
    Realloc(pCars);
    pCars->l[pCars->nrElements] = car;
    pCars -> nrElements ++;
}

Car* getCar(ListCars* pCars, int index)
{
    /*
     * returneaza masina cu indexul dat
     * pCars : ListaCars (lista de masini)
     * index : int
     */
   // Car *c = pCars->l[index];
    //Car *c2 = CreateCar(c->nr, c->model, c->category);
    //return c2;
    return pCars->l[index];
}

int getCarIndex(ListCars *pCars, char *numar)
{
    /*
     * returneaza indexul masinii cu numarul de inmatriculare
     * dat
     * numar : char
     */
    int index = -1;
    for(int i = 0; i < pCars->nrElements; i ++) {
        Car *c = getCar(pCars, i);
        if (strcmp(c->nr, numar) == 0) {
            //printf("Am gasit!");
            index = i;
        }
        //destroyCar(c);
    }
    return index;
}

int getSize(ListCars* pCars)
{
     return pCars->nrElements;
}
void updateCar(ListCars* pCars, int index, Car *newCar)
{
     /*updateaza o masina din lista cu valori noi
      * index : int
      * newCar : Car
      */
     pCars->l[index] = newCar;
}

ListCars* showCars(ListCars* pCars)
{
    /*
     * returneaza lista de masini
     */
   // ListCars *l = CreateList();
   // for(int i = 0; i < pCars->nrElements; i ++)
    //    addCar(l, pCars->l[i]);
    //return l;
    return pCars;
}

void destroyCars(ListCars* pCars)
{
    for(int i = 0; i < pCars -> nrElements; i ++)
    {
        destroyCar(pCars->l[i]);
        free(pCars->l[i]);
        //pCars->df(pCars->l[i]);
    }
    //free(pCars->l);
    free(pCars->l);
    free(pCars);
}

