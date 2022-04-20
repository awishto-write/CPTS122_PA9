#pragma once

#include "tile.h"

class Board
{
private: 
	Tile mBoard[8][8]; 
	bool mOccupied[8][8]; 

public: 
	Board(); 

	Tile getTile(int i, int j); 

	bool getOccupied(int i, int j); 
};

Board::Board()
{
	// Initialize variables: 
	double xTilePos = 0.0, yTilePos = 0.0;

	sf::Color redTile = sf::Color::Red;
	sf::Color blackTile = sf::Color::Black;

	// Draw board: 
	for (int i = 0; i < 8; ++i)
	{
		xTilePos = 0.0;
		for (int j = 0; j < 8; ++j)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					this->mBoard[j][i].setColor(redTile); 
				}

				else
				{
					this->mBoard[j][i].setColor(blackTile); 
				}
			}

			else
			{
				if (j % 2 == 0)
				{
					this->mBoard[j][i].setColor(blackTile); 
				}

				else
				{
					this->mBoard[j][i].setColor(redTile); 
				}
			}

			this->mBoard[j][i].setPosition(xTilePos, yTilePos); 
			xTilePos += 50;
		}

		yTilePos += 50;
	}

	// Set occupied: 

	// Intialize every slot to false: 
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			this->mOccupied[i][j] = false; 
		}
	}

	// Set specific slots to true: 
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0 || i == 2)
		{
			for (int j = 1; j < 8; j += 2)
			{
				this->mOccupied[i][j] = true; 
			}
		}

		else if (i == 1)
		{
			for (int j = 0; j < 8; j += 2)
			{
				this->mOccupied[i][j] = true; 
			}
		}
	}

	// For the color blue

	k = 0;
	for (int i = 5; i < 8; i++)
	{
		if (i == 5 || i == 7)
		{
			for (int j = 0; j < 8; j += 2)
			{
				this->mOccupied[i][j] = true; 
			}
		}

		else if (i == 6)
		{
			for (int j = 1; j < 8; j += 2)
			{
				this->mOccupied[i][j] = true; 
			}
		}
	}
}


Tile Board::getTile(int i, int j)
{
	return this->mBoard[i][j]; 
}

bool Board::getOccupied(int i, int j)
{
	return this->mOccupied[i][j]; 
}
