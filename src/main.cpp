#include <iostream>
#include "imgui.h"
#include "imgui_demo.cpp"
#include "imgui-SFML.h"
#include "application.h"
#include "menu.h"
#include "graph.h"
#include "data.h"

// #ifndef DEBUG
// 	#define DEBUG true
// #endif

int main()
{
	App* app = new App("Math Project", 1280, 800);
	App::version = "0.0.2";
	App::isRunning = true;

	Menu* menu = new Menu();
	Graph* graph = new Graph();
	Data* data = new Data();

	while (App::isRunning)
	{
		app->Process();
		app->Update();
#if DebugMode
		ImGui::ShowDemoWindow();
#endif
		menu->Update();
		graph->Update();
		data->Update();
		app->Render();
	}

	delete data;
	delete graph;
	delete menu;
	delete app;
}
