#include "Contessa.hpp"
#include "Game.hpp"
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
    if(p.getCurrentAction() != "eliminate" || this->isPlaying == 0){
        throw std::invalid_argument("Error"); 
    }
    p.actionedPlayer->setIsPlaying(1);
}