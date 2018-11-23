#include <iostream>
#include "imgui.h"
#include "imgui-SFML.h"
#include "application.h"

int width = 640;
int height = 480;
static bool open = true;
static bool show_about_us = false;
static bool show_about_software = false;
static bool show_exit_confirmation = false;
App* app;

void showAboutUs();
void showAboutSoftware();
void showExitConfirmation();

int main()
{
	app = new App("Math Project", width, height);
	app->isRunning = true;
	ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove |
    ImGuiWindowFlags_NoCollapse;

	while (app->isRunning)
	{
		app->Process();
		app->Update();

    if (show_about_us) showAboutUs();
    if (show_about_software) showAboutSoftware();
    if (show_exit_confirmation) showExitConfirmation();
    if (ImGui::BeginMainMenuBar())
    {
      if (ImGui::BeginMenu("File"))
      {
        	// if (ImGui::MenuItem("")) show_exit_confirmation = true;
        	if (ImGui::MenuItem("Exit")) show_exit_confirmation = true;
          ImGui::EndMenu();
      }
      if (ImGui::BeginMenu("About"))
      {
        if (ImGui::MenuItem("About Us")) show_about_us = true;
        if (ImGui::MenuItem("About The Software")) show_about_software = true;
        ImGui::EndMenu();
      }
      ImGui::EndMainMenuBar();
    }

		app->Render();
	}

	delete app;
}

void showAboutUs()
{
  ImGui::SetNextWindowPosCenter();
  ImGui::SetNextWindowSize(ImVec2(width/2, height/2));
	ImGui::Begin("About Us", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
  ImGui::NewLine();
	ImGui::Text("Made By:");
	ImGui::Text("Brandon B. Lim-it");
	ImGui::Text("Jaykel O. Punay");
	ImGui::Text("Edward C. Concepcion");
	ImGui::Text("Ricardo Palconit Jr.");
	ImGui::Text("Aeron John E. Villanueva");

  ImGui::NewLine();
  ImGui::NewLine();
  ImGui::NewLine();
	if (ImGui::Button("Close"))
	{
		show_about_us = false;
	}
	ImGui::End();
}

void showAboutSoftware()
{
  ImGui::SetNextWindowPosCenter();
	ImGui::Begin("About Software", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
  ImGui::NewLine();
	ImGui::Text("This Software is written in C++");
	ImGui::Text("It uses the imgui library");

  ImGui::NewLine();
  ImGui::NewLine();
  ImGui::NewLine();
	if (ImGui::Button("Close"))
	{
		show_about_software = false;
	}
	ImGui::End();
}

void showExitConfirmation()
{
  ImGui::SetNextWindowPosCenter();
	ImGui::Begin("Exit Confirmation", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
  ImGui::NewLine();
	ImGui::Text("Are you sure you want to exit?");

  ImGui::NewLine();
  ImGui::NewLine();
  ImGui::NewLine();
  ImGui::Separator();
	if (ImGui::Button("Yes"))
	{
		app->Close();
		open = false;
	}
  ImGui::Separator();
	if (ImGui::Button("No"))
	{
		show_exit_confirmation = false;
	}
	ImGui::End();
}
