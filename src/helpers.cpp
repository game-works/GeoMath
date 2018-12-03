#include "helpers.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "imgui.h"
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

float Helpers::getDistance(Vector2 a, Vector2 b)
{
	float x = (a.x - b.x) * (a.x - b.x);
	float y = (a.y - b.y) * (a.y - b.y);
	float d = sqrt(x + y);
	return d;
}

Vector2 Helpers::getSlope(Vector2 a, Vector2 b)
{
	float x = (b.x - a.x);
	float y = (b.y - a.y);
	return Vector2(x, y);
}

void Helpers::BeginCombo(std::vector<std::string> items, const char* str, const char* &current_item, int &a)
{
	if (ImGui::BeginCombo(str, current_item))
	{
		int i = 0;
		for (const std::string& str : items)
		{
			const char* item = str.c_str();
			bool isSelected = (current_item == item);
			if (ImGui::Selectable(item, isSelected))
			{
				current_item = item;
				a = i;
			}
			if (isSelected)
				ImGui::SetItemDefaultFocus();

			i++;
		}
		ImGui::EndCombo();
	}
}
