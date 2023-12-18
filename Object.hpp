// #include "Player.hpp"
#include<SDL.h>
#include <iostream>
// #include "Bullet.hpp"
#include <vector>
#pragma once


class Object{
    protected:    // Protected bcz we want to access these variables in the derived classes.
        std::string name;
        SDL_Rect src, mover;
    public:
        virtual void display(SDL_Renderer* renderer, SDL_Texture* assets);
        virtual void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
        SDL_Rect get_mover();
};
