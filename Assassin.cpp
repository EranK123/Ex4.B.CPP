#include "Assassin.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

Assassin::Assassin(Game game, string name) : Player(game, name){

}

void Assassin::eliminate(Player p){
    return;
}