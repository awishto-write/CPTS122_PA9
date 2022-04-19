#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"

using std::cout;
using std::endl;

int main(void)
{
	// Initialize board: 
	sf::RenderWindow window(sf::VideoMode(400, 400), "Checkers!");

	Tile board[8][8];

	sf::Color redTile = sf::Color::Red;
	sf::Color blackTile = sf::Color::Black;

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

		window.display(); 
	}
}
