#include<iostream>
#include<string>
#include<ostream>
#include<vector>

#include "Player.h"
#include "LineOfMines.h"
using namespace std;

int main() 
{
	srand(time(nullptr));

	// The game is explained
	cout <<
		"This is a game of Linesweeper: mines are arranged on a line. \n"
		"You select a position to reveal what is there. \n"
		"For every safe location you reveal, you get +1 point. \n"
		"If you reveal a mine, you get a score of 0. \n"
		"A given location may have a mine to either its left, right, both, or neither. \n"
		"The number of neighbouring mines of a revealed location 0/1/2 is displayed. \n"
		"You can continue playing until you either hit a mine or choose not to reveal any more locations." << '\n';

	/* the rest is for you to fill in */
	//Initialize all the variables that will be used in the loop conditions and constructor conditions
	string playerName;
	string yesOrNo;
	string nextGame = "y";
	//Get the player's name
	cout << "What is your name? ";
	getline(cin, playerName);
	//Call the constructor 
	Player p1(playerName);
	int lineLength;
	int totalMines;
	//Then get the lineLength and totalmines from the user
	cout << "How long do you want the line? ";
	cin >> lineLength;
	cout << "How many mines do you want on the line? ";
	cin >> totalMines;
	//Use a while loop which will run the entire game over again if the user selects "y" at the end for a new game
	while (nextGame == "y")
	{
		LineOfMines g1(lineLength, totalMines);
		g1.display();
		cout << "\n";
		//Do while loop is used for the condition that the user continues to respond "y" to revealing locations.
		//This will allow the line to modified as the user continues to choose to reveal new indexes
		do
		{
			cout << "What position would you like to reveal? ";
			int location;
			cin >> location;
			g1.makeSelection(location);
			//If else statement for whether or not a mine has been hit. If it has, the game is over and the user 
			//has a score of zero, then display the line of mines. If the user selects an index that doe not have an input,
			//display the makeselection (at the beginning of the do loop) and as to reveal another location
			if (g1.hasHitMine() == true)
			{
				cout << "The mine locations are now revealed:\n";
				g1.grandReveal();
				break;
			}
			else if (g1.hasHitMine() == false)
			{

				cout << "\n" << "Would you like to reveal another location? [y/n] ";
			}
			cin >> yesOrNo;
		} while (yesOrNo == "y");
		//Use a while loop if the user enter's no when revealing a new location
		while (yesOrNo == "n")
		{
			cout << "The mine locations are now revealed:\n";
			g1.grandReveal();
			break;
		}
		

		if (p1.checkRecord(g1.getScore()) == true)
		{
			p1.checkRecord(g1.getScore());
			cout << "\n" << "You have a new high score of " << p1.getMaxScore() << "!";
		}
		else
		{
			cout << "\n" << "You scored " << g1.getScore() << ", but your best score was still " << p1.getMaxScore();
		}
		cout << "\n";
		cout << "Would you like to play another game? [y/n] ";
		cin >> nextGame;
		
		if (nextGame == "n")
		{
			cout << "\n";
			cout << p1.getName() << ", your top score was " << p1.getMaxScore() << ".";
		}
	}
	return 0;
}