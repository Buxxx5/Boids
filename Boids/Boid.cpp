#include <random>
#include <iostream>
#include "Boid.h"
#include "Constants.h"
#include "VectorMath.h"

#define _USE_MATH_DEFINES
#include <math.h>

Boid::Boid(int n)
{
	std::default_random_engine random;
	std::uniform_int_distribution<int> distribution(-100, 100);
	random.seed(n);
	shape = sf::CircleShape(10.f, 3);
	shape.setFillColor(sf::Color(207, 171, 74));
	shape.setOrigin(5.f, 5.f);
	direction = sf::Vector2f(random(), random());
	direction = normalized(direction);
}


sf::CircleShape Boid::GetShape()
{
	return shape;
}

sf::Vector2f Boid::Cohesion(std::vector<Boid> otherBoids)
{
	// Calculates the middle point of the neighbors boids

	sf::Vector2f cohesionDirection(0.f, 0.f);
	float x = 0.f, y = 0.f;
	int numberOfBoids = 0;

	for (Boid boid : otherBoids) {
		if (IsInRange(boid)) {
			sf::Vector2f boidPos = boid.GetShape().getPosition();
			x += boidPos.x;
			y += boidPos.y;

			numberOfBoids++;
		}
	}
	if (numberOfBoids > 0) {
		sf::Vector2f middlePoint = sf::Vector2f(x / numberOfBoids, y / numberOfBoids);
		cohesionDirection = middlePoint - shape.getPosition();

	}
	return cohesionDirection;
}

sf::Vector2f Boid::Alignment(std::vector<Boid> otherBoids)
{
	sf::Vector2f alignmentVector;
	int neighbors = 0;
	for (Boid otherBoid : otherBoids) {
		if (IsInRange(otherBoid)) {
			alignmentVector += otherBoid.GetDirection();
			neighbors++;
		}
	}
	if (neighbors > 0) {
		alignmentVector = sf::Vector2f(alignmentVector.x / neighbors, alignmentVector.y / neighbors);
	}

	//Check all the boids in a certain range
	return direction - alignmentVector;
}

sf::Vector2f Boid::Separation(std::vector<Boid> otherBoids)
{
	return sf::Vector2f(0, 0);
}

sf::Vector2f Boid::GetDirection()
{
	return direction;
}

void Boid::DefineDirection(std::vector<Boid> otherBoids)
{

	acceleration = Cohesion(otherBoids) * COHESION_STRENGTH;
	acceleration += Alignment(otherBoids) * ALIGNMENT_STRENGTH;
	acceleration += Separation(otherBoids) * SEPARATION_STRENGTH;


	direction += acceleration;
	direction = normalized(direction);
}

void Boid::Move(float _delta)
{
	float angle = atan2(direction.y, direction.x) * 180.f / (float)M_PI;
	angle += 90;
	shape.setRotation(angle);

	sf::Vector2f oldPos = shape.getPosition();
	sf::Vector2f newPos = shape.getPosition() + sf::Vector2f(direction.x * BOID_SPEED * _delta, direction.y * BOID_SPEED * _delta);

	if (newPos.x < 0) {
		newPos.x = SCREEN_SIZE_W;
	}
	else if (newPos.x > SCREEN_SIZE_W) {
		newPos.x = 0;
	}
	if (newPos.y < 0) {
		newPos.y = SCREEN_SIZE_H;
	}
	else if (newPos.y > SCREEN_SIZE_H) {
		newPos.y = 0;
	}

	shape.setPosition(newPos);
}

bool Boid::IsInRange(Boid otherBoid)
{
	// (x - center_x)^2 + (y - center_y)^2 < radius^2

	if (otherBoid.GetShape().getPosition().x == shape.getPosition().x && otherBoid.GetShape().getPosition().y == shape.getPosition().y) {
		return false;
	}

	sf::Vector2f otherPosition = otherBoid.GetShape().getPosition();
	float baseX = otherPosition.x - shape.getPosition().x;
	float baseY = otherPosition.y - shape.getPosition().y;
	bool result = std::pow(baseX, 2.f) + std::pow(baseY, 2.f) < std::pow((float)COHESION_RANGE, 2.f);
	return result;
}


void Boid::SetPosition(sf::Vector2f newPosition)
{
	shape.setPosition(newPosition);
}
