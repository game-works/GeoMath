#include <iostream>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include "points.h"
#include "menu.h"
#include "graph.h"
#include "application.h"
#include "data.h"
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

	ImGui::SetNextWindowPos(ImVec2(x, y));
	ImGui::SetNextWindowSize(ImVec2(w, h));
	ImGui::Begin(title, NULL, App::flags);
	int i = 0;
	for (Vector2* point : points)
	{
		ImGui::PushID(i);
		char buf[128];
    sprintf(buf, "Point %d", i);
		ImGui::Separator();
		ImGui::Text("%s", buf);
		int x = (int)point->x;
		int y = (int)point->y;
		if (ImGui::InputInt("x", &x))
			point->x = x;
		if (ImGui::InputInt("y", &y))
			point->y = y;
		if (ImGui::Button("Delete Point", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.75, 0)))
		{
			Data::items.pop_back();
			points.pop_back();
		}

		ImGui::SameLine(); Helpers::ShowHelp("Delete A Point");

		i++;
		ImGui::NewLine();
		ImGui::PopID();
	}

	if (ImGui::Button("New Point", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.75, 0)))
	{
		char buf[128];
    sprintf(buf, "Point %d", i);
		std::string str(buf);
		Data::items.push_back(str);
		points.push_back(new Vector2());
	}

	ImGui::SameLine(); Helpers::ShowHelp("Add A New Point");
	ImGui::End();
}
