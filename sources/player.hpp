#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
using namespace std;
class Player
{
private:
    string playername;
    int has_played;

public:
    Player(string name_p);
    Player();
    int get_hasPlayed();
    void set_hasPlayed()
    {
        this->has_played = 1;
    }
    int stacksize();
    int cardesTaken();
    string getName();
};

#endif