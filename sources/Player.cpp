#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace coup;
const int seven = 7;
const int six = 6;
const int ten = 10;

Player::Player(Game &game, string name){
    this->game = &game;
     if(this->game->gameStarted == 1){
         throw std::invalid_argument("Game already started");
    }
    this->name = move(name);
    if(this->game->playersList.size() >= six){
         throw std::invalid_argument("Too many players");
    }
    this->game->add(this);
    this->coin_amount = 0;
    this->currentAction = "";
    this->actionedPlayer = NULL;
    this->isPlaying = 1;
}

void Player::income(){
    if(this->isPlaying == 0 || this->game->turn() != this->name || this->game->playersList.size() == 1){
        throw std::invalid_argument("Not playing or Not his turn");
    }
    this->game->gameStarted = 1;
    this->setCurrentAction("income");
    this->coin_amount += 1;
    this->game->turnNum++;
     while(this->game->playersList.at(this->game->turnNum % this->game->playersList.size())->getIsPlaying() == 0){
        this->game->turnNum++;
    }
}

void Player::foreign_aid(){
     if(this->isPlaying == 0 || this->game->turn() != this->name || this->game->playersList.size() == 1 || this->coin_amount >= ten){
        throw std::invalid_argument("Not playing");
    }
    this->setCurrentAction("foreign_aid");
    this->coin_amount += 2;
    this->game->turnNum++;
    while(this->game->playersList.at(this->game->turnNum % this->game->playersList.size())->getIsPlaying() == 0){
        this->game->turnNum++;
    }
}

void Player::coup(Player &p){
     if(this->isPlaying == 0 || p.getIsPlaying() == 0 || this->game->turn() != this->name){
        throw std::invalid_argument("Not playing or not his turn");
    }
    if(this->coin_amount < seven){
        throw std::invalid_argument("Needs at least 3 coins");
    }
    this->setCurrentAction("coup");
    this->game->turnNum++;
    this->coin_amount -= seven;
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

string Player::role(){
    return this->roleName;
}


int Player::coins() const{
    return this->coin_amount;
}
