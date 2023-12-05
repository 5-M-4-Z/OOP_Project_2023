#include "Object.hpp"
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#include "Health.hpp"
#pragma once

class EnemyPlane1 : public Object
{
private:
    int delay;
    int shootTimer;
public:
    void move();
    void shoot();
    void display(SDL_Renderer* renderer, SDL_Texture* texture);
    void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
    void move_bullet(int height);
    // void set_delay(int x);
    EnemyPlane1(int x, int y, int random);
    EnemyPlane1();
    // ~EnemyPlane1();
};