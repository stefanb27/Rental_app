//
// Created by Stefan on 03.03.2021.
//
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//DOMAIN------------------------------------------------------------
void testCreateCar()
{
    char n[10] = "bc27ctr", m[10] = "jeep", c[10] = "suv";
    Car *car = CreateCar(n, m, c);
    assert(strcmp(car->nr, n) == 0);
    assert(strcmp(car->model, m) == 0);
    assert(strcmp(car->category, c) == 0);

    char n1[10] = "ct30bum", m1[10] = "bmw", c1[10] = "sport";
    Car *car2 = CreateCar(n1, m1, c1);
    assert(strcmp(car2->nr, n1) == 0);
    assert(strcmp(car2->model, m1) == 0);
    assert(strcmp(car2->category, c1) == 0);

    destroyCar(car);
    free(car);
    destroyCar(car2);
    free(car2);
}

void testReadCar()
{
    assert(validateNr("sv34bgg") == 1);
    assert(validateNr("svssbgg") == 0);
    assert(validateNr("3333bgg") == 0);
    assert(validateNr("sv34bgg99") == 0);
    assert(validateNr("66vv432") == 0);

    assert(validateModel("dacia") == 1);
    assert(validateModel("dasss") == 0);
    assert(validateModel("volvo") == 1);
    assert(validateModel("vol4voo") == 0);

    assert(validateCategory("sedan") == 1);
    assert(validateCategory("das44ss") == 0);
    assert(validateCategory("ssss") == 0);
    assert(validateCategory("mini") == 1);

}
//DOMAIN------------------------------------------------------------

//VCT---------------------------------------------------------------
void testRealloc()
{
    ListCars *pcars = CreateList();
    pcars->nrElements = 2;
    pcars->maxElements = 2;
    Realloc(pcars);
    assert(pcars->nrElements == 2);
    assert(pcars->maxElements == 4);
    pcars->nrElements = 4;
    Realloc(pcars);
    assert(pcars->nrElements == 4);
    assert(pcars->maxElements == 8);
    Realloc(pcars);
    assert(pcars->nrElements == 4);
    assert(pcars->maxElements == 8);
    free(pcars->l);
    free(pcars);
    //destroyCars(pcars);
}

void testAddCar()
{
    ListCars *pcars = CreateList();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCar(pcars, car);
    assert(pcars->nrElements == 1);
    Car* car2 = CreateCar("sv11max", "logan", "cabrio");
    addCar(pcars, car2);
    assert(pcars->nrElements == 2);

    destroyCars(pcars);
}

void testGetCarIndex()
{
    ListCars *pcars = CreateList();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCar(pcars, car);
    int i = getCarIndex(pcars, "sv56man");
    assert(i == 0);
    Car* car2 = CreateCar("sv11max", "logan", "cabrio");
    addCar(pcars, car2);
    int i2 = getCarIndex(pcars, "sv11max");
    assert(i2 == 1);
    int i3 = getCarIndex(pcars, "blabla");
    assert(i3 == -1);

    destroyCars(pcars);
}

void testUpdateCar()
{
    ListCars *pcars = CreateList();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCar(pcars, car);
    destroyCar(car);
    free(car);
    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    //addCar(pcars, car2);
    updateCar(pcars, 0, car2);
    //destroyCar(car2);
    Car *c = getCar(pcars, 0);

    assert(strcmp(c->nr, "sv56man") == 0);
    assert(strcmp(c->model, "logan") == 0);
    assert(strcmp(c->category, "cabrio") == 0);
    destroyCars(pcars);
}

void testGetCar()
{
    ListCars *pcars = CreateList();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCar(pcars, car);

    Car *c = getCar(pcars, 0);
    assert(strcmp(c->nr, "sv56man") == 0);
    assert(strcmp(c->model, "fiat") == 0);
    assert(strcmp(c->category, "mini") == 0);
    //destroyCar(c);
    //free(c);
    //free(pcars);
    destroyCars(pcars);
}

void testShowCars()
{
    ListCars *pcars = CreateList();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCar(pcars, car);

    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    addCar(pcars, car2);

    ListCars *l = showCars(pcars);
    assert(l->nrElements == 2);

    //destroyCars(l);
    destroyCars(pcars);
}
//VCT-----------------------------------------------------------------

