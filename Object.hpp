#include "Player.hpp"
#include<SDL.h>
#pragma once


class Object{
protected:    // Protected bcz we want to access these variables in the derived classes.
    SDL_Rect src, mover;
public:
    void draw(SDL_Renderer* renderer, SDL_Texture* assets);
    virtual void move();  
    virtual void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
    SDL_Rect get_mover();
    // virtual void shoot();  
    virtual void collision(SDL_Rect player_mover);
    virtual void collision_player_bullet(Player player);
};
