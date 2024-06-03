#pragma once

//#include "Entity.h" Why this not needed?
#include <memory>

class Entity;

class Component {
public:
	Component(std::shared_ptr<Entity> owner)
		: owner_(owner) {}

	virtual void update(const sf::Time&) {}
	virtual void render(std::shared_ptr<sf::RenderWindow>) {}

protected:
	std::shared_ptr<Entity> owner_;
};