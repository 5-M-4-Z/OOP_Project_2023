#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bullet.hpp"


class Enemy {
private:
    SDL_Rect src, mover;
    std::vector<Bullet> bullets_array;
    // int delay;
    int shootTimer;
public:
    Enemy(int x, int y);
    void move();
    void shoot();
    void display(SDL_Renderer* renderer, SDL_Texture* assets);
    void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
    void move_bullet();
    // void set_delay(int x);
};