#include "collision_system.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// compare deux drones selon leur X (utilisée par qsort)
static int compare_by_x(const void* a, const void* b) {
    float diff = ((Drone*)a)->x - ((Drone*)b)->x;
    // (diff>0)-(diff<0) donne -1, 0 ou 1 à partir d'un float
    return (diff > 0) - (diff < 0);
}

// calcule la distance entre deux drones
static float distance(Drone* a, Drone* b) {
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;
    return sqrtf(dx*dx + dy*dy + dz*dz);
}

// allocation d'un seul bloc contigu pour tous les drones
Drone* create_swarm(int N) {
    Drone* swarm = (Drone*)malloc(N * sizeof(Drone));
    if (swarm == NULL) {
        fprintf(stderr, "Erreur allocation\n");
        exit(1);
    }
    return swarm;
}

// initialisation des positions (sans crochets, uniquement des pointeurs)
void init_swarm(Drone* swarm, int N) {
    Drone* ptr = swarm;
    for (int i = 0; i < N; i++) {
        ptr->id = i;
        ptr->x = (float)(rand() % 10000) / 10.0f;
        ptr->y = (float)(rand() % 10000) / 10.0f;
        ptr->z = (float)(rand() % 10000) / 10.0f;
        ptr++;
    }
}

// detection des collisions : tri par X + fenêtre glissante
void detect_collisions(Drone* swarm, int N, float seuil) {
    // on trie d'abord par X
    qsort(swarm, N, sizeof(Drone), compare_by_x);
    
    Drone* courant = swarm;
    Drone* fin = swarm + N;      // pointe après le dernier drone
    
    while (courant < fin) {
        Drone* suivant = courant + 1;
        
        // fenêtre glissante : on compare tant que l'écart en X < seuil
        while (suivant < fin && (suivant->x - courant->x) < seuil) {
            if (distance(courant, suivant) < seuil) {
                printf("Collision drone %d <-> %d (dist=%.2f m)\n",
                       courant->id, suivant->id, distance(courant, suivant));
            }
            suivant++;
        }
        courant++;
    }
}

// liberation de la memoire
void free_swarm(Drone* swarm) {
    free(swarm);
}
