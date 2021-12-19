//
// Created by alexh on 2/24/2021.
//

#ifndef SPACEINVADERSSFML_SHIELDOBJ_H
#define SPACEINVADERSSFML_SHIELDOBJ_H

#include <string>
#include "MainFriendlyClass.h"
class ShieldObj : public MainFriendlyClass
{

 public:
  ShieldObj(std::string *textures, int x, int y, int HP);
  ShieldObj();
  ~ShieldObj();

  void onHit ();
  void reset();

  int hp = 0;

 private:
  std::string *texture_bank;

};

#endif // SPACEINVADERSSFML_SHIELDOBJ_H
