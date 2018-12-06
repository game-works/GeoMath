#include "helpers.h"
#include <iostream>
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

std::string Helpers::GetEquationOfTheLineStandard(Vector2 a, Vector2 slope)
{
	float m = (slope.y/slope.x);
	float y1 = a.y;
	float x1 = a.x;
	char sf[64];
	sprintf(sf, "%gx - y = %g", m, (m * x1) + (y1 * -1)); //simplification
	return std::string(sf);
}

std::string Helpers::GetEquationOfTheLineGeneral(Vector2 a, Vector2 slope)
{
	float m = (slope.y/slope.x);
	float y1 = a.y;
	float x1 = a.x;
	char gf[64];
	sprintf(gf, "%gx - y + %g = 0", m, (m * x1) + (y1 * -1)); //simplification
	return std::string(gf);
}
