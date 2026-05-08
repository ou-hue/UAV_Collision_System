#include "collision_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int N = 10000;
    const float SEUIL = 5.0f;
    
    // initialisation du générateur aléatoire
    srand((unsigned int)time(NULL));
    
    printf("=== DETECTION DE COLLISIONS ===\n");
    printf("Drones : %d | Seuil : %.1f m\n\n", N, SEUIL);
    
    // allocation
    Drone* swarm = create_swarm(N);
    
    // initialisation
    init_swarm(swarm, N);
    
    // detection
    detect_collisions(swarm, N, SEUIL);
    
    // liberation
    free_swarm(swarm);
    
    printf("\n=== FIN ===\n");
    return 0;
}
