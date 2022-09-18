#include "Particle.h"

Particle::Particle() {
	this->x = 0;
	this->y = 0;
	fitness = INT_MAX;
	velocity = 0;
	best_x = 0;
	best_y = 0;
	best_fitness = INT_MAX;
	this->inertia = NULL;
	this->cognitive_constant = NULL;
	this->social_constant = NULL;
}

Particle::Particle( int x, int y, double inertia, double cognitive_constant, double social_constant ) {
	this->x = x;
	this->y = y;
	fitness = INT_MAX;
	velocity = 0;
	best_x = x;
	best_y = y;
	best_fitness = INT_MAX;
	this->inertia = inertia;
	this->cognitive_constant = cognitive_constant;
	this->social_constant = social_constant;
}

ostream& operator << ( ostream& out, const Particle& p ) {
	out << "\nBest x : " << p.best_x << endl;
	out << "Best y : " << p.best_y << endl;
	out << "Best fitness: " << p.best_fitness << endl;
	return out;
}

void Particle::update_fitness() {
	fitness = calculate_fitness();
	if( best_fitness > fitness ) {
		best_fitness = fitness;
		best_x = x;
		best_y = y;
	}
}

int Particle::calculate_fitness() {
	int result = pow( ( x + 2 * y - 7 ), 2) + pow( ( 2 * x + y - 5 ), 2);
	return result;
}

double Particle::calculate_inertia() {
	return inertia * velocity;
}

double Particle::calculate_cognitive_acceleration() {
	srand( (unsigned)time( NULL ) );
	double random = rand() / RAND_MAX;
	return cognitive_constant * random;
}

double Particle::calculate_social_acceleration() {
	srand( ( unsigned ) time( NULL ) );
	double random = rand() / RAND_MAX;
	return social_constant * random;
}

double Particle::calculate_distance( int _best_x, int _best_y, int x, int y ) {
	return sqrt( pow( ( _best_x - x ), 2 ) + pow( ( _best_y - y ), 2 ) );
}

double Particle::calculate_cognitive() {
	double acceleration = calculate_cognitive_acceleration();
	double distance = calculate_distance(best_x, best_y, x, y);
	return acceleration * distance;
}

double Particle::calculate_social( int _best_x, int _best_y ) {
	double acceleration = calculate_social_acceleration();
	double distance = calculate_distance( _best_x, _best_y, x, y );
	return acceleration * distance;
}

void Particle::update_particle( int swarm_best_x, int swarm_best_y ) {
	double inertia_ = calculate_inertia();
	double cognitive = calculate_cognitive();
	double social = calculate_social( swarm_best_x, swarm_best_y );
	velocity = inertia_ + cognitive + social;
	x = x + velocity;
	y = y + velocity;
}