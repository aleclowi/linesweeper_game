#include <string>
#include <cmath>

#include "Player.h"

std::string Player::getName() 
{
	//return player's name for this function
	return name;
}
int Player::getMaxScore()
{
	//return player's best score for this function
	return bestScore;
}
	//updating the maximum score if this input is greater; it should also return true to indicate the
		//new score is strictly better, if it is, and otherwise return false.

bool Player::checkRecord(int currentScore)
{
	//updating the maximum score if this input is greater; it should also return true to indicate the
		//new score is strictly better, if it is, and otherwise return false.
	if (currentScore > bestScore)
	{
		bestScore = currentScore;
		return true;
	}
	else
	{
		return false;
	}
}

