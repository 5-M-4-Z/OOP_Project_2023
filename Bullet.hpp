#include <SDL.h>
// #include "Explosion.hpp"
#pragma once

class Bullet {
    private:
        SDL_Rect mover, src;
        int damage;
        int bullet_state;
        // Explosion explosion;
        // int destroyed;
    public:
        Bullet(int x, int y);
        void move_bullet();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void display(SDL_Renderer* renderer, SDL_Texture* assets, int x);
        void destroy();
        void move_bullet(int dummy);
        SDL_Rect get_mover();
        // void explode(SDL_Renderer* renderer, SDL_Texture* assets);
};