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
/// Refernces:
/// Mantis Z.
/// Helped me on my powerBar
/// Micheal Rainsford.
/// taught me to imcrement the line and draw it
/// Michal K.
/// fixed my asteroid to draw properly
/// ------------------------------------------------------------
/// Estinmated time: 5-7 hours
/// Session 1 5:00pm to 7:00pm 3rd of December
/// Session 2 7:30pm to 9:30pm 5th of December
/// Session 3 9:00am to 10:00am 6th of December
/// Session 4 2:00pm to 5:00pm 6th of December
/// Session 5 4:00pm to 7:00pm 7th of December
/// Session 6 3:30pm to 6:30pm 9th of December
/// Session 7 4:30pm to 9:00pm 10th of December
/// Session 8 11:30pm to 1:00am 10th-11th of December
/// Actual time: 20hrs and 30mins
/// Known Bugs: 
/// Can click and shoot the laser without waiting till it finished exploded.
/// Can't figure out the powerBar to halfway the shot of the laser if the bar is halfway.
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
	void asteroidSpawn(); // spawning the asteroid
	void asteroidUpdate(); // sets up the asteroid
	void laserCollision(); // the collision for the laser and asteroid


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_altitudeText; // text for the altitude bar
	sf::Text m_scoreText; // text for the score
	sf::Text m_gameoverText; // text for the gameover text
	sf::RectangleShape m_ground; // shape of the ground
	sf::RectangleShape m_cannon; // shape of the cannon
	sf::RectangleShape m_altitudeBar; // shape of the altitude bar
	sf::CircleShape m_explosion{ }; // draws a circle for the explodsion //side note the size is for testing
	sf::Vector2i m_mouseClick{ 0.0f,0.0f }; // location of 1st mouse
	sf::VertexArray m_line{ sf::Lines }; // line to be drawn
	sf::VertexArray m_asteriodLine{ sf::Lines }; // the lines of asteroid
	sf::Vector2f m_cannonBase{ 400.0f, 550.0f }; // The cannon base
	sf::Vector2f endPoint{}; // location of mouse click
	sf::Vector2f m_laserVelocity = {0,0}; // the unit vector's result
	sf::Vector2f m_distanceVec{}; // the distance of the cannon to the mouse click
	sf::Vector2f m_laserPosition{}; // the line being drawn increment
	sf::Vector2f asteroidSpawnPoint{}; // the spawning point of the asteroid
	sf::Vector2f asteroidTrajectoryPoint{}; // the trajectory of the asteroid point
	sf::Vector2f asteroidVelocity = {}; // the speed of the asteroid
	sf::Vector2f m_asteroidDistanceVec{}; // finds the distance to the end point of the asteroid

	float m_maxBar = 400.0f; // the maximium range of the laser
	float m_startBar = 0.0f; // the starting point of the altitude bar
	float m_maxRadius = 30.0f; // the maximium size of the explosion
	float m_startRadius = 0.0f; // the starting radius of the explosion
	float m_lenghtOfUnitVector = 0.0f; // sets the increment speed on the laser 
	int score = 0; // the score of the player



	bool m_exitGame; // control exiting game
	bool m_exploded = false; // its set to false
	bool m_firedLaser = false; // stops the player from clicking after firing the laser
	bool m_asteroid = true; // respawns the asteroid
	bool m_collided = false; // for the collision
	bool m_chargeBar = false; // power charge
	bool m_gameover = false; // gameover state


};

#endif // !GAME

