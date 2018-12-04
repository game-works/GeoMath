#pragma once
#include "imgui.h"

class Graph
{
private:

public:
	static bool isShowing;
	double x, y, w, h;
	double graph_width, graph_height;

public:
	Graph();
	~Graph();
	void Update();
};
