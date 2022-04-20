#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"
#include "token.h"

using std::cout;
using std::endl;

// Setting the pieces to their position on each square of the board
void Setting(sf::RenderWindow& window, Ball* BluePieces, Ball* WhitePieces)
{
	// For the color white

	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = (int)!(i % 2 & 1); j < 8; j += 2)
		{
			WhitePieces[k].isAlive = true;
			WhitePieces[k].x = j;
			WhitePieces[k].y = i;
			k++;
		}

	}

	// For the color blue

	k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = (int)(i % 2 & 1); j < 8; j += 2)
		{
			BluePieces[k].isAlive = true;
			BluePieces[k].x = j;
			BluePieces[k].y = 7 - i;
			k++;
		}

	}
}



int main(void)
{
	// Initialize variables: 
	sf::RenderWindow window(sf::VideoMode(400, 400), "Checkers!");

	Board gameBoard; 

	sf::Color redTile = sf::Color::Red;
	sf::Color blackTile = sf::Color::Black;

	double xPos = 0.0, yPos = 0.0;

	bool occupiedTest = false; 

	Ball BluePieces[12];
	Ball WhitePieces[12];

	for (int i = 0; i < 12; i++)
	{
		BluePieces[i].color = sf::Color::Blue;
		WhitePieces[i].color = sf::Color::White;
	}

	//  Placement of the pieces on the board
	Setting(window, BluePieces, WhitePieces);

	while (window.isOpen())
	{
		sf::Event event;

		// Check if window needs to be closed: 
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Window commands: 
		window.clear();

		//// Draw board:
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				window.draw(gameBoard.getTile(i, j));
			}
		}

		// Draw pieces
		for (int i = 0; i < 12; i++)
		{
			WhitePieces[i].Draw(window);
			BluePieces[i].Draw(window);
		}

		// Detection of click: 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			xPos = sf::Mouse::getPosition(window).x;
			yPos = sf::Mouse::getPosition(window).y;

			int vectRow = 0, vectCol = 0; 

			// Get matrix locations: 
			vectCol = xPos / 50; 
			vectRow = yPos / 50; 

			cout << vectRow << " " << vectCol << endl; 

			occupiedTest = gameBoard.getOccupied(vectRow, vectCol); 

			if (occupiedTest == true)
			{
				cout << "Occupied!" << endl; 
			}

			else if(occupiedTest == false)
			{
				cout << "Not Occupied!" << endl; 
			}


		}

		window.display();
	}
}
