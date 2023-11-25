#include <SDL.h>

#pragma once

class Player{
    private:
        SDL_Rect src, mover;
        int health=100, exp=0, power=20;
    public:
        Player(int x, int y);
        void move(char c);
        void shoot();
        void gainExp();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void gainPow();
};