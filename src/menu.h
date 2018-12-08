#pragma once
#include "popup.h"
#include "application.h"

class Menu
{
private:
	Popup* exit_confirmation;
	Popup* about_us;
	Popup* about_software;

public:
	static bool isShowing;
	static bool isShowHelp;
	static bool show_exit_confirmation;
	static bool show_about_us;
	static bool show_about_software;
	static float height;
	App* context_app;

public:
	Menu();
	~Menu();
	void Update();
};
