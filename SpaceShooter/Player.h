#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Player
{
public:

	Player(String name, unsigned int score);
	~Player();

	String getHighscore();

private:

	String name;
	unsigned int score;
	unsigned int highscore;

};

