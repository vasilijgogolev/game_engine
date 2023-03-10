#include "App.h"
#include "GLFW/glfw3.h"

using namespace Application;

namespace {
	GLFWwindow* window = nullptr;
}

bool App::initialize() {
	if (inited) {
		return true;
	}
	if (!glfwInit()) {
		return false;
	}
	window = glfwCreateWindow(640, 480, "Hello world!", NULL, NULL);
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
	while(!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}