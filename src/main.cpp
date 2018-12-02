#include <iostream>
#include "imgui.h"
#include "imgui_demo.cpp"
#include "imgui-SFML.h"
#include "application.h"
#include "menu.h"
#include "graph.h"
#include "points.h"
#include "data.h"

int main()
{
	App* app = new App("Math Project", 1024, 720, false);
	App::version = "0.0.2";
	App::isRunning = true;

	Menu* menu = new Menu();
	menu->context_app = app;
	Graph* graph = new Graph();
	Points* points = new Points();
	Data* data = new Data();

	while (App::isRunning)
	{
		app->Process();
		app->Update();
#if _DEBUG
		ImGui::ShowDemoWindow();
#endif

		menu->Update();

		static int pad_x = 16;
		static int pad_y = 16;
		static int y = Menu::height + pad_y;
		static double width = App::width - (pad_x * 4);
		static double height = App::height - Menu::height - pad_y * 2;
		graph->x = pad_x;
		graph->y = y;
		graph->w = width * 0.4;
		graph->h = height;
		points->x = graph->x + graph->w + pad_x;
		points->y = y;
		points->w = width * 0.35;
		points->h = height;
		data->x = points->x + points->w + pad_x;
		data->y = y;
		data->w = width * 0.25;
		data->h = height;

		graph->Update();
		points->Update();
		data->Update();
		app->Render();
	}

	delete points;
	delete graph;
	delete menu;
	delete app;
}
