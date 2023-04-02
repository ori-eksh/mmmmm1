#include "player.hpp"
#include "game.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

Game::Game(Player &p1, Player &p2)
{
    if ((p1.get_hasPlayed()) == 1 || (p2.get_hasPlayed()) == 1)
    {
        throw string("player can play just in one game.");
    }
    else
    {
        this->p1 = p1;
        this->p2 = p2;
        p1.set_hasPlayed();
        p2.set_hasPlayed();
    }
}
Game::Game()
{
    Player q1("ori");
    Player q2("ori");

    this->p1 = q1;
    this->p2 = q2;
    q1.set_hasPlayed();
    q2.set_hasPlayed();
}
void Game::playTurn() {}
void Game::printLastTurn() {}
void Game::playAll() {}
void Game::printWiner() {}
void Game::printLog() {}
void Game::printStats() {}

Player Game::getPlayer1()
{
    return p1;
}
Player Game::getPlayer2()
{
    return p2;
}
