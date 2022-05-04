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
    // Assassin assassin(g, "assassin");
    Ambassador ambassador(g, "amb");
    Captain captain(g, "cap");
    duke.foreign_aid();
    ambassador.foreign_aid();
    captain.steal(duke);
    ambassador.block(captain);
    cout << captain.coins() << endl;
    cout << duke.coins() << endl;
    


}