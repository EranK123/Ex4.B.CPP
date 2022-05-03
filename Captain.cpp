#include "Captain.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
namespace coup{
Captain::Captain(Game game, string name) : Player(game, name){
}
void Captain::block(Player p){
    return;
}

void Captain::steal(Player p){

}
}