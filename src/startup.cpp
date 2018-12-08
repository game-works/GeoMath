#include "startup.h"
#include <iostream>
#include "imgui.h"
#include "application.h"

bool Startup::isShowing = true;

Startup::Startup()
{
	ID = "";
	text = "This is a free software";
}

Startup::~Startup()
{
	std::cout << "Deleted Startup" << std::endl;
}

void Startup::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowFocus();
	ImGui::SetNextWindowSize(ImVec2(App::width * 0.5, App::height * 0.5));
	ImGui::SetNextWindowPosCenter();
	ImGui::OpenPopup(ID);
	if (ImGui::BeginPopupModal(ID, NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings))
	{
		ImGui::NewLine();
		ImGui::Text(text, "%s");
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::NewLine();

		if (ImGui::Button("Close", ImVec2(ImGui::GetWindowContentRegionWidth(), 0)))
		{
			ImGui::SetItemDefaultFocus();
			ImGui::CloseCurrentPopup();
			isShowing = false;
		}
		ImGui::EndPopup();
	}
}
