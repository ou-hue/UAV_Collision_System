#include "collision_system.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int compare_by_x(const void* a, const void* b) {
    float diff = ((Drone*)a)->x - ((Drone*)b)->x;
    return (diff > 0) - (diff < 0);
}

static float distance(Drone* a, Drone* b) {
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;
    return sqrtf(dx*dx + dy*dy + dz*dz);
}

Drone* create_swarm(int N) {
    Drone* swarm = (Drone*)malloc(N * sizeof(Drone));
    if (!swarm) {
        fprintf(stderr, "Erreur allocation\n");
        exit(1);
    }
    return swarm;
}

void init_swarm(Drone* swarm, int N) {
    Drone* ptr = swarm;
    for (int i = 0; i < N; ++i) {
        ptr->id = i;
        ptr->x = (float)(rand() % 10000) / 10.0f;
        ptr->y = (float)(rand() % 10000) / 10.0f;
        ptr->z = (float)(rand() % 10000) / 10.0f;
        ptr++;
    }
}

void detect_collisions(Drone* swarm, int N, float threshold) {
    qsort(swarm, N, sizeof(Drone), compare_by_x);
    
    Drone* current = swarm;
    Drone* end = swarm + N;
    
    while (current < end) {
        Drone* next = current + 1;
        
        while (next < end && (next->x - current->x) < threshold) {
            float dist = distance(current, next);
            if (dist < threshold) {
                printf("Collision %d <-> %d (dist=%.2f)\n", 
                       current->id, next->id, dist);
            }
            next++;
        }
        current++;
    }
}

void free_swarm(Drone* swarm) {
    free(swarm);
}
