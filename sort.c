//
// Created by Stefan on 08.03.2021.
//
#include "sort.h"

void sort(ListCars* l, cmp cmpF)
{
    int i, j;
    for(i = 0; i < l->nrElements; i ++)
    {
        for(j = 0; j < l->nrElements; j ++)
        {
            Car* c1 = getCar(l, i);
            Car* c2 = getCar(l, j);
            if(cmpF(c1, c2) > 0)
            {
                updateCar(l, i, c2);
                updateCar(l, j, c1);
            }
        }
    }
}