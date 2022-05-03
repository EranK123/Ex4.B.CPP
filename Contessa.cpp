#include "Contessa.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

    Contessa::Contessa(Game game, string name) : Player(game, name){}


void Contessa::block(Player p) {
    return;
}