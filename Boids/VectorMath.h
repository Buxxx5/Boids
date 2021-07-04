#pragma once
#include <SFML/Graphics.hpp>

float magnitude(sf::Vector2f inputVector) {
	return sqrt(pow(inputVector.x, 2) + pow(inputVector.y, 2));
}

sf::Vector2f normalized(sf::Vector2f inputVector) {

	float mag = magnitude(inputVector);
	if (mag != 0) {
		return inputVector / mag;
	}
	else return sf::Vector2f();
}
