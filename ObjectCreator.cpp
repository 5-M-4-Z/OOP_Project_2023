#include "ObjectCreator.hpp"

Object* ObjectCreator::getObject(int x, int y){
    int random = rand()%4;
    if(random == 0){                            // random object.
        return new EnemyPlane1(x,y);
    }                                            
    else if(random == 1){
        return new EnemyPlane2(x,y);
    }
    else if (random == 2){
        return new EnemyPlane3(x,y);
    }
    else{
        return new EnemyPlane4(x,y);
    }
}