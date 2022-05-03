#include "Ambassador.cpp"
#include "Player.cpp"
#include "Duke.cpp"
#include "Assassin.cpp"
#include "Captain.cpp"
#include "Game.cpp"
using namespace coup;
#include <iostream>
#include <string.h>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){
    Game g;
    Duke duke(g, "duke");
    Assassin assassin(g, "assassin");
    Ambassador ambassador(g, "amb");
    Captain captain(g, "cap");
    duke.income();
    assassin.income();
    ambassador.transfer(duke, assassin);
    captain.steal(assassin);
    cout << g.turn() << endl;
    duke.tax();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    cout << captain.coins();
    cout << ambassador.coins();
    cout << duke.coins();
    cout << g.winner();
    


}