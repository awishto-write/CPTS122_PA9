#pragma once

#define BLUE_PLAYER 0
#define WHITE_PLAYER 1

#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"
#include "token.h"

using std::cout;
using std::endl;

int main(void)
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

		// Blue player turn: 
		if (playerTurn == BLUE_PLAYER)
		{
			cout << "Blue Player's Turn!" << endl; 

			if (event.type == sf::Event::MouseButtonReleased)
			{
				// Get position of click: 
				xPos = sf::Mouse::getPosition(window).x; 
				yPos = sf::Mouse::getPosition(window).y; 

				int vectRow = 0, vectCol = 0;
				bool firstRun = true; 
				int dummyX2 = 30, dummyY2 = 30; 

				// Set array values: 
				vectRow = yPos / 50; 
				vectCol = xPos / 50; 

				// Check if user clicked a specific token: 
				for (int i = 0; i < 12; ++i)
				{
					int dummyX = int(BluePieces[i].getXLocation()) / 50;
					int dummyY = int(BluePieces[i].getYLocation()) / 50; 

					// Check for clicking: 
					if (vectRow == dummyY && vectCol == dummyX)
					{
						// Change fill color: 
						BluePieces[i].setFillColor(active); 

						// Redraw window: 
						window.clear();

						// Draw board:
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

						// Get another click from the user: 
						while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							; 
						}

						while (dummyY2 != (dummyY + 1) && (dummyX2 != dummyX))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								// Get second click location: 
								xPos = sf::Mouse::getPosition(window).x;
								yPos = sf::Mouse::getPosition(window).y;

								dummyX2 = xPos / 50;
								dummyY2 = yPos / 50;
							}

							cout << dummyX2 << " " << dummyY2 << endl;
						} 

						// Check if piece can be moved: 
						if ((dummyX == dummyX2) && (dummyY == dummyY2 - 1))
						{
							BluePieces[i].move(0, 50);
							BluePieces[i].setFillColor(sf::Color::Blue);

							BluePieces[i].setYLocation(BluePieces[i].getYLocation() + 50); 
						}

						cout << "Ended" << endl;

						// Switch user:
						playerTurn = WHITE_PLAYER;
					}
				}
			} 

		}

		// White Player's turn: 
		if (playerTurn == WHITE_PLAYER)
		{
			cout << "White Player's Turn!" << endl;

			if (event.type == sf::Event::MouseButtonReleased)
			{
				// Get position of click: 
				xPos = sf::Mouse::getPosition(window).x;
				yPos = sf::Mouse::getPosition(window).y;

				int vectRow = 0, vectCol = 0;
				bool firstRun = true;
				int dummyX2 = 30, dummyY2 = 30;

				// Set array values: 
				vectRow = yPos / 50;
				vectCol = xPos / 50;

				// Check if user clicked a specific token: 
				for (int i = 0; i < 12; ++i)
				{
					int dummyX = int(WhitePieces[i].getXLocation()) / 50;
					int dummyY = int(WhitePieces[i].getYLocation()) / 50;

					// Check for clicking: 
					if (vectRow == dummyY && vectCol == dummyX)
					{
						// Change fill color: 
						WhitePieces[i].setFillColor(active);

						// Redraw window: 
						window.clear();

						// Draw board:
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

						// Get another click from the user: 
						while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							;
						}

						while (dummyY2 != (dummyY - 1) && (dummyX2 != dummyX))
						{
							// Get second click location: 
							xPos = sf::Mouse::getPosition(window).x;
							yPos = sf::Mouse::getPosition(window).y;

							dummyX2 = xPos / 50;
							dummyY2 = yPos / 50;

							cout << dummyX2 << " " << dummyY2 << endl;
						}

						// Check if piece can be moved: 
						if ((dummyX == dummyX2) && (dummyY == dummyY2 + 1))
						{
							WhitePieces[i].move(0, -50);
							WhitePieces[i].setFillColor(sf::Color::White);

							WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() + 50);
						}

						cout << "Ended" << endl;

						// Switch user:
						playerTurn = BLUE_PLAYER;
					}
				}
			}
		}

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
