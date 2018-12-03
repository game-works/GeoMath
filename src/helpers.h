#pragma once

#include <string>
#include <vector>
#include "vec2.h"

class Helpers
{
public:
	static void ShowHelp(const char* desc);
	static float getDistance(Vector2 a, Vector2 b);
	static Vector2 getSlope(Vector2 a, Vector2 b);
	static void BeginCombo(std::vector<std::string> items, const char* str, const char* &current_item, int &a);
};
