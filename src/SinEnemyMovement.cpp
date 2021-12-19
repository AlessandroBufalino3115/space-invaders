//
// Created by alexh on 3/4/2021.
//

#include "SinEnemyMovement.h"
SinEnemyMovement::SinEnemyMovement(sf::Texture, std::string filename, int x, int y)
{

  sprite = new sf::Sprite();

  cent_x = x - sprite->getGlobalBounds().width/2;
  cent_y = y - sprite->getGlobalBounds().height-5;

  shoot_num = rand() % 25 + 1;

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(cent_x,cent_y);

}
void SinEnemyMovement::movement()
{
  this->radians += this->speed;

  if (this->sprite->getPosition().x <= 0)
  {
    dir = true;
  }
  else if (this->sprite->getPosition().x + this->sprite->getGlobalBounds().width >= 1320)
  {
    dir = false;
  }

  if (dir)
  {
    this->sprite->setPosition(this->sprite->getPosition().x +1,cent_y + sin(radians)*30);
  }
  else
  {
    this->sprite->setPosition(this->sprite->getPosition().x -1,cent_y + sin(radians)*30);
  }
}
SinEnemyMovement::~SinEnemyMovement() {}
