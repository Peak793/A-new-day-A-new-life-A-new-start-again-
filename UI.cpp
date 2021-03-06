#include "UI.h"

UI::UI(sf::Vector2f playerPos)
{
	font.loadFromFile("fonts/TarrgetAcademyItalic-qzmx.otf");
	hpbackTex.loadFromFile("img/hpback.png");

	//setFont
	//hpText.setFont(font);
	//hpText.setCharacterSize(10.f);
	//hpText.setFillColor(sf::Color::Black);
	//hpText.setOutlineColor(sf::Color::White);
	//hpText.setOutlineThickness(2.f);

	abilityback.setSize( sf::Vector2f(64.f,6.f));
	abilityback.setFillColor(sf::Color::White);
	abilityback.setPosition(playerPos.x-32,playerPos.y + 38);
	ability.setFillColor(sf::Color::Red);
	ability.setSize(sf::Vector2f(0.f, 6.f));
	ability.setPosition(playerPos.x - 32, playerPos.y + 38);

	Score.setFont(font);
	Score.setCharacterSize(20.f);
	Score.setFillColor(sf::Color::Black);
	Score.setOutlineColor(sf::Color::White);
	Score.setOutlineThickness(2.f);
	Score.setPosition(370-Score.getGlobalBounds().width/2,4);

	//RectangleShape setup
	/*hpback.setOutlineColor(sf::Color::White);
	hpback.setOutlineThickness(2.f);*/
	hpback.setTexture(hpbackTex);
	hpback.setPosition(playerPos.x-32, playerPos.y + 32);

	hp.setSize(sf::Vector2f(64.f, 6.f));
	hp.setFillColor(sf::Color::Green);
	hp.setPosition(playerPos.x-32, playerPos.y + 32);

	hpText.setOrigin(hpText.getGlobalBounds().width/2,hpText.getGlobalBounds().height/2);
	hpText.setPosition(hp.getPosition());
	
}

UI::~UI()
{
}

void UI::update(float dt,int hp,int hpmax,int score,sf::Vector2f playerPos,int &abilityCount,bool isultiready)
{
	hpText.setString(std::to_string(hp) + "/" + std::to_string(hpmax));
	Score.setString("SCORE : " + std::to_string(score));
	if (isultiready == false)
	{
		ability.setFillColor(sf::Color::Red);
	}
	if (hp > 0)
	{
		this->hp.setSize(sf::Vector2f((hp * 64) / 3, 6));
	}
	else
	{
		this->hp.setSize(sf::Vector2f(0,6));
	}
	ability.setSize(sf::Vector2f(abilityCount *64/100 , 6));
	if (abilityCount == 100)
	{
		totalTime += dt;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			ability.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
		}
	}

	hpback.setPosition(playerPos.x-32, playerPos.y + 32);
	this->hp.setPosition(playerPos.x - 32, playerPos.y + 32);
	ability.setPosition(playerPos.x - 32, playerPos.y + 38);
	abilityback.setPosition(playerPos.x - 32, playerPos.y + 38);
	/*hpText.setPosition(this->hp.getPosition());*/
}

void UI::render(sf::RenderTarget& target)
{
	target.draw(Score);
	target.draw(hp);
	target.draw(hpText);
	/*target.draw(abilityback);*/
	target.draw(ability);
	target.draw(hpback);
}