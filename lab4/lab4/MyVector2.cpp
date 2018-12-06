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
/// Reference:
/// Richard Fleming: helped me on the calulation of the vectors 
/// Mantis Z: He let me use his example to check if my code if its 
/// outputing the same answer. 
/// Estinmated time: 5-7 hours
/// Session 1 6:00pm to 7:00am 15th of November 
/// Session 2 7:00pm to 8:30pm 17th of November
/// Session 3 5:30pm to 9:00pm 19th of November 
/// Actual time: 7 hours
/// Known Bugs: 
/// None as of now
/// </summary> 

#include "MyVector2.h"

/// <summary>
/// get length of vector using sqrt of the sum of the squares
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>length</returns>
float vectorLength(sf::Vector2f t_vector)  // root x2 + y2
{
	float lenght = (t_vector.x * t_vector.x ) + (t_vector.y * t_vector.y); //finds the lenght
	const float lenghtSqrt = sqrt(lenght); // sqaure roots it
	return lenghtSqrt; // returns it back
}

/// <summary>
/// get lenght of vector using squares (x * x)
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>lenghtSquared</returns>
float vectorLengthSquared(sf::Vector2f t_vector) // x*2 + y*2
{
	float lenghtSquared = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y); //gets the lenght's square 2
	return lenghtSquared; //returns it back
}

/// <summary>
/// get the cross product 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>crossProduct</returns>
float vectorCrossProduct(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB) // x1 * y2 - y1 * x2
{
	float crossProduct = (t_vectorA.x * t_vectorB.y) - (t_vectorA.y * t_vectorB.x); //gets the cross product
	return crossProduct; // returns it back
}

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>dotProduct</returns>
float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB) // (x1*x2) + (y1 * y2)
{
	float dotProduct = (t_vectorA.x * t_vectorB.x) + (t_vectorA.y * t_vectorB.y); // gets the dot product
	return dotProduct; // returns it back
}

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>angleChange</returns>
float vectorAngleBetween(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB) // 
{
	const float dotProduct = vectorDotProduct(t_vectorA, t_vectorB); // gets the dot product
	float lenghtA = vectorLength(t_vectorA); // gets the lenght root for A
	float lenghtB = vectorLength(t_vectorB); // gets the lenght root for B
	float calculatedRandians = (dotProduct / (lenghtA * lenghtB)); // gets the randius
	const float angleChange = acos(calculatedRandians) *(180/PI); // gets the degrees
	return angleChange; // returns it back
}

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vector and a angleRadians</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians) 
{
	float newRotateByX = t_vector.x *cos(t_angleRadians) - t_vector.y * sin(t_angleRadians); // gets the X-coord value 
	float newRotatebyY = t_vector.x * sin(t_angleRadians) + t_vector.y * cos(t_angleRadians); // gets the Y-coord value 
	return sf::Vector2f(newRotateByX, newRotatebyY); // returns it back
}

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	float dotProduct = vectorDotProduct(t_vector, t_onto); // gets the dot product
	float lenght = vectorLength(t_onto); // gets the lenght root
	float projectionCalulation = dotProduct / (lenght * lenght);
	return sf::Vector2f(projectionCalulation * t_onto.x, projectionCalulation * t_onto.y); // returns it back
} 

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	sf::Vector2f projection = vectorProjection(t_vector, t_onto); // gets the projection
	sf::Vector2f rejection = t_vector - projection; // calculate the rejection
	return sf::Vector2f(rejection); // returns it back

}

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>SCALAR_PROJECTION</returns>
float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	sf::Vector2f projection = vectorProjection(t_vector, t_onto); // gets the projection
	const float SCALAR_PROJECTION = vectorLength(projection); // calculate the scalar projection
	return SCALAR_PROJECTION; // returns it back
}

/// <summary>
/// 
/// </summary>
/// <param name="t_vector">input vectorA and vectorB</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector)
{
	float lenght = vectorLength(t_vector); // gets the lenght root
	return sf::Vector2f((t_vector.x / lenght), (t_vector.y / lenght)); // returns with the answer
}
