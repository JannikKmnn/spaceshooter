#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Stone
{
public:

	Stone(Texture* Texture);
	~Stone();

	void SetFirstPosition(float windowsize);
	void Update(float stone_speed, float pos_x, float pos_y, float windowsize, float shuttle_height);
	void Draw(RenderWindow& window);

	Vector2f GetPosition() { return stone.getPosition(); }
	Vector2f GetSize() { return stone.getSize(); }

	bool GroundHit() { return lifeDecrease; }

	void CheckShotHit();
	bool ShotHit() { return scoreInc; }

private:

	RectangleShape stone;

	bool lifeDecrease;
	bool scoreInc;

	float piclength;
	float picheight;

};

