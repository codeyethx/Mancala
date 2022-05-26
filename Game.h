#ifndef Game_H
#define Game_H
#include "MancalaBoard.h"
#include "Player.h"

class Game {
private:
    Player p1;
    Player p2;
    MancalaBoard board;
public:
    Game();
    void play();
};

#endif // Game_H
