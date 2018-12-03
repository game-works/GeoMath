#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
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
char Data::standard_form[128];
char Data::general_form[128];
int Data::a;
int Data::b;
int Data::opened = 0;
float Data::distance;
Vector2* Data::slope = new Vector2();
bool Data::calculated = false;
bool Data::autohide = false;
bool Data::is_custom_slope = false;

Data::Data()
{
	title = "Data";
}

Data::~Data()
{
	delete slope;
	std::cout << "Data Deleted" << std::endl;
	std::cout << "Slope Deleted" << std::endl;
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
	ImGui::Separator();
	ShowEquationOfTheLine();
	ImGui::Separator();
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
				char step0[64]; char step1[64]; char step2[64];
				char step3[64]; char step4[64];
				char step5[64]; char step6[64];
				sprintf(step0, "Formula\n= (x1 - x2)² + (y1 - y2)²");
				sprintf(step1, "Substitution\n= (%g - %g)² + (%g - %g)²", p1.x, p2.x, p1.y, p2.y);
				sprintf(step2, "Simplification\n= (%g)² + (%g)²", (p1.x - p2.x), (p1.y - p2.y));
				sprintf(step3, "= (%g + %g)", ((p1.x - p2.x) * (p1.x - p2.x)), ((p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step4, "= (%g)", ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step5, "= square root of (%g)", ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
				sprintf(step6, "= %g", distance);
				ImGui::Text("%s", step0); ImGui::Text("%s", step1); ImGui::Text("%s", step2);
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
				char step0[64]; char step1[64]; char step2[64];
				sprintf(step0, "Formula\n= (y2 - y1)/(x2 - x1)");
				sprintf(step1, "Substitution\n= (%g - %g)/(%g - %g)", p2.y, p1.y, p2.x, p1.x);
				sprintf(step2, "Simplification\n= %g/%g", slope->y, slope->x);
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
		sprintf(buf, "%g/%g", slope->y, slope->x);
		ImGui::Text("%s", buf);

		if (ImGui::Button("Calculate Slope", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			if (current_item != NULL && current_item2 != NULL)
			{
				*slope = Helpers::getSlope(*Points::points.at(a), *Points::points.at(b));
				calculated = true;
			}
		}
	}
}

void Data::ShowEquationOfTheLine()
{
	if (autohide)
		ImGui::SetNextTreeNodeOpen((opened == 3) ? true : false);

	if (ImGui::TreeNode("Get Equation of the Line"))
	{
		opened = 3;
		ImGui::SameLine(); Helpers::ShowHelp("Point-Slope Form : y - y1 = m(x - x1)\nTwo-Point Form : y - y1 = [(y2 - y1)/(x2 - x1)](x - x1)");
		if (items.size() == 0)
			calculated = false;
		if (calculated)
		{
			if (ImGui::TreeNode("Show Computation"))
			{
				Vector2 point = *Points::points.at(a);
				Vector2 point2 = *Points::points.at(b);
				float m = (slope->y/slope->x);
				float y1 = point.y; float x1 = point.x;
				char slope[64]; char slope1[64]; char slope2[64];
				char step0[64]; char step1[64];
				char step2[64]; char step3[64];
				char sf[64]; char gf[64];

				ImGui::BeginChild("scrolling", ImVec2(0, ImGui::GetFrameHeightWithSpacing() * 7 + 30), true, ImGuiWindowFlags_HorizontalScrollbar);
				sprintf(slope, "Slope Formula\n(y2 - y1)/(x2 - x1)");
				sprintf(slope1, "Substitution\n(%g - %g)/(%g - %g)", point2.y, point.y, point2.x, point.x);
				sprintf(slope2, "Slope\n%g/%g\n", point2.y - point.y, point2.x - point.x);
				sprintf(step0, "Formula\ny - y1 = m(x - x1)"); //equation
				sprintf(step1, "Substitution\ny - %g = %g(x - %g)", y1, m, x1); //substitution
				sprintf(step2, "Distribution\ny - %g = %gx - %g", y1, m, m * x1); //distribution
				sprintf(step3, "Transposition\n%gx - y = %g + %g", m, m * x1, y1 * -1); //transposition
				sprintf(sf, "Standard Form: %gx - y = %g", m, (m * x1) + (y1 * -1)); //simplification
				sprintf(gf, "General Form: %gx - y + %g = 0", m, (m * x1) + (y1 * -1)); //simplification
				ImGui::Text("%s", slope);	ImGui::Text("%s", step0);
				ImGui::Text("%s", step1);	ImGui::Text("%s", step2);
				ImGui::Text("%s", step3);	ImGui::Text("%s", sf);
				ImGui::Text("%s", gf);	ImGui::EndChild();
				ImGui::TreePop();
			}
		}
		else
		{
			ImGui::Text("Computation");
		}

		Helpers::BeginCombo(items, "Point A", current_item, a);
		if (!is_custom_slope)
			Helpers::BeginCombo(items, "Point B", current_item2, b);

		ImGui::Checkbox("Custom Slope", &is_custom_slope);
		if (is_custom_slope)
		{
			int x = (int)slope->x;
			int y = (int)slope->y;
			if (ImGui::InputInt("x", &x))
				slope->x = x;
			if (ImGui::InputInt("y", &y))
				slope->y = y;
		}
		char str[64];
		sprintf(str, "Slope: %g/%g", slope->y, slope->x);
		ImGui::Text("%s", str);
		ImGui::TreePop();
		ImGui::Separator();

		ImGui::Text("Standard Form: ");
		ImGui::SameLine();
		ImGui::Text("%s", standard_form);

		ImGui::Separator();

		ImGui::Text("General Form: ");
		ImGui::SameLine();
		ImGui::Text("%s", general_form);

		if (ImGui::Button("Calculate", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			if (current_item != NULL)
			{
				std::string str1 = Helpers::GetEquationOfTheLineStandard(*current_item, *slope);
				std::string str2 = Helpers::GetEquationOfTheLineGeneral(*current_item, *slope);
				strcpy(standard_form, str1.c_str());
				strcpy(general_form, str2.c_str());
				std::cout << "SF: " << standard_form << std::endl;
				std::cout << "GF: " << general_form << std::endl;
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
