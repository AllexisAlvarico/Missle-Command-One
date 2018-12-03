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
	void setupScene();

	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	sf::RectangleShape m_ground; // shape of the ground
	sf::RectangleShape m_cannon; // shape of the cannon
	bool m_exitGame; // control exiting game

};

#endif // !GAME

