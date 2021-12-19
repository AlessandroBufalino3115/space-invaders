//
// Created by alexh on 2/24/2021.
//

#ifndef SPACEINVADERSSFML_MAINFRIENDLYCLASS_H
#define SPACEINVADERSSFML_MAINFRIENDLYCLASS_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <iostream>
using namespace std;

class MainFriendlyClass
{
 public:
  MainFriendlyClass();
  ~MainFriendlyClass();
  sf::Sprite* getSprite();

  bool dead = false;
  sf::Sprite *sprite;
  sf::Texture texture;


 private:
};

#endif // SPACEINVADERSSFML_MAINFRIENDLYCLASS_H
