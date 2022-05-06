#include "sources/Ambassador.cpp"
#include "sources/Player.cpp"
#include "sources/Duke.cpp"
#include "sources/Assassin.cpp"
#include "sources/Captain.cpp"
#include "sources/Contessa.cpp"
#include "sources/Game.cpp"
using namespace coup;
#include <iostream>
#include <string.h>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){
     Game scenario1{};

    Duke PlayerONE{scenario1, "Player ONE"};
	Assassin PlayerTWO{scenario1, "Player TWO"};


    cout << scenario1.players().size();
    PlayerONE.foreign_aid();
     PlayerTWO.foreign_aid();
      PlayerONE.foreign_aid();
       PlayerTWO.foreign_aid();
        PlayerONE.foreign_aid();
         PlayerTWO.eliminate(PlayerONE);
        cout << PlayerTWO.actionedPlayer->getName();
//     cout << PlayerONE.coins();
//     // vector<string> s = g.players();
// //     for(int i=0; i < s.size(); i++){
// //     std::cout << s.at(i) << ' ' << endl;
// // }

}