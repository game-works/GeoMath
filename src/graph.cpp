#include <iostream>
#include "imgui.h"
#include "graph.h"
#include "application.h"

Graph::Graph()
{
	flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse;
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
	ImGui::SetNextWindowSize(ImVec2(main_width, main_height));
	ImGui::Begin("Graph", NULL, flags);
  // static float values[90] = { 0 };
	// void ImGui::PlotLines(const char* label, const float* values, int values_count, int values_offset, const char* overlay_text, float scale_min, float scale_max, ImVec2 graph_size, int stride)
	// static float value[8] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7};
	// ImGui::PlotLines("", value, 8, 0, "", 1, 2, ImVec2(graph_width, graph_height), 8);
	// ImGui::PlotLines("Graph", values, IM_ARRAYSIZE(values), 0, "", -0.5f, 1.0f, ImVec2(graph_width, graph_height));
	ImGui::End();
}
