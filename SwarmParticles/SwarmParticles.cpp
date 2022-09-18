#include <iostream>
#include "Swarm.h"

#define ITERATIONS 1000

int main()
{
    // Create swarm
    Swarm s = Swarm( 10 );

    // Calculate fitness of particles
    s.update_fitness();

    int i = 0;
    while( i < ITERATIONS ) {
        s.update_swarm();
        s.update_fitness();
        i++;
    }

    Particle best = s.get_best();
    cout << best << endl;
    

}
