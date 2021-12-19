#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window): window(game_window)
{
  srand(time(NULL));
}
Game::~Game() {}

bool Game::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))  //loading font

#pragma region setstring

  life_display.setString("Lives left:");
  life_display.setFillColor(sf::Color(255,255,255,140));
  life_display.setFont(font);
  life_display.setCharacterSize(20);
  life_display.setPosition(0, window.getSize().y - 200);


  score_display.setFillColor(sf::Color(255,255,255,140));
  score_display.setFont(font);
  score_display.setCharacterSize(20);
  score_display.setString("your score");
  score_display.setPosition(window.getSize().x/2 - (score_display.getGlobalBounds().width/2), window.getSize().y - 200);

  //---------------------------------------------------------------------------------------------------------------------------------------

  if (!game_background.loadFromFile("Data/Images/SpaceShooterRedux/Backgrounds/blue.png")){}

  background.setTexture(game_background);
  background.setPosition(0,0);
  background.setScale(6,4);

  start_text_menu.setString("Click on me to start the normal game");
  start_text_menu.setFillColor(sf::Color(255,255,255,255));
  start_text_menu.setFont(font);
  start_text_menu.setCharacterSize(20);
  start_text_menu.setPosition(window.getSize().x/2 - start_text_menu.getGlobalBounds().width/2, window.getSize().y/8);

  enemy_choice_text_menu.setString("Choose the enemies to go against");
  enemy_choice_text_menu.setFillColor(sf::Color(255,255,255,255));
  enemy_choice_text_menu.setFont(font);
  enemy_choice_text_menu.setCharacterSize(20);
  enemy_choice_text_menu.setPosition(window.getSize().x/2 - enemy_choice_text_menu.getGlobalBounds().width/2, window.getSize().y/3);

  description_text_menu.setString("                                           Use the mouse to select things\n\n"
                                  "    You can press the 'Esc' key to come back to the main menu at any time\n\n"
                                  "                                                           You have 3 lives \n\n"
                                  "                    Choose the type of enemy you would like to go against,\n"
                                  "                       Otherwise press start game to go start from the top");
  description_text_menu.setFillColor(sf::Color(255,255,255,255));
  description_text_menu.setFont(font);
  description_text_menu.setCharacterSize(20);
  description_text_menu.setPosition(window.getSize().x/2 - description_text_menu.getGlobalBounds().width / 2, window.getSize().y/2 + description_text_menu.getGlobalBounds().height/2);

  //-------------------------------------------------------------------------------------------------------------------

  description_text_choice.setString("Choose what kind of enemies you want to face");
  description_text_choice.setFillColor(sf::Color(255,255,255,255));
  description_text_choice.setFont(font);
  description_text_choice.setCharacterSize(20);
  description_text_choice.setPosition(window.getSize().x/2 - description_text_choice.getGlobalBounds().width/2, window.getSize().y/8 - description_text_choice.getGlobalBounds().height);

  normal_text_choice.setString("                                                              Normal enemies \ntypical arcade style moving enemies, the more you kill the faster the they will move");
  normal_text_choice.setFillColor(sf::Color(255,255,255,255));
  normal_text_choice.setFont(font);
  normal_text_choice.setCharacterSize(20);
  normal_text_choice.setPosition(window.getSize().x/2 - 420, 300 - normal_text_choice.getGlobalBounds().height);

  strafing_text_choice.setString("                                                              Strafing enemies \nSlowly descending enemies which strafe from left to right while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
  strafing_text_choice.setFillColor(sf::Color(255,255,255,255));
  strafing_text_choice.setFont(font);
  strafing_text_choice.setCharacterSize(20);
  strafing_text_choice.setPosition(window.getSize().x/2 - 420, 400 - strafing_text_choice.getGlobalBounds().height);

  sin_text_choice.setString("                                                              Undulating enemies \nEnemies that go up and down while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
  sin_text_choice.setFillColor(sf::Color(255,255,255,255));
  sin_text_choice.setFont(font);
  sin_text_choice.setCharacterSize(20);
  sin_text_choice.setPosition(window.getSize().x/2 - 420, 500 - sin_text_choice.getGlobalBounds().height);

  quadratic_text_choice.setString("                                                              Swinging enemies \nEnemies that move in a pendulum swinging pattern while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
  quadratic_text_choice.setFillColor(sf::Color(255,255,255,255));
  quadratic_text_choice.setFont(font);
  quadratic_text_choice.setCharacterSize(20);
  quadratic_text_choice.setPosition(window.getSize().x/2 - 420, 600 - quadratic_text_choice.getGlobalBounds().height);

  circle_text_choice.setString("                                                              Circling enemies \nEnemies that circle around a spot while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
  circle_text_choice.setFillColor(sf::Color(255,255,255,255));
  circle_text_choice.setFont(font);
  circle_text_choice.setCharacterSize(20);
  circle_text_choice.setPosition(window.getSize().x/2 - 420, 700 - circle_text_choice.getGlobalBounds().height);

  meteor_text_choice.setString("                                                        Meteor mode \nEnemies come down like meteors, kill them before they reach your base");
  meteor_text_choice.setFillColor(sf::Color(255,255,255,255));
  meteor_text_choice.setFont(font);
  meteor_text_choice.setCharacterSize(20);
  meteor_text_choice.setPosition(window.getSize().x/2 - 420, 800 - meteor_text_choice.getGlobalBounds().height);

  return_text_choice.setString("Return to the menu (Esc)");
  return_text_choice.setFillColor(sf::Color(255,255,255,255));
  return_text_choice.setFont(font);
  return_text_choice.setCharacterSize(20);
  return_text_choice.setPosition(window.getSize().x/2 - return_text_choice.getGlobalBounds().width / 2, 850 - return_text_choice.getGlobalBounds().height);

  //-------------------------------------------------------------------------------------------------------------------

  game_ending_description.setString("this is a description for the end");
  game_ending_description.setFillColor(sf::Color(255,255,255,255));
  game_ending_description.setFont(font);
  game_ending_description.setCharacterSize(20);
  game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);

  game_ending_menu.setString("Go back to the menu");
  game_ending_menu.setFillColor(sf::Color(255,255,255,255));
  game_ending_menu.setFont(font);
  game_ending_menu.setCharacterSize(20);
  game_ending_menu.setPosition(window.getSize().x/2 - game_ending_menu.getGlobalBounds().width/2, window.getSize().y/1.5);

#pragma endregion

  player_ship = new PlayerObj(player_ship_texture,"Data/Images/SpaceShooterRedux/PNG/playerShip1_red.png",  window.getSize().x/2, window.getSize().y);
  resetPlayer();
  return true;
}

void Game::update(float dt)
{
  sf::Time enemy_fire_timer = Shoot_clock.getElapsedTime();
  sf::Time spawner_timer = spawn_clock.getElapsedTime();

  player_ship->getSprite()->move(
    player_ship->direction.x * player_ship->speed * dt,
    player_ship->direction.y * player_ship->speed * dt);
  end_game = true;
  int largest = 0;

  if (!can_fire)    //fire rate timer
  {
    sf::Time friendly_timer = player_clock.getElapsedTime();

    if (friendly_timer > player_fire_rate )
      can_fire = true;
  }




#pragma region Loosing conditions
  if (player_lives == 0 && current_enemy_type != METEOR)
  {
    game_ending_description.setString("Your ship took too much damage and was destroyed. Your final score was " + to_string(player_score));
    game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);
    current_screen = END_SCREEN;
    resetPlayer();
  }
  else if (player_lives == 0 && current_enemy_type == METEOR)
  {
    game_ending_description.setString("You let too many ships pass you by, the base has now been destroyed. Your final score was " + to_string(player_score));
    game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);
    current_screen = END_SCREEN;
    resetPlayer();
  }
#pragma endregion

  score_display.setString("Your score " + to_string(player_score));
  score_display.setPosition(0, window.getSize().y - 200);

  life_display.setString("Lives left: "+ to_string(player_lives));
  life_display.setPosition(0, window.getSize().y - 150);

  switch(current_screen)
  {
    case GAME_SCREEN:

      switch (current_enemy_type)
      {
        case NORMAL:

          if (enemy_fire_timer > move_call_normal_enemies)  // timer for the movement
          {
            Shoot_clock.restart();
            moveSprites();

            for (int i = 0; i < size_norm_arr; i++)
            {
              if (!test[i].dead)
              {
                end_game = false;
                if (test[i].shoot((rand() % 25 + 1)))
                  bullets.push_back(new BulletsObj(false,test[i].getSprite()->getPosition().x +(test[i].getSprite()->getGlobalBounds().width / 2),test[i].getSprite()->getPosition().y));

                if(largest < test[i].row) //finding the y coord of the lowest alien
                  largest = test[i].row;
              }
            }

            if (largest == 8)  // depending on the lowest alien the player looses the shields or the game
            {
              for (auto & shield : shields)
              {
                while (!shield->dead)
                {
                  shield->onHit();
                }
              }
            }
            else if (largest == 9)
            {
              game_ending_description.setString("The aliens reached your ship and you couldn't escape fast enough. Your final score was " + to_string(player_score));
              game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);
              current_screen = END_SCREEN;
              resetPlayer();
            }

            if (end_game)   // if all the enemies have been defeated
            {
              end_game = false;
              game_ending_description.setString("You won wowoww, you defeated all of the aliens. Your final score was " + to_string(player_score));
              game_ending_description.setPosition(window.getSize().x/2 - game_ending_description.getGlobalBounds().width/2, window.getSize().y/6);
              current_screen = END_SCREEN;
              resetPlayer();
            }
          }
          break;


        case STRAFING:

          if (spawner_timer > spawn_rate)   //timer for the spawn of the new enemy of the specific type
          {
            spawn_clock.restart();
            strafing_vector_container.push_back(new StrafingEnemyMovement(enemy_ship_texture,fileName, window.getSize().x/2,rand() % 150 + 50, rand() % 500 + 50));
            spawn_rate *= 0.95f;
          }

          if (enemy_fire_timer > enemy_fire_rate)  // fire rate of the enemy
          {
            Shoot_clock.restart(); // every move_call_normal_enemies timer

            for (auto & i : strafing_vector_container)
            {
              if (i->shoot((rand() % 25 + 1)))
              {
                bullets.push_back(new BulletsObj(false,i->getSprite()->getPosition().x +(i->getSprite()->getGlobalBounds().width / 2),i->getSprite()->getPosition().y));
              }
            }
          }

          for (auto & i : strafing_vector_container)   // call for movement function in enemy script
          {
            i->movement();
          }
          break;


        case CIRCLE:

          if (spawner_timer > spawn_rate)
          {
            spawn_clock.restart();
            circle_vector_container.push_back(new CircleEnemyMovement(enemy_ship_texture,fileName, rand() % 1000 + 50,rand() % 450 + 50));
            spawn_rate *= 0.95f;
          }

          if (enemy_fire_timer > enemy_fire_rate)
          {
            Shoot_clock.restart();

            for (auto & i : circle_vector_container)
            {
              if (i->shoot((rand() % 25 + 1)))
              {
                bullets.push_back(new BulletsObj(false,i->getSprite()->getPosition().x +(i->getSprite()->getGlobalBounds().width / 2),i->getSprite()->getPosition().y));
              }
            }
          }

          for (auto & i : circle_vector_container)
          {
            i->movement();
          }
          break;


        case SIN:

          if (spawner_timer > spawn_rate)
          {
            spawn_clock.restart();
            sin_vector_container.push_back(new SinEnemyMovement(enemy_ship_texture,fileName, rand() % 1000 + 50,rand() % 450 + 50));
            spawn_rate *= 0.95f;
          }

          if (enemy_fire_timer > enemy_fire_rate)
          {
            Shoot_clock.restart();

            for (auto & i : sin_vector_container)
            {
              if (i->shoot((rand() % 25 + 1)))
              {
                bullets.push_back(new BulletsObj(false,i->getSprite()->getPosition().x +(i->getSprite()->getGlobalBounds().width / 2),i->getSprite()->getPosition().y));
              }
            }
          }

          for (auto & i : sin_vector_container)
          {
            i->movement();
          }
          break;


        case METEOR:

          if (spawner_timer > spawn_rate)
          {
            spawn_clock.restart();
            meteor_vector_container.push_back(new MeteorEnemyClass(enemy_ship_texture,fileName, rand() % 1200 + 50,-100));
            spawn_rate *= 0.95f;
          }

          for (auto & i : meteor_vector_container)
          {
            i->movement(dt);
          }
          break;


        case QUADRATIC:

          if (spawner_timer > spawn_rate)
          {
            spawn_clock.restart();
            quadratic_vector_container.push_back(new QuadraticEnemyMovement(enemy_ship_texture,fileName, rand() % 500 + 100,rand() % 500 + 100, window.getSize().x));
            spawn_rate *= 0.95f;
          }

          if (enemy_fire_timer > enemy_fire_rate)
          {
            Shoot_clock.restart();

            for (auto & i : quadratic_vector_container)
            {
              if (i->shoot((rand() % 25 + 1)))
                bullets.push_back(new BulletsObj(false,i->getSprite()->getPosition().x +(i->getSprite()->getGlobalBounds().width / 2),i->getSprite()->getPosition().y));
            }
          }

          for (auto & i : quadratic_vector_container)
          {
              i->movement(dt);
          }
          break;
      }

      collisionCheck();

      for (auto & bullet : bullets)
      {
        bullet->getSprite()->move(0, bullet->direction.y * bullet->speed * dt);
      }

      break;
  }
}
void Game::collisionCheck()
{
#pragma region bullet collision
  for (int i = 0; i < bullets.size(); ++i)
  {
    if (bullets[i]->friendly)  //if the bullet is fired by the player
    {
      if (bullets[i]->getSprite()->getPosition().y + bullets[i]->getSprite()->getGlobalBounds().height <= 0)
      {
        delete bullets[i];
        bullets.erase(bullets.begin() + i);
      }

      for (auto & shield : shields)
      {
        if (bullets[i]->getSprite()->getGlobalBounds().intersects(shield->getSprite()->getGlobalBounds()) && !shield->dead && !bullets[i]->to_destroy)
          bullets[i]->changeTexture();
      }


      switch (current_enemy_type)  //bullets collision depending on the type of enemy choosen
      {
        case NORMAL:

          for (auto & enemyShip : test)
          {
            if (!enemyShip.dead)
            {
              if (bullets[i]->getSprite()->getGlobalBounds().intersects(enemyShip.getSprite()->getGlobalBounds()) && !bullets[i]->to_destroy)
              {
                enemyShip.dead = true;
                move_call_normal_enemies *= 0.97f;
                player_score += 50;
                bullets[i]->changeTexture();
              }
            }
          }
          break;

        case STRAFING:

          for (int j = 0; j < strafing_vector_container.size(); ++j)
          {
            if (bullets[i]->getSprite()->getGlobalBounds().intersects(strafing_vector_container[j]->getSprite()->getGlobalBounds()) && !bullets[i]->to_destroy)
            {
              delete strafing_vector_container[j];
              player_score +=100;
              strafing_vector_container.erase(strafing_vector_container.begin() + j);
              bullets[i]->changeTexture();
            }
          }
          break;

        case CIRCLE:

          for (int j = 0; j < circle_vector_container.size(); ++j)
          {
            if (bullets[i]->getSprite()->getGlobalBounds().intersects(circle_vector_container[j]->getSprite()->getGlobalBounds()) && !bullets[i]->to_destroy)
            {
              delete circle_vector_container[j];
              player_score +=100;
              circle_vector_container.erase(circle_vector_container.begin() + j);
              bullets[i]->changeTexture();
            }
          }
          break;

        case SIN:

          for (int j = 0; j < sin_vector_container.size(); ++j)
          {
            if (bullets[i]->getSprite()->getGlobalBounds().intersects(sin_vector_container[j]->getSprite()->getGlobalBounds()) && !bullets[i]->to_destroy)
            {
              delete sin_vector_container[j];
              player_score +=100;
              sin_vector_container.erase(sin_vector_container.begin() + j);
              bullets[i]->changeTexture();
            }
          }
          break;

        case METEOR:

          for (int j = 0; j < meteor_vector_container.size(); ++j)
          {
            if (bullets[i]->getSprite()->getGlobalBounds().intersects(meteor_vector_container[j]->getSprite()->getGlobalBounds()) && !bullets[i]->to_destroy)
            {
              delete meteor_vector_container[j];
              player_score += 75;
              meteor_vector_container.erase(meteor_vector_container.begin() + j);
              bullets[i]->changeTexture();
            }
          }
          break;

        case QUADRATIC:

          for (int j = 0; j < quadratic_vector_container.size(); ++j)
          {
              if (bullets[i]->getSprite()->getGlobalBounds().intersects(quadratic_vector_container[j]->getSprite()->getGlobalBounds()) && !bullets[i]->to_destroy)
              {
                delete quadratic_vector_container[j];
                player_score +=100;
                quadratic_vector_container.erase(quadratic_vector_container.begin() + j);
                bullets[i]->changeTexture();
              }
          }
          break;
      }
    }

    else  // if the bullet is fired by one of the enemies
    {
      if (bullets[i]->getSprite()->getPosition().y >= window.getSize().y)
      {
        delete bullets[i];
        bullets.erase(bullets.begin() + i);
      }

      for (auto & shield : shields)
      {
        if (bullets[i]->getSprite()->getGlobalBounds().intersects(shield->getSprite()->getGlobalBounds()) && !shield->dead && !bullets[i]->to_destroy)
        {
          bullets[i]->changeTexture();
          shield->onHit();
        }
      }

      if (bullets[i]->getSprite()->getGlobalBounds().intersects(
          player_ship->getSprite()->getGlobalBounds())&& !bullets[i]->to_destroy)
      {
        player_lives --;
        bullets[i]->changeTexture();
      }
    }

    if (bullets[i]->to_destroy)
    {
      if (bullets[i]->changeTexture())
        bullets.erase(bullets.begin() + i);
    }
  }
#pragma endregion

#pragma region paddle clamping

  if (player_ship->getSprite()->getPosition().x < 0)
  {
    player_ship->direction.x = 0;
    player_ship->getSprite()->setPosition(0,window.getSize().y - player_ship->getSprite()->getGlobalBounds().height - 5);
  }
  else if (
    player_ship->getSprite()->getPosition().x  > window.getSize().x - player_ship->getSprite()->getGlobalBounds().width)
  {
    player_ship->direction.x = 0;
    player_ship->getSprite()->setPosition(window.getSize().x - player_ship->getSprite()->getGlobalBounds().width ,window.getSize().y - player_ship->getSprite()->getGlobalBounds().height -5);
  }

#pragma endregion

#pragma region special enemy type collisions

  if (current_enemy_type == METEOR)
  {
    for (int j = 0; j < meteor_vector_container.size(); ++j)
    {
      if (meteor_vector_container[j]->getSprite()->getPosition().y > window.getSize().y)
      {
        player_lives --;
        delete meteor_vector_container[j];
        meteor_vector_container.erase(meteor_vector_container.begin() + j);
      }
    }
  }
  else if (current_enemy_type == STRAFING)
  {
    for (int j = 0; j < strafing_vector_container.size(); ++j)
    {
      if (strafing_vector_container[j]->getSprite()->getPosition().y > window.getSize().y)
      {
        player_lives --;
        delete strafing_vector_container[j];
        strafing_vector_container.erase(strafing_vector_container.begin() + j);
      }
    }
  }

#pragma endregion
}
void Game::render()
{
  window.draw(background);

  switch(current_screen)
  {
    case MAIN_MENU_SCREEN:
      window.draw(start_text_menu);
      window.draw(description_text_menu);
      window.draw(enemy_choice_text_menu);
      break;

    case ENEMY_TYPE_SCREEN:
      window.draw(strafing_text_choice);
      window.draw(normal_text_choice);
      window.draw(meteor_text_choice);
      window.draw(quadratic_text_choice);
      window.draw(circle_text_choice);
      window.draw(sin_text_choice);
      window.draw(description_text_choice);
      break;

    case GAME_SCREEN:
      window.draw(score_display);
      window.draw(life_display);

      for (auto & bullet : bullets)
      {
        window.draw(*bullet->getSprite());
      }

      window.draw(*player_ship->getSprite());

      if (current_enemy_type != METEOR)
      {
        for (auto & shield : shields)
        {
          if (!shield->dead)
            window.draw(*shield->getSprite());
        }
      }

      switch (current_enemy_type) //drawing the specific types of enemy depending on what is choosen
      {
        case NORMAL:
          for (int i = 0; i < size_norm_arr; ++i)
          {
            if (!test[i].dead)
            {
              window.draw(*test[i].getSprite());
            }
          }
          break;

        case STRAFING:
          for (auto & i : strafing_vector_container)
          {
            window.draw(*i->getSprite());
          }
          break;

        case CIRCLE:
          for (auto & i : circle_vector_container)
          {
            window.draw(*i->getSprite());
          }
          break;

        case SIN:
          for (auto & i : sin_vector_container)
          {
            window.draw(*i->getSprite());
          }
          break;

        case METEOR:
          for (auto & i : meteor_vector_container)
          {
              window.draw(*i->getSprite());
          }
          break;

        case QUADRATIC:
          for (auto & i : quadratic_vector_container)
          {
              window.draw(*i->getSprite());
          }
          break;
      }

      break;

    case END_SCREEN:
      window.draw(game_ending_description);
      window.draw(game_ending_menu);
      break;
  }
}

