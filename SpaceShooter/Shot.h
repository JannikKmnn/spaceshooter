#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Shot
{
public:

	Shot(Texture* Texture, float windowsize, Vector2f shipposition, float shipheight);
	~Shot();

	void Update(float shot_speed, float pos_x, float pos_y);
	void Draw(RenderWindow& window);

	Vector2f GetPosition() { return shot.getPosition(); }
	Vector2f GetSize() { return shot.getSize(); }

	bool GetsDestroyed() { return getsdestroyed; }
	void CheckStoneHit();

private:

	RectangleShape shot;

	float piclength;
	float picheight;

	bool getsdestroyed;

	Vector2f initialPosition;

};

