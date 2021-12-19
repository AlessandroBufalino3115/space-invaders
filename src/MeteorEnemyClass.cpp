//
// Created by alexh on 3/4/2021.
//

#include "MeteorEnemyClass.h"
MeteorEnemyClass::~MeteorEnemyClass()
{
  cout << "destroy metero"<< endl;
}



MeteorEnemyClass::MeteorEnemyClass(sf::Texture, std::string filename, int x, int y)
{
  sprite = new sf::Sprite();

  cent_x = x - sprite->getGlobalBounds().width/2;
  cent_y = y - sprite->getGlobalBounds().height-5;

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(cent_x,cent_y);
}



void MeteorEnemyClass::movement(float dt)
{
  dt_total += dt;

  this->speed += 0.5f * pow(dt_total,2);

  this->sprite->move(0,this->speed*dt);
}