void Game::mouseClicked(sf::Event event)
{
  sf::Vector2i click = sf::Mouse::getPosition(window);

  switch(current_screen)
  {
    case MAIN_MENU_SCREEN:
      if ((click.x >= start_text_menu.getPosition().x && click.x <= start_text_menu.getPosition().x + start_text_menu.getGlobalBounds().width) && (click.y >= start_text_menu.getPosition().y && click.y <= start_text_menu.getPosition().y + start_text_menu.getGlobalBounds().height))
      {
        current_enemy_type = NORMAL;
        resetPlayer();
        current_screen = GAME_SCREEN;
      }

      if ((click.x >= enemy_choice_text_menu.getPosition().x && click.x <= enemy_choice_text_menu.getPosition().x + enemy_choice_text_menu.getGlobalBounds().width) && (click.y >= enemy_choice_text_menu.getPosition().y && click.y <= enemy_choice_text_menu.getPosition().y + enemy_choice_text_menu.getGlobalBounds().height))
        current_screen = ENEMY_TYPE_SCREEN;

      break;

    case GAME_SCREEN: //to delete after this is just for debugging
      for (int i = 0; i < size_norm_arr; ++i)
      {
        if (!test[i].dead)
          if ((click.x >= test[i].getSprite()->getPosition().x && click.x <= test[i].getSprite()->getPosition().x + test[i].getSprite()->getGlobalBounds().width) && (click.y >= test[i].getSprite()->getPosition().y && click.y <= test[i].getSprite()->getPosition().y + test[i].getSprite()->getGlobalBounds().height))
            test[i].dead = true;

      }
      break;

    case END_SCREEN:
      if ((click.x >= game_ending_menu.getPosition().x && click.x <= game_ending_menu.getPosition().x + game_ending_menu.getGlobalBounds().width) && (click.y >= game_ending_menu.getPosition().y && click.y <= game_ending_menu.getPosition().y + game_ending_menu.getGlobalBounds().height))
        current_screen = MAIN_MENU_SCREEN;

      break;

    case ENEMY_TYPE_SCREEN:
      if ((click.x >= strafing_text_choice.getPosition().x && click.x <= strafing_text_choice.getPosition().x + strafing_text_choice.getGlobalBounds().width) && (click.y >= strafing_text_choice.getPosition().y && click.y <= strafing_text_choice.getPosition().y + strafing_text_choice.getGlobalBounds().height))
      {
        current_enemy_type = STRAFING;
        current_screen = GAME_SCREEN;
        strafing_vector_container.push_back(new StrafingEnemyMovement(enemy_ship_texture,fileName, window.getSize().x/2,rand() % 150 + 50, rand() % 500 + 50));
      }

      if ((click.x >= quadratic_text_choice.getPosition().x && click.x <= quadratic_text_choice.getPosition().x + quadratic_text_choice.getGlobalBounds().width) && (click.y >= quadratic_text_choice.getPosition().y && click.y <= quadratic_text_choice.getPosition().y + quadratic_text_choice.getGlobalBounds().height))
      {
        current_enemy_type = QUADRATIC;
        current_screen = GAME_SCREEN;
        quadratic_vector_container.push_back(new QuadraticEnemyMovement(enemy_ship_texture,fileName, 100,rand() % 500 + 100, window.getSize().x));
      }

      if ((click.x >= circle_text_choice.getPosition().x && click.x <= circle_text_choice.getPosition().x + circle_text_choice.getGlobalBounds().width) && (click.y >= circle_text_choice.getPosition().y && click.y <= circle_text_choice.getPosition().y + circle_text_choice.getGlobalBounds().height))
      {
        current_enemy_type = CIRCLE;
        current_screen = GAME_SCREEN;
        circle_vector_container.push_back(new CircleEnemyMovement(enemy_ship_texture,fileName, rand() % 1000 + 50,rand() % 450 + 50));
      }

      if ((click.x >= meteor_text_choice.getPosition().x && click.x <= meteor_text_choice.getPosition().x + meteor_text_choice.getGlobalBounds().width) && (click.y >= meteor_text_choice.getPosition().y && click.y <= meteor_text_choice.getPosition().y + meteor_text_choice.getGlobalBounds().height))
      {
        current_enemy_type = METEOR;
        current_screen = GAME_SCREEN;
        meteor_vector_container.push_back(new MeteorEnemyClass(enemy_ship_texture,fileName, rand() % 1200 + 50,-100));
      }

      if ((click.x >= normal_text_choice.getPosition().x && click.x <= normal_text_choice.getPosition().x + normal_text_choice.getGlobalBounds().width) && (click.y >= normal_text_choice.getPosition().y && click.y <= normal_text_choice.getPosition().y + normal_text_choice.getGlobalBounds().height))
      {
        current_enemy_type = NORMAL;
        current_screen = GAME_SCREEN;
      }

      if ((click.x >= sin_text_choice.getPosition().x && click.x <= sin_text_choice.getPosition().x + sin_text_choice.getGlobalBounds().width) && (click.y >= sin_text_choice.getPosition().y && click.y <= sin_text_choice.getPosition().y + sin_text_choice.getGlobalBounds().height))
      {
        current_enemy_type = SIN;
        current_screen = GAME_SCREEN;
        sin_vector_container.push_back(new SinEnemyMovement(enemy_ship_texture,fileName, rand() % 1000 + 50,rand() % 450 + 50));
      }

      if ((click.x >= return_text_choice.getPosition().x && click.x <= return_text_choice.getPosition().x + return_text_choice.getGlobalBounds().width) && (click.y >= return_text_choice.getPosition().y && click.y <= return_text_choice.getPosition().y + return_text_choice.getGlobalBounds().height))
        current_screen = MAIN_MENU_SCREEN;

      break;
  }
}
void Game::mousePos(sf::Event event)
{
  sf::Vector2i position = sf::Mouse::getPosition(window); // position of the cursor

  switch(current_screen)
  {
    case MAIN_MENU_SCREEN:

      if ((position.x >= start_text_menu.getPosition().x && position.x <= start_text_menu.getPosition().x + start_text_menu.getGlobalBounds().width) && (position.y >= start_text_menu.getPosition().y && position.y <= start_text_menu.getPosition().y + start_text_menu.getGlobalBounds().height))
        start_text_menu.setString("<Click on me to start the normal game>");
      else
        start_text_menu.setString("Click on me to start the normal game");

      if ((position.x >= enemy_choice_text_menu.getPosition().x && position.x <= enemy_choice_text_menu.getPosition().x + enemy_choice_text_menu.getGlobalBounds().width) && (position.y >= enemy_choice_text_menu.getPosition().y && position.y <= enemy_choice_text_menu.getPosition().y + enemy_choice_text_menu.getGlobalBounds().height))
        enemy_choice_text_menu.setString("<Choose the enemies to go against>");
      else
        enemy_choice_text_menu.setString("Choose the enemies to go against");

      break;


    case END_SCREEN:

      if ((position.x >= game_ending_menu.getPosition().x && position.x <= game_ending_menu.getPosition().x + game_ending_menu.getGlobalBounds().width) && (position.y >= game_ending_menu.getPosition().y && position.y <= game_ending_menu.getPosition().y + game_ending_menu.getGlobalBounds().height))
        game_ending_menu.setString("<Go back to the menu>");
      else
        game_ending_menu.setString("Go back to the menu");

      break;


    case ENEMY_TYPE_SCREEN:

      if ((position.x >= return_text_choice.getPosition().x && position.x <= return_text_choice.getPosition().x + return_text_choice.getGlobalBounds().width) && (position.y >= return_text_choice.getPosition().y && position.y <= return_text_choice.getPosition().y + return_text_choice.getGlobalBounds().height))
        return_text_choice.setString("<Return to the menu> (Esc)");
      else
        return_text_choice.setString("Return to the menu (Esc)");

      if ((position.x >= strafing_text_choice.getPosition().x && position.x <= strafing_text_choice.getPosition().x + strafing_text_choice.getGlobalBounds().width) && (position.y >= strafing_text_choice.getPosition().y && position.y <= strafing_text_choice.getPosition().y + strafing_text_choice.getGlobalBounds().height))
        strafing_text_choice.setString("                                                            <Strafing enemies> \nSlowly descending enemies which strafe from left to right while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
      else
        strafing_text_choice.setString("                                                              Strafing enemies \nSlowly descending enemies which strafe from left to right while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");

      if ((position.x >= quadratic_text_choice.getPosition().x && position.x <= quadratic_text_choice.getPosition().x + quadratic_text_choice.getGlobalBounds().width) && (position.y >= quadratic_text_choice.getPosition().y && position.y <= quadratic_text_choice.getPosition().y + quadratic_text_choice.getGlobalBounds().height))
        quadratic_text_choice.setString("                                                            <Swinging enemies> \nEnemies that move in a pendulum swinging pattern while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
      else
        quadratic_text_choice.setString("                                                              Swinging enemies \nEnemies that move in a pendulum swinging pattern while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");

      if ((position.x >= circle_text_choice.getPosition().x && position.x <= circle_text_choice.getPosition().x + circle_text_choice.getGlobalBounds().width) && (position.y >= circle_text_choice.getPosition().y && position.y <= circle_text_choice.getPosition().y + circle_text_choice.getGlobalBounds().height))
        circle_text_choice.setString("                                                            <Circling enemies> \nEnemies that circle around a spot while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
      else
        circle_text_choice.setString("                                                              Circling enemies \nEnemies that circle around a spot while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");

      if ((position.x >= meteor_text_choice.getPosition().x && position.x <= meteor_text_choice.getPosition().x + meteor_text_choice.getGlobalBounds().width) && (position.y >= meteor_text_choice.getPosition().y && position.y <= meteor_text_choice.getPosition().y + meteor_text_choice.getGlobalBounds().height))
        meteor_text_choice.setString("                                                            <Meteor mode> \nEnemies come down like meteors, kill them before they reach your base");
      else
        meteor_text_choice.setString("                                                              Meteor mode \nEnemies come down like meteors, kill them before they reach your base");

      if ((position.x >= normal_text_choice.getPosition().x && position.x <= normal_text_choice.getPosition().x + normal_text_choice.getGlobalBounds().width) && (position.y >= normal_text_choice.getPosition().y && position.y <= normal_text_choice.getPosition().y + normal_text_choice.getGlobalBounds().height))
        normal_text_choice.setString("                                                            <Normal enemies> \ntypical arcade style moving enemies, the more you kill the faster the they will move");
      else
        normal_text_choice.setString("                                                              Normal enemies \ntypical arcade style moving enemies, the more you kill the faster the they will move");

      if ((position.x >= sin_text_choice.getPosition().x && position.x <= sin_text_choice.getPosition().x + sin_text_choice.getGlobalBounds().width) && (position.y >= sin_text_choice.getPosition().y && position.y <= sin_text_choice.getPosition().y + sin_text_choice.getGlobalBounds().height))
        sin_text_choice.setString("                                                            <Undulating enemies> \nEnemies that go up and down while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");
      else
        sin_text_choice.setString("                                                              Undulating enemies \nEnemies that go up and down while they try to shoot you.\nThe more you survive the more quicker they are going to spawn back");

      break;
  }
}

void Game::keyPressed(sf::Event event)
{
  if (current_screen != MAIN_MENU_SCREEN)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      if (current_screen == GAME_SCREEN)
        resetPlayer();

      current_screen = MAIN_MENU_SCREEN;
    }
  }


  switch(current_screen)
  {
    case GAME_SCREEN:

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player_ship->direction.x = 4;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player_ship->direction.x = -4;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && can_fire)
      {
        can_fire = false;
        bullets.push_back(new BulletsObj(true,player_ship->getSprite()->getPosition().x + (player_ship->getSprite()->getGlobalBounds().width/2),player_ship->getSprite()->getPosition().y));
        player_clock.restart();
      }

      break;
  }
}
void Game::keyReleased(sf::Event event)
{
  player_ship->direction.x = 0;
}

