#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"

namespace ariel
{
}
using namespace ariel;
using namespace std;

class Player
{

 private:
    string name;
    stack<card> num_of_card;
    int cards_gained;

 public:
    player(){};

    player(string name){};

    int stacksize()
    {
        return num_of_card.size();
    }

    string getPlayerName()
    {
        return this->name;
    }

    int cardesTaken()
    {
        return this->cards_gained;
    }
    };

#endif