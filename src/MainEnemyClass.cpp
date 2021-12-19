//
// Created by alexh on 2/24/2021.
//

#include "MainEnemyClass.h"
// at instantiate it creates a rnadmon number for it , then on every update a number i sent form the game,ccpp if the number matches it shoots
MainEnemyClass::~MainEnemyClass() {}
MainEnemyClass::MainEnemyClass() {}






 bool MainEnemyClass::shoot(int num)
{
  if (num == shoot_num)
    return true;
  else
    return false;
}


sf::Sprite* MainEnemyClass::getSprite()
{
  return sprite;
}

