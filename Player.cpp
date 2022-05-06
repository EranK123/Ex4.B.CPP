#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace coup;

Player::Player(){
    
}

Player::Player(Game &game, string name){
    this->game = &game;
    this->name = name;
    this->game->add(*this);
    this->coin_amount = 0;
    this->currentAction = "";
    this->actionedPlayer = new Player();
    this->isPlaying = 1;
}

void Player::income(){
    if(this->isPlaying == 0 || this->game->turn() != this->name){
        throw std::invalid_argument("Not playing or Not his turn");
    }
    this->setCurrentAction("income");
    this->coin_amount += 1;
    this->game->turnNum++;
}

void Player::foreign_aid(){
     if(this->isPlaying == 0 || this->game->turn() != this->name){
        throw std::invalid_argument("Not playing");
    }
    this->setCurrentAction("foreign_aid");
    this->coin_amount += 2;
    this->game->turnNum++;
}

void Player::coup(Player &p){
     if(this->isPlaying == 0 || this->game->turn() != this->name){
        throw std::invalid_argument("Not playing");
    }
    if(this->coin_amount < 7){
        throw std::invalid_argument("Needs at least 3 coins");
    }
    this->setCurrentAction("coup");
    this->game->turnNum++;
    // int index = 0;
    // for(int i = 0; i < this->game->playersList.size(); i++){
    //     if(this->game->playersList.at(i)->name == p.name){
    //         index = i;
    //         break;
    //     }
    // }
    // this->game->playersList.erase(this->game->playersList.begin() + index);
    this->coin_amount -= 7;
    p.setIsPlaying(0);
}

string Player::role(){
    return this->roleName;
}


int Player::coins(){
    return this->coin_amount;
}
