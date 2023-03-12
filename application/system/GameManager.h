#pragma once

namespace Engine::Application {
	class GameManager {
	public:
		GameManager() = default;
		virtual ~GameManager() = default;

		virtual void initialize() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void processInput() = 0;
		virtual void terminate() = 0;
	};
}