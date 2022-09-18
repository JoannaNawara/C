#pragma once

#include "Particle.h"

#define INERTIA 0.1
#define COGNITIVE_CONSTANT 0.5
#define SOCIAL_CONSTANT 0.5
#define MAX_X 10
#define MIN_X -10
#define MAX_Y 10
#define MIN_Y -10

class Swarm
{
public:
	Swarm( int num_of_particles );
	void printSwarm();
	Particle get_best();
	void update_swarm();
	void update_fitness();

public:
	Particle* swarm;
	int size;
};

