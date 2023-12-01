#include "Object.hpp"
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#pragma once

class EnemyPlane1 : public Object
{
private:
    std::vector<Bullet> bullets_array;
    int delay;
    int shootTimer;
public:
    void move();
    void shoot();
    void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
    void move_bullet();
    void set_delay(int x);
    EnemyPlane1(int x, int y, int random);
    EnemyPlane1();
    // ~EnemyPlane1();
    void collision(SDL_Rect player_mover);
    void collision_player_bullet(Player player);
};