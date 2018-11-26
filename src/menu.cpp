#include <stdio.h>
#include <iostream>
#include "imgui.h"
#include "application.h"
#include "menu.h"
#include "popup.h"
#include "graph.h"
#include "data.h"

bool Menu::isShowing = true;
bool Menu::show_exit_confirmation = false;
bool Menu::show_about_us = false;
bool Menu::show_about_software = false;

void print()
{
	std::cout << "1" << std::endl;
}

Menu::Menu()
{
	exit_confirmation = new Popup("Exit Confirmation", "Are you sure you want to quit?");
	exit_confirmation->SetButton1("Okay");
	exit_confirmation->SetButton2("Cancel");

	about_us = new Popup("About Us",
			"Made By:\n"
			"Brandon B. Lim-it\n"
			"Jaykel O. Punay\n"
			"Edwarc C. Concepcion\n"
			"Aeron Rae E. Villanueva\n"
			"Ricardo Palconit Jr.\n");
	about_us->SetButton1("Close");

	static char buf[128];
	sprintf(buf, "Written in C++\nUsing ImGui\nVersion: %s", App::version);

	about_software = new Popup("About Software", buf);
	about_software->SetButton1("Close");
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
	exit_confirmation->Update(show_exit_confirmation);
	about_us->Update(show_about_us);
	about_software->Update(show_about_software);
	HandleExitConfirmation();
	HandleAboutConfirmation(show_about_us, about_us->clicked);
	HandleAboutConfirmation(show_about_software, about_software->clicked);
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit")) show_exit_confirmation = true;
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{
			ImGui::Checkbox("Graph", &Graph::isShowing);
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

void Menu::HandleExitConfirmation()
{
	switch (exit_confirmation->clicked)
	{
		case(0):
			show_exit_confirmation = false;
			break;
		case(1):
			App::isRunning = false;
			break;
	}
}

void Menu::HandleAboutConfirmation(bool &target, int &choice)
{
	switch (choice)
	{
		case(1):
			target = false;
			break;
	}
}
