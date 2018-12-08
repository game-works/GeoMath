#pragma once

#include "imgui.h"
#include "application.h"

class Graph
{
private:

public:
	App* app;
	static bool isShowing;
	static bool isFullscreen;
	static int scale;
	static int radius;
	double x, y, w, h;
	double graph_width, graph_height;
	double full_w, full_h;

public:
	Graph();
	~Graph();
	void Update();
	void DrawHorizontal(float mx, float my, int sign, ImColor line_color);
	void DrawVertical(float mx, float my, int sign, ImColor line_color);
};
