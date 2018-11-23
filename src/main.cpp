#include <iostream>
#include "imgui.h"
#include "imgui_demo.cpp"
#include "imgui-SFML.h"
#include "application.h"
#include "menu.h"

int main()
{
	Menu* menu = new Menu();
	App* app = new App("Math Project", 640, 480);
	App::isRunning = true;

	while (App::isRunning)
	{
		app->Process();
		app->Update();
		ImGui::ShowDemoWindow();
		menu->Update();
		app->Render();
	}

	delete app;
	delete menu;
}
