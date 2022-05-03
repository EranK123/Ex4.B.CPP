#include "Player.hpp"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
namespace coup{
    class Captain : public Player{
        public:
        Captain(Game game, string name);
        void block(Player p);
        void steal(Player p);
    };
}