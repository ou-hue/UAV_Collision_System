#include "collision_system.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// compare deux drones selon leur X (utilisee par qsort)
static int comparer_par_x(const void* a, const void* b) {
    float diff = ((Drone*)a)->x - ((Drone*)b)->x;
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
Drone* creer_essaim(int N) {
    Drone* essaim = (Drone*)malloc(N * sizeof(Drone));
    if (essaim == NULL) {
        fprintf(stderr, "Erreur allocation\n");
        exit(1);
    }
    return essaim;
}

// initialisation des positions (sans crochets, uniquement des pointeurs)
void init_essaim(Drone* essaim, int N) {
    Drone* ptr = essaim;
    for (int i = 0; i < N; i++) {
        ptr->id = i;
        ptr->x = (float)(rand() % 10000) / 10.0f;
        ptr->y = (float)(rand() % 10000) / 10.0f;
        ptr->z = (float)(rand() % 10000) / 10.0f;
        ptr++;
    }
}

// detection des collisions : tri par X + fenetre glissante
void detecter_collisions(Drone* essaim, int N, float seuil) {
    // on trie d'abord par X
    qsort(essaim, N, sizeof(Drone), comparer_par_x);
    
    Drone* courant = essaim;
    Drone* fin = essaim + N;
    
    while (courant < fin) {
        Drone* suivant = courant + 1;
        
        // fenetre glissante : on compare tant que l'ecart en X < seuil
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
void liberer_essaim(Drone* essaim) {
    free(essaim);
}
