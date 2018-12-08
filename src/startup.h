#pragma once

class Startup
{
private:
	const char* ID;
	const char* text;

public:
	static bool isShowing;

public:
	Startup();
	~Startup();
	void Update();
};
