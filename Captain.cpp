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
    return;
}

void Captain::steal(Player &p){
    p.setCoinAmount(-2);
    this->coin_amount += 2;
    this->game->turnNum++;
}
}