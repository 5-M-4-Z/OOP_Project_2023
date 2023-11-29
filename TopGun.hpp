#include<SDL.h>
#include "EnemyPlane1.hpp"
#include "EnemyPlane2.hpp"
#include "ENemyPlane3.hpp"
#include "ObjectCreator.hpp"
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
};