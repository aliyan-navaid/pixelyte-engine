#include "Core/SceneManager.h"

Core::SceneManager::SceneManager()
{
}

void Core::SceneManager::pushState(std::unique_ptr<Scene> scene)
{
	scenes_.push(std::move(scene));
}

void Core::SceneManager::popState()
{
	scenes_.pop();
}

void Core::SceneManager::update(const sf::Time& dt)
{
	if (!scenes_.empty()) {
		scenes_.top()->update(dt);
	}
}

void Core::SceneManager::render(std::shared_ptr<sf::RenderWindow> window)
{
	if (!scenes_.empty()) {
		scenes_.top()->render(window);
	}
}
