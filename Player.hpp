#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#include "Object.hpp"
#include "Health.hpp"
#include "Score.hpp"
#include "Explosion.hpp"

#pragma once

class Player: public Object{
    private:
        int health_factor, exp, power;
        int delay;
        bool f_pressed;
        Health health;
        Score score;
        Explosion explosion;
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
        SDL_Rect get_mover();
        void add();
        void explode(SDL_Renderer* renderer, SDL_Texture* assets);
};