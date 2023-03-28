#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "iostream"

class game{
    private:
    player player1;
    player player2;


    public:
    game(){};
    game(player p1,player p2){};

    void playTurn(){};

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();


    
};
#endif