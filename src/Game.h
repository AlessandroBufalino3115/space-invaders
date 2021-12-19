#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "BasicEnemyMovement.h"
#include "BulletsObj.h"
#include "PlayerObj.h"
#include "ShieldObj.h"
#include "StrafingEnemyMovement.h"
#include "CircleEnemyMovement.h"
#include "SinEnemyMovement.h"
#include "MeteorEnemyClass.h"
#include "QuadraticEnemyMovement.h"
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <iostream>


using namespace std;

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();

  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void mousePos(sf::Event event);
  void collisionCheck();

  void moveSprites();
  void resetPlayer();

  sf::Texture enemy_ship_texture;
  sf::Texture player_ship_texture;

 private:

  std::string fileName = "Data/Images/SpaceShooterRedux/PNG/Enemies/enemyBlue1.png";
  sf::RenderWindow& window;

  sf::Texture game_background;
  sf::Sprite background;

  PlayerObj* player_ship;
  std::vector<BulletsObj*> bullets;

  std::string shield_text[3] = {"Data/Images/Alien UFO pack/PNG/shipGreen_damage2.png","Data/Images/Alien UFO pack/PNG/shipGreen_damage1.png","Data/Images/Alien UFO pack/PNG/shipGreen.png"};
  std::string *pointer_shield_text = shield_text;

  ShieldObj* shields[3] = {new ShieldObj(pointer_shield_text, int(window.getSize().x/4), int(window.getSize().y-100), 3),
                           new ShieldObj(pointer_shield_text, int(window.getSize().x/2), int(window.getSize().y -100), 3),
                           new ShieldObj(pointer_shield_text, int((3 * window.getSize().x)/4), int(window.getSize().y -100) , 3)} ;


  BasicEnemyMovement test[32] = {{ enemy_ship_texture,fileName, 2,0},{ enemy_ship_texture,fileName, 3,0},{ enemy_ship_texture,fileName, 4,0},{ enemy_ship_texture,fileName, 5,0},{ enemy_ship_texture,fileName, 6,0},{ enemy_ship_texture,fileName, 7,0},{ enemy_ship_texture,fileName, 8,0},{ enemy_ship_texture,fileName, 9,0}
                                  ,{ enemy_ship_texture,fileName, 2,1},{ enemy_ship_texture,fileName, 3,1},{ enemy_ship_texture,fileName, 4,1},{ enemy_ship_texture,fileName, 5,1},{ enemy_ship_texture,fileName, 6,1},{ enemy_ship_texture,fileName, 7,1},{ enemy_ship_texture,fileName, 8,1},{ enemy_ship_texture,fileName, 9,1}
                                  ,{ enemy_ship_texture,fileName, 2,2},{ enemy_ship_texture,fileName, 3,2},{ enemy_ship_texture,fileName, 4,2},{ enemy_ship_texture,fileName, 5,2},{ enemy_ship_texture,fileName, 6,2},{ enemy_ship_texture,fileName, 7,2},{ enemy_ship_texture,fileName, 8,2},{ enemy_ship_texture,fileName, 9,2}
                                  ,{ enemy_ship_texture,fileName, 2,3},{ enemy_ship_texture,fileName, 3,3},{ enemy_ship_texture,fileName, 4,3},{ enemy_ship_texture,fileName, 5,3},{ enemy_ship_texture,fileName, 6,3},{ enemy_ship_texture,fileName, 7,3},{ enemy_ship_texture,fileName, 8,3},{ enemy_ship_texture,fileName, 9,3}
  };
  int size_norm_arr = sizeof(test)/sizeof(*test);

  std::vector<QuadraticEnemyMovement*> quadratic_vector_container;
  std::vector<MeteorEnemyClass*> meteor_vector_container;
  std::vector<SinEnemyMovement*> sin_vector_container;
  std::vector<CircleEnemyMovement*> circle_vector_container;
  std::vector<StrafingEnemyMovement*> strafing_vector_container;


  sf::Font font;

  sf::Text start_text_menu; // menu text
  sf::Text description_text_menu;
  sf::Text enemy_choice_text_menu;

  sf::Text description_text_choice;
  sf::Text return_text_choice;
  sf::Text strafing_text_choice;
  sf::Text quadratic_text_choice;
  sf::Text circle_text_choice;
  sf::Text meteor_text_choice;
  sf::Text normal_text_choice;
  sf::Text sin_text_choice;

  sf::Text score_display;  // in game text
  sf::Text life_display;

  sf::Text game_ending_description; //description of how the game ended
  sf::Text game_ending_menu;

  sf::Clock Shoot_clock;
  sf::Clock spawn_clock;
  sf::Time move_call_normal_enemies = sf::seconds(1);
  sf::Time enemy_fire_rate = sf::seconds(1);
  sf::Time spawn_rate = sf::seconds(5);

  enum CurrentScreen //different states of the screen
  {
    MAIN_MENU_SCREEN = 0,
    ENEMY_TYPE_SCREEN,
    GAME_SCREEN,
    END_SCREEN
  };

  CurrentScreen current_screen = MAIN_MENU_SCREEN;

  enum EnemyType
  {
    NORMAL = 0,
    STRAFING,
    CIRCLE,
    SIN,
    METEOR,
    QUADRATIC
  };

  EnemyType current_enemy_type = NORMAL;

  bool end_game = false;
  bool moving_left = true;
  int player_score = 0;
  int player_lives = 0;
  sf::Clock player_clock;
  sf::Time player_fire_rate = sf::seconds(0.0001f);
  bool can_fire;

};

#endif // SPACEINVADERS_GAME_H