void Game::moveSprites()   //movement function for the arcade style enemies
{
  int smallest = 99;
  int largest = 0;
  int index = size_norm_arr -1;

  for(int i = 0;i < size_norm_arr; i++)   // to find the extremities of the chain of the enemies which are alive
  {
    if(!test[i].dead && !moving_left)
    {
      if(largest < test[i].coloumn)
      {
        largest = test[i].coloumn;
        index = i;
      }
    }
    if(!test[i].dead && moving_left)
    {
      if(test[i].coloumn < smallest)
      {
        smallest = test[i].coloumn;
        index = i;
      }
    }
  }


  if (test[index].getSprite()->getPosition().x + (2 * test[index].getSprite()->getGlobalBounds().width) >= window.getSize().x && !moving_left)
  {
    moving_left = true;
    for (int i = 0; i < size_norm_arr; ++i)
    {
      if (!test[i].dead)
        test[i].Move(0,1);

    }
  }
  else if (test[index].getSprite()->getPosition().x - test[index].getSprite()->getGlobalBounds().width < 0 && moving_left)
  {
    moving_left = false;
    for (int i = 0; i < size_norm_arr; ++i)
    {
      if (!test[i].dead)
        test[i].Move(0,1);

    }
  }
  else
  {
    for (int i = 0; i < size_norm_arr; ++i)
    {
      if (!test[i].dead)
      {
        if (moving_left)
          test[i].Move(-1,0);
        else
          test[i].Move(1,0);

      }
    }
  }
}
void Game::resetPlayer()  //resetting all of the stats, vectors and regenerating shields and enemies
{
  player_ship->getSprite()->setPosition(window.getSize().x/2 -
      player_ship->getSprite()->getGlobalBounds().width/2, window.getSize().y - player_ship->getSprite()->getGlobalBounds().height-5);

  for (auto & shield : shields)
  {
    shield->reset();
  }

  switch (current_enemy_type)
  {
    case NORMAL:
      for (int i = 0; i <size_norm_arr; ++i)
      {
        test[i].reset();
      }
      break;

    case STRAFING:
      while (!strafing_vector_container.empty())
      {
        delete strafing_vector_container[strafing_vector_container.size() -1];
        strafing_vector_container.erase(strafing_vector_container.begin() + (strafing_vector_container.size() -1));
      }
      break;

    case CIRCLE:
      while (!circle_vector_container.empty())
      {
        delete circle_vector_container[circle_vector_container.size() -1];
        circle_vector_container.erase(circle_vector_container.begin() + (circle_vector_container.size() -1));
      }
      break;

    case SIN:
      while (!sin_vector_container.empty())
      {
        delete sin_vector_container[sin_vector_container.size() -1];
        sin_vector_container.erase(sin_vector_container.begin() + (sin_vector_container.size() -1));
      }
      break;

    case METEOR:
      while (!meteor_vector_container.empty())
      {
        delete meteor_vector_container[meteor_vector_container.size() -1];
        meteor_vector_container.erase(meteor_vector_container.begin() + (meteor_vector_container.size() -1));
      }
      break;

    case QUADRATIC:
      while (!quadratic_vector_container.empty())
      {
        delete quadratic_vector_container[quadratic_vector_container.size() -1];
        quadratic_vector_container.erase(quadratic_vector_container.begin() + (quadratic_vector_container.size() -1));
      }
      break;
  }

  while (!bullets.empty())
  {
    delete bullets[bullets.size() -1];
    bullets.erase(bullets.begin() + (bullets.size() -1));
  }

  spawn_rate = sf::seconds(5);
  player_score = 0;
  player_lives = 3;
}