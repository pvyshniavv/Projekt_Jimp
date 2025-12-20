#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <math.h>
#include "pso.h"



double oblicz_fitness(double x, double y , MapaTerenu *mapa){
    int wiersz = (int)y;
    int kolumna = (int)x;
    if ( wiersz < 0 || wiersz >= mapa->wiersze || kolumna < 0 || kolumna => mapa->kolumny){// when beyond the map
        return -10000.0; //Bad result
    }
    return mapa-> tablica[wiersz][kolumna];
}


double random_double(double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min);
}


Swarm* inicjalizuj_roj(int liczba_czastek, MapaTerenu *mapa, double w, double c1, double c2) {

    Swarm *roj = (Swarm*)malloc(sizeof(Swarm));
    roj->liczba_czastek = liczba_czastek;
    roj->w = w;
    roj->c1 = c1;
    roj->c2 = c2;

    roj->particles = (Particle*)malloc(sizeof(Particle) * liczba_czastek);

    roj->gBest_val = -1000000.0; // Bad start value

    for (int i = 0; i < liczba_czastek; i++) {
        Particle *p = &roj->particles[i];

        p->x = random_double(0, mapa->kolumny - 1);
        p->y = random_double(0, mapa->wiersze - 1); //random start position on map

        p->vx = random_double(-1.0, 1.0);
        p->vy = random_double(-1.0, 1.0);// random start speed

        double val = oblicz_fitness(p->x, p->y, mapa);

        p->pBest_x = p->x;
        p->pBest_y = p->y;
        p->pBest_val = val; // Bad start personal value

        if (val > roj->gBest_val) {
            roj->gBest_x = p->x;
            roj->gBest_y = p->y;
            roj->gBest_val = val;// Bad start group value
        }
    }

    return roj;
}

void aktualizuj_roj(Swarm *roj, MapaTerenu *mapa){
    
    
    for(int i=0; i < roj->liczba_czastek; i++){
        double r1 =random_double(0,1);
        double r2 =random_double(0,1);

        Particle *p = &roj->particles[i];


        p->vx = (roj->w * p->vx)+(roj->c1 * r1 * (p->pBest_x - p->x)) +(roj ->c2 *r2 * (roj->gBest_x - p->x)); 
        p->vy = (roj->w * p->vy)+(roj->c1 * r1 * (p->pBest_y - p->y)) +(roj ->c2 *r2 * (roj->gBest_y - p->y)); 
        p->x = p->x + p->vx;
        p->y = p->y + p->vy;

        double current_val = oblicz_fitness(p->x, p->y, mapa);

        if (current_val > p->pBest_val) { //change personal best
            p->pBest_val = current_val;
            p->pBest_x = p->x;
            p->pBest_y = p->y;
        }

        if (current_val > roj->gBest_val) { //change group best
            roj->gBest_val = current_val;
            roj->gBest_x = p->x;
            roj->gBest_y = p->y;
        }


    }

}
void zwolnij_roj(Swarm *roj) {
    if (roj != NULL) {
        free(roj->particles); // free memory
        free(roj);           
    }
}