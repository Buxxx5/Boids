#pragma once
#include <SFML/Graphics.hpp>

sf::Vector2f normalized(sf::Vector2f inputVector) {

	float magnitude = sqrt(pow(inputVector.x, 2) + pow(inputVector.y, 2));
	if (magnitude != 0) {
		return inputVector / magnitude;
	}
	else return sf::Vector2f();
}