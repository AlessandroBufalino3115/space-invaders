//
// Created by alexh on 2/24/2021.
//

#include "PlayerObj.h"

PlayerObj::~PlayerObj() {}
PlayerObj::PlayerObj() {}



PlayerObj::PlayerObj(sf::Texture, std::string filename, int x, int y)
{

  sprite = new sf::Sprite();

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(x - sprite->getGlobalBounds().width/2,y - sprite->getGlobalBounds().height-5);
}

