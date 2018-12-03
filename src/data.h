#pragma once

#include <vector>
#include <string>
#include "imgui.h"
#include "vec2.h"

class Data
{
private:
	const char* title;

public:
	static bool isShowing;
	static std::vector<std::string> items;
	double x, y, w, h;
	static const char* current_item;
	static const char* current_item2;
	static int opened;
	static int a;
	static int b;
	static float distance;
	static Vector2 slope;
	static bool calculated;
	static bool autohide;

public:
	Data();
	~Data();
	void Update();
	void ShowDistance();
	void ShowSlope();
	static void Reset();
};
