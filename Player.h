#ifndef _PLAYER_H
#define _PLAYER_H

#include<string>
#include<vector>
#include<cstddef>


class Player 
{
public:
	/**
	Constructor: takes a single input of the player's name

	@param name, the player's name that was inputted
	@param bestScore is set to zero when a name is entered
	*/
	Player(std::string PlayerName) : name(PlayerName), bestScore(0){}

	/**
	This function returns the the player's name in the form of a string

	@return the player's name
	*/

	std::string getName();

	/**
	This function checks the score record of the game

	@return true or false depending on whether or not the best score has been beat by the current score
	*/
	bool checkRecord(int currentScore);

	/**
	This function returns the maxScore of the game

	@return an int representing the maxScore of the game
	*/
	int getMaxScore();

private:
	//name and bestScore variables placed in the private because they are modified through the constructor
	std::string name;
	int bestScore;
};

#endif
