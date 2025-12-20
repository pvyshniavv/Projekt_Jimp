#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <math.h>
#include "pso.h"

double random_double(double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min);
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


    }

}