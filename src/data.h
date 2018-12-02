#pragma once

#include <vector>
#include <string>
#include "imgui.h"

class Data
{
private:
	const char* title;

public:
	static bool isShowing;
	static std::vector<std::string> items;
	double x, y, w, h;

public:
	Data();
	~Data();
	void Update();
	void ShowDistance();
};
