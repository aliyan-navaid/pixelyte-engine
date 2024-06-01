#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Core/SceneManager.h"
#include "testScene.h"

class Game {
public:
	Game();
	
	void update();
	void render();

	void calculateDT();
	bool isRunning() const;

private:
	/* Extend ownership to Core Managers */
	std::shared_ptr<sf::RenderWindow> window_;
	
	/* Consistent Gameplay on different Devices */
	sf::Clock clock_;
	sf::Time dt_;

	Core::SceneManager scenes_;

	bool running_;
};