//
// Created by alexh on 2/24/2021.
//

#include "ShieldObj.h"
ShieldObj::~ShieldObj()
{
  printf ("this is deleted");
}
ShieldObj::ShieldObj()
{
  sprite = new sf::Sprite();
}

ShieldObj::ShieldObj(std::string *textures, int x, int y, int HP)
{
  sprite = new sf::Sprite();
  texture_bank = textures;
  hp = HP;

  if (!texture.loadFromFile(*(texture_bank + hp-1)))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(x - sprite->getGlobalBounds().width/2,y - sprite->getGlobalBounds().height-5);
}

void ShieldObj::onHit()
{
  hp--;

  if (hp == 0)
  {
    this->dead = true;
  }
  else
  {
    if (!texture.loadFromFile(*(texture_bank + hp-1)))
    {
      printf("ball not balling filename");
    }
    sprite->setTexture(texture);
  }
}

void ShieldObj::reset()
{
  dead = false;
  hp = 3;
  if (!texture.loadFromFile(*(texture_bank + hp-1)))
  {
    printf("ball not balling filename");
  }
  sprite->setTexture(texture);


}

