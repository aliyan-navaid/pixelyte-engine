#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow first(sf::VideoMode(1280, 720), "Hello");
	while (first.isOpen()) {
		sf::Event event;
		while (first.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				first.close();
		}

		first.clear(sf::Color::White);
		first.display();
	}
}