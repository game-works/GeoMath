#include "application.h"
#include <iostream>

bool App::isRunning = false;

App::App(const char* title, int w, int h)
{
	window_title = title;
	width = w;
	height = h;

	window = new sf::RenderWindow(sf::VideoMode(width, height), window_title);
	window->setVerticalSyncEnabled(true);
	ImGui::SFML::Init(*window);
	window->setTitle(window_title);
	window->resetGLStates();
}

App::~App()
{
	ImGui::SFML::Shutdown();
	delete window;
	std::cout << "Application Deleted" << std::endl;
}

void App::Process()
{
	while(window->pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);
		if (event.type == sf::Event::Closed)
		{
			isRunning = false;
			window->close();
		}
	}
}

void App::Update()
{
	ImGui::SFML::Update(*window, dt.restart());
}

void App::Render()
{
	window->clear(bgColor);
	ImGui::SFML::Render(*window);
	window->display();
}

void App::Close()
{
	isRunning = false;
}

const char* App::getWindowTitle()
{
	return window_title;
}
