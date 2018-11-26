#pragma once
#include "popup.h"

class Menu
{
private:
	Popup* exit_confirmation;
	Popup* about_us;
	Popup* about_software;

public:
	static bool isShowing;
	static bool show_exit_confirmation;
	static bool show_about_us;
	static bool show_about_software;

public:
	Menu();
	~Menu();
	void Update();
	void HandleExitConfirmation();
	void HandleAboutConfirmation(bool &target, int &choice);
};
