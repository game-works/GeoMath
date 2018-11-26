#include <iostream>
#include "popup.h"
#include "menu.h"
#include "imgui.h"

Popup::Popup(const char* str, const char* text)
	:ID(str), text(text)
{
}

Popup::~Popup()
{
	std::cout << "Deleted: " << ID << std::endl;
}

void Popup::Update(bool &open)
{
	if (!open)
		return;
	clicked = -1;
	ImGui::OpenPopup(ID);
	if (ImGui::BeginPopupModal(ID, NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::NewLine();
		ImGui::Text(text, "%s");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::NewLine();

		if (btn_1)
		{
			if (ImGui::Button(btn1_text, ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
			{
				ImGui::CloseCurrentPopup();
				clicked = 1;
			}
		}

		if (btn_2)
		{
			ImGui::SetItemDefaultFocus();
			if (ImGui::Button(btn2_text, ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
			{
				ImGui::CloseCurrentPopup();
				clicked = 0;
			}
		}
		ImGui::EndPopup();
	}
}

void Popup::SetButton1(const char* text)
{
	btn1_text = text;
	btn_1 = true;
}

void Popup::SetButton2(const char* text)
{
	btn2_text = text;
	btn_2 = true;
}
