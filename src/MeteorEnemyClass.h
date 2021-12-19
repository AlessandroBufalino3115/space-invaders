//
// Created by alexh on 3/4/2021.
//

#ifndef SPACEINVADERSSFML_METEORENEMYCLASS_H
#define SPACEINVADERSSFML_METEORENEMYCLASS_H

#include "MainEnemyClass.h"
#include "Vector2.h"
#include <math.h>

class MeteorEnemyClass : public MainEnemyClass
{
 public:
  MeteorEnemyClass();
  ~MeteorEnemyClass();

  MeteorEnemyClass(sf::Texture, std::string filename, int x, int y);

  void movement(float dt);

  float cent_x;
  float cent_y;

  float dt_total = 0;
  float speed = 0.0000003;
};

#endif // SPACEINVADERSSFML_METEORENEMYCLASS_H
