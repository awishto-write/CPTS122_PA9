#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"
#include "piece.h"

using std::cout;
using std::endl;

         // Setting the pieces to their position on each square of the board
void Setting(sf::RenderWindow& window, Ball* BluePieces, Ball* WhitePieces)
{
                 // For the color white
	
	int k = 0;
	for (int i = 0;i < 3;i++)
	{
		for (int j = (int)!(i % 2 & 1);j < 8;j += 2)
		{
			WhitePieces[k].isAlive = true;
			WhitePieces[k].x = j;
			WhitePieces[k].y = i;
			k++;
		}

	}
	
	      // For the color blue

	k = 0;
	for (int i = 0;i < 3;i++)
	{
		for (int j = (int)(i % 2 & 1);j < 8;j += 2)
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
	// Initialize board: 
	sf::RenderWindow window(sf::VideoMode(400, 400), "Checkers!");

	Tile board[8][8];

	sf::Color redTile = sf::Color::Red;
	sf::Color blackTile = sf::Color::Black;

       
	   // Initialize pieces
	
	Ball BluePieces[12];
	Ball WhitePieces[12];

	for (int i = 0; i < 12; i++)
	{
		BluePieces[i].color = sf::Color::Blue;
		WhitePieces[i].color = sf::Color::White;
	}

	     //  Placement of the pieces on the board
	Setting(window, BluePieces, WhitePieces);
	
	
	// Initialize variables: 
	double xTilePos = 0.0, yTilePos = 0.0;

	// Construct board: 
	for (int i = 0; i < 8; ++i)
	{
		xTilePos = 0.0;
		for (int j = 0; j < 8; ++j)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					board[j][i].setColor(redTile); 
				}

				else
				{
					board[j][i].setColor(blackTile); 
				}
			}

			else
			{
				if (j % 2 == 0)
				{
					board[j][i].setColor(blackTile); 
				}

				else
				{
					board[j][i].setColor(redTile); 
				}
			}

			board[j][i].setPosition(xTilePos, yTilePos); 
			xTilePos += 50; 
		}

		yTilePos += 50; 

	}
	 

	double xPos = 0.0, yPos = 0.0; 

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

		// Detection of click: 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			xPos = sf::Mouse::getPosition(window).x; 
			yPos = sf::Mouse::getPosition(window).y; 

			cout << xPos << " " <<  yPos << endl;
		}

		// Window commands: 
		window.clear(); 
		
		// Draw board:
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				window.draw(board[j][i]); 
			}
		}
		
		  // Draw pieces
		for (int i = 0; i < 12; i++)
		{
			WhitePieces[i].Draw(window);
			BluePieces[i].Draw(window);
		}

		window.display(); 
	}
}
