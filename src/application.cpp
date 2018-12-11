#include <iostream>
#include "application.h"

const char* App::window_title;
const char* App::version;
const char* App::date;
ImGuiWindowFlags App::flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
bool App::isRunning = false;
bool App::isFullscreen = false;
int App::width;
int App::height;

App::App(const char* title, int w, int h, bool fs)
{
	window_title = title;
	width = w;
	height = h;
	isFullscreen = fs;

	window = new sf::RenderWindow(sf::VideoMode(width, height), window_title, (App::isFullscreen) ? sf::Style::Fullscreen : sf::Style::Default);
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
