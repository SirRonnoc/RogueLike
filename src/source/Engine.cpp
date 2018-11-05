#define GLEW_STATIC
#include <iostream>
#include "Engine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Engine::Engine() {

}
Engine::~Engine() {

}
Engine::Engine(const char* title, int width, int height, bool fullscreen) {
	if (!glfwInit()) {
		std::cout << "failed to initialize glfw" << std::endl;
		return;
	}
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL) {
		std::cout << "window failed to be initialied" << std::endl;
		glfwTerminate();
		return;
	}
	
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "glew initialization failed" << std::endl;
		glfwTerminate();
		return;
	}
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}
void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT);

	//draw stuff here
	glfwSwapBuffers(window);
}
void Engine::handleEvents() {
	glfwPollEvents();
	if (glfwWindowShouldClose(window) != 0) {
		glfwTerminate();
	}
}
bool Engine::running() {
	return isRunning;
}