#include <iostream>
#include "graph.h"
#include "application.h"
#include "data.h"

bool Graph::isShowing = true;

Graph::Graph()
{
	flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
	main_width = App::width * 0.5;
	main_height = App::height * 0.8;
	graph_width = main_width * 0.95;
	graph_height = main_height * 0.9;
}

Graph::~Graph()
{
	std::cout << "Graph Deleted" << std::endl;
}

void Graph::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowSize(ImVec2(main_width, main_height));
	ImGui::Begin("Graph", NULL, flags);
	// if (Data::points.size() > 0)
	// {
  //   static float values[10] = {};
  //   int i = 0;
  //   for (Vector2* point : Data::points)
  //   {
  //   	values[i] = point->x/100;
  //   	i++;
  //   }
	// 	ImGui::PlotLines("", values, IM_ARRAYSIZE(values), 0, "", -0.5f, 1.0f, ImVec2(graph_width, graph_height));
	// }
	ImGui::End();
}
