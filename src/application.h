#pragma once
#include <vector>
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui-SFML.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"

class App
{
private:
	sf::RenderWindow* window;
	sf::Clock dt;
	sf::Event event;
	sf::Color bgColor;

public:
	static const char* window_title;
	static const char* version;
	static ImGuiWindowFlags flags;
	static bool isRunning;
	static bool isFullscreen;
	static int width;
	static int height;

public:
	App(const char* title, int w, int h, bool isFullscreen);
	~App();
	void Process();
	void Update();
	void Render();
	void Close();
};
