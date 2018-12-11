#include "user.h"
#include <iostream>
#include <assert.h>

int User::style = 1;
int User::layout = 2;
sf::Texture User::tex_logo;

User::User()
{
	int n = tex_logo.loadFromFile("assets/textures/title.png");
	std::cout << n << std::endl;
	assert(n == 1 && "Assets are missing. Please redownload and DO NOT remove the assets folder");
}

User::~User()
{
	std::cout << "User Deleted" << std::endl;
}
