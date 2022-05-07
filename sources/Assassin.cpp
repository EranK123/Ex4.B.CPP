#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;
const int six_ = 6;
const int seven_ = 7;

Assassin::Assassin(Game &game, string name) : Player(game, move(name)){
    this->roleName = "Assassin";
}

void Assassin::coup (Player &p){
    if(this->game->turn() != this->name || p.getIsPlaying() == 0){
        throw std::invalid_argument("Not his turn or not playing");
    }
    
    if(this->coin_amount < 3){
        throw std::invalid_argument("Needs at least 3 coins");
    }
    if(this->coin_amount >= 3 && this->coin_amount <= six_){
        this->game->turnNum++;
    this->setCurrentAction("eliminate");
    this->coin_amount -= 3;
    p.setIsPlaying(0);
    this->actionedPlayer = &p;
    while(this->game->playersList.at(this->game->turnNum % this->game->playersList.size())->getIsPlaying() == 0){
        this->game->turnNum++;
    }
    int count = 0;
    for(unsigned long i = 0; i < this->game->playersList.size(); i++){
    if(this->game->playersList.at(i)->getIsPlaying() == 1){
        count++;
        }
    }
    if(count == 1){
        this->game->gameEnded = 1;
    }
    }else{
        // this->coup(p);
    this->setCurrentAction("coup");
    this->game->turnNum++;
    this->coin_amount -= seven_;
    p.setIsPlaying(0);
    int count = 0;
    for(unsigned long i = 0; i < this->game->playersList.size(); i++){
    if(this->game->playersList.at(i)->getIsPlaying() == 1){
        count++;
        }
    }
    if(count == 1){
        this->game->gameEnded = 1;
    }
    while(this->game->playersList.at(this->game->turnNum % this->game->playersList.size())->getIsPlaying() == 0){
        this->game->turnNum++;
    }
    }
}