//
// Created by alexh on 2/24/2021.
//

#ifndef SPACEINVADERSSFML_PLAYEROBJ_H
#define SPACEINVADERSSFML_PLAYEROBJ_H

#include "MainFriendlyClass.h"

class PlayerObj : public MainFriendlyClass
{
 public:
  PlayerObj();
  ~PlayerObj();
  PlayerObj(sf::Texture, std::string filename, int x, int y);


  Vector2 direction = {0,0};
  float speed = 175;

};

#endif // SPACEINVADERSSFML_PLAYEROBJ_H
