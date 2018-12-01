#pragma once
#include <vector>
#include "vec2.h"
#include "imgui.h"

class Points
{
private:
	const char* title;

public:
	static bool isShowing;
	static std::vector<Vector2*> points;
	double x, y, w, h;

public:
	Points();
	~Points();
	void Update();
};
