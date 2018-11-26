#pragma once
#include <vector>
#include "vec2.h"
#include "imgui.h"

class Data
{
private:
	ImGuiWindowFlags flags;
	const char* title;
	double main_width;
	double main_height;

public:
	static std::vector<Vector2*> points;

public:
	Data();
	~Data();
	void Update();
};
