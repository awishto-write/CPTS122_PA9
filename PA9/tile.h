#pragma once

#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape
{
public:

	Tile(const sf::Vector2f& pos = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(50, 50), const sf::Color& color = sf::Color::Black) :
		sf::RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
		this->setSize(size);
	}


	// Setters: 
	void setColor(sf::Color& color)
	{
		this->setFillColor(color);
	}

	void setPos(sf::Vector2f& pos)
	{
		this->setPosition(pos);
	}
};

    