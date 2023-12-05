// #include "Player.hpp"
#include<SDL.h>
#include <iostream>
#include "Bullet.hpp"
#include <vector>
#pragma once


class Object{
protected:    // Protected bcz we want to access these variables in the derived classes.
    SDL_Rect src, mover;
    std::string name;
    std::vector<Bullet> bullets_array;
public:
    virtual void display(SDL_Renderer* renderer, SDL_Texture* assets);
    virtual void move();
    virtual void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
    SDL_Rect get_mover();
    // virtual void shoot();  
    virtual void move(int x, int y);
    virtual void shoot();
    virtual void move_bullet();
    virtual void move_bullet(int height);
    
    virtual void set_delay(int x);

    bool collision_current_opponent_bullet(Object* opponent);
    void collision_player_enemy_bullet(Object* opponent);
};
