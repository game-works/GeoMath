#include <iostream>
#include "graph.h"
#include "application.h"
#include "menu.h"
#include "points.h"

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
	// if (Points::points.size() > 0)
	// {
  //   static float values[10] = {};
  //   int i = 0;
  //   for (Vector2* point : Points::points)
  //   {
  //   	float n = point->x*i/100;
  //   	values[i] = n;
  //   	i++;
  //   }
	// 	ImGui::PlotLines("", values, IM_ARRAYSIZE(values), 0, "", -0.5f, 1.0f, ImVec2(graph_width, graph_height));
	// }
	ImGui::End();
}
