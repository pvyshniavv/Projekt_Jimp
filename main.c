#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "pso.h"
#include <time.h> //dla srand
#include <string.h> //dla strcmp


int main(int argc, char *argv[]) {
    int liczba_czastek = 30;
    int liczba_iteracji = 100;
    int co_n_napis = 0;
    char *plik_konfig = NULL;
    char *plik_mapy = NULL;

    double w = 0.5, c1 = 1.0, c2 = 1.0;

    if(argc < 2) {
        printf("Uzycie: %s <plik_mapy>, -p czastki, -i iteracji, -c konfig, -n zapis\n", argv[0]);
        return 1;
    }
    plik_mapy = argv[1];

    //przeszukiwanie pozostalych argumentow
    for(int i = 2; i < argc; i++) {
        if(strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            liczba_czastek = atoi(argv[++i]); //zamiana string na int
        } else if(strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            liczba_iteracji = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            co_n_napis = atoi (argv[++i]);
        } else if (strcmp (argv[i], "-c") == 0 && i + 1 < argc) {
            plik_konfig = argv[++i];
        }
     }

srand(time(NULL)); //inicjalizacja generatora liczb losowych
MapaTerenu m;
if (wczytaj_plikmapy(&m, plik_mapy) == 0) {
    return 1; //blad wczytywania mapy
}

//wczytywanie mapy

    Swarm *roj = inicjalizuj_roj(liczba_czastek, &m, w, c1, c2);
    for(int i = 0; i < liczba_iteracji; i++){
        aktualizuj_roj(roj, &m);
        printf("Iteracja: %d: Najlepszy sygnal (gBest_val): %lf w punkcie (%lf %lf)\n", i, roj->gBest_val, roj->gBest_x, roj->gBest_y);
    }
    //Wynik koncowy
    printf ("Symulacja zakonczona pomyslnie!\n");
    printf("Znalezione maksimum: %lf w punkcie (%lf %lf)\n", roj->gBest_val, roj->gBest_x, roj->gBest_y);

    //Zwalniamy pamiec 
    zwolnij_roj(roj);
    zwolnij_mape(&m);
    return 0;
}
