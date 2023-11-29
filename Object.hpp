#include<SDL.h>
#pragma once


class Object{
protected:    // Protected bcz we want to access these variables in the derived classes.
    SDL_Rect src, mover;
public:
    void draw(SDL_Renderer* renderer, SDL_Texture* assets);
    virtual void move();  
    // virtual void shoot();  
};
