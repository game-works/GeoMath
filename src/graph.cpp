#include <iostream>
#include "graph.h"
#include "application.h"
#include "menu.h"
#include "points.h"
#include <SFML/Graphics.hpp>

bool Graph::isShowing = true;

Graph::Graph()
{
}

Graph::~Graph()
{
	std::cout << "Graph Deleted" << std::endl;
}

void Graph::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowPos(ImVec2(x, y));
	ImGui::SetNextWindowSize(ImVec2(w, h));
	ImGui::Begin("Graph", NULL, App::flags);
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
	ImVec2 canvas_size = ImGui::GetContentRegionAvail();
	ImVec2 mouse_pos_in_canvas = ImVec2(ImGui::GetIO().MousePos.x - canvas_pos.x, ImGui::GetIO().MousePos.y - canvas_pos.y);
	static ImColor canvas_color = IM_COL32(50, 50, 50, 255);
	static ImColor canvas_color2 = IM_COL32(50, 50, 60, 255);
	static ImColor canvas_color3 = IM_COL32(50, 50, 70, 255);
	static ImColor canvas_color4 = IM_COL32(50, 50, 80, 255);
	static ImColor line_color = IM_COL32(255, 255, 0, 255);
	static ImColor point_color = IM_COL32(150, 150, 150, 255);
	draw_list->AddRectFilledMultiColor(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), canvas_color, canvas_color2, canvas_color3, canvas_color4);
	draw_list->AddLine(ImVec2(canvas_pos.x, canvas_pos.y + canvas_size.y/2), ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y/2), line_color);
	draw_list->AddLine(ImVec2(canvas_pos.x + canvas_size.x/2, canvas_pos.y), ImVec2(canvas_pos.x + canvas_size.x/2, canvas_pos.y + canvas_size.y), line_color);

	for (Vector2 *point : Points::points)
	{
		float radius = 4;
		float bx = canvas_pos.x + canvas_size.x/2;
		float by = canvas_pos.y + canvas_size.y/2;
		float x = bx + (point->x * 32);
		float y = by + (point->y * 32);
		draw_list->AddCircleFilled(ImVec2(x, y), radius, point_color);
	}

	ImGui::End();
}
