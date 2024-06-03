#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "Component.h"


class Entity {
public:
	Entity();

	void addComponent(const std::string& name, std::shared_ptr<Component> component);
	void removeComponent(const std::string& name);
	
	template <typename T>
	std::shared_ptr<T> getComponent(const std::string& name) {
		return std::dynamic_pointer_cast<T>(components_[name]);
	}

	void update(const sf::Time&);
	void render(std::shared_ptr<sf::RenderWindow> window);

	static int count;

private:
	int id_;
	std::map<std::string, std::shared_ptr<Component>> components_;
};

