//
// Created by alexh on 3/4/2021.
//

#ifndef SPACEINVADERSSFML_SINENEMYMOVEMENT_H
#define SPACEINVADERSSFML_SINENEMYMOVEMENT_H

#include "MainEnemyClass.h"
#include "Vector2.h"
#include <math.h>

class SinEnemyMovement : public MainEnemyClass
{
 public:
  SinEnemyMovement();
  ~SinEnemyMovement();

  SinEnemyMovement(sf::Texture, std::string filename, int x, int y);

  void movement();

  float cent_x;
  float cent_y;

  bool dir = false;
  Vector2 direction = {0,0};
  float speed = 0.05;
  float radians = 0;





};

#endif // SPACEINVADERSSFML_SINENEMYMOVEMENT_H
