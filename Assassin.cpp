#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

Assassin::Assassin(Game &game, string name) : Player(game, name){
    this->roleName = "Assassin";
}

void Assassin::eliminate(Player &p){
    this->game->turnNum++;
    if(this->coin_amount < 3){
        throw std::invalid_argument("Needs at least 3 coins");
    }else if(this->coin_amount >= 3 && this->coin_amount <= 6){
    this->coin_amount -= 3;
    int index = 0;
    for(int i = 0; i < this->game->playersList.size(); i++){
        if(this->game->playersList.at(i)->getName() == p.getName()){
            index = i;
            break;
        }
    }
    this->game->playersList.erase(this->game->playersList.begin() + index);
    }else{
        this->coup(p);
    }
}