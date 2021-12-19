//
// Created by alexh on 3/3/2021.
//

#include "StrafingEnemyMovement.h"
StrafingEnemyMovement::StrafingEnemyMovement() {}
StrafingEnemyMovement::~StrafingEnemyMovement() {}

StrafingEnemyMovement::StrafingEnemyMovement(sf::Texture, std::string filename,float window_size_x, int y, int Range)
{
  sprite = new sf::Sprite();

  range = Range;
  shoot_num = rand() % 25 + 1;
  cent_x = window_size_x - sprite->getGlobalBounds().width/2;
  cent_y = y - sprite->getGlobalBounds().height;

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(cent_x,cent_y);
}

void StrafingEnemyMovement::movement()
{
    this->radians += this->speed;
    this->cent_y += 0.01;

    this->sprite->setPosition(cent_x + cos(radians) * range, cent_y);
}
