#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "menu.h"

using std::cout;
using std::endl;
int page_number;

int main(void)
{
	while (true)   // We use that option because the exit section does not accept "break" in a for-loop
	{
		// Initialize variables: 
		sf::RenderWindow window(sf::VideoMode(500, 500), "Checkers!", sf::Style::Close);

		Menu menu(500, 500);

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


				// Key has been released
				if (event.type == sf::Event::KeyReleased)
				{
					// You have to go up for it to work, with use of actual keyboard, not a mouse
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.moveUp();
						break;
					}
					// You have to down for it to work, with use of actual keyboard, not a mouse
					if (event.key.code == sf::Keyboard::Down)
					{
						menu.moveDown();
						break;
					}

					// Chosing pages: options

					if (event.key.code == sf::Keyboard::Return)
						// You have to press "enter" for it to work  // So use of actual keyboard, not a mouse

					{
						if (menu.option_selected() == 0)   // Play
						{
							window.close();
							page_number = 0;
						}

						if (menu.option_selected() == 1)   // Instructions
						{
							window.close();
							page_number = 1;
						}

						if (menu.option_selected() == 2)     // Exit
						{
							window.close();
							page_number = 2;
						}

					}

				}

			}

			// Window commands: 
			window.clear();
			menu.display_background(window);
			menu.draw(window);
			window.display();
		}


		// Probabaly use a switch statement for the page number

// Playing the game

/*switch (page_number)
{
  case 0:

	  sf::RenderWindow window_play(sf::VideoMode(500, 500), "Play", sf::Style::Close);

	  while (window_play.isOpen())
	  {
		  sf::Event event;
		  while (window_play.pollEvent(event))
		  {
			  if (event.type == sf::Event::Closed)
				  window_play.close();
		  }

		  window_play.clear();
		  window_play.display();
	  }

	  break;*/

	  // case 1:

		  // sf::RenderWindow window_play(sf::VideoMode(500, 500), "Instructions", sf::Style::Close);

		  // while (window_play.isOpen())
		  // {
			 //  sf::Event event;
			 //  while (window_play.pollEvent(event))
			 //  {
			 //	  if (event.type == sf::Event::Closed)
			 //		  window_play.close();
			 //  }

			 //  window_play.clear();

			 //  // infinte loop of course
			 //  cout << "  The section for 'instructions' has been selected!" << endl;

			 //  // Try to drag the image here instead of a function, then try other options

			 //  menu.instructions_text(window_play);

			 //  window_play.display();

		  // }

		  // break;

	   //case 2:
		  // cout << "Thank you for passing by!" << endl << endl;
		  // cout << "   Butch was happy to see you! " << endl;
		  // break;
	 //}

		if (page_number == 0)
		{
			sf::RenderWindow window_play(sf::VideoMode(500, 500), "Play", sf::Style::Close);

			while (window_play.isOpen())
			{
				sf::Event event;
				while (window_play.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window_play.close();
				}

				window_play.clear();
				window_play.display();
			}
		}

		// Instructions for the game

		if (page_number == 1)
		{
			sf::RenderWindow window_play(sf::VideoMode(500, 500), "Instructions", sf::Style::Close);

			while (window_play.isOpen())
			{
				sf::Event event;
				while (window_play.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window_play.close();
				}

				window_play.clear();

				// infinte loop of course
				cout << "  The section for 'instructions' has been selected!" << endl;

				// Try to drag the image here instead of a function, then try other options

				menu.instructions_text(window_play);

				window_play.display();

				//break;
			}


		}

		// Exit

		if (page_number == 2)
		{
			cout << "Thank you for passing by!" << endl << endl;
			cout << "   Butch was happy to see you! " << endl;
			break;
		}

	}

	return 0;
}
