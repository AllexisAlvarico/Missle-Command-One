/// <summary>
/// Name: Allexis Alvarico
/// Login: C00242855
/// Date: 15th of November 2018
/// --------------------------------------------------------
/// Summary:
/// The program is to test all vector mathematics for use
/// in future labs. when testing this program, it should have
/// two example to test its correctness.
/// ---------------------------------------------------------
/// Estinmated time: 5-7 hours
/// Session 1 6:00pm to 7:00am 15th of November 
/// Session 2 7:00pm to 8:30pm 17th of November
/// Session 3 5:30pm to 9:00pm 19th of November 
/// Actual time: 7 hours
/// Known Bugs: 
/// None as of now
/// </summary> 

// author Peter Lowe
// don't edit this file
#ifndef MY_VECTOR2
#define MY_VECTOR2

#include <SFML/Graphics.hpp>



float vectorLength(const sf::Vector2f t_vector);  // root x2 + y2
float vectorLengthSquared(const sf::Vector2f t_vector); // x2 + y2
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector);// length of ans is one
float vectorCrossProduct(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB);  // Vx * Uy - Vy * Ux
float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB);  // Vx * Uy + Vy * Ux
float vectorAngleBetween(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB); // result always 0>= && <=180
sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians); // anti-clockwise ({1,0},PI/2) = {0,1}
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto);// ans parallel to second vector
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto);// ans perpendicular to second vector
float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto);// scalar resolute




const float PI = 3.14159265359f; 



#endif  // MY_VECTOR2