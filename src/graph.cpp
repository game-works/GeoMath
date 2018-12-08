#include <iostream>
#include <SFML/Graphics.hpp>
#include "graph.h"
#include "application.h"
#include "menu.h"
#include "points.h"
#include "data.h"

bool Graph::isShowing = true;
bool Graph::isFullscreen = false;
int Graph::scale = 32;
int Graph::radius = 4;

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

	if (isFullscreen)
		ImGui::SetNextWindowSize(ImVec2(full_w, full_h));
	else
		ImGui::SetNextWindowSize(ImVec2(w, h));

	ImGui::Begin("Graph", NULL, App::flags);
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
	ImVec2 canvas_size = ImGui::GetContentRegionAvail();
	static ImColor canvas_color = IM_COL32(50, 50, 50, 255);
	static ImColor canvas_color2 = IM_COL32(50, 50, 60, 255);
	static ImColor canvas_color3 = IM_COL32(50, 50, 70, 255);
	static ImColor canvas_color4 = IM_COL32(50, 50, 80, 255);
	static ImColor line_color = IM_COL32(255, 255, 0, 255);
	static ImColor point_color = IM_COL32(150, 150, 150, 255);
	draw_list->AddRectFilledMultiColor(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), canvas_color, canvas_color2, canvas_color3, canvas_color4);
	draw_list->AddLine(ImVec2(canvas_pos.x, canvas_pos.y + canvas_size.y/2), ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y/2), line_color);
	draw_list->AddLine(ImVec2(canvas_pos.x + canvas_size.x/2, canvas_pos.y), ImVec2(canvas_pos.x + canvas_size.x/2, canvas_pos.y + canvas_size.y), line_color);

	float mx = canvas_pos.x + canvas_size.x/2;
	float my = canvas_pos.y + canvas_size.y/2;
	DrawHorizontal(mx, my, -1, line_color);
	DrawHorizontal(mx, my, 1, line_color);
	DrawVertical(mx, my, -1, line_color);
	DrawVertical(mx, my, 1, line_color);

	for (Vector2 *point : Points::points)
	{
		float x = mx + (point->x * scale);
		float y = my + (point->y * scale);
		draw_list->AddCircleFilled(ImVec2(x, y), radius, point_color);
	}

	Vector2 a = *Points::points.at(Data::a);
	Vector2 b = *Points::points.at(Data::b);
	float x1 = mx + (a.x * scale);
	float y1 = my + (a.y * scale);
	float x2 = mx + (b.x * scale);
	float y2 = my + (b.y * scale);
	draw_list->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), line_color);

	ImGui::End();
}

void Graph::DrawHorizontal(float mx, float my, int sign, ImColor line_color)
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	for (int i = 1; i <= scale/2; i++)
	{
		float x = mx + (sign * i * scale);
		float y = my - scale/4;
		float y2 = my + scale/4;
		draw_list->AddLine(ImVec2(x, y), ImVec2(x, y2), line_color);
	}
}

void Graph::DrawVertical(float mx, float my, int sign, ImColor line_color)
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	for (int i = 1; i <= scale/2; i++)
	{
		float y = my + (sign * i * scale);
		float x = mx - scale/4;
		float x2 = mx + scale/4;
		draw_list->AddLine(ImVec2(x, y), ImVec2(x2, y), line_color);
	}
}
