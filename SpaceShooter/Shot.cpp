#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Shot::Shot(Texture* Texture, float windowsize, Vector2f shipposition, float shipheight)
{
	this->piclength = Texture->getSize().x;
	this->picheight = Texture->getSize().y;

	shot.setTexture(Texture);
	shot.setSize(Vector2f(piclength / 8.0f, picheight / 8.0f));
	shot.setOrigin(shot.getSize().x / 2.0f, shot.getSize().y / 2.0f);

	initialPosition.x = shipposition.x;
	initialPosition.y = windowsize - shipheight/2;

	shot.setPosition(initialPosition);

	getsdestroyed = false;
}

Shot::~Shot()
{
}

void Shot::Update(float shot_speed, float pos_x, float pos_y)
{
	if (shot.getPosition().y >= -2*(shot.getSize().y / 2)) {
		pos_y -= shot_speed;
		shot.setPosition(pos_x, pos_y);
	}
	else {
		getsdestroyed = true;
	}
}

void Shot::Draw(RenderWindow& window)
{
	window.draw(shot);
}

void Shot::CheckStoneHit()
{
	getsdestroyed = true;
}
