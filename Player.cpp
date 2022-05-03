#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace coup;

Player::Player(Game game, string name){
    this->game = game;
    this->name = name;
}

void Player::income(){
    return;
}

void Player::foreign_aid(){
    return;
}

void  Player::coup(Player p){
    return;
}

int Player::coins(){
    return -1;
}
