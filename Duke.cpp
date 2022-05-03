#include "Duke.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
using namespace coup;

        Duke::Duke(Game &game, string name) : Player(game, name){
             this->roleName = "Duke";
        }
        
        void Duke::tax(){
                this->game->turnNum++;
                this->coin_amount += 3;
                
        }
        void Duke::block(Player p){

        }


