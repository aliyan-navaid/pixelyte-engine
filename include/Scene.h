#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Scene {
public:
	virtual void update(const sf::Time&) = 0;
	virtual void render(std::shared_ptr<sf::RenderWindow>) = 0;
};