#include "GameObject.hpp"
#include "game.hpp"
#pragma once

class Player:public GameObject{
    private:
        int health=100, exp=0, power=20;
    public:
        Player(int x, int y);
        void move(char c);
        void shoot();
        void gainExp();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void gainPow();
};