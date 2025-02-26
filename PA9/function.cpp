#include "function.h"

void Game::game_loop()
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

	     // Number of token of each player      // Has been added
	int blue_num_token = 12;      
	int white_num_token = 12;      


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
			//cout << "Blue Player's Turn!" << endl; 
			bool moveOn = false;

			if (event.type == sf::Event::MouseButtonReleased)
			{
				// Get position of click: 
				xPos = sf::Mouse::getPosition(window).x;
				yPos = sf::Mouse::getPosition(window).y;

				int vectRow = 0, vectCol = 0;
				bool firstRun = true;
				bool myTurn = true;
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
						// Change to active color: 
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

						while (moveOn == false)
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								// Get second click location: 
								xPos = sf::Mouse::getPosition(window).x;
								yPos = sf::Mouse::getPosition(window).y;

								dummyX2 = xPos / 50;
								dummyY2 = yPos / 50;

								// Check if piece can be moved normally: 
								if ((dummyX == dummyX2 - 1) && (dummyY == dummyY2 - 1))
								{
									// Space occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Space not occupied: 
									else
									{
										// Move piece: 
										BluePieces[i].move(50, 50);
										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}

										else
										{
											BluePieces[i].setFillColor(sf::Color::Blue);

										}

										// Reallocate piece location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() + 50);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() + 50);

										// Update occupied board positions: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										moveOn = true;

										// King: 
										if ((int(BluePieces[i].getYLocation()) / 50) == 7)
										{
											BluePieces[i].setKing();
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}
									}

								}

								if ((dummyX == dummyX2 + 1) && (dummyY == dummyY2 - 1))
								{
									// Space occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Space not occupied: 
									else
									{
										// Move piece: 
										BluePieces[i].move(-50, 50);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}

										else
										{
											BluePieces[i].setFillColor(sf::Color::Blue);

										}

										// Reallocate piece location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() + 50);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() - 50);

										// Update occupied board positions: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										moveOn = true;

										// King: 
										if ((int(BluePieces[i].getYLocation()) / 50) == 7)
										{
											BluePieces[i].setKing();
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}
									}

								}

								// Check if piece is attacking: 
								if ((dummyX == dummyX2 - 2) && (dummyY == dummyY2 - 2))
								{
									// Piece is taken: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 - 1, dummyY2 - 1) != WHITE_PLAYER)
									{
										cout << "NO Whites here" << endl;
									}

									// Piece not taken: 
									else
									{
										// Move piece: 
										BluePieces[i].move(100, 100);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}

										else
										{
											BluePieces[i].setFillColor(sf::Color::Blue);

										}

										// Set new piece location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() + 100);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() + 100);

										moveOn = true;

										// Update occupied board logic: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										// King: 
										if ((int(BluePieces[i].getYLocation()) / 50) == 7)
										{
											BluePieces[i].setKing();
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(WhitePieces[enemy].getXLocation()) / 50 == (dummyX2 - 1)) &&
												(int(WhitePieces[enemy].getYLocation()) / 50 == (dummyY2 - 1)))
											{
												// Get piece off the board: 
												WhitePieces[enemy].move(500, 500);

												WhitePieces[enemy].setXLocation(500);
												WhitePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 - 1, dummyY2 - 1);
												gameBoard.setColor(dummyX2 - 1, dummyY2 - 1, NO_TOKEN);

												         // Has been added
 
										           // Decrementing the number of token after being captured
												white_num_token--;

											}
										}
									}

								}

								if ((dummyX == dummyX2 + 2) && (dummyY == dummyY2 - 2))
								{
									// Tile occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 + 1, dummyY2 - 1) != WHITE_PLAYER)
									{
										cout << "NO Whites here" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										BluePieces[i].move(-100, 100);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}

										else
										{
											BluePieces[i].setFillColor(sf::Color::Blue);

										}

										// Set new piece location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() + 100);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() - 100);

										moveOn = true;

										// Update tile occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										// King: 
										if ((int(BluePieces[i].getYLocation()) / 50) == 7)
										{
											BluePieces[i].setKing();
											BluePieces[i].setFillColor(sf::Color::Cyan);
										}

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(WhitePieces[enemy].getXLocation()) / 50 == (dummyX2 + 1)) &&
												(int(WhitePieces[enemy].getYLocation()) / 50 == (dummyY2 - 1)))
											{
												// Get piece off the board: 
												WhitePieces[enemy].move(500, 500);

												WhitePieces[enemy].setXLocation(500);
												WhitePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 + 1, dummyY2 - 1);
												gameBoard.setColor(dummyX2 + 1, dummyY2 - 1, NO_TOKEN);


												// Decrementing the number of token after being captured
												white_num_token--;

											}
										}
									}
								}

								// Check if piece is a king and moves backwards normally: 
								if ((dummyX == dummyX2 + 1) && (dummyY == dummyY2 + 1) && BluePieces[i].checkKing())
								{
									// If tile is occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										BluePieces[i].move(-50, -50);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											BluePieces[i].setFillColor(sf::Color::White);
										}

										// Set new tile location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() - 50);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() - 50);

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										moveOn = true;
									}
								}

								if ((dummyX == dummyX2 - 1) && (dummyY = dummyY2 + 1) && BluePieces[i].checkKing())
								{
									// If tile is occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										BluePieces[i].move(+50, -50);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											BluePieces[i].setFillColor(sf::Color::White);
										}

										// Set new tile location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() - 50);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() + 50);

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										moveOn = true;
									}
								}

								// Check if piece is a king and attacks: 
								if ((dummyX == dummyX2 + 2) && (dummyY == dummyY2 + 2) && BluePieces[i].checkKing())
								{
									// Tile occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 + 1, dummyY2 + 1) != WHITE_PLAYER)
									{
										cout << "No blues here" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										BluePieces[i].move(-100, -100);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											BluePieces[i].setFillColor(sf::Color::White);
										}

										// Set new piece location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() - 100);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() - 100);

										moveOn = true;

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(WhitePieces[enemy].getXLocation()) / 50 == (dummyX2 + 1)) &&
												(int(WhitePieces[enemy].getYLocation()) / 50 == (dummyY2 + 1)))
											{
												// Get piece off the board: 
												WhitePieces[enemy].move(500, 500);

												WhitePieces[enemy].setXLocation(500);
												WhitePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 + 1, dummyY2 + 1);
												gameBoard.setColor(dummyX2 + 1, dummyY2 + 1, NO_TOKEN);



												// Decrementing the number of token after being captured
												white_num_token--;
											}
										}
									}
								}

								if ((dummyX == dummyX2 - 2) && (dummyY == dummyY2 + 2) && BluePieces[i].checkKing())
								{
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 - 1, dummyY2 + 1) != WHITE_PLAYER)
									{
										cout << "NO blues here" << endl;
									}

									else
									{
										// Move piece: 
										BluePieces[i].move(+100, -100);

										if (BluePieces[i].checkKing())
										{
											BluePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											BluePieces[i].setFillColor(sf::Color::White);
										}

										// Update piece location: 
										BluePieces[i].setYLocation(BluePieces[i].getYLocation() - 100);
										BluePieces[i].setXLocation(BluePieces[i].getXLocation() + 100);

										moveOn = true;

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, BLUE_PLAYER);

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(WhitePieces[enemy].getXLocation()) / 50 == (dummyX2 - 1)) &&
												(int(WhitePieces[enemy].getYLocation()) / 50 == (dummyY2 + 1)))
											{
												// Get piece off the board: 
												WhitePieces[enemy].move(500, 500);

												WhitePieces[enemy].setXLocation(500);
												WhitePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 - 1, dummyY2 + 1);
												gameBoard.setColor(dummyX2 - 1, dummyY2 + 1, NO_TOKEN);


												// Decrementing the number of token after being captured
												white_num_token--;
											}
										}
									}

								}

								// Deselecting piece: 
								if ((dummyX == dummyX2) && (dummyY == dummyY2))
								{

								}
							}

							//cout << dummyX2 << " " << dummyY2 << endl;
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
			//cout << "Blue Player's Turn!" << endl;
			bool moveOn = false;

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

						while (moveOn == false)
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								// Get second click location: 
								xPos = sf::Mouse::getPosition(window).x;
								yPos = sf::Mouse::getPosition(window).y;

								dummyX2 = xPos / 50;
								dummyY2 = yPos / 50;

								// Check if piece can be moved normally: 
								if ((dummyX == dummyX2 + 1) && (dummyY == dummyY2 + 1))
								{
									// If tile is occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(-50, -50);

										if (WhitePieces[i].checkKing())
										{
											WhitePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											WhitePieces[i].setFillColor(sf::Color::White);
										}

										// Set new tile location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() - 50);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() - 50);

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										moveOn = true;

										// King: 
										if ((int(WhitePieces[i].getYLocation()) / 50) == 0)
										{
											WhitePieces[i].setKing();
											WhitePieces[i].setFillColor(sf::Color::Green);
										}
									}
								}

								if ((dummyX == dummyX2 - 1) && (dummyY == dummyY2 + 1))
								{
									// If tile is occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(+50, -50);

										if (WhitePieces[i].checkKing())
										{
											WhitePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											WhitePieces[i].setFillColor(sf::Color::White);
										}

										// Set new tile location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() - 50);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() + 50);

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										moveOn = true;

										// King: 
										if ((int(WhitePieces[i].getYLocation()) / 50) == 0)
										{
											WhitePieces[i].setKing();
											WhitePieces[i].setFillColor(sf::Color::Green);
										}
									}
								}

								// Check if piece can attack: 
								if ((dummyX == dummyX2 + 2) && (dummyY == dummyY2 + 2))
								{
									// Tile occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 + 1, dummyY2 + 1) != BLUE_PLAYER)
									{
										cout << "No blues here" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(-100, -100);

										if (WhitePieces[i].checkKing())
										{
											WhitePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											WhitePieces[i].setFillColor(sf::Color::White);
										}

										// Set new piece location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() - 100);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() - 100);

										moveOn = true;

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										// King: 
										if ((int(WhitePieces[i].getYLocation()) / 50) == 0)
										{
											WhitePieces[i].setKing();
											WhitePieces[i].setFillColor(sf::Color::Green);
										}

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(BluePieces[enemy].getXLocation()) / 50 == (dummyX2 + 1)) &&
												(int(BluePieces[enemy].getYLocation()) / 50 == (dummyY2 + 1)))
											{
												// Get piece off the board: 
												BluePieces[enemy].move(500, 500);

												BluePieces[enemy].setXLocation(500);
												BluePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 + 1, dummyY2 + 1);
												gameBoard.setColor(dummyX2 + 1, dummyY2 + 1, NO_TOKEN);


												      // Has been added
													  
												// Decrementing the number of token after being captured
												blue_num_token--;

											}
										}
									}


								}

								if ((dummyX == dummyX2 - 2) && (dummyY == dummyY2 + 2))
								{
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 - 1, dummyY2 + 1) != BLUE_PLAYER)
									{
										cout << "NO blues here" << endl;
									}

									else
									{
										// Move piece: 
										WhitePieces[i].move(+100, -100);

										if (WhitePieces[i].checkKing())
										{
											WhitePieces[i].setFillColor(sf::Color::Green);
										}
										else
										{
											WhitePieces[i].setFillColor(sf::Color::White);
										}

										// Update piece location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() - 100);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() + 100);

										moveOn = true;

										// Update board occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										// King: 
										if ((int(WhitePieces[i].getYLocation()) / 50) == 0)
										{
											WhitePieces[i].setKing();
											WhitePieces[i].setFillColor(sf::Color::Green);
										}

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(BluePieces[enemy].getXLocation()) / 50 == (dummyX2 - 1)) &&
												(int(BluePieces[enemy].getYLocation()) / 50 == (dummyY2 + 1)))
											{
												// Get piece off the board: 
												BluePieces[enemy].move(500, 500);

												BluePieces[enemy].setXLocation(500);
												BluePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 - 1, dummyY2 + 1);
												gameBoard.setColor(dummyX2 - 1, dummyY2 + 1, NO_TOKEN);


												// Decrementing the number of token after being captured
												blue_num_token--;

											}
										}
									}
								}

								// Check if piece moves normally as king: 
								if ((dummyX == dummyX2 - 1) && (dummyY == dummyY2 - 1) && WhitePieces[i].checkKing())
								{
									// Space occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Space not occupied: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(50, 50);
										WhitePieces[i].setFillColor(sf::Color::Green);

										// Reallocate piece location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() + 50);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() + 50);

										// Update occupied board positions: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										moveOn = true;
									}
								}

								if ((dummyX == dummyX2 + 1) && (dummyY == dummyY2 - 1) && WhitePieces[i].checkKing())
								{
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									// Space not occupied: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(-50, 50);
										WhitePieces[i].setFillColor(sf::Color::Green);

										// Reallocate piece location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() + 50);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() - 50);

										// Update occupied board positions: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										moveOn = true;
									}
								}

								// Check if piece attacks as a king: 
								if ((dummyX == dummyX2 - 2) && (dummyY == dummyY2 - 2) && WhitePieces[i].checkKing())
								{
									// Piece is taken: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 - 1, dummyY2 - 1) != BLUE_PLAYER)
									{
										cout << "NO Whites here" << endl;
									}

									// Piece not taken: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(100, 100);
										WhitePieces[i].setFillColor(sf::Color::Green);

										// Set new piece location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() + 100);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() + 100);

										moveOn = true;

										// Update occupied board logic: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(BluePieces[enemy].getXLocation()) / 50 == (dummyX2 - 1)) &&
												(int(BluePieces[enemy].getYLocation()) / 50 == (dummyY2 - 1)))
											{
												// Get piece off the board: 
												BluePieces[enemy].move(500, 500);

												BluePieces[enemy].setXLocation(500);
												BluePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 - 1, dummyY2 - 1);
												gameBoard.setColor(dummyX2 - 1, dummyY2 - 1, NO_TOKEN);

												    // Has been added
													
												// Decrementing the number of token after being captured
												blue_num_token--;
											}
										}
									}
								}

								if ((dummyX == dummyX2 + 2) && (dummyY == dummyY2 - 2) && WhitePieces[i].checkKing())
								{
									// Tile occupied: 
									if (gameBoard.getOccupied(dummyX2, dummyY2))
									{
										cout << "This spot is taken!" << endl;
									}

									else if (gameBoard.getColor(dummyX2 + 1, dummyY2 - 1) != BLUE_PLAYER)
									{
										cout << "NO Whites here" << endl;
									}

									// Tile not occupied: 
									else
									{
										// Move piece: 
										WhitePieces[i].move(-100, 100);
										WhitePieces[i].setFillColor(sf::Color::Green);


										// Set new piece location: 
										WhitePieces[i].setYLocation(WhitePieces[i].getYLocation() + 100);
										WhitePieces[i].setXLocation(WhitePieces[i].getXLocation() - 100);

										moveOn = true;

										// Update tile occupied status: 
										gameBoard.setNotOccupied(dummyX, dummyY);
										gameBoard.setColor(dummyX, dummyY, NO_TOKEN);

										gameBoard.setOccupied(dummyX2, dummyY2);
										gameBoard.setColor(dummyX2, dummyY2, WHITE_PLAYER);

										for (int enemy = 0; enemy < 12; ++enemy)
										{
											if ((int(BluePieces[enemy].getXLocation()) / 50 == (dummyX2 + 1)) &&
												(int(BluePieces[enemy].getYLocation()) / 50 == (dummyY2 - 1)))
											{
												// Get piece off the board: 
												BluePieces[enemy].move(500, 500);

												BluePieces[enemy].setXLocation(500);
												BluePieces[enemy].setYLocation(500);

												gameBoard.setNotOccupied(dummyX2 + 1, dummyY2 - 1);
												gameBoard.setColor(dummyX2 + 1, dummyY2 - 1, NO_TOKEN);

												// Decrementing the number of token after being captured
												blue_num_token--;


											}
										}
									}
								}
							}

							//cout << dummyX2 << " " << dummyY2 << endl;
						}

						//cout << "Ended" << endl;

						// Switch user:
						playerTurn = BLUE_PLAYER;
					}
				}
			}
		}

		     // Start of Win and lose situation - Results

		if (white_num_token == 0)
		{
			// Also, if the number of token of a specific color is 0, then that color lost
			cout << "BLUE is the winner, White lost!" << endl;
		}
		else if (blue_num_token == 0)
		{
			cout << "WHITE is the winner, Blue lost!" << endl;
		}

		      // End of Win and lose situation - End of reults
		
		                 // Start of Win and lose situation - Results

		bool BlueGameOver = true, WhiteGameOver = true;

			  // The game over if either side has no piece remaining

		for (int i = 0; i < 12; i++)
		{
			// If there more are pieces of certain color off the board, then that color lost
			// Also, if the number of token of a specific color is 0, then that color lost

			if (white_num_token == 0 && (int(BluePieces[i].getXLocation()) == 500 &&
				int(BluePieces[i].getYLocation()) == 500) < (int(WhitePieces[i].getXLocation()) == 500 &&
					int(WhitePieces[i].getYLocation()) == 500))
			{
				BlueGameOver = false;   // Blue has less pieces off the board, so Blue wins
				                       // White has 0 token left on the board, so White loses
				cout << "BLUE is the winner, White lost!" << endl;
			}


			else if (blue_num_token == 0 && (int(BluePieces[i].getXLocation()) == 500 &&
				int(BluePieces[i].getYLocation()) == 500) > (int(WhitePieces[i].getXLocation()) == 500 && 
					int(WhitePieces[i].getYLocation()) == 500))
			{

				WhiteGameOver = false;  // Blue has more pieces off the board so loses, White wins
				                      // Blue has 0 token left on the board, so White wins
				cout << "WHITE is the winner, Blue lost!" << endl;
			}

		}

		        // End of Win and lose situation - End of reults


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
	}
}