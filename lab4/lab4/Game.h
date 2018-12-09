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
/// Session 6 3:30pm to 6:30pm 9th of December
/// Actual time: 
/// Known Bugs: 
/// can click and shoot the laser without
/// waiting till it finished exploded.
/// </summary>  


#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents(); 
	void update(sf::Time t_deltaTime);
	void render(); 
	void setupFontAndText(); 
	void setupSprite();
	void setupScene(); // sets up the scene
	void processMouseEvents(sf::Event t_mouseEvent); // A laser appears and position itself on the click
	void explodsion(); // where the end of the click's position explodes  
	void powerBar(); // the altitude bar where the range increases for the laser
	void laserUpdate(); // drawing the laser

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_altitudeText; // text for the altitude bar
	sf::RectangleShape m_ground; // shape of the ground
	sf::RectangleShape m_cannon; // shape of the cannon
	sf::RectangleShape m_altitudeBar; // shape of the altitude bar
	sf::CircleShape m_explosion{ }; // draws a circle for the explodsion //side note the size is for testing
	sf::Vector2i m_mouseClick{ 0.0f,0.0f }; // location of 1st mouse
	sf::VertexArray m_line{ sf::Lines }; // line to be drawn
	sf::Vector2f m_cannonBase{ 400.0f, 550.0f };
	sf::Vector2f m_laserVec{ m_cannonBase };
	sf::Vector2f endPoint{}; // location of mouse click
	sf::Vector2f m_laserVelocity = {0.0f,0.0f}; // the unit vector's result
	sf::Vector2f distanceVec{}; // the distance of the cannon to the mouse click
	sf::Vector2f m_laserPosition{}; // the line being drawn increment

	float m_maxBar = 600.0f; // the maximium range of the laser
	float m_startBar = 0.0f; // the starting point of the altitude bar
	float m_maxRadius = 30.0f; // the maximium size of the explosion
	float m_startRadius = 0.0f; // the starting radius of the explosion
	float m_lenghtOfUnitVector = 0.0f; // sets the increment speed on the laser 

	bool m_exitGame; // control exiting game
	bool m_exploded = false; // its set to false
	bool m_firedLaser = false; // stops the player from clicking after firing the laser


};

#endif // !GAME

