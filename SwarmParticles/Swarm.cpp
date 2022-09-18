#include "Swarm.h"

Swarm::Swarm( int num_of_particles ) {
	swarm = new Particle[num_of_particles];
	size = num_of_particles;
	srand( ( unsigned ) time( NULL ) );
	for( int i = 0; i < num_of_particles; i++ ) {
		int x = ( rand() % ( MAX_X - MIN_X + 1 ) ) + MIN_X;
		int y = ( rand() % ( MAX_Y - MIN_Y + 1 ) ) + MIN_Y;
		swarm[i] = Particle( x, y, INERTIA, COGNITIVE_CONSTANT, SOCIAL_CONSTANT );
	}
}

void Swarm::printSwarm() {
	for( int i = 0; i < size; i++ ) {
		cout << swarm[i];
	}
}

Particle Swarm::get_best() {
	int best_fitness = INT_MAX;
	Particle best_particle = Particle();
	for( int i = 0; i < size; i++ ) {
		swarm[i].update_fitness();
		if( swarm[i].best_fitness < best_fitness ) {
			best_fitness = swarm[i].best_fitness;
			best_particle = swarm[i];
		}
	}
	return best_particle;
}

void Swarm::update_swarm() {
	Particle best_particle = get_best();
	int best_swarm_x = best_particle.best_x;
	int best_swarm_y = best_particle.best_y;
	for( int i = 0; i < size; i++ ) {
		swarm[i].update_particle( best_swarm_x, best_swarm_y );
	}
}

void Swarm::update_fitness() {
	for( int i = 0; i < size; i++ ) {
		swarm[i].update_fitness();
	}
}
