#include "Contessa.hpp"
#include "Game.cpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

Contessa::Contessa(Game &game, string name) : Player(game, name){
    this->roleName = "Contessa";
}


void Contessa::block(Player &p) {
    if(p.getCurrentAction() != "eliminate"){
        throw std::invalid_argument("Must block eliminate"); 
    }
    p.setCoinAmount(3);
    //get the player who was elimintaed back to the game in his original turn
}