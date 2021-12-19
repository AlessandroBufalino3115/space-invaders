//
// Created by alexh on 2/24/2021.
//

#ifndef SPACEINVADERSSFML_BASICENEMYMOVEMENT_H
#define SPACEINVADERSSFML_BASICENEMYMOVEMENT_H

#include "MainEnemyClass.h"

class BasicEnemyMovement : public MainEnemyClass //inheriting hp and get sprite
{
 public:
  BasicEnemyMovement();
  ~BasicEnemyMovement();
  BasicEnemyMovement(sf::Texture, std::string filename, int x, int y);

  void Move(int dir, int down);
  void reset();

  int coloumn;
  int row;

  int initial_coloum;
  int initial_row;


 private:


};

#endif // SPACEINVADERSSFML_BASICENEMYMOVEMENT_H
