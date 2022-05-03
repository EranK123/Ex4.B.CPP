#include "Ambassador.cpp"
#include "Player.cpp"
#include "Duke.cpp"
#include "Assassin.cpp"
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
    // Ambassador ambassador(g, "amb");
    duke.income();
    assassin.income();
    // ambassador.transfer(duke, assassin);
    assassin.foreign_aid();
    assassin.foreign_aid();
    assassin.foreign_aid();
    assassin.coup(duke);

    cout << g.winner();
    // vector<string> names = g.players();
    // for (string i: names)
    // std::cout << i << ' ';


}