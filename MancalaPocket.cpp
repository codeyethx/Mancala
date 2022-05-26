/*
 * Description: Program that allows user to play Mancala
 * @file: MancalaPocket.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: April 26, 2021
 */
#include "MancalaPocket.h"
#include "Pocket.h"

void MancalaPocket::set_marbles(int marbles) {
    total_mancala = marbles;
}

int MancalaPocket::get_marbles() const {
    return total_mancala;
}

void MancalaPocket::add(int marble_amount) {
  total_mancala += marble_amount;
}

void MancalaPocket::send_pocket(int send) {}
