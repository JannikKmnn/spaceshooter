#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

using namespace sf;

Player::Player(String name, unsigned int score)
{
	this->name = name;
	this->score = score;

	std::ofstream highscores;

	highscores.open("Highscores.txt", std::ios::ate | std::ios::app);
	highscores << std::string(name) << "\t\t\t|" << std::to_string(score) << "\n";
	highscores.close();

}

Player::~Player()
{
}

String Player::getHighscore()
{
	highscore = 0;

	std::ofstream highscores;

	highscores.open("Highscores.txt", std::ios::out);
	return String();
}
