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
/// Session 2 7:30pm to 9:30pm 5th of December
/// Session 3 9:00am to 10:00am 6th of December
/// Session 4 2:00pm to 5:00pm 6th of December
/// Session 5 4:00pm to 7:00pm 7th of December
/// Actual time: 
/// Known Bugs: 
/// Explosion draws on the start of the program
/// Power bar don't reset once fired
/// </summary>  


#include "Game.h"
#include "MyVector2.h"
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
	setupScene(); // sets the shapes up
	powerBar(); // sets the altitude bar
	
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
		if (sf::Event::MouseButtonPressed == event.type)
		{
			processMouseEvents(event); // when mouse is clicked
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	powerBar(); // calls the function to update
	laserUpdate();

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
	m_window.draw(m_line); // Draws the line
	m_window.draw(m_altitudeBar); // draws the bar
	m_window.draw(m_altitudeText); // text is drawn
	if(m_exploded) // do this
	{
		m_window.draw(m_explosion); // draws the explodsion
	}
	//m_window.draw(m_welcomeMessage); // Note hideden it 
	//m_window.draw(m_logoSprite); // Note hideden it
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
	//m_welcomeMessage.setFont(m_ArialBlackfont);
	//m_welcomeMessage.setString("SFML Game");
	//m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	//m_welcomeMessage.setPosition(40.0f, 40.0f);
	//m_welcomeMessage.setCharacterSize(80);
	//m_welcomeMessage.setOutlineColor(sf::Color::Red);
	//m_welcomeMessage.setFillColor(sf::Color::Black);
	//m_welcomeMessage.setOutlineThickness(3.0f);

	m_altitudeText.setFont(m_ArialBlackfont); // set its font
	m_altitudeText.setString("Altitude: "); // displays the text
	m_altitudeText.setPosition(10, 555);  // set the position
	m_altitudeText.setCharacterSize(24); // the character size
	m_altitudeText.setFillColor(sf::Color::White); // The text's colour


}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	//if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	//{
	//	// simple error message if previous call fails
	//	std::cout << "problem loading logo" << std::endl;
	//}
	//m_logoSprite.setTexture(m_logoTexture);
	//m_logoSprite.setPosition(300.0f, 180.0f);
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

	m_explosion.setFillColor(sf::Color::Red); // set the colour

	m_altitudeBar.setPosition(125, 560); // sets the position
	m_altitudeBar.setFillColor(sf::Color::Red); // set the colour


}

void Game::processMouseEvents(sf::Event t_mouseEvent)
{
	//sf::Vertex lineStart{}; // start point of line
	//sf::Vertex lineEnd{}; // end point of line

	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button)
	{
		//mouseClick = sf::Vector2f{ m_cannonBase }; // sets the base of the line on the cannon
		//lineStart = sf::Vertex{ mouseClick , sf::Color::Red }; // the line is red
		//m_line.append(lineStart); // Where the line is starts

		//if (m_mouseClicks == 0) // if the clicks is 0

		if(!m_firedLaser) // when clicking do this
		{
			endPoint = sf::Vector2f{ static_cast<float>(t_mouseEvent.mouseButton.x),static_cast<float>(t_mouseEvent.mouseButton.y) }; // the clicked's position in x and y axis 
			sf::Vector2f distanceVec = endPoint - m_cannonBase; // gets the distance of the click from the cannon base
			m_laserVelocity = vectorUnitVector(distanceVec); // gets the unit vector of the distanceVector
			m_laserPosition = m_cannonBase; // laser's position is on the cannon
			m_startRadius = 0; // set the explosion's radius to zero
			//lineEnd = sf::Vertex{ m_laserVec, sf::Color::Red }; // the line is red
			// calls the function for the explodsion
			//m_line.append(lineEnd); // where the user clicked on the window
			m_readyToFire = false; // stops the bar and reset it back 0
			//m_mouseClicks++; // increments it 

		}
		//else if (m_mouseClicks == 1) //The amount of clicks done do this
		//{
		//	m_exploded = false; // set it to false
		//	m_readyToFire = true; // reset the bar
		//	m_mouseClicks = 0; // reset the clicks
		//	//m_line.clear(); // clears the line after the click
		//}
	}

}

void Game::explodsion() // explodsion that the circle appears
{
	 // sets the coodinates where the explodsion happens
	if (m_exploded) 
	{
		if (m_startRadius <= m_maxRadius) // the if the radius is zero
		{
			m_startRadius += 0.8f; // increase the size of the radius
			m_explosion.setRadius(m_startRadius); // set the radius of the explosion
			m_explosion.setOrigin(m_startRadius, m_startRadius); // set the origin to the centre of the circle
			m_explosion.setPosition(m_laserPosition); // position it on the click
		}
		else
		{
			m_startRadius += 0; // stops the increase of the radius
			m_exploded = false; // set it to false
		}
	}
}

void::Game::powerBar()
{
	if (m_readyToFire) // if its true
	{

		if (m_startBar < m_maxBar) // if less than the maximun bar 
		{
			m_startBar += 1; // add 1 to it
		}
		if (m_startBar == m_maxBar) // if equal to maximun bar
		{
			m_startBar += 0; // stops the increase
		}
	}
	else // if the readyTo
	{
		m_startBar = 0; // it reset to zero
	}

	m_altitudeBar.setSize(sf::Vector2f(m_startBar,25)); // updates the bar

}


void::Game::laserUpdate()
{
	m_laserPosition += m_laserVelocity * 2.0f; // the speed of the laser drawing

	m_line.append(m_cannonBase); // where the user clicked on the window
	m_line.append(m_laserPosition); // where the user clicked on the window
	m_firedLaser = true; // allows the player to fire
	
	if (m_laserPosition.y <= endPoint.y) // if the laser reached the same y axis value do this
	{
		
		// its set the exploded to true
		m_firedLaser = false; // stops the player from firing again
		m_line.clear(); // clears the laser
		m_laserPosition = endPoint; // sets the end point of the line 
		m_exploded = true; // draws the explosion
		explodsion(); // calls the function
	}
	//if (m_laserPosition.y >= endPoint.y) 
	//{
	//	m_exploded = true;
	//}
}