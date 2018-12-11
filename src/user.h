#pragma once

#include "SFML/Graphics/Texture.hpp"

class User
{
public:
	static int style;
	static int layout;
	static sf::Texture tex_logo;

public:
	User();
	~User();
};
