#include "Player.hpp"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
namespace coup{
    class Ambassador : public Player{
        public:
        Ambassador(Game game, string name);
        void transfer(Player p1, Player p2);
    };
}