#include "Player.hpp"
#include "Game.hpp"
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
using namespace coup;
        Game::Game(){
            this->turnNum = 0;
        }
        string Game::turn(){
            return this->playersList.at(this->turnNum % this->playersList.size())->getName();
        }
        vector<string> Game::players(){
            vector<string> s;
            for (size_t i = 0; i < this->playersList.size(); i++){
                s.push_back(this->playersList.at(i)->getName());
            }
            return s;
        }
        string Game::winner(){
            if(this->playersList.size() == 1){
                return this->playersList.at(0)->getName();
            }else{
                return "No winner yet";
            }
        }

        void Game::add(Player &p){
            this->playersList.push_back(new Player(p));
        }

     