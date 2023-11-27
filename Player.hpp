#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#pragma once

class Player{
    private:
        SDL_Rect src, mover;
        int health=100, exp=0, power=20;
        std::vector<Bullet> bullets_array;
        int delay;
        bool f_pressed;
    public:
        Player(int x, int y);
        void move(int width, int height);
        void shoot();
        void gainExp();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void gainPow();
        void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
        void move_bullet();
        void set_delay(int x);
        int get_f_pressed();
};