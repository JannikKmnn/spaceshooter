#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class SpaceShip
{
public:
	SpaceShip(Texture* Texture, float windowsize);
	~SpaceShip();

	void Update(float speed, float pos_x, float pos_y, float windowsize);
	void Draw(RenderWindow& window);

	Vector2f GetPosition() { return spaceship.getPosition(); }
	float GetHeight() { return spaceship.getSize().y; }
	
private:

	RectangleShape spaceship;

	float piclength;
	float picheight;

	Vector2f initialPosition;

};

