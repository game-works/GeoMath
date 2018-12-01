#include <stdio.h>
#include <iostream>
#include "points.h"
#include "menu.h"
#include "graph.h"
#include "application.h"
#include "helpers.h"

bool Points::isShowing = true;
std::vector<Vector2*> Points::points;

Points::Points()
{
	title = "Points";
}

Points::~Points()
{
	std::cout << "Points Deleted" << std::endl;
}

void Points::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(w, h), ImGuiCond_FirstUseEver);
	ImGui::Begin(title, NULL, App::flags);
	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth());
	int i = 0;
	for (Vector2* point : points)
	{
		ImGui::PushID(i);
    char buf[128];
    sprintf(buf, "Point %d", i);
		ImGui::Text("%s", buf);
		int x = (int)point->x;
		int y = (int)point->y;
		if (ImGui::InputInt("x", &x))
			point->x = x;
		if (ImGui::InputInt("y", &y))
			point->y = y;
		if (ImGui::Button("Delete Point"))
			points.pop_back();

		ImGui::SameLine(); Helpers::ShowHelp("Delete A Point");

		i++;
		ImGui::NewLine();
		ImGui::PopID();
	}

	if (ImGui::Button("New Point"))
		points.push_back(new Vector2());

	ImGui::SameLine(); Helpers::ShowHelp("Add A New Point");
	ImGui::PopItemWidth();
	ImGui::End();
}
