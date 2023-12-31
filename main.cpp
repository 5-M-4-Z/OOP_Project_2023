#include <iostream>

#include "game.hpp"

using namespace std;

//Using the files provided in OOP HW to recreate main file
int main(int argc, char * argcv[]){
    Game game;  //We will create a class game that will be like a backbone to our game that will import images, create window,etc
    srand(time(NULL));
    if (!game.init()){
        printf("Failed to initialize!\n");
        return 0;
    }

    if (!game.load_media()){
        printf( "Failed to load media!\n" );
        return 0;
    }
    
    game.run();
    game.close();

    return 0;
}