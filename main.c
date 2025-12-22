#include <stdio.h>
#include <stdlib.h>
#include "map.h"



int main(int argc, char *argv[]) {
       srand(time(NULL));
    MapaTerenu m;
    int sukces = wczytaj_plikmapy(&m, argv[1]);
    if (sukces == 0) {
        printf("Brak mapy \n");
    }
    else {
        printf("Mapa wczytana pomyslnie \n");
        drukuj_mape(m);
    }
}
