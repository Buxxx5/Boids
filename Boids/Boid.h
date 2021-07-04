#pragma once
#include <SFML/Graphics.hpp>

class Boid : sf::Transformable {
private:
	sf::CircleShape shape;
	sf::Vector2f direction;
	sf::Vector2f acceleration;

public:
	Boid(int n);

	sf::CircleShape GetShape();
	sf::Vector2f Cohesion(std::vector<Boid> otherBoids);
	sf::Vector2f Alignment(std::vector<Boid> otherBoids);
	sf::Vector2f Separation(std::vector<Boid> otherBoids);
	sf::Vector2f GetDirection();

	void DefineDirection(std::vector<Boid> otherBoids);
	void Move(float _delta);

	bool IsInRange(Boid otherBoid, float range);
	void SetPosition(sf::Vector2f newPosition);

	//Cohesion, Alignment, and Separation.
};

