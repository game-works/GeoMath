#pragma once
#include "imgui.h"

class Graph
{
private:
	ImGuiWindowFlags flags;
	double main_width;
	double main_height;
	double graph_width;
	double graph_height;

public:
	Graph();
	~Graph();
	void Update();
};
