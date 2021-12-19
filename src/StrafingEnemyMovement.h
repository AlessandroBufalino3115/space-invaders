//
// Created by alexh on 3/3/2021.
//

#ifndef SPACEINVADERSSFML_STRAFINGENEMYMOVEMENT_H
#define SPACEINVADERSSFML_STRAFINGENEMYMOVEMENT_H

#include "MainEnemyClass.h"
#include "Vector2.h"
#include <math.h>

class StrafingEnemyMovement : public MainEnemyClass
{
 public:
  StrafingEnemyMovement();
  ~StrafingEnemyMovement();

  float cent_x;

  int range;
  float cent_y;

  float speed = 0.01;
  float radians = 0;

  void movement();

  StrafingEnemyMovement(sf::Texture, std::string filename,float window_size_x , int y, int Range);
};

#endif // SPACEINVADERSSFML_STRAFINGENEMYMOVEMENT_H
