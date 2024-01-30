#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "menu.h"
#include "function.h"

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
		Game game;


		                          // Start of Audio functionality
		sf::Music music;
		if (!music.openFromFile("Assets/music.ogg"))
			return -1;   // error
		music.play();    // Play the audio 

		//music.setPlayingOffset(sf::seconds(10));
		//music.setVolume(15);

		//music.pause();  // pause playback
		//music.play();    // Play the music again
		//music.stop();  // stop playback and rewind
		    
		                         // End of audio functionality
								  


		cout << "You can only click down for the menu." << endl;
		cout << "If you reach the last option, when you click 'down', you will be redirected at the top." << endl;

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
						// You have to press "enter" for it to work 
						// So use of actual keyboard, not a mouse

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

		system("cls");  // Clear the screen

		                     // Effectuate the user input
		switch (page_number)
		{
			case 0:    // The game option
			{
				sf::RenderWindow window_play(sf::VideoMode(400, 400), "Play", sf::Style::Close);
				//cout << "  The section for 'play' has been selected!" << endl;
				while (window_play.isOpen())
				{
					sf::Event event;
					while (window_play.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window_play.close();
					}

					window_play.clear();

					        // Put the game loop first
					game.game_loop();

					        // Display the winner image then
					menu.winnerImage(window_play);

					window_play.display();
				}

				break;
			}



			case 1:     // The instructions option

			{
				sf::RenderWindow window_play(sf::VideoMode(800, 800), "Instructions", sf::Style::Close);
				//cout << "  The section for 'instructions' has been selected!" << endl;
				while (window_play.isOpen())
				{
					sf::Event event;
					while (window_play.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window_play.close();
					}

					window_play.clear();

					    // Display the image for instructions
					menu.instructions_text(window_play);

					window_play.display();

				}

				break;

			}

			

		}  // end of the switch


			        // The exit option

		  if (page_number == 2)
	      {

			  sf::RenderWindow window_play(sf::VideoMode(500, 500), "EXIT", sf::Style::Close);
			  while (window_play.isOpen())
			  {
				  sf::Event event;
				  while (window_play.pollEvent(event))
				  {
					  if (event.type == sf::Event::Closed)
						  window_play.close();
				  }

				  window_play.clear();

				       // Display the image for saying bye
				  menu.byeImage(window_play);

				  window_play.display();

			  }

			     // After closing the window, the message below appears and you exit

	   	      cout << "Thank you for passing by!" << endl << endl;
	   	      cout << "   Butch was happy to see you! " << endl;
	          break;
	      }


	}

	return 0;
}

