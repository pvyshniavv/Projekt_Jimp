#include <stdio.h>
#include <stdlib.h>

typedef struct { //map.h
    int wiersze;
    int kolumny;
    double **tablica;

}MapaTerenu;



double** allokuj_tablice (int wiersze, int kolumny) { //funkscja bieze pamiec komputerowa
    double **tab_liczb;
    tab_liczb = (double **)malloc(wiersze * sizeof(double*)); //nauczyc sie na pamiec 
    for(int w = 0; w < wiersze; w++) {
        tab_liczb[w] = (double *)malloc(kolumny * sizeof(double));
    }
    return tab_liczb;
}

int wczytaj_plikmapy(MapaTerenu *mapa_terenu, const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        printf("Brak pliku.%s\n", nazwa_pliku);
        return 0; 
    }
    else {
        printf("Czytam mape z pliku: %s\n", nazwa_pliku); 
        fscanf(plik, "%d", &mapa_terenu->kolumny);
        fscanf(plik, "%d", &mapa_terenu->wiersze);
        mapa_terenu ->tablica = allokuj_tablice(mapa_terenu->wiersze, mapa_terenu->kolumny);
        for (int w = 0; w< mapa_terenu->wiersze; w++) {
            for (int k = 0; k < mapa_terenu->kolumny; k++) {
                fscanf(plik, "%lf", &mapa_terenu->tablica[w][k]);
            }
        }
        fclose(plik); 
        printf("Mapa wczytana z pliku.%s\n", nazwa_pliku);
        return 1;
    }

}
void drukuj_mape(MapaTerenu mapa_terenu) { //definicja funkcji (czaswm ma *, czasem nie)
    printf("Mapa terenu o rozmiarze: %d x %d \n",mapa_terenu.wiersze, mapa_terenu.kolumny); //bo mapa_terenu nie ma *, dlatego kropka
    for (int w = 0; w < mapa_terenu.wiersze; w++) {
        for (int k = 0; k < mapa_terenu.kolumny; k++) {
            printf("%lf ", mapa_terenu.tablica[w][k]);
        }
        printf("\n");
    }
}