#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

// structure d'un drone
typedef struct {
    int id;      // numéro unique du drone
    float x;     // coordonnée X
    float y;     // coordonnée Y
    float z;     // altitude
} Drone;

// alloue la mémoire pour N drones (un seul bloc contigu)
Drone* create_swarm(int N);

// initialise les positions avec des valeurs aléatoires
void init_swarm(Drone* swarm, int N);

// détecte toutes les collisions (tri par X + fenêtre glissante)
void detect_collisions(Drone* swarm, int N, float seuil);

// libère la mémoire
void free_swarm(Drone* swarm);

#endif
