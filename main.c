#include "collision_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int N = 10000;
    const float SEUIL = 5.0f;
    
    // initialisation du generateur aleatoire
    srand((unsigned int)time(NULL));
    
    printf("=== DETECTION DE COLLISIONS ===\n");
    printf("Drones : %d | Seuil : %.1f m\n\n", N, SEUIL);
    
    // allocation
    Drone* essaim = creer_essaim(N);
    
    // initialisation
    init_essaim(essaim, N);
    
    // detection
    detecter_collisions(essaim, N, SEUIL);
    
    // liberation
    liberer_essaim(essaim);
    
    printf("\n=== FIN ===\n");
    return 0;
}
