#ifndef _LINEOFMINES_H
#define _LINEOFMINES_H

#include<string>
#include<vector>
#include<cstddef>


class LineOfMines
{
public: 
	/**
	Constructor: takes an input of lineLength and number of mines inputted by the user, sets the score to zero,
	sets location displays to a string of index size lineLength with underscores at each index, neighboringMineCounts
	and mineLocations to zero, and hitMine to false. It also calls the functions placeMines() and setCounts() which 
	refresh every game

	@param the length of line inputted by the user
	@param the number of mines chosed by the user
	*/
	LineOfMines(size_t lineLength_, size_t numberOfMines_) : lineLength(lineLength_),
		numberOfMines(numberOfMines_), score(0), locationDisplays(lineLength_, underscores), neighboringMineCounts(),
		mineLocations(), hitMine(false)
	{
		placeMines();
		setCounts();
	}

	/**
	This function returns the score of the current game

	@return current score
	*/
	int getScore() const;
	/**
	This function returns whether or not a mine has been hit

	@return true or false depending on hitMine
	*/
	bool hasHitMine();
	/**
	Displays the new line of Linesweeper game depending on the lineLength that the user inputs

	@return the string vector of the Line
	*/
	void display();
	/**
	Places mines in random locations on the line

	@return nothing, just modifying the display() line
	*/
	void placeMines();
	/**
	This function checks each index of the display() line to see if a mine is located there or not

	@return true or false depending on whether or not a mine is located at the index
	*/
	bool containsMine(int position);
	/**
	This function reveals all of the mines on the line when a mine has been hit

	@return all the mines on the line
	*/
	void grandReveal();
	/**
	This function sets each 0, 1, and 2 on the line where there are no mines 
	and adds up the score of each turn

	@return nothing
	*/
	void setCounts();
	/**
	this function reveals the 0,1,or 2 of the selected location on the line

	@return the 0, 1, 2 on the line
	*/
	void makeSelection(int reveal);

private:
	//Place all variables that will be used in the .cpp file function definitions here
	int score;
	std::string underscores = "_____";
	size_t lineLength;
	size_t numberOfMines;
	std::vector<std::string> locationDisplays;
	std::vector<int> neighboringMineCounts;
	std::vector<int> mineLocations;
	bool hitMine;
	std::string mines = "__*__";
	std::string zero = "__0__";
	std::string one = "__1__";
	std::string two = "__2__";
};
#endif
