#include "Entity.h"

int Entity::count = 0;

Entity::Entity()
	: id_(count++)
{
}

void Entity::addComponent(const std::string& name, std::shared_ptr<Component> component)
{
	// insert check for already exists
	components_[name] = component;
}

void Entity::removeComponent(const std::string& name)
{
	// insert check for not found
	components_.erase(name);
}

void Entity::update(const sf::Time& dt)
{
	for (auto itr = components_.begin(); itr != components_.end(); itr++) {
		itr->second->update(dt);
	}
}

void Entity::render(std::shared_ptr<sf::RenderWindow> window)
{
	for (auto itr = components_.begin(); itr != components_.end(); itr++) {
		itr->second->render(window);
	}
}
