#pragma once
#include "game.hpp"
#include <SDL.h>

class GameObject{
    private:
        int x, y, width, height;
        SDL_Rect src, mover;
    public:
        GameObject(int x, int y, int width, int height, SDL_Rect src, SDL_Rect mover);
        virtual void display()=0;
};