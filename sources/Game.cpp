#include "Player.hpp"
#include "Game.hpp"
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
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
            for (unsigned long i = 0; i < this->playersList.size(); i++){
                if(this->playersList.at(i)->getIsPlaying() == 1){
                    cout << this->playersList.at(i)->getIsPlaying();
                s.push_back(this->playersList.at(i)->getName());
                }
            }
            return s;
        }
        string Game::winner(){
            int count = 0;
            for(unsigned long i = 0; i < this->playersList.size(); i++){
                if(this->playersList.at(i)->getIsPlaying() == 1){
                    count++;
                }
            }
            if (count == 1){
            for(unsigned long i = 0; i < this->playersList.size(); i++){
                if(this->playersList.at(i)->getIsPlaying() != 0){
                    return this->playersList.at(i)->getName();
                }
            }
            }
        return "No Winner Yet";
        }

        void Game::add(Player *p){
            this->playersList.push_back(p);
        }

     