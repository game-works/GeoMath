#include "data.h"
#include "application.h"
#include "graph.h"
#include "points.h"
#include "menu.h"

bool Data::isShowing = true;

Data::Data()
{
	title = "Data";
}

Data::~Data()
{

}

void Data::Update()
{
	if (!isShowing)
		return;

	ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(w, h), ImGuiCond_FirstUseEver);
	ImGui::Begin(title, NULL, App::flags);

	ImGui::End();
}
