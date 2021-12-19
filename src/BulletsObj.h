//
// Created by alexh on 2/27/2021.
//

#ifndef SPACEINVADERSSFML_BULLETSOBJ_H
#define SPACEINVADERSSFML_BULLETSOBJ_H

#include "MainFriendlyClass.h"

class BulletsObj : public MainFriendlyClass
{



 public:


  BulletsObj();
  ~BulletsObj();
  BulletsObj(bool Friendly,int x, int y);
  bool changeTexture();

  sf::Clock clock;
  sf::Time second = sf::seconds(0.5);

  sf::Time TOI;


  bool to_destroy= false;

  bool friendly;

  Vector2 direction = {0,0};
  float speed = 500;




};

#endif // SPACEINVADERSSFML_BULLETSOBJ_H
