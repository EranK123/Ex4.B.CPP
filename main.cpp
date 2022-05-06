#include "Ambassador.cpp"
#include "Player.cpp"
#include "Duke.cpp"
#include "Assassin.cpp"
#include "Captain.cpp"
#include "Contessa.cpp"
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
    Contessa contessa(g, "con");
    // vector<string> s = g.players();
//     for(int i=0; i < s.size(); i++){
//     std::cout << s.at(i) << ' ' << endl;
// }

}