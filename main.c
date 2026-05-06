#include "collision_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int N = 10000;
    const float SEUIL = 5.0f;
    
    srand(time(NULL));
    
    Drone* swarm = create_swarm(N);
    init_swarm(swarm, N);
    
    printf("Detection collisions (seuil=%.1f)\n", SEUIL);
    detect_collisions(swarm, N, SEUIL);
    
    free_swarm(swarm);
    return 0;
}
