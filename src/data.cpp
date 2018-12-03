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
const char* Data::current_item = NULL;
const char* Data::current_item2 = NULL;
int Data::a;
int Data::b;
int Data::opened = 0;
float Data::distance;
Vector2 Data::slope;
bool Data::calculated = false;
bool Data::autohide = true;

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
	ImGui::Separator();
	ShowSlope();
	ImGui::End();
}

void Data::ShowDistance()
{
	if (autohide)
		ImGui::SetNextTreeNodeOpen((opened == 1) ? true : false);

	if (ImGui::TreeNode("Get Distance:"))
	{
		opened = 1;
		ImGui::SameLine(); Helpers::ShowHelp("Calculate the distance between two points: square root of ((x1 - x2)² + (y1 + y2)²)");
		if (items.size() == 0)
			calculated = false;

		if (calculated)
		{
			if (ImGui::TreeNode("Show Computation"))
			{
        ImGui::BeginChild("scrolling", ImVec2(0, ImGui::GetFrameHeightWithSpacing() * 7 + 30), true, ImGuiWindowFlags_HorizontalScrollbar);
				Vector2 p1 = *Points::points.at(a);
				Vector2 p2 = *Points::points.at(b);
				static char step1[64]; static char step2[64];
				static char step3[64]; static char step4[64];
				static char step5[64]; static char step6[64];
				sprintf(step1, "= (%g - %g)² + (%g - %g)²", p1.x, p2.x, p1.y, p2.y);
				sprintf(step2, "= (%g)² + (%g)²", (p1.x - p2.x), (p1.y - p2.y));
				sprintf(step3, "= (%g + %g)", ((p1.x - p2.x) * (p1.x - p2.x)), ((p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step4, "= (%g)", ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step5, "= square root of (%g)", ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step6, "= %g", distance);
				ImGui::Text("%s", step1); ImGui::Text("%s", step2);
				ImGui::Text("%s", step3); ImGui::Text("%s", step4);
				ImGui::Text("%s", step5); ImGui::Text("%s", step6);
				ImGui::EndChild();
				ImGui::TreePop();
			}
		}
		else
		{
			ImGui::Text("Computation");
		}

		Helpers::BeginCombo(items, "Point A", current_item, a);
		Helpers::BeginCombo(items, "Point B", current_item2, b);
		ImGui::TreePop();
		ImGui::Text("Distance: ");
		ImGui::SameLine();
		char buf[64];
		sprintf(buf, "%g", distance);
		ImGui::Text("%s", buf);

		if (ImGui::Button("Calculate Distance", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			if (current_item != NULL && current_item2 != NULL)
			{
				distance = Helpers::getDistance(*Points::points.at(a), *Points::points.at(b));
				calculated = true;
			}
		}
	}
}

void Data::ShowSlope()
{
	if (autohide)
		ImGui::SetNextTreeNodeOpen((opened == 2) ? true : false);

	if (ImGui::TreeNode("Get Slope:"))
	{
		opened = 2;
		ImGui::SameLine(); Helpers::ShowHelp("Calculate the slope: (rise/run) or (y2 - y1)/(x2 - x1)");
		if (items.size() == 0)
			calculated = false;
		if (calculated)
		{
			if (ImGui::TreeNode("Show Computation"))
			{
        ImGui::BeginChild("scrolling", ImVec2(0, ImGui::GetFrameHeightWithSpacing() * 7 + 30), true, ImGuiWindowFlags_HorizontalScrollbar);
				Vector2 p1 = *Points::points.at(a);
				Vector2 p2 = *Points::points.at(b);
				static char step1[64]; static char step2[64];
				sprintf(step1, "= (%g - %g)/(%g - %g)", p2.y, p1.y, p2.x, p1.x);
				sprintf(step2, "= %g/%g", slope.y, slope.x);
				ImGui::Text("%s", step1); ImGui::Text("%s", step2);
				ImGui::EndChild();
				ImGui::TreePop();
			}
		}
		else
		{
			ImGui::Text("Computation");
		}

		Helpers::BeginCombo(items, "Point A", current_item, a);
		Helpers::BeginCombo(items, "Point B", current_item2, b);
		ImGui::TreePop();
		ImGui::Text("Slope: ");
		ImGui::SameLine();
		char buf[64];
		sprintf(buf, "%g/%g", slope.y, slope.x);
		ImGui::Text("%s", buf);

		if (ImGui::Button("Calculate Slope", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			if (current_item != NULL && current_item2 != NULL)
			{
				slope = Helpers::getSlope(*Points::points.at(a), *Points::points.at(b));
				calculated = true;
			}
		}
	}
}

void Data::Reset()
{
	current_item = NULL;
	current_item2 = NULL;
	a = 0;
	b = 0;
	distance = 0;
	calculated = false;
}
