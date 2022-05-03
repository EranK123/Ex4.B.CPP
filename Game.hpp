#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
class Game{
         public:
         Game();
         string turn();
         vector<string > players();
         string winner();    
};
