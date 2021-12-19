//
// Created by alexh on 3/4/2021.
//

#ifndef SPACEINVADERSSFML_CIRCLEENEMYMOVEMENT_H
#define SPACEINVADERSSFML_CIRCLEENEMYMOVEMENT_H

#include "MainEnemyClass.h"
#include "Vector2.h"
#include <math.h>


class CircleEnemyMovement :  public MainEnemyClass
{
 public:
  CircleEnemyMovement();
  ~CircleEnemyMovement();

  CircleEnemyMovement(sf::Texture, std::string filename, int x, int y);

  void movement();

  float cent_x;
  float cent_y;

  int radius;
  float speed = 0.05;
  float radians = 0;

};

#endif // SPACEINVADERSSFML_CIRCLEENEMYMOVEMENT_H
