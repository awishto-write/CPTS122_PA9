#pragma once

#define BLUE_PLAYER 0
#define WHITE_PLAYER 1

//constexpr auto BLUE_PLAYER = 0;
//constexpr auto WHITE_PLAYER = 0;

#include <SFML/Graphics.hpp>
#include <iostream>

#include "board.h"
#include "token.h"

using std::cout;
using std::endl;

class Checkers
{
public:
	Checkers();
	void gaming();
};

Checkers::Checkers()
{
	//
}

void Checkers::gaming()
{
	// Initialize variables: 
	sf::RenderWindow window(sf::VideoMode(400, 400), "Checkers!");
	Board gameBoard;
	sf::Color redTile = sf::Color::Red;
	sf::Color blackTile = sf::Color::Black;
	sf::Color active = sf::Color::Yellow;
	double xPos = 0.0, yPos = 0.0;
	bool occupiedTest = false;
	Token BluePieces[12];
	Token WhitePieces[12];
	double xTokenPos = 10, yTokenPos = 10;

	// Set player turn: 
	int playerTurn = BLUE_PLAYER;

	// Set blue piece location: 
	for (int i = 0; i < 12; ++i)
	{
		// Set location: 
		BluePieces[i].setPosition(xTokenPos, yTokenPos);
		BluePieces[i].setXLocation(xTokenPos);
		BluePieces[i].setYLocation(yTokenPos);

		// Move X location: 
		xTokenPos += 100.0;

		// If reaching maximum: 
		if ((i + 1) % 4 == 0)
		{
			// Move back to start of row; 
			xTokenPos = 10;

			if ((i + 1) == 4)
			{
				// Offset tokens: 
				xTokenPos = 60;
			}

			// Move to next row: 
			yTokenPos += 50.0;
		}
	}

	// Set token position for tokens on other side of board: 
	yTokenPos = 260, xTokenPos = 60;

	// Set white piece location: 
	for (int i = 0; i < 12; ++i)
	{
		// Set location: 
		WhitePieces[i].setPosition(xTokenPos, yTokenPos);
		WhitePieces[i].setXLocation(xTokenPos);
		WhitePieces[i].setYLocation(yTokenPos);

		// Move X Location: 
		xTokenPos += 100;

		if ((i + 1) % 4 == 0)
		{
			// Move back to start of row: 
			xTokenPos = 60;

			if ((i + 1) == 4)
			{
				// Offset for middle row: 
				xTokenPos = 10;
			}

			// Move to next row: 
			yTokenPos += 50;
		}
	}

	// Set piece color: 
	for (int i = 0; i < 12; i++)
	{
		BluePieces[i].setFillColor(sf::Color::Blue);
		WhitePieces[i].setFillColor(sf::Color::White);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Infinite loop: 
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

		if (playerTurn == BLUE_PLAYER)
		{
			// Detection of click: 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				xPos = sf::Mouse::getPosition(window).x;
				yPos = sf::Mouse::getPosition(window).y;

				int vectRow = 0, vectCol = 0;

				bool firstRun = true;

				// Get matrix locations: 
				vectCol = xPos / 50;
				vectRow = yPos / 50;


				for (int i = 0; i < 12; ++i)
				{
					// Initialize variables: 
					int dummy = int(BluePieces[i].getXLocation()) / 50;
					int dummy2 = int(BluePieces[i].getYLocation()) / 50;
					bool live = false;
					bool firstRun = true;
					int activeVectRow = 0;

					// Set piece to active: 
					if (vectRow == dummy2 && vectCol == dummy)
					{
						// Change fill color to yellow: 
						BluePieces[i].setFillColor(active);

						window.clear();

						//// Draw board:
						for (int i = 0; i < 8; ++i)
						{
							for (int j = 0; j < 8; ++j)
							{
								window.draw(gameBoard.getTile(i, j));
							}
						}

						// Draw Pieces: 
						for (int i = 0; i < 12; ++i)
						{
							window.draw(BluePieces[i]);
							window.draw(WhitePieces[i]);
						}

						window.display();

						// Infinite loop until key is unpressed: 
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							;
						}

						// Move piece: 
						while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								//// Get location of click: 
								//double newXPos = sf::Mouse::getPosition(window).x; 
								//double newYPos = sf::Mouse::getPosition(window).y; 
								//int dummy3 = int(newXPos) / 50; 
								//cout << dummy3 << endl; 

								//if (newYPos == (yPos + 1) && newXPos == xPos)
								//{
								BluePieces[i].move(0, 50);
								BluePieces[i].setYLocation(BluePieces[i].getYLocation() + 50);
								BluePieces[i].setFillColor(sf::Color::Blue);
								//}

								// Change player turn: 
								playerTurn = WHITE_PLAYER;

								cout << "White Player's Turn!" << endl;
							}
						}

						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							;
						}

					}
				}

			}
		}

		if (playerTurn == WHITE_PLAYER)
		{
			// Detection of click: 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				xPos = sf::Mouse::getPosition(window).x;
				yPos = sf::Mouse::getPosition(window).y;

				int vectRow = 0, vectCol = 0;

				bool firstRun = true;

				// Get matrix locations: 
				vectCol = xPos / 50;
				vectRow = yPos / 50;


				for (int i = 0; i < 12; ++i)
				{
					// Initialize variables: 
					int dummy = int(WhitePieces[i].getXLocation()) / 50;
					int dummy2 = int(WhitePieces[i].getYLocation()) / 50;
					bool live = false;
					bool firstRun = true;
					int activeVectRow = 0;

					// Set piece to active: 
					if (vectRow == dummy2 && vectCol == dummy)
					{
						// Change fill color to yellow: 
						WhitePieces[i].setFillColor(active);

						window.clear();

						//// Draw board:
						for (int i = 0; i < 8; ++i)
						{
							for (int j = 0; j < 8; ++j)
							{
								window.draw(gameBoard.getTile(i, j));
							}
						}

						// Draw Pieces: 
						for (int i = 0; i < 12; ++i)
						{
							window.draw(BluePieces[i]);
							window.draw(WhitePieces[i]);
						}

						window.display();

						// Infinite loop until key is unpressed: 
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							;
						}

						// Move piece: 
						while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								//// Get location of click: 
								//double newXPos = sf::Mouse::getPosition(window).x; 
								//double newYPos = sf::Mouse::getPosition(window).y; 
								//int dummy3 = int(newXPos) / 50; 
								//cout << dummy3 << endl; 

								//if (newYPos == (yPos + 1) && newXPos == xPos)
								//{
								WhitePieces[i].move(0, -50);
								WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() - 50);
								WhitePieces[i].setFillColor(sf::Color::White);
								//}

								// Change player turn: 
								playerTurn = BLUE_PLAYER;

								cout << "Blue Player's Turn!" << endl;
							}
						}

						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							;
						}

					}
				}

			}
		}


		//BluePieces[2].move(.01, 0);

		window.clear();

		//// Draw board:
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				window.draw(gameBoard.getTile(i, j));
			}
		}

		// Draw Pieces: 
		for (int i = 0; i < 12; ++i)
		{
			window.draw(BluePieces[i]);
			window.draw(WhitePieces[i]);
		}

		window.display();
	}
}