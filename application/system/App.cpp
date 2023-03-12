#include "App.h"
#include "GLFW/glfw3.h"

using namespace Engine::Application;

namespace {
	GLFWwindow* window = nullptr;
	int gameWidth = 640;
	int gameHeight = 480;
	std::string gameTitle = "demo";
	bool inited = false;
	std::unique_ptr<GameManager> gManager = nullptr;
}

bool App::initialize() {
	if (inited) {
		return true;
	}
	if (!gManager) {
		return false;
	}
	if (!glfwInit()) {
		return false;
	}
	window = glfwCreateWindow(gameWidth, gameHeight, gameTitle.c_str(), NULL, NULL);
	if (!window) {
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	inited = true;
	return true;
}

void App::run() {
	if (!inited) {
		return;
	}
	if (!gManager) {
		return;
	}
	while(!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		gManager->update();
		gManager->draw();
		gManager->processInput();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	gManager->terminate();
}

void App::setGameName(const std::string &_title) {
	gameTitle = _title;
}

void App::setGameResolution(int _width, int _height) {
	gameWidth = _width;
	gameHeight = _height;
}

void App::setGameManager(std::unique_ptr<GameManager> _manager) {
	gManager = std::move(_manager);
}

void App::terminate() {
	if (gManager) {
		gManager->terminate();
	}
}
