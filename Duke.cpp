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
                this->setCurrentAction("tax");
                this->game->turnNum++;
                this->coin_amount += 3;
                
        }
        void Duke::block(Player &p){
                if(p.getCurrentAction() != "foreign_aid"){
                        throw std::invalid_argument("Must be foreign aid");
                }
                this->setCurrentAction("block");
                p.setCoinAmount(-2);
        }
                


