#include "user.h"
#include <iostream>

int User::style = 1;
int User::layout = 2;
sf::Texture User::tex_logo;

User::User()
{
	tex_logo.loadFromFile("assets/textures/title.png");
}

User::~User()
{
	std::cout << "User Deleted" << std::endl;
}
