#include <iostream>
#include <random>
#include "Flock.h"
#include "Constants.h"
#include "Boid.h"

Flock::Flock()
{
	srand((unsigned int)time(NULL));
	std::default_random_engine random;

	for (int i = 0; i < NUMBER_OF_BOIDS; i++) {
		Boid boid(i);
		sf::Vector2f startingPos = sf::Vector2f(random() % SCREEN_SIZE_W, random() % SCREEN_SIZE_H);
		boid.SetPosition(startingPos);
		boids.push_back(boid);
	}
}

std::vector<Boid> Flock::getBoids()
{
	return boids;
}


void Flock::Update(float _delta)
{
	for (std::vector<Boid>::iterator it = boids.begin(); it != boids.end(); ++it) {
		Boid& boid = *it;;
		boid.DefineDirection(boids);
		boid.Move(_delta);
	}
}


