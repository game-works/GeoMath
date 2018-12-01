#pragma once

#include "imgui.h"

class Data
{
private:
	const char* title;

public:
	static bool isShowing;
	double x, y, w, h;

public:
	Data();
	~Data();
	void Update();
};
