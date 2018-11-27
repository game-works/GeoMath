#include <iostream>
#include "imgui.h"
#include "button.h"

Button::Button(const char* text, void (*func)(void))
	:text(text), callback(func)
{
}

Button::~Button()
{
	std::cout << "Button " << text << " Deleted" << std::endl;
}

void Button::Update()
{
	if (ImGui::Button(text, ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
	{
		ImGui::SetItemDefaultFocus();
		callback();
		ImGui::CloseCurrentPopup();
	}
}
