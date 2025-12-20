#ifndef PSO_H
#define PSO_H

#include "map.h"

typedef struct {
    double x, y;          
    double vx, vy;        
    
   
    double pBest_x, pBest_y; 
    double pBest_val;     
} Particle;


typedef struct {
    Particle *particles;  
    int liczba_czastek;   
    
    
    double gBest_x, gBest_y; 
    double gBest_val;
    
    
    double w;  
    double c1; 
    double c2; 
} Swarm;

Swarm* inicjalizuj_roj(int liczba_czastek, MapaTerenu *mapa, double w, double c1, double c2);
double oblicz_fitness(double x, double y, MapaTerenu *mapa);
void zwolnij_roj(Swarm *roj);

#endif