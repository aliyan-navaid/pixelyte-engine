#pragma once

#include "Scene.h"

#include <stack>

namespace Core {
	class SceneManager {
	public:
		SceneManager();

		void pushState(std::unique_ptr<Scene> scene);
		void popState();

		void update(const sf::Time& dt);
		void render(std::shared_ptr<sf::RenderWindow> window);

	private:
		std::stack<std::unique_ptr<Scene>> scenes_;
	};
}
