#pragma once

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>


using namespace std;

class Particle {
public:
	Particle();
	Particle(int x, int y, double inertia, double cognitive_constant, double social_constant);
	//friend istream& operator >> ( istream& in, Particle& p );
	friend ostream& operator << ( ostream& out, const Particle& p );

	int calculate_fitness();
	void update_fitness();
	double calculate_inertia();
	double calculate_cognitive_acceleration();
	double calculate_social_acceleration();
	double calculate_distance( int _best_x, int _best_y , int x, int y);
	double calculate_cognitive();
	double calculate_social( int _best_x, int _best_y );
	void update_particle(int swarm_best_x, int swarm_best_y);

public:
	int x; //coordinates of particle (x, y)
	int y; //coordinates of particle (x, y)
	int best_x;
	int best_y;

	double velocity;
	int fitness;
	int best_fitness;
	double inertia;
	double cognitive_constant;
	double social_constant;
};


