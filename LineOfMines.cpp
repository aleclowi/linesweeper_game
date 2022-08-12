#include <string>
#include <cmath>
#include<iostream>
#include<ostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include "LineOfMines.h"

int LineOfMines::getScore() const
{
	//all this function does is return the score
	return score;
}
bool LineOfMines::hasHitMine()
{
	//all this function does is return the hitMine bool
	return hitMine;
}

void LineOfMines::display()
{
	//output each position from 1 to lineLength on one line and each value of locationDisplays on the next
		//line(all of which must have a width of 5, each separated by a space, such that the
		//position numbers align on the left of their corresponding locationDisplays value.
	std::vector<int> lineNumbers;
	//use a for loop from 1 to lineLength to display numbers of the lines
	for (int i = 1;i <= lineLength;i++)
	{
		if (i <= 9)
		{
			std::cout << i << "     ";
		}
		else
		{
			std::cout << i << "    ";
		}
	}

	std::cout << "\n";
	//for loop for the display of underscores
	for (int i = 0; i < lineLength; ++i)
	{
		std::cout << locationDisplays[i] << " ";
	}
}

void LineOfMines::placeMines()
{
	srand(time(NULL));
	std::vector <int> total;
	//use a for loop from 1 to line Length to create a new vector that matches the size of lineLength to be modified
	for (int i = 1; i <= lineLength; ++i)
	{
		total.push_back(i);
	}
	//use a for loop from 1 to numberOfmines to randomly place mines on different indexes on the lines
	for (int i = 1; i <= numberOfMines; ++i)
	{
		size_t sizeOfNoMines = total.size();
		size_t randIndex = rand() % sizeOfNoMines;
		int numberOfMines = total[randIndex];
		total.erase(total.begin() + randIndex);
		mineLocations.push_back(numberOfMines);
	}
}

bool LineOfMines::containsMine(int position)
{
	//Create a variables that scans each index of the line looking for mines
	auto findMines = find(mineLocations.begin(), mineLocations.end(), position);
	//If else statement for whether or not findMines is true or false at each index
	if (findMines != end(mineLocations))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void LineOfMines::grandReveal()
{
	//for loop from 0 to number of mines that reveals all of the mines on the line if the mine has been hit
	for (int j = 0; j < numberOfMines; ++j)
	{
		int mod = mineLocations[j];
		locationDisplays[mod - 1] = mines;
	}
	//call the display function to modify the line 
	display();
}

void LineOfMines::setCounts()
{
	//for loop from one to line length to set the 0, 1, or 2 at each index where a mine is not 
	for (int k = 1; k <= lineLength; ++k)
	{
		//use if else statement to add up the counts on the line
		if (k == 1)
		{
			if (containsMine(k + 1) == true)
			{
				neighboringMineCounts.push_back(1);
			}
			else
			{
				neighboringMineCounts.push_back(0);
			}
		}
		if ((k > 1) && (k < lineLength))
		{
			if ((containsMine(k + 1) == true) || (containsMine(k - 1) == true))
			{
				neighboringMineCounts.push_back(1);
			}
			else if ((containsMine(k + 1) == true) && (containsMine(k - 1) == true))
			{
				neighboringMineCounts.push_back(2);
			}
			else
			{
				neighboringMineCounts.push_back(0);
			}
		}
		if (k == lineLength)
		{
			if (containsMine(k - 1) == true)
			{
				neighboringMineCounts.push_back(1);
			}
			else
			{
				neighboringMineCounts.push_back(0);
			}
		}
	}
}

void LineOfMines::makeSelection(int reveal)
{
	int index = reveal - 1;
	//If the selected index contains a mine, reveal the mines
	if (containsMine(reveal))
	{
		//locationDisplays[index] = mines;
		score = 0;
		hitMine = true;
	}
	//If the index selected has a zero, display the zero and modify displays() function
	else if (neighboringMineCounts[index] == 0)
	{
		locationDisplays[index] = zero;
		score += 1;
		display();
	}
	//If the index selected has a one, display the one and modify displays() function
	else if (neighboringMineCounts[index] == 1)
	{
		locationDisplays[index] = one;
		score += 1;
		display();
	}
	//If the index selected has a two, display the two and modify displays() function
	else if (neighboringMineCounts[index] == 2)
	{
		locationDisplays[index] = two;
		score += 1;
		display();
	}
	
}
