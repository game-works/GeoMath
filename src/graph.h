#pragma once
#include "imgui.h"

class Graph
{
private:

public:
	static bool isShowing;
	double x, y, w, h;

public:
	Graph();
	~Graph();
	void Update();
};
