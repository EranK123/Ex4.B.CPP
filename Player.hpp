#pragma once
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

namespace coup{
    class Game;
    class Player{
        protected:
        string roleName;
        
        string name;
        Game *game;
        string currentAction;
        unsigned long isPlaying;
        public:
        int coin_amount;
        Player *actionedPlayer;
        Player();
        Player(Game &game, string name);
        // ~Player();
        void income();
        void foreign_aid();
        void coup(Player &p);
        string role();
        int coins();
        void removeAtStart();
        string role(string name);
        
        string getName() const{
            return this->name;
        }

        int getCoinAmount() const {
            return this->coin_amount;
        }

        string getRoleName() const {
            return this->roleName;
        }

        void setCoinAmount(int amount){
                this->coin_amount += amount;
        }

        string getCurrentAction() const {
            return this->currentAction;
        }

        void setCurrentAction(string action)  {
             this->currentAction = action;
        }

        unsigned long getIsPlaying() const {
            return this->isPlaying;
        }

        void setIsPlaying(int x)  {
             this->isPlaying = x;
        }
        
    };
}