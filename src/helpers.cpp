#include "imgui.h"
#include "helpers.h"
#include "menu.h"

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
