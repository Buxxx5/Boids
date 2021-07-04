#pragma once
#include "Boid.h"

class Flock {

private:
	std::vector<Boid> boids;

public:
	Flock();

	std::vector<Boid> getBoids();

	void Update(float _delta);
};

