#pragma once

#include <SFML/Graphics.hpp>

       // As you can see, I failed using inheritance with ''class Ball : public sf::CircleShape'' 
    // Any ideas to how to use that instead of the one below?  

class Ball 
{ 
  public:


      float radius = 16;
      int x, y;
      bool isAlive;
      bool isKing = false;
      sf::Color color;
    
      void Draw(sf::RenderWindow& window)
      {
         
          if (isAlive)
          {
              sf::CircleShape rounds(radius);
              rounds.setFillColor(color);

              if (isKing)
              {

                  rounds.setOutlineThickness(2.f);
                  rounds.setOutlineColor(sf::Color::Yellow);
              }
                             // Because the size of a square of box is 50
              rounds.setPosition(sf::Vector2f(x * 50 + (50 - radius * 2) / 2, y * 50
                  + (50 - 2 * radius) / 2));

              window.draw(rounds);
          }
      }
};
