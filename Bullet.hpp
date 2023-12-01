

#include <SDL.h>
#pragma once

class Bullet {
    private:
        SDL_Rect mover, src;
        int damage;
        int bullet_state;
    public:
        Bullet(int x, int y);
        void move_bullet();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void display(SDL_Renderer* renderer, SDL_Texture* assets, int x);
        void destroy();
        void move_bullet(int dummy);
};