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
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "game.h"
#include <ctime>





/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{

	int numGen = 0; // My random number gen
#ifdef _DEBUG 
	srand(static_cast <unsigned int>(numGen)); // Always the same outcome when starting program

#else

	srand(static_cast <unsigned int>(time(NULL))); // Always a random numnber when running the program


#endif // _DEBUG

	Game game;
	game.run();
	return 0;
}