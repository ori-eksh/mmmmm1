#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <stdexcept>
#include <string>

TEST_CASE("constructor player check)")
{
    Player pp1("ori");
    CHECK(pp1.getName() == "ori");
    Player pp2("orieksh");
    CHECK(pp2.getName() == "orieksh");
}

TEST_CASE("constructor game check")
{
    Player pq1("ori");
    Player pq2("rinat");
    Game game(pq1, pq2);
    CHECK(game.getPlayer1().getName() == "ori");
    CHECK(game.getPlayer2().getName() == "rinat");
}

TEST_CASE("constructor game check")
{
    Player player0("player0");
    Player player1("player1");
    Player player2("player2");
    Game(player0, player1);

    CHECK_THROWS(Game(player0, player1));
    CHECK_THROWS(Game(player0, player2));
    CHECK_THROWS(Game(player1, player2));
}

TEST_CASE("stacksize befor game")
{
    Player ss1("ori");
    Player ss2("rinat");
    Game game(ss1, ss2);

    CHECK(ss1.stacksize() == 26);
    CHECK(ss2.stacksize() == 26);
}

TEST_CASE("cardesTaken befor game")
{
    Player ss1("ori");
    Player ss2("rinat");
    Game game(ss1, ss2);

    CHECK(ss1.cardesTaken() == 0);
    CHECK(ss2.cardesTaken() == 0);
}

TEST_CASE("stacksize after game")
{
    Player alic("Alice");
    Player bob("Bob");

    Game game(alic, bob);
    for (int i = 0; i < 3; i++)
    {
        game.playTurn();
    }
    CHECK(alic.stacksize() <= 23);
    CHECK(bob.stacksize() <= 23);
}

TEST_CASE("stacksize after game")
{
    Player me("me");
    Player sweet("sweet");

    Game game(me, sweet);
    for (int i = 0; i < 4; i++)
    {
        game.playTurn();
    }
    CHECK(me.stacksize() <= 22);
    CHECK(sweet.stacksize() <= 22);

    for (int i = 0; i < 4; i++)
    {
        game.playTurn();
    }
    CHECK(me.stacksize() <= 18);
    CHECK(sweet.stacksize() <= 18);
}

TEST_CASE("cardesTaken after game")
{
    Player irena("Alice");
    Player tehila("Bob");

    Game game(irena, tehila);
    for (int i = 0; i < 10; i++)
    {
        game.playTurn();
    }
    CHECK(irena.cardesTaken());
}

TEST_CASE("someone loos")
{
    Player dani("dani");
    Player shira("shira");

    Game game(dani, shira);
    for (int i = 0; i < 3; i++)
    {
        game.playTurn();
    }

    CHECK(shira.cardesTaken() >= 0);
    CHECK(dani.cardesTaken() >= 0);
}

TEST_CASE("game over")
{
    Player love("love");
    Player you("you");

    Game game(love, you);
    game.playTurn();

    CHECK(love.cardesTaken() >= 0);
    CHECK(you.cardesTaken() >= 0);
    CHECK(love.stacksize() <= 25);
    CHECK(you.stacksize() <= 25);
}
TEST_CASE("game over and we cant keep play")
{
    Player want_again1("want_again1");
    Player want_again2("want_again2");

    Game game(want_again1, want_again2);
    game.playAll();
    CHECK_THROWS(game.playAll());
}
