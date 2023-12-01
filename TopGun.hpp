#include<SDL.h>
#include "EnemyPlane1.hpp"
#include "Player.hpp"

#include<vector>
#include<list>
using namespace std;


class TopGun{
    //Create your list here
    list<Object*> lst;
public:
    void drawObjects(SDL_Renderer* renderer, SDL_Texture* assets); 
    void createObject(int, int);
    // create destructor which deletes all dynamic objects
    // ~TopGun();
    void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
    void collision(Player obj);
};