//
// Created by alexh on 3/4/2021.
//

#ifndef SPACEINVADERSSFML_QUADRATICENEMYMOVEMENT_H
#define SPACEINVADERSSFML_QUADRATICENEMYMOVEMENT_H

#include "MainEnemyClass.h"
#include "Vector2.h"
#include <math.h>


class QuadraticEnemyMovement : public MainEnemyClass
{

 public:

  QuadraticEnemyMovement();
  ~QuadraticEnemyMovement();

  QuadraticEnemyMovement(sf::Texture, std::string filename, int x, int y, int screen_width);


  void movement(float dt);

  float cent_x;
  float cent_y;

  int midd_x = 1320 /2;
  int screen_width_x=0;
  Vector2 direction = {1,0};
  float speed = 150;
  
};

#endif // SPACEINVADERSSFML_QUADRATICENEMYMOVEMENT_H
