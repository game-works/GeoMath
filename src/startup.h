#pragma once

class Startup
{
private:
	const char* ID;

public:
	static bool isShowing;

public:
	Startup();
	~Startup();
	void Update();
};
