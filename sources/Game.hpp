#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
namespace coup{
class Player;
class Game{
        public:
        vector<Player*> playersList;
        unsigned long turnNum;
         Game();
         string turn();
         vector<string > players();
         string winner();
         void add(Player *p);
         void removeAtStart();
};
}


