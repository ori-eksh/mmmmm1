#include "player.hpp"
#include <stdexcept>
#include <string>

Player::Player(string name_p)
{
    this->playername = name_p;
    this->has_played = 0;
}
Player::Player()
{
    this->playername = "anonymous";
    this->has_played = 0;
}
int Player::get_hasPlayed()
{
    return has_played;
}

int Player::stacksize() { return 26; }
int Player::cardesTaken() { return 0; }
string Player::getName() { return playername; }
