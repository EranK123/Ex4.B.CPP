#include "Duke.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
using namespace coup;

        Duke::Duke(Game &game, string name) : Player(game, move(name)){
             this->roleName = "Duke";
        }
        
        void Duke::tax(){
        if(this->isPlaying == 0 || this->game->turn() != this->name){
          throw std::invalid_argument("Not playing or not your turn"); 
        }   
                this->setCurrentAction("tax");
                this->game->turnNum++;
        while(this->game->playersList.at(this->game->turnNum % this->game->playersList.size())->getIsPlaying() == 0){
        this->game->turnNum++;
    }
                this->coin_amount += 3;
                
        }
        void Duke::block(Player &p){
        if(this->isPlaying == 0 || p.getCurrentAction() != "foreign_aid"){
        throw std::invalid_argument("Error"); 
        }   
        this->setCurrentAction("block");
        p.setCoinAmount(-2);
        }
                


