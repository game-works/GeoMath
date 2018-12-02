#pragma once

#include "imgui.h"
#include "menu.h"

class Helpers
{
public:
	static void ShowHelp(const char* desc);
};

void Helpers::ShowHelp(const char* desc)
{
	if (!Menu::isShowHelp)
		return;

	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}
