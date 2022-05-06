#include "Captain.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
namespace coup{
Captain::Captain(Game &game, string name) : Player(game, name){
    this->roleName = "Captain";
}
void Captain::block(Player &p){
     if(this->isPlaying == 0 || p.getIsPlaying()){
          throw std::invalid_argument("Not playing"); 
    }
    return;
}

void Captain::steal(Player &p){
     if(this->isPlaying == 0 || p.getIsPlaying() == 0 || this->game->turn() != this->name){
          throw std::invalid_argument("Not playing"); 
    }
    this->setCurrentAction("steal");
    p.setCoinAmount(-2);
    this->coin_amount += 2;
    this->game->turnNum++;
    this->actionedPlayer = &p;
}
}