#include <iostream>
#include <math.h>
#include "data.h"
#include "application.h"
#include "graph.h"
#include "points.h"
#include "menu.h"
#include "helpers.h"
#include "vec2.h"

bool Data::isShowing = true;
std::vector<std::string> Data::items;

Data::Data()
{
	title = "Data";
}

Data::~Data()
{
	std::cout << "Data Deleted" << std::endl;
}

void Data::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowPos(ImVec2(x, y));
	ImGui::SetNextWindowSize(ImVec2(w, h));
	ImGui::Begin(title, NULL, App::flags);
	ShowDistance();
	ImGui::End();
}

void Data::ShowDistance()
{
	if (ImGui::TreeNode("Get Distance:"))
	{
		ImGui::SameLine(); Helpers::ShowHelp("Calculate the distance between two points: √((x1 - x2)² + (y1 + y2)²)");
		static const char* current_item = NULL;
		static const char* current_item2 = NULL;
		static int a;
		static int b;
		static float d;
		static bool calculated = false;

		if (items.size() == 0)
			calculated = false;

		if (calculated)
		{
			if (ImGui::TreeNode("Show Computation"))
			{
        ImGui::BeginChild("scrolling", ImVec2(0, ImGui::GetFrameHeightWithSpacing() * 7 + 30), true, ImGuiWindowFlags_HorizontalScrollbar);
				Vector2 p1 = *Points::points.at(a);
				Vector2 p2 = *Points::points.at(b);
				static char step1[64];
				static char step2[64];
				static char step3[64];
				static char step4[64];
				static char step5[64];
				static char step6[64];
				sprintf(step1, "= (%f - %f)² + (%f - %f)²", p1.x, p2.x, p1.y, p2.y);
				sprintf(step2, "= (%f)² + (%f)²", (p1.x - p2.x), (p1.y - p2.y));
				sprintf(step3, "= (%f + %f)", ((p1.x - p2.x) * (p1.x - p2.x)), ((p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step4, "= (%f)", ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step5, "= square root of (%f)", sqrt(((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))));
				sprintf(step6, "= %f", d);
				ImGui::Text("%s", step1);
				ImGui::Text("%s", step2);
				ImGui::Text("%s", step3);
				ImGui::Text("%s", step4);
				ImGui::Text("%s", step5);
				ImGui::Text("%s", step6);
				ImGui::EndChild();

				ImGui::TreePop();
			}
		}
		else
		{
			ImGui::Text("Computation");
		}

		if (ImGui::BeginCombo("Point A", current_item))
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

		if (ImGui::BeginCombo("Point B", current_item2))
		{
			int i = 0;
			for (const std::string& str : items)
			{
				const char* item = str.c_str();
				bool isSelected = (current_item2 == item);
				if (ImGui::Selectable(item, isSelected))
				{
					current_item2 = item;
					b = i;
				}
				if (isSelected)
					ImGui::SetItemDefaultFocus();

				i++;
			}
			ImGui::EndCombo();
		}
		ImGui::TreePop();

		ImGui::Text("Distance: ");
		ImGui::SameLine();
		char buf[64];
		sprintf(buf, "%f", d);
		ImGui::Text("%s", buf);

		if (ImGui::Button("Calculate Distance", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			if (current_item != NULL && current_item2 != NULL)
			{
				d = Helpers::getDistance(*Points::points.at(a), *Points::points.at(b));
				calculated = true;
			}
		}
	}
}
