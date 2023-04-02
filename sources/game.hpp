#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
namespace ariel
{
}
class Game
{
private:
    Player p1;
    Player p2;

public:
    Game(Player &pp1, Player &pp2);
    Game();

    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    Player getPlayer1(); //
    Player getPlayer2(); //
};

#endif