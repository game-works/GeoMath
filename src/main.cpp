#include <iostream>
#include "imgui.h"
#include "imgui_demo.cpp"
#include "imgui-SFML.h"
#include "application.h"
#include "startup.h"
#include "menu.h"
#include "graph.h"
#include "points.h"
#include "data.h"
#include "user.h"

App* app;
Startup* startup;
Menu* menu;
Graph* graph;
Points* points;
Data* data;

void SetLayoutA();
void SetLayoutB();

int main()
{
	app = new App("Math Project", 1024, 720, false);
	startup = new Startup();
	menu = new Menu();
	graph = new Graph();
	graph->app = app;
	points = new Points();
	data = new Data();

	App::version = "0.0.5";
	App::isRunning = true;
	menu->context_app = app;

	while (App::isRunning)
	{
		app->Process();
		app->Update();
#if _DEBUG
		ImGui::ShowDemoWindow();
#endif

		startup->Update();
		menu->Update();

		if (User::layout == 1)
			SetLayoutA();
		else if (User::layout == 2)
			SetLayoutB();

		graph->Update();
		points->Update();
		data->Update();
		app->Render();
	}

	delete points;
	delete graph;
	delete menu;
	delete startup;
	delete app;
}

void SetLayoutA()
{
	int pad_x = 16;
	int pad_y = 16;
	int y = Menu::height + pad_y;
	double width = App::width - (pad_x * 4);
	double height = App::height - Menu::height - pad_y * 2;
	graph->x = pad_x;
	graph->y = y;
	graph->w = width * 0.4;
	graph->h = height;
	graph->graph_width = graph->w * 0.9;
	graph->graph_height = graph->h * 0.9;
	graph->full_w = width;
	graph->full_h = height + pad_y;
	points->x = graph->x + graph->w + pad_x;
	points->y = y;
	points->w = width * 0.25;
	points->h = height;
	data->x = points->x + points->w + pad_x;
	data->y = y;
	data->w = width * 0.35;
	data->h = height;
}

void SetLayoutB()
{
	int pad_x = 16;
	int pad_y = 16;
	int y = Menu::height + pad_y;
	double width = App::width - (pad_x * 2);
	double height = App::height - Menu::height - (pad_y * 3);
	graph->x = pad_x;
	graph->y = y;
	graph->w = width;
	graph->h = height * 0.55;
	graph->graph_width = graph->w * 0.9;
	graph->graph_height = graph->h * 0.9;
	graph->full_w = width;
	graph->full_h = height + pad_y;

	points->x = pad_x;
	points->y = graph->y + graph->h + pad_y;
	points->w = graph->w * 0.5 - pad_x;
	points->h = height * 0.45;

	data->x = points->x + points->w + pad_x;
	data->y = points->y;
	data->w = graph->w * 0.5;
	data->h = points->h;
}
