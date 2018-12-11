#include "startup.h"
#include <iostream>
#include "imgui.h"
#include "user.h"
#include "application.h"

bool Startup::isShowing = true;
char* buf = new char[64];

Startup::Startup()
{
	sprintf(buf, "%s - version %s", App::window_title, App::version);
	ID = buf;
}

Startup::~Startup()
{
	std::cout << "Deleted Startup" << std::endl;
	delete[] buf;
}

void Startup::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowFocus();
	ImGui::SetNextWindowPosCenter();
	ImGui::OpenPopup(ID);
	if (ImGui::BeginPopupModal(ID, NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings))
	{
		const float scale = ImGui::GetWindowContentRegionWidth()/User::tex_logo.getSize().x;
		const ImVec2 size = ImVec2(ImGui::GetWindowContentRegionWidth(), User::tex_logo.getSize().y * scale);
		ImGui::Image(User::tex_logo, size);
		ImGui::Text("Geo::Math is a software for assisting teachers and learners about Geometry.");
		ImGui::Text("The features so far:");
		ImGui::Bullet(); ImGui::Text("Simple Cartesian Plane Graph");
		ImGui::Bullet(); ImGui::Text("Plot Points");
		ImGui::Bullet(); ImGui::Text("Line between points (slope)");
		ImGui::Bullet(); ImGui::Text("Calculate the Distance between two points");
		ImGui::Bullet(); ImGui::Text("Calculate the Slope of two points");
		ImGui::Bullet(); ImGui::Text("Calculate the General Form of the equation of the line");
		ImGui::Bullet(); ImGui::Text("Calculate the Standard Form of the equation of the line");
		ImGui::Bullet(); ImGui::Text("Show the computation of Distance, Slope, and General/Standard Form of the equation of the line");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::Text("To be implemented:");
		ImGui::Bullet(); ImGui::Text("Circles");
		ImGui::Bullet(); ImGui::Text("Parabolas");
		ImGui::Bullet(); ImGui::Text("Hyperbolas");
		ImGui::Bullet(); ImGui::Text("Conic sections");
		ImGui::Bullet(); ImGui::Text("Plotting of points inside the graph");
		ImGui::Bullet(); ImGui::Text("Connecting two points to make a line inside the graph");
		ImGui::Bullet(); ImGui::Text("And more!");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::Text("Since this is an university project made withing short period of time, expect some bugs.");
		ImGui::Text("This project is still going to be worked on and updated.");
		ImGui::Text("If you want to follow the development, follow the developer at @flamendless");
		ImGui::Text("or send feedbacks through email to flamendless8@gmail.com");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::Text("Geo::Math is a free software under the MIT license (see include LICENSE file fore more info)");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::Text("Software by Brandon Lim-it, Edward Concepcion, Jaykel Punay,");
		ImGui::Text("Ricardo Palconit Jr., and Aeron John Villanueva (See About for more details)");

		if (ImGui::Button("Close", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			ImGui::SetItemDefaultFocus();
			ImGui::CloseCurrentPopup();
			isShowing = false;
		}
		ImGui::EndPopup();
	}
}
