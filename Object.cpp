#include "Object.hpp"
#include <iostream>

void Object::display(SDL_Renderer* renderer, SDL_Texture* assets){}
void Object::move(){};

void Object::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){};

SDL_Rect Object::get_mover(){
    return mover;
}

void Object::move(int x, int y){}
void Object::shoot(){}
void Object::move_bullet(){}
void Object::move_bullet(int height){}
void Object::set_delay(int x){}

bool Object::collision_current_opponent_bullet(Object* opponent){
    for (int i=0; i<bullets_array.size(); i++){
        Bullet bullet = bullets_array[i];
        SDL_Rect bullet_mvr = bullet.get_mover(), opponent_mover = opponent->get_mover();
        if (SDL_HasIntersection(&opponent_mover, &bullet_mvr)){
            // bullet.explode(renderer, assets);
            bullets_array.erase(bullets_array.begin() + i);
            std::cout << this->get_power() << '\n';
            opponent->reduce_health(this->get_power());
            return 1;
        }
    }
    return 0;
}

void Object::collision_player_enemy_bullet(Object* opponent){
    int size = opponent->bullets_array.size();
    for (int i=0; i<bullets_array.size(); i++){
        SDL_Rect p_bullet_mvr = (bullets_array[i]).get_mover();

        for (int j=0; j<size; j++){
            SDL_Rect e_bullet_mvr = (opponent->bullets_array[j]).get_mover();

            if (SDL_HasIntersection(&p_bullet_mvr, &e_bullet_mvr)){
                std::cout << "Bullet to bullet collision\n";
                bullets_array.erase(bullets_array.begin() + i);
                opponent->delete_bullet(i);
            }
        }
    }
}

void Object::add(){}

void Object::explode(SDL_Renderer* renderer, SDL_Texture* assets){}

void Object::reduce_health(int power){}

bool Object::get_destroyed(){return destroyed;}

void Object::delete_bullet(int i){
    this->bullets_array.erase(bullets_array.begin() + i);
}

int Object::get_power(){};

int Object::get_health(){};

bool Object::is_completely_destroyed(){}