#include <stdio.h>
#include <iostream>
#include "data.h"
#include "application.h"

bool Data::isShowing = true;
std::vector<Vector2*> Data::points;

Data::Data()
{
	title = "Data";
	flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
	main_width = App::width * 0.3;
	main_height = App::height * 0.8;
}

Data::~Data()
{
	std::cout << "Data Deleted" << std::endl;
}

void Data::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowPos(ImVec2(main_width/2, 0), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(main_width, main_height));
	ImGui::Begin(title, NULL, flags);
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

		i++;
		ImGui::NewLine();
		ImGui::PopID();
	}

	if (ImGui::Button("New Point"))
		points.push_back(new Vector2());
	ImGui::PopItemWidth();
	ImGui::End();
}
