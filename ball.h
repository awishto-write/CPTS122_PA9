#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape 
{
public: 
	//Ball(const sf::Vector2f& pos, const float &radius, const sf::Color& color) : 
		//sf::CircleShape(radius)
	//{
		//this->setFillColor(color); 
		//this->setPosition(pos); 
	//}
	
	
	                           // outlineThickness
	Ball(const float& radius, const sf::Color& color, const float& thickness) : 
		sf::CircleShape (radius)
	{
		this->setFillColor(color);
		this->setOutlineThickness(thickness);
		this->setOutlineColor(sf::Color::White);
	}


	// Draws Piece's member sf::CircleShape round.
	void draw(sf::RenderWindow& renderWindow) : sf::CircleShape(radius)
	{
		//renderWindow.draw(round);
		renderWindow.draw(radius);
	}


	// Repositionning the Pieces, without considering the outline thickness (i.e. the x and y
	// coordinates start at the actual shape, not the outline).

	void setPosition(const sf::Vector2f& newPosition) : sf::CircleShape(radius)
	{
		radius.setPosition(newPosition);
	}

	void setColor(const sf::Color& newColor) : sf::CircleShape(radius)
	{
		radius.setFillColor(newColor);
	}

	void setOutlineColor(const sf::Color& newColor) : sf::CircleShape(radius)
	{
		radius.setOutlineColor(newColor);
	}

	sf::CircleShape getCircle() 
	{
		return round;
	}

	sf::Vector2f getPosition() 
	{
		return round.getPosition();
	}


   /*private:
	sf::CircleShape round;*/
};
