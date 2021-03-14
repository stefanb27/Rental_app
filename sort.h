//
// Created by Stefan on 08.03.2021.
//

#ifndef LAB2_4_SORT_H
#define LAB2_4_SORT_H
#include "vct.h"

typedef int(*cmp) (Car* c1, Car* c2);
void sort(ListCars* l, cmp cmpF);

#endif //LAB2_4_SORT_H
