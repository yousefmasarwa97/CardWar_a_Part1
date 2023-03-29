#include <iostream>
#include <string>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;


TEST_CASE("cheking the initialization")
{
    
    Player firstPlayer("yousef");
    Player secondPlayer("yousef");

    
    Game g(firstPlayer, secondPlayer);

    /**cheking if the two players got 26 cards(half of the 52 cards) and cheking that no one of them start the game with the value
    of cardestaken bigger than 0 */
    CHECK(firstPlayer.stacksize() == 26);
    CHECK(firstPlayer.cardesTaken() == 0);

    
    CHECK(secondPlayer.stacksize() == 26);
    CHECK(secondPlayer.cardesTaken() == 0);
}


TEST_CASE("cheking the game after 5 steps")
{   
    
    Player yousef("yousef");
    Player khateeb("khateeb");

    
    Game g(yousef, khateeb);

    // making 5 game steps
    int i = 0;
    for (i = 0; i < 5; i++) 
    {
        g.playTurn();
    }

    
    CHECK(yousef.cardesTaken() == 0);
    CHECK(yousef.stacksize() == 21);

    
    CHECK(khateeb.cardesTaken() == 0);
    CHECK(khateeb.stacksize() == 21);

    //cheking the game after playing all the steps
    CHECK_NOTHROW(g.playAll());
    CHECK_NOTHROW(g.printWiner());
    CHECK_NOTHROW(g.printLog());
    CHECK_NOTHROW(g.printStats());

    
}

TEST_CASE("cheking the game after 10 steps")
{   
    
    Player yousef("yousef");
    Player khateeb("khateeb");

    
    Game g(yousef, khateeb);

    // making 10 game steps
    int i = 0;
    for (i = 0; i < 10; i++) 
    {
        g.playTurn();
    }

    
    CHECK(yousef.cardesTaken() == 0);
    CHECK(yousef.stacksize() == 21);

    
    CHECK(khateeb.cardesTaken() == 0);
    CHECK(khateeb.stacksize() == 21);

   
    CHECK_NOTHROW(g.printLog());
    CHECK_NOTHROW(g.printStats());

    
}


TEST_CASE("cheking bad game")
{
   
    Player first_player("User1");

    //just one player
    CHECK_THROWS(Game(first_player, first_player));
}


TEST_CASE("cheking if we can start the game with players using the deafult constuctor")
{
    
    Player yousef;
    Player khateeb;

    
    CHECK_THROWS(Game(yousef, khateeb));
}


TEST_CASE("check if setPlayerName works correctly"){
    Player p1("yousef");
    CHECK_NOTHROW(p1.setPlayerName("khateeb"));
}


TEST_CASE("check if cadresTaken work correctly "){
    Player p1("yousef");
    CHECK(p1.cardesTaken()>=0);
}


TEST_CASE("check if staksize work correctly "){
    Player p("bob");
    CHECK(p.stacksize()<=26);

}


TEST_CASE("check if getPlayerName works correctly"){
    Player pl1("yousef");
    Player pl2("khateeb");
    CHECK(pl1.getPlayerName().compare("yousef")==0);
    CHECK(pl2.getPlayerName().compare("khateeb")==0);
 
}
