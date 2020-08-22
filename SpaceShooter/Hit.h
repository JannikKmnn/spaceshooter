#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Hit
{
public:

	Hit();
	~Hit();

	bool ShotHitCheck(Vector2f stonePos, Vector2f stoneSize, Vector2f shotPos, Vector2f shotSize);

private:

	bool scoreInc;

	bool shotHit;
	bool groundHit;
};

