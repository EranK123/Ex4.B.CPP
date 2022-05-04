#include "Ambassador.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

Ambassador::Ambassador(Game &game, string name) : Player(game, name){
    this->roleName = "Ambassador";
}


void Ambassador::transfer(Player &p1, Player &p2){
    this->setCurrentAction("transfer");
    this->game->turnNum++;
    p1.setCoinAmount(-1);
    p2.setCoinAmount(1);
}

void Ambassador::block(Player &p){
    if(p.getCurrentAction() != "steal"){
        throw std::invalid_argument("Must be steal");
    }
    p.setCoinAmount(-2);
    p.actionedPlayer->setCoinAmount(2);
}