/// <summary>
/// Name: Allexis Alvarico
/// Login: C00242855
/// Date: 3rd of December
/// --------------------------------------------------------
/// Summary:
/// Create a missle command like game from scratch. All work must
/// be saved or updated in gitHub throughout the project's creatation.
/// Create parts of the project not all at once.
/// ---------------------------------------------------------
/// Estinmated time: 5-7 hours
/// Session 1 5:00pm to 7:00pm 3rd of December
/// Session 2 
/// Session 3 
/// Actual time: 
/// Known Bugs: 
/// None as of now
/// </summary>  


#include "Game.h"
#include <iostream>


/// <summary>
/// default construcor
/// pass parameters fpr sfml window, setup m_exitGame
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	setupScene();
}

/// <summary>
/// default destructor for game, nothing to release
/// </summary>
Game::~Game()
{
}


/// <summary>
/// game loop running at 60fps
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black); // change's the window to black
	m_window.draw(m_ground); // draws the ground
	m_window.draw(m_cannon); // draws the cannon
	//m_window.draw(m_welcomeMessage);
	//m_window.draw(m_logoSprite);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}


void Game::setupScene()
{
	//setup for the ground
	m_ground.setSize(sf::Vector2f (800, 50)); // set size of the rectangle
	m_ground.setPosition(0, 550); // set the position
	m_ground.setFillColor(sf::Color::Green); // set the colour
	//setup for the cannons 
	m_cannon.setSize(sf::Vector2f(50, 50)); // set size of the rectangle
	m_cannon.setPosition(375, 500); // set the position
	m_cannon.setFillColor(sf::Color::Yellow); // set the colour

}