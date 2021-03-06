#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

#include "Menu.h"
#include "Player.h"
#include "Background.h"
#include "How_to_play.h"
#include "Gamestart.h"
#include "Bullet.h"
#include "Fire.h"
#include "SpawnEnemies.h"
#include "Collision.h"
#include "SpawnEbullet.h"
#include "AddExplo.h"
#include "UI.h"
#include "itemDropping.h"
#include "GamePause.h"
#include "spawnAsteroid.h"
#include <fstream>
#include <iostream>

class Game
{
private:
	sf::RenderWindow window;
	sf::Clock dtClock;
	float dt;
	
	float state = 0;
	/*
		0	= menu
		1	= GameState
		2	= GamePause
		3	= Dead
		4	= HowToPlay
		5	= LeaderBoard
	*/
	//Music
	sf::SoundBuffer meTheme;
	sf::Sound menuTheme;
	sf::Music bgTheme;
	sf::Time time;	

	//Menu state
			Menu menu;

	//Game state
		//Variables
			int score = 0;
			float gameLV = 0;
		
		//Background
			Background background;
		
		//Gamestar text
			Gamestart gsText;
		
		//Player
			Player mPlayer;

		//Bullet
			sf::Texture bTex;
			Fire fire;

		//ulti
			sf::Texture ultiTex;
			sf::Texture ultiRingTex;

		//Enemies
			sf::Texture eTex;
			SpawnEnemies spawnEne;

		//Enemy's bullets
			sf::Texture ebulletTex;
			SpawnEbullet SpawnEB;

		//SpawnAsteroid
			spawnAsteroid asteroid;
	
		//Collision
			Collision collision;

		//Dead animation
			AddExplo ADEX;

		//How to play state
			How_to_play howtoplay;

		//Ui
			UI ui;
		
		// item dropping
			itemDropping drop;

		//Shield
			sf::Texture shieldRingTex;

		//Pause menu
			GamePause pause;

		//leaderBoard
			sf::Font font;
			sf::Text lead;
			sf::Text text[6] = {};
			std::string str;
			sf::Sprite leaderBG;
			sf::Texture Leadtex;
			bool isread = false;

		//Dead state
			sf::Texture deadTex;
			sf::Sprite deadbg;
			sf::Vector2f deadimageCount;
			sf::Vector2f deadcurrentImage;
			sf::IntRect deadRect;
			sf::Text name;
			std::string allname[6] = {};
			int allscore[6] = {};
			std::string o;
			std::string playername;
			sf::Font font2;
			float totalTimeDead = 0;
			float switchTimeDead = 0.1;

			//std::string t;

			//sound effect
			sf::SoundBuffer click;
			sf::SoundBuffer fireA;
			sf::SoundBuffer boom;
			sf::SoundBuffer ultiB;
			sf::SoundBuffer warning;

			sf::Sound clickS;
			sf::Sound fireS;
			sf::Sound boomS;
			sf::Sound ultiS;
			sf::Music warningS;
private:

public:
	//Game state
			bool isGAMESTART = false;
public:
	Game(int Width, int Height);
	~Game();
	void		restart();
	void		restartMucsic();
	void		loadSoundFX();

	void		run();
	void		updateDt();
	void		pollEvent();
	void		loadObject();
	void		loadTexture();
	void		update();
	void		render();
	
	//menu state
	void		menuUpdate();
	void		menuRender();
	void		updateMenuState();
	void		renderMenuState();
	void		changeState();

	//Game state
	void		updateGameState();
	void		renderGameState();
	void		animationUpdate();
	void		updateGameLV();
	void		collisionupdate(float gameLV);

	//Pause state
	void		updateGamePauseState();
	void		renderGamePauseState();

	//Dead state
	void		updateDeadState();
	void		renderDeadState();

	//How to play
	void		updateHowtoplayState();
	void		renderHowtoplayState();

	//leaderboard state
	void		updateleaderboard();
	void		renderleaderboard();
};