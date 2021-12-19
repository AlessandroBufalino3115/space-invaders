//
// Created by alexh on 2/24/2021.
//

#include "BasicEnemyMovement.h"

BasicEnemyMovement::BasicEnemyMovement()
{
  sprite = new sf::Sprite();
}
BasicEnemyMovement::~BasicEnemyMovement()
{
  cout << "deleted basic movement" << endl;
}
BasicEnemyMovement::BasicEnemyMovement(sf::Texture, std::string filename, int x, int y)
{
  shoot_num = rand() % 25 + 1;

  coloumn = x;
  row = y;
  initial_coloum = x;
  initial_row = y;

  sprite = new sf::Sprite();

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(sprite->getGlobalBounds().width * x, sprite->getGlobalBounds().height * y);
}



void BasicEnemyMovement::Move(int dir, int down)
{
  coloumn += dir;
  row += down;
  sprite->setPosition(sprite->getGlobalBounds().width * coloumn, sprite->getGlobalBounds().height * row);
}

void BasicEnemyMovement::reset()
{
  coloumn = initial_coloum;
  row = initial_row;
  dead = false;
}
