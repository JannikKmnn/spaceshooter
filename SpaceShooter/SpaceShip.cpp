#include "SpaceShip.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

SpaceShip::SpaceShip(Texture* Texture, float windowsize)
{
	this->piclength = Texture->getSize().x;
	this->picheight = Texture->getSize().y;

	spaceship.setTexture(Texture);
	spaceship.setSize(Vector2f(piclength / 8.0f, picheight / 8.0f));
	spaceship.setOrigin(spaceship.getSize().x / 2.0f, spaceship.getSize().y / 2.0f);

	initialPosition.x = windowsize / 2.0f;
	initialPosition.y = windowsize - spaceship.getSize().y / 2.0f;

	spaceship.setPosition(initialPosition);
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::Update(float speed, float pos_x, float pos_y, float windowsize)
{
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (pos_x <= windowsize - spaceship.getSize().x / 2) {
			pos_x += speed;
			spaceship.setPosition(pos_x, pos_y);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (pos_x >= spaceship.getSize().x / 2) {
			pos_x -= speed;
			spaceship.setPosition(pos_x, pos_y);
		}
	}
}

void SpaceShip::Draw(RenderWindow& window) {
	window.draw(spaceship);
}
