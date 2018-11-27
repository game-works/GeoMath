#pragma once

class Button
{
private:
	const char* text;
	void (*callback)(void);

public:
	Button(const char* text, void (*func)());
	~Button();
	void Update();
};
