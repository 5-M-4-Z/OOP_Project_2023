#pragma once
#include "game.hpp"
#include <SDL.h>

class GameObject{
    private:
        SDL_Rect src, mover;
    public:
        GameObject(SDL_Rect src, SDL_Rect mover);
        virtual void display()=0;
};