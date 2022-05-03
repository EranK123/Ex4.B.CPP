#pragma once
#include "Game.hpp"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

namespace coup{
    class Player{
        protected:
        int coin_amount;
        string name;
        Game game;

        public:
        Player(Game game, string name);
        void income();
        void foreign_aid();
        void coup(Player p);
        string role();
        int coins();
    };
}