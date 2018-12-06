#pragma once
#include "imgui.h"
#include "application.h"

class Graph
{
private:

public:
	App* app;
	static bool isShowing;
	double x, y, w, h;
	double graph_width, graph_height;

public:
	Graph();
	~Graph();
	void Update();
};
