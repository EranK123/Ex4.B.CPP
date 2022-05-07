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
	Duke PlayerTHREE{scenario1, "Player THREE"};
	Contessa PlayerFOUR{scenario1, "Player FOUR"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE, &PlayerFOUR};

    (PlayerONE.income());

    for (size_t i = 1; i < Players.size(); i++)
    {
        (Players.at(i)->income());
    }
    for (size_t j = 0; j < 2; j++)
    {
        for (size_t i = 0; i < Players.size(); i++)
        {
            (Players.at(i)->income());
        }
    }

    (PlayerONE.tax());
    (PlayerTWO.coup(PlayerONE)); // Player TWO is an assassin and can coup with 3 coins
    (PlayerTHREE.tax());
    (PlayerFOUR.block(PlayerTWO)); // Contessa blocks the coup and ..
    PlayerFOUR.foreign_aid();
    (PlayerONE.income());
    (PlayerTWO.foreign_aid());
    (PlayerTHREE.block(PlayerTWO)); // Player THREE can block Player TWO's foreign aid.
    (PlayerTHREE.tax());
    PlayerFOUR.foreign_aid();
    PlayerONE.income();
    PlayerTWO.income();
    PlayerTHREE.income();
    (PlayerFOUR.coup(PlayerONE));
    (PlayerTWO.foreign_aid());
    (PlayerTHREE.block(PlayerTWO));
    PlayerTHREE.coup(PlayerFOUR);
    PlayerTWO.foreign_aid();
    PlayerTHREE.tax();
    cout << scenario1.turn() << endl;
    cout << PlayerTHREE.getIsPlaying();
    // PlayerTWO.coup(PlayerTHREE);
    // cout << scenario1.players().size();
    // CHECK_EQ(scenario1.winner(), "Player TWO");
    // // (scenario2.winner(), "Player TWO");

}