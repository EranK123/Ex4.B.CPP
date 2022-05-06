#include "Ambassador.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

Ambassador::Ambassador(Game &game, string name) : Player(game, move(name)){
    this->roleName = "Ambassador";
}


void Ambassador::transfer(Player &p1, Player &p2){
    if(this->isPlaying == 0 || p1.getIsPlaying() == 0 || p2.getIsPlaying() == 0){
          throw std::invalid_argument("Not playing"); 
    }
    this->setCurrentAction("transfer");
    this->game->turnNum++;
    p1.setCoinAmount(-1);
    p2.setCoinAmount(1);
}

void Ambassador::block(Player &p){
    if(p.getCurrentAction() != "steal" || p.getIsPlaying() == 0 || this->isPlaying == 0){
        throw std::invalid_argument("Must be steal");
    }
    p.setCoinAmount(-2);
    p.actionedPlayer->setCoinAmount(2);
}