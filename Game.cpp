/*
 * Description: Program that allows user to play Mancala
 * @file: Game.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: April 26, 2021
 */
#include <iostream>
#include "MancalaBoard.h"
#include "Player.h"
#include "Game.h"

using namespace std;

/**
 * Reads player's side
 */
Game::Game() {
    board.read(cin);
    p1.save_side(board.size());
    p2.save_side(board.size()/2);
}

/**
 * Writes the number of marbles stored as the player plays
 */
void Game::play() {
    bool game_on = true;
    bool next_turn = true;

    while(cin.peek() != '\n') {
        if (next_turn)
            next_turn = board.move_marbles(p1.pick_number(), p1.get_side(), p2.get_side());
        else
            next_turn = board.move_marbles(p2.pick_number(), p2.get_side(), p1.get_side());
    }
    board.write(cout);
}
