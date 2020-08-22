#include "Hit.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Hit::Hit()
{
	shotHit = false;
}

Hit::~Hit()
{

}

bool Hit::ShotHitCheck(Vector2f stonePos, Vector2f stoneSize, Vector2f shotPos, Vector2f shotSize)
{
	float deltaX = abs(shotPos.x - stonePos.x);
	float deltaY = abs(shotPos.y - stonePos.y);

	if (deltaX < stoneSize.x / 2.0f + shotSize.x / 2.0f && deltaY < stoneSize.y / 2.0f + shotSize.y / 2.0f) {
		return true;
	}
	else {
		return false;
	}
}