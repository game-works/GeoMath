#include <stdio.h>
#include <iostream>
#include "imgui.h"
#include "imgui_internal.h"
#include "application.h"
#include "menu.h"
#include "popup.h"
#include "button.h"
#include "graph.h"
#include "points.h"
#include "data.h"

bool Menu::isShowing = true;
bool Menu::show_exit_confirmation = false;
bool Menu::show_about_us = false;
bool Menu::show_about_software = false;
float Menu::height;

Menu::Menu()
{
	exit_confirmation = new Popup("Exit Confirmation", "Are you sure you want to quit?");
	exit_confirmation->AddButton(new Button("Okay", [](void)
		{
			App::isRunning = false;
		}));
	exit_confirmation->AddButton(new Button("Cancel", [](void)
		{
			show_exit_confirmation = false;
		}));

	about_us = new Popup("About Us",
			"Made By:\n"
			"Brandon B. Lim-it\n"
			"Jaykel O. Punay\n"
			"Edwarc C. Concepcion\n"
			"Aeron Rae E. Villanueva\n"
			"Ricardo Palconit Jr.\n");
	about_us->AddButton(new Button("Close", [](void)
		{
			show_about_us = false;
		}));

	static char buf[128];
	sprintf(buf, "Written in C++\nUsing ImGui\nVersion: %s", App::version);

	about_software = new Popup("About Software", buf);
	about_software->AddButton(new Button("Close", [](void)
		{
			show_about_software = false;
		}));
}

Menu::~Menu()
{
	delete exit_confirmation;
	delete about_us;
	delete about_software;
}

void Menu::Update()
{
	if (!isShowing)
		return;

	if (show_exit_confirmation) exit_confirmation->Update();
	if (show_about_us) about_us->Update();
	if (show_about_software) about_software->Update();

	if (ImGui::BeginMainMenuBar())
	{
		static ImGuiContext& g = *GImGui;
		static ImGuiWindow* window = g.CurrentWindow;
		height = window->MenuBarHeight();

		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit")) show_exit_confirmation = true;
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{
			ImGui::Checkbox("Graph", &Graph::isShowing);
			ImGui::Checkbox("Points", &Points::isShowing);
			ImGui::Checkbox("Data", &Data::isShowing);
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("About"))
		{
			if (ImGui::MenuItem("About Us")) show_about_us = true;
			if (ImGui::MenuItem("About Software")) show_about_software = true;
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}
