#include "Fire.h"

Fire::Fire()
{

}

Fire::~Fire()
{

}

void Fire::reset()
{
	bool canshoot = true;
	float totalTime = 0;
	bool isUltiReady = false;
	bool isUltiPlaying = false;
	float ultiTimer = 0;
	bullets.clear();
	ultis.clear();
}

void Fire::update(float dt, Player& player, sf::Texture& texture, sf::Texture& ultiTex, SpawnEbullet& EB, sf::Texture& ultiRingTex, sf::Sound& fireA, sf::Sound& ultiS)
{
	if (totalTime < cooldown)
	{
		totalTime += dt;
	}
	else
	{
		canshoot = true;
	}
	if (player.abilityCount == 100)
	{
		isUltiReady = true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and isUltiReady == true)
	{
		/*EB.Ebullets.clear();*/
		ultiS.play();
		std::cout << "Fire ULT" << std::endl;
		isUltiReady = false;
		isUltiPlaying = true;
		player.abilityCount = 0;
		ultis.push_back(Ulti(player.getPos(),ultiTex,ultiRingTex));
	}
	if (isUltiPlaying == true)
	{
		ultiTimer += dt;
		if (ultiTimer < ultiCooldown)
		{
			for (int i = 0; i < ultis.size(); i++)
			{
				ultis[i].update(dt,isUltiPlaying,player.getPos());
			}
		}
		else
		{
			ultiTimer = 0;
			isUltiPlaying = false;
			ultiS.stop();
			ultis.clear();
		}
	}
	if (/*sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and */canshoot == true and isUltiPlaying == false)
	{
		totalTime = 0 ;
		canshoot = false;
		fireA.play();
		bullets.push_back(Bullet(texture, sf::Vector2f(player.getPos().x , player.getPos().y-10)));
		bullets.push_back(Bullet(texture,sf::Vector2f(player.getPos().x-10,player.getPos().y)));
		bullets.push_back(Bullet(texture, sf::Vector2f(player.getPos().x + 10, player.getPos().y)));
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update(dt);
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getPos().y < -6)
		{
			bullets.erase(bullets.begin() + i);
		}
	}

}

void Fire::render(sf::RenderTarget& target)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].render(target);
	}
	for (int i = 0; i < ultis.size(); i++)
	{
		ultis[i].render(target);
	}
}