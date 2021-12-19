//
// Created by alexh on 2/27/2021.
//

#include "BulletsObj.h"
BulletsObj::BulletsObj()
{

}

BulletsObj::~BulletsObj()
{
    printf ("destroyd bullet");
}

BulletsObj::BulletsObj(bool Friendly,int x, int y)
{
  friendly = Friendly;

  sprite = new sf::Sprite();


  if (!texture.loadFromFile("Data/Images/Alien UFO pack/PNG/laserBeige1.png"))
  {
    printf("ball not balling filename");
  }
  sprite->setTexture(texture);
  sprite->setScale(0.4,0.4);
  sprite->setPosition(x - sprite->getGlobalBounds().width/2, y - sprite->getGlobalBounds().height);


  if (!friendly)
  {
    this->direction.y = 1;
  }
  else
  {
    this->direction.y = -1;
  }
}

bool BulletsObj::changeTexture()//call change texture all the time till gone
{
  if (!to_destroy)
  {
    clock.restart();
    to_destroy = true;
    this->direction.y = 0;

    if (!texture.loadFromFile("Data/Images/Alien UFO pack/PNG/laserBeige_burst.png"))
    {
      printf("ball not balling filename");
    }
    sprite->setTexture(texture, true);
    sprite->setPosition(sprite->getPosition().x - (sprite->getGlobalBounds().width/2), sprite->getPosition().y - (sprite->getGlobalBounds().height/2));

  }
  else
  {
    sf::Time elapsed1 = clock.getElapsedTime();
    if (elapsed1 > second)
    {
      delete this;
      return true;
    }
  }

  return false;

}
