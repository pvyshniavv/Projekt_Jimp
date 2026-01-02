#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include <stdlib.h>

typedef struct { //map.h
    int wiersze;
    int kolumny;
    double **tablica;

}MapaTerenu;
double** allokuj_tablice (int wiersze, int kolumny);
int wczytaj_plikmapy(MapaTerenu *mapa_terenu, const char *nazwa_pliku);
void drukuj_mape(MapaTerenu mapa_terenu);
void zwolnij_mape(MapaTerenu *mapa);

#endif