#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

// structure d'un drone
typedef struct {
    int id;      // numero unique du drone
    float x;     // coordonnee X
    float y;     // coordonnee Y
    float z;     // altitude
} Drone;

// alloue la memoire pour N drones (un seul bloc contigu)
Drone* creer_essaim(int N);

// initialise les positions avec des valeurs aleatoires
void init_essaim(Drone* essaim, int N);

// detecte toutes les collisions (tri par X + fenetre glissante)
void detecter_collisions(Drone* essaim, int N, float seuil);

// libere la memoire
void liberer_essaim(Drone* essaim);

#endif
