//
// Created by alexh on 2/24/2021.
//

#ifndef SPACEINVADERSSFML_MAINENEMYCLASS_H
#define SPACEINVADERSSFML_MAINENEMYCLASS_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <iostream>
using namespace std;

class MainEnemyClass
{
 public:
  MainEnemyClass();
  ~MainEnemyClass();

  sf::Sprite* getSprite();

  bool shoot(int num);

  bool dead = false;
  sf::Sprite *sprite;
  sf::Texture texture;

  int shoot_num ;


};

#endif // SPACEINVADERSSFML_MAINENEMYCLASS_H
