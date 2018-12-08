#include <iostream>
#include <vector>
#include "popup.h"
#include "menu.h"
#include "imgui.h"

bool Popup::isShowing = true;

Popup::Popup(const char* str, const char* text)
	:ID(str), text(text)
{
}

Popup::~Popup()
{
	std::cout << "Popup " << ID << " Deleted" << std::endl;
}

void Popup::Update()
{
	if (!isShowing)
		return;

	ImGui::OpenPopup(ID);
	if (ImGui::BeginPopupModal(ID, NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings))
	{
		ImGui::NewLine();
		ImGui::Text(text, "%s");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::NewLine();

		for(Button* button : buttons)
		{
			button->Update();
		}
		ImGui::EndPopup();
	}
}

void Popup::AddButton(Button* button)
{
	buttons.push_back(button);
}