//REPO----------------------------------------------------------------
void testAddCarR()
{
    Repository* r = createRepo();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarR(r, car);
    assert(getSizeR(r) == 1);

    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    addCarR(r, car2);
    assert(getSizeR(r) == 2);

    destroyR(r);
}

void testShowCarsR()
{
    Repository* r = createRepo();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarR(r, car);

    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    addCarR(r, car2);

    ListCars *l = showCarsR(r);
    assert(l->nrElements == 2);

    destroyR(r);
}

void testUpdateCarR()
{
    Repository* r = createRepo();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarR(r, car);
    destroyCar(car);
    free(car);
    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    updateCarR(r, 0, car2);

    Car *c = getCarR(r, 0);
    assert(strcmp(c->nr, "sv56man") == 0);
    assert(strcmp(c->model, "logan") == 0);
    assert(strcmp(c->category, "cabrio") == 0);
    destroyR(r);
}

void testGetCarR()
{
    Repository* r = createRepo();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarR(r, car);

    Car* c = getCarR(r, 0);
    assert(strcmp(c->nr, "sv56man") == 0);
    assert(strcmp(c->model, "fiat") == 0);
    assert(strcmp(c->category, "mini") == 0);
    //destroyCar(c);
    destroyR(r);

}

void testGetSizeR()
{
    Repository* r = createRepo();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarR(r, car);
    assert(getSizeR(r) == 1);

    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    addCarR(r, car2);

    assert(getSizeR(r) == 2);
    destroyR(r);
}
//REPO----------------------------------------------------------------

//SERVICE-------------------------------------------------------------
void testAddCarS()
{
    Service s = createService();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarS(&s, car);

    assert(getSizeS(&s) == 1);

    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    addCarS(&s, car2);

    assert(getSizeS(&s) == 2);
    destroyS(&s);
}

void testShowCarS()
{
    Service s = createService();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarS(&s, car);

    ListCars *l = showCarS(&s);
    assert(getSize(l) == 1);

    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    addCarS(&s, car2);

    ListCars *l2 = showCarS(&s);
    assert(getSize(l2) == 2);

    //destroyCars(l2);
    destroyS(&s);

}

void testUpdateCarsS()
{
    Service s = createService();
    Car* car = CreateCar("sv56man", "fiat", "mini");
    addCarS(&s, car);
    destroyCar(car);
    free(car);
    Car* car2 = CreateCar("sv56man", "logan", "cabrio");
    updateCarS(&s, 0, car2);

    Car *c = getCarS(&s, 0);
    assert(strcmp(c->nr, "sv56man") == 0);
    assert(strcmp(c->model, "logan") == 0);
    assert(strcmp(c->category, "cabrio") == 0);
    //destroyCar(car2);
    destroyS(&s);
}

void testRentCarS()
{
    Service s = createService();
    Car *car = CreateCar("sv56man", "fiat", "mini");
    addCarS(&s, car);

    int ans = rentCarS(&s, car->nr);
    assert(ans == 1);

    int ans2 = rentCarS(&s, car->nr);
    assert(ans2 == -1);
    destroyS(&s);
}

void testReturnCarS()
{
    Service s = createService();
    Car *car = CreateCar("sv56man", "fiat", "mini");
    addCarS(&s, car);
    int ans = returnCarS(&s,car->nr);
    // printf("%d ", ans);
    assert(ans == -1);

    car->rent = 1;

    int ans2 = returnCarS(&s, car->nr);
    // printf("%d ", ans2);
    assert(ans2 == 1);
    destroyS(&s);

}
//SERVICE-------------------------------------------------------------

void testAll()
{
    testCreateCar();
    testRealloc();
    testAddCar();
    testGetCarIndex();
    testUpdateCar();
    testGetCar();
    testShowCars();
    testAddCarR();
    testShowCarsR();
    testUpdateCarR();
    testGetCarR();
    testGetSizeR();
    testAddCarS();
    testUpdateCarsS();
    testRentCarS();
    testReturnCarS();
    testReadCar();
    testShowCarS();
}
