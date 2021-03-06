#include "Captain.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
namespace coup{
Captain::Captain(Game &game, string name) : Player(game, move(name)){
    this->roleName = "Captain";
}
void Captain::block(Player &p){
       if(p.getCurrentAction() != "steal" || p.getIsPlaying() == 0 || this->isPlaying == 0){
        throw std::invalid_argument("Must be steal");
    }
    p.setCoinAmount(-2);
    p.actionedPlayer->setCoinAmount(2);
}

void Captain::steal(Player &p){
     if(this->isPlaying == 0 || p.getIsPlaying() == 0 || this->game->turn() != this->name){
          throw std::invalid_argument("Not playing"); 
    }
    this->setCurrentAction("steal");
    if(p.getCoinAmount() == 1){
        p.setCoinAmount(-1);
    this->coin_amount += 1;
    }else if(p.getCoinAmount() == 0){
         p.setCoinAmount(0);
        this->coin_amount += 0;
    }else{
        p.setCoinAmount(-2);
        this->coin_amount += 2;
    }
    this->game->turnNum++;
    this->actionedPlayer = &p;
}
}