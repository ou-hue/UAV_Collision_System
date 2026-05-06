#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

typedef struct {
    int id;
    float x;
    float y;
    float z;
} Drone;

Drone* create_swarm(int N);
void init_swarm(Drone* swarm, int N);
void detect_collisions(Drone* swarm, int N, float threshold);
void free_swarm(Drone* swarm);

#endif
