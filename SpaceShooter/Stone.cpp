#include "Stone.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace sf;

Stone::Stone(Texture* Texture)
{
	this->piclength = Texture->getSize().x;
	this->picheight = Texture->getSize().y;

	stone.setTexture(Texture);
	stone.setSize(Vector2f(piclength / 9.0f, picheight / 9.0f));
	stone.setOrigin(stone.getSize().x / 2.0f, stone.getSize().y / 2.0f);

	lifeDecrease = false;
	scoreInc = false;
}

Stone::~Stone()
{
}

void Stone::SetFirstPosition(float windowsize)
{
	srand(time(NULL));
	unsigned int random = rand();

	stone.setPosition(float(rand() % int(windowsize)), -float(stone.getSize().y));

	if (stone.getPosition().x < stone.getSize().x / 2 || stone.getPosition().x > windowsize - stone.getSize().x / 2) {
		stone.setPosition(float(rand() % int(windowsize)), -float(stone.getSize().y));
	}
}

void Stone::Update(float stone_speed, float pos_x, float pos_y, float windowsize, float shuttle_height)
{
	if (stone.getPosition().y <= windowsize - 2*shuttle_height) {
		pos_y += stone_speed;
		stone.setPosition(pos_x, pos_y);
	}
	else {
		lifeDecrease = true;
	}
}

void Stone::Draw(RenderWindow& window)
{
	window.draw(stone);
}


void Stone::CheckShotHit()
{
	scoreInc = true;
}
