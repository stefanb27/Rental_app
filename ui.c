//
// Created by Stefan on 03.03.2021.
//
#include "ui.h"
//#include "domain.h"
//#include "ui.h"
//#include "service.h"
//#include "validators.h"
//#include "repo.h"

Car* readCar()
{
    /*
     * citeste o masina de la tastatura si o valideaza
     */
    char Nr[15], Model[15], Category[15];
    while(1) {
        printf("Dati numarul de inmatriculare: ");
        scanf("%s", Nr);
        if(validateNr(Nr) == 0)
        {
            printf("Numarul de inmatriculare trebuie "
                   "sa fie de forma 'llcclll'");
            printf("\n");
        }
        if(validateNr(Nr) == 1)
            break;
    }
    while(1) {
        printf("Dati modelul: ");
        scanf("%s", Model);
        if(validateModel(Model) == 0) {
            printf("Modelul de masina este invalid!\n");
            printf("Modele posibile: ");
            printf("{dacia, skoda, ford, hyundai, toyota, suzuki, peugeot, mercedes, bmw, audi, lamborghini, volkswagen, tesla, porsche, volvo, honda, jeep, fiat, mazda, alfa romeo, lexus, jaguar, citroen, maserati, ferrari, chevrolet}");
            printf("\n");
        }
        if(validateModel(Model) == 1)
            break;
    }
    while(1)
    {
        printf("Dati cateogoria: ");
        scanf("%s", Category);
        if(validateCategory(Category) == 0)
        {
            printf("Categoria de masina este invalida!\n");
            printf("Categorii posibile: ");
            printf("{sedan, mini, coupe, suv, cabrio, hatchback, roadster,supercar, van, crossover}");
            printf("\n");
        }
        if(validateCategory(Category) == 1)
            break;
    }

    Car *c = CreateCar(Nr, Model, Category);
    //printf("%s %s %s",c->nr, c->category,c->model);
    return c;
}

void menu()
{
     /*
     * afiseaza meniul
     */
    printf("---------------MENIU--------------\n");
    printf("1. Adauga masina\n");
    printf("2. Afiseaza masini\n");
    printf("3. Actualizeaza masina existenta\n");
    printf("4. Inchiriaza masina\n");
    printf("5. Returneaza masina\n");
    printf("6. Filtreaza masini dupa model\n");
    printf("7. Filtreaza masini dupa categorie\n");
    printf("8. Sorteaza masini\n");
    printf("---------------MENIU--------------\n");
}
void initCars(Service *s)
{
    addCarS(s, CreateCar("bc27jim", "jeep", "suv"));
    addCarS(s,  CreateCar("sv77lam", "lamborghini", "supercar"));
    addCarS(s, CreateCar("ct30jap", "toyota", "sedan"));
    addCarS(s, CreateCar("gl77cut", "porsche", "suv"));
    addCarS(s, CreateCar("bv66fst", "tesla", "sedan"));
    addCarS(s, CreateCar("tm03alb", "fiat", "mini"));
    addCarS(s, CreateCar("ct30bum", "volvo", "crossover"));
    addCarS(s, CreateCar("is99rrr", "jaguar", "coupe"));
    addCarS(s, CreateCar("cj10spd", "ferrari", "cabrio"));
    addCarS(s, CreateCar("sv27bmb", "bmw", "roadster"));
}
void console()
{
    /*
     * ruleaza partea de interfata a aplicatie
     */
    Service srv = createService();
    initCars(&srv);

    while(1)
    {
        menu();
        char cmd[10];
        printf("%s", "Dati comanda: \n");
        scanf(" %s", cmd);
        if(strcmp(cmd, "0") == 0)
        {
            destroyS(&srv);
            break;
        }
        else if(strcmp(cmd, "1") == 0)
        {
            Car* cr = readCar();
            addCarS(&srv, cr);
        }
        else if(strcmp(cmd, "2") == 0)
        {
            ListCars *l = showCarS(&srv);
            for(int i = 0; i < l->nrElements; i ++) {
                Car* crr = getCar(l, i);
                printf("%s %s %s \n", crr->nr, crr->model, crr->category);
            }
        }
        else if(strcmp(cmd, "3") == 0)
        {
            char Numar[10], Model[10], Categorie[10];
            printf("Dati numarul de inmatriculare: ");
            scanf("%s", Numar);
            int i = getCarIndexR(srv.r, Numar);
            if(i == -1) {
                printf("Nu exista acest numar de inmatriculare!\n");
            }
            else {
                printf("Dati noul model: ");
                scanf("%s", Model);
                printf("Dati noua categorie: ");
                scanf("%s", Categorie);
                Car *cr = CreateCar(Numar, Model, Categorie);
                updateCarS(&srv, i, cr);
               //destroyCar(cr);
            }
        }
        else if(strcmp(cmd, "4") == 0)
        {
            // rent a car
            char nr[10];
            printf("Dati numarul de inmatriculare al "
                   "masinii: ");
            scanf("%s", nr);
            int ans = rentCarS(&srv, nr);
            if(ans == 1)
                printf("Masina inchiriata cu succes!\n");
            else if(ans == -1)
            {
                printf("Masina este deja inchiriata!\n");
            }
            else if(ans == 0)
            {
                printf("Masina nu exista!\n");
            }
        }
        else if(strcmp(cmd, "5") == 0)
        {
            char nr[10];
            printf("Dati numarul de inmatriculare al "
                   "masinii: ");
            scanf("%s", nr);
            int ans2 = returnCarS(&srv, nr);
            if(ans2 == -1)
            {
                printf("Masina nu a fost inchiriata!\n");
            }
            else if(ans2 == 1)
            {
                printf("Masina a fost returnata cu succes!\n");
            }
            else if(ans2 == 0)
            {
                printf("Masina nu exista!\n");
            }
        }
        else if(strcmp(cmd, "6") == 0)
        {
            char mod[10];
            printf("Dati modelul: ");
            scanf("%s", mod);
            ListCars *l = filterModelS(&srv, mod);
            for(int i = 0; i < l->nrElements; i ++)
            {
                Car* cr = getCar(l, i);
                printf("%s %s %s\n", cr->nr, cr->model, cr->category);
            }
            destroyCars(l);
        }
        else if(strcmp(cmd, "7") == 0)
        {
            char ctg[10];
            printf("Dati categoria: ");
            scanf("%s", ctg);
            ListCars *l = filterCategoryS(&srv, ctg);
            for(int i = 0; i < l->nrElements; i ++)
            {
                Car* cr = getCar(l, i);
                printf("%s %s %s\n", cr->nr, cr->model, cr->category);
            }
            destroyCars(l);
        }
        else if(strcmp(cmd, "8") == 0)
        {
            printf("1. Dupa model\n");
            printf("2. Dupa categorie\n");
            int filtr;
            printf("Dati optiunea: ");
            scanf("%d", &filtr);
            printf("1. Crescator\n");
            printf("2. Descrescator\n");
            int reverse = 1;
            printf("Dati optiunea: ");
            scanf("%d", &reverse);
            if(reverse == 2) reverse = -1;
            ListCars *l = SortCars(&srv, filtr, reverse);
        }
        else printf("Comanda invalida!\n");
    }

}