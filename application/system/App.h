#pragma once
#include <string>
#include <memory>
#include "GameManager.h"

namespace Engine::Application {
	class App {
	public:
		App() = default;
		~App() = default;

		static bool initialize();
		static void run();

		static void setGameName(const std::string& _title);
		static void setGameResolution(int _width, int _height);
		static void setGameManager(std::unique_ptr<GameManager> _manager);
		static void terminate();
	};
}