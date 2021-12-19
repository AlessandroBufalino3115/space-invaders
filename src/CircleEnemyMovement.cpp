//
// Created by alexh on 3/4/2021.
//

#include "CircleEnemyMovement.h"
CircleEnemyMovement::CircleEnemyMovement(
  sf::Texture, std::string filename, int x, int y)
{
  sprite = new sf::Sprite();
  shoot_num = rand() % 25 + 1;
  cent_x = x - sprite->getGlobalBounds().width/2;
  cent_y = y - sprite->getGlobalBounds().height-5;

  this->radius = rand() % 100 + 40;

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(cent_x,cent_y);

}

void CircleEnemyMovement::movement()
{
  this->radians += this->speed;

  this->sprite->setPosition(cent_x + cos(radians) * radius,cent_y + sin(radians)*radius);
}
CircleEnemyMovement::~CircleEnemyMovement() {}
