#pragma once
#include <map>
#include <cstring>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Engine {
public:
	Engine();
	~Engine();
	Engine(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
private:
	bool isRunning;
	GLFWwindow* window;
	//std::map<std::string, SDL_Texture*> texMap;
};