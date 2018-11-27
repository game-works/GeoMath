#pragma once
#include <vector>
#include "button.h"

class Popup
{
private:
	const char* ID;
	const char* text;
	std::vector<Button*> buttons;

public:
	static bool isShowing;

public:
	Popup(const char* str, const char* text);
	~Popup();
	void Update();
	void AddButton(Button* button);
};
