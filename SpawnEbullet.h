#pragma once
#include "SFML/Graphics.hpp"
#include "Enemybullet.h"
#include "SpawnEnemies.h"
#include "iostream"
class SpawnEbullet
{
public:
	std::vector<Enemybullet> Ebullets;
	float totalTime = 0;
	float updateTime = 3;
public:
	SpawnEbullet();
	~SpawnEbullet();
	void				reset();

	void				update(float dt,SpawnEnemies &SE,sf::Texture &texture,float LV);
	void				render(sf::RenderTarget& target);
};