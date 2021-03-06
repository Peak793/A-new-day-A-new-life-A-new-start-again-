#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>


#define MAX_SIZE_OF_ITEMS 4

class Menu
{
private:
	//Game Logo , main memu UI
	sf::Sprite background;
	sf::Texture BGtexture;
	sf::Font Menufont;
	sf::Font LogoFont1;
	sf::Font LogoFont2;
	sf::Text menu[MAX_SIZE_OF_ITEMS];
	sf::Text Logo[3];
	sf::Clock clock;
	sf::Clock press;

	
	//soundtrack
	sf::Music soundtrack;

	//Variables
	int selectedIndex;
	bool FontSelect;
	int updatelogo = -20;
	float pressTimer = 0;
	float pressAbleTime = 1;
	float totalTime = 0;
	float switchTime = 0.2;


public:


public:
	Menu(float Width, float Height);
	~Menu();

	void	render(sf::RenderTarget &target);
	int	update(float &state, sf::RenderWindow& window,float dt,sf::Sound &clickS,sf::Music &bgtheme);
	void	Move(sf::Sound& clickS,float dt);


	void	initMenu(float Width, float Height);
	void	initLogo(float Width, float Height);
	void	updateLogo(float state);
	int	pressMenu(float &state, sf::RenderWindow& window,float dt, sf::Music& music);
};