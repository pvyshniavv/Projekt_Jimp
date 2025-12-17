#include <stdio.h>
#include <stdlib.h>

typedef struct { //map.h
    int wiersze;
    int kolumny;
    double **tablica;
}MapaTerenu;

int main(int argc, char *argv[]) {
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
