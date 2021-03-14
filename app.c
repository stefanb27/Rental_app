//
// Created by Stefan on 03.03.2021.
//

//#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "domain.h"
//#include "vct.h"
//#include "tests.h"
//#include "validators.h"
#include "tests.h"
//Car* CreateCar(char *nr, char* model, char *category);

int main()
{
    char buff[BUFSIZ];
    setvbuf(stdout, buff, _IONBF, BUFSIZ);
    setvbuf(stdin, buff, _IONBF, BUFSIZ);
    testAll();
    console();

    /*
    ListCars *l = CreateList();
    addCar(l, CreateCar("bc27jim", "jeep", "suv"));
    addCar(l,  CreateCar("sv77lam", "lamborghini", "supercar"));

    for(int i = 0; i < l->nrElements; i ++) {

        destroyCar(l->l[i]);
        free(l->l[i]);
    }
    free(l->l);
    free(l);
     */
    fclose(stdout);
    fclose(stdin);
    return 0;
}
