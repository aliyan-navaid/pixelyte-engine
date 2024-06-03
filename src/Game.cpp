#include "Game.h"
#include "iostream"
/* Why was relative path not working? */

Game::Game()
	: window_(std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Game")), 
	  scenes_(std::make_shared<Core::SceneManager>()), running_(true)
{
	scenes_->pushState(std::make_unique<testScene>());
	scenes_->pushState(std::make_unique<flashScene>(scenes_));
}

void Game::update()
{
	/* Window Events */
	sf::Event event;
	while (window_->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			running_ = false;
	}
	scenes_->update(dt_);
}

void Game::render()
{
	window_->clear(sf::Color::White);
	scenes_->render(window_);
	window_->display();
}

void Game::calculateDT()
{
	dt_ = clock_.restart();
}

bool Game::isRunning() const
{
	return running_;
}
