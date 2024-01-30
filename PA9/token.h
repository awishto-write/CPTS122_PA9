#pragma once

#include <SFML/Graphics.hpp>

class Token : public sf::CircleShape
{
private:
	bool mIsActive;
	double mXPos;
	double mYPos;
	bool mKing;


public:


	Token(const sf::Vector2f& pos = sf::Vector2f(25, 25), const double& radius = 15, const sf::Color& color = sf::Color::White) :
		sf::CircleShape(radius)
	{
		this->setPosition(pos);
		this->setRadius(radius);
		this->setFillColor(color);
		this->mKing = false;
	}

	void setNewFillColor(sf::Color newColor);

	double getXLocation(void);
	double getYLocation(void);

	void setXLocation(double newXLocation);
	void setYLocation(double newYLocation);
	void setKing(void);

	bool checkKing(void);

};



