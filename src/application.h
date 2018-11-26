#pragma once
#include <vector>
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"

class App
{
//PROPERTIES
private:
	sf::RenderWindow* window;
	sf::Clock dt;
	sf::Event event;
	sf::Color bgColor;

public:
	static const char* window_title;
	static int width;
	static int height;
	static bool isRunning;

//METHODS
public:
	App(const char* title, int w, int h);
	~App();
	void Process();
	void Update();
	void Render();
	void Close();
};