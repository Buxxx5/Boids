#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "Flock.h"


using std::cout;
using std::endl;

int main()
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE_W, SCREEN_SIZE_H), "Boids");

	Flock flock;

	while (window.isOpen()) {

		sf::Time elapsed = clock.restart();


		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(sf::Color(41, 43, 48, 255));
		flock.Update(elapsed.asSeconds());
		for (Boid boid : flock.getBoids()) {
			window.draw(boid.GetShape());
		}

		window.display();
	}

	return 0;
}