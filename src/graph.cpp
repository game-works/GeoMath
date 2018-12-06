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

	sf::Vertex line[] =
	{
    	sf::Vertex(sf::Vector2f(10.f, 10.f)),
    	sf::Vertex(sf::Vector2f(150.f, 150.f))
	};
	app->window->draw(line, 2, sf::Lines);

	ImGui::End();
}
