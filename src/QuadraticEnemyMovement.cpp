//
// Created by alexh on 3/4/2021.
//

#include "QuadraticEnemyMovement.h"
QuadraticEnemyMovement::QuadraticEnemyMovement(sf::Texture, std::string filename, int x, int y, int screen_width)
{
  sprite = new sf::Sprite();
  shoot_num = rand() % 25 + 1;

  this->screen_width_x = screen_width;
  this->cent_x = x - sprite->getGlobalBounds().width/2;
  this->cent_y = y - sprite->getGlobalBounds().height-5;

  if (!texture.loadFromFile(filename))
  {
    printf("ball not balling filename");
  }

  sprite->setTexture(texture);
  sprite->setPosition(cent_x,cent_y);
}
void QuadraticEnemyMovement::movement(float dt)
{
  float relative_x = this->sprite->getPosition().x - 1320/2;

      //quadratic like wtf
      if (relative_x <= 0 )
      {
        this->getSprite()->move( this->direction.x * this->speed * dt, ((pow(this->getSprite()->getPosition().x - midd_x, 2) / 4000 ) ) *-this->direction.x* dt);
      }
      else if  (relative_x > 0 )
      {
        this->getSprite()->move( this->direction.x * this->speed * dt, ((pow(this->getSprite()->getPosition().x - midd_x, 2) / 4000 ) ) * this->direction.x * dt);
      }


  if (this->getSprite()->getPosition().x < 0)
  {
    this->direction.x = 1;
    this->sprite->setPosition(0, this->sprite->getPosition().y);
  }
  else if (this->sprite->getPosition().x  > screen_width_x - this->sprite->getGlobalBounds().width)
  {
    this->direction.x = -1;
    this->sprite->setPosition(screen_width_x - this->sprite->getGlobalBounds().width , this->sprite->getPosition().y);
  }

}
QuadraticEnemyMovement::~QuadraticEnemyMovement() {}
