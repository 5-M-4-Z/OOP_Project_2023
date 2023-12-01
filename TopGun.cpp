#include <iostream>
#include "TopGun.hpp"


void TopGun::drawObjects(SDL_Renderer* renderer, SDL_Texture* assets)
{
    for (Object* l : lst) {
        l->draw(renderer,assets);                      
        l->move();                     
    }
}

// creates new objects 
void TopGun::createObject(int x, int y){
    // std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    // ObjectCreator obj;                             // creating an object of the class ObjectCreator.
    // Object* o = obj.getObject(x,y);                  // creating a pointer to the object of the class Unit.

    // using same logic but only for enemyPlane1
    int random  = rand() % 4;
    Object* o = new EnemyPlane1(x,y,random);
    lst.push_back(o);                              
}

// TopGun::~TopGun(){
//     for(U* l: lst){
// 		delete l;                          // deleting the objects, need to delete every single object created dynamically
// 	}
//     lst.clear(); 
//     cout<<"List Cleared"<<endl;            //clears all the items from list             
// }

void TopGun::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (Object* enemy : lst){
        enemy->display_bullet(renderer, assets);
    }
}

void TopGun::collision(Player player){
    SDL_Rect player_mover = player.get_mover();

    for (Object* enemy : lst){
        SDL_Rect enmy_mover = enemy->get_mover();
        // Checks if player and enemy collide
        if (SDL_HasIntersection(&player_mover, &enmy_mover)){   // collision works here plane to plane 
            std::cout << "plane plane\n";
        }
        
        // Check if player's bullet collide with enemy
            player.collision(enmy_mover);
        // Check if enemy's bullet collide with player
            enemy->collision(player_mover);
        // Check if player's bullet collide with enemy's bullet
            enemy->collision_player_bullet(player);
    }


}