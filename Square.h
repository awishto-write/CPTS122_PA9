#pragma once

#include <SFML/Graphics.hpp>

                 // 32 squares for the 8X8 board   // We want it to static 
             // different color each other square

class Square : public sf::SquareShape
{
public:
	Square(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) :
		sf::SquareShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

};
