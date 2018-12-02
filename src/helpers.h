#pragma once

#include "vec2.h"

class Helpers
{
public:
	static void ShowHelp(const char* desc);
	static float getDistance(Vector2 a, Vector2 b);
	static Vector2 getSlope(Vector2 a, Vector2 b);
};
